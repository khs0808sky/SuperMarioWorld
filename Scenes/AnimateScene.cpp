#include "framework.h"

void AnimateScene::change_stage(int stage)
{
	for (auto p : stage_list[this->stage]) 
		// 스테이지가 바뀐다면 기존 스테이지에 있던 것들은 비활성화를 해야 하니
		// 그에 맞게 비활성화 작업을 그렇게 거침
	{
		p->SetActive(false);
		p->GetCollider()->SetActive(false);
	}

	for (auto p : stage_list[stage]) // 이번엔 벡터의 벡터를 이용하는 상황이니
		// 이에 맞게표기를 바꿔주는 것
	{
		p->SetActive(true);
		p->GetCollider()->SetActive(true);
		// 이를 통해 앞으로 사용될 스테이지에 있는 장애물들을 그 시점에서 활성화
	}
	// 지금 쓰고 있는 것을 먼저 비활성화시킨 뒤 새로 사용할 것들
	// (+기존에 사용했던 걸 재활용하는 파트) <- 이게 비활성화되는 불상사를 막을 수 있음

	this->stage = stage;

}

AnimateScene::AnimateScene()
	: stage(0), fade_time(0)
{
	player = new AnimatePlayer();
	player->pos = Vector2(WIN_CENTER_X, WIN_CENTER_Y);

	obstackle = new Platform(Vector2(200, 200), Vector2(400, 200), Vector2(1, 1), 0.0f);
	/*obstackle->SetActive(true);
	obstackle->GetCollider()->SetActive(true);*/

	ground = new Platform(Vector2(WIN_CENTER_X, WIN_HEIGHT - 50), 
		Vector2(WIN_WIDTH - 200, 30), Vector2(1, 1), 0.0f);
	/*ground->SetActive(true);
	ground->GetCollider()->SetActive(true);*/

	platform_list.push_back(obstackle);
	platform_list.push_back(ground);


	platform_list.push_back(new Platform(Vector2(800, 200), 
		Vector2(100, 100), Vector2(1, 1), 90.0f));
	/*platform_list[2]->SetActive(true);
	platform_list[2]->GetCollider()->SetActive(true);*/

	stage_list.push_back(platform_list); // 위에서 만들었던 플랫폼 리스트들을
	// 첫번째 스테이지 데이터가 완성되었으면 스테이지 리스트에 추가

	vector<Platform*> temp_pList; // 두번째 스테이지를 생성
	temp_pList.push_back(obstackle);
	temp_pList.push_back(ground);

	temp_pList.push_back(new Platform(Vector2(700, 400),
		Vector2(300, 400), Vector2(1, 1), 0.0f));
	temp_pList.push_back(new Platform(Vector2(120, 600),
		Vector2(50, 50), Vector2(1, 1), 0.0f));

	stage_list.push_back(temp_pList); // 완성됐으면 스테이지 리스트에 제출

	change_stage(1);

	/*
	어떻게 하면 이렇게 2개 이상 만들어진 스테이지를
	"한순간에" 바꿀 수 있을지, 코드상으로 어떤 코드를 작성할 것인지 한 번 생각해보기

	바뀌는 상황은 일단 D를 눌렀을 때 스테이지를 자동 전환시키는 치트키를 쳤을 때라고 생각했을 때
	*/
}

AnimateScene::~AnimateScene()
{
	delete player;
	for (auto p : stage_list[stage])
		delete p;
	platform_list.clear();
}

void AnimateScene::Update()
{
	// 이제부터 충돌처리를 만들어볼 것인데
	/*
	충돌했을 경우 어떻게 처리할 것인가를 고민해볼 것
	
	충돌 자체는 여러가지 방식으로 작용하도록 구상할 수 있지만,
	최종적으로 어떤 방식을 채택하든 "어느 방향에서 충돌했는지를 판단할 수 있는 방법은 필요함
	*/

	if (KEY_CON->Down('D') && fade_time <= 0)
		// 지금은 테르트를 위해 버튼으로 했지만
		// 나중에는 이거 말고 플레이어 캐릭터가 다음 맵으로 가게 되는 위치에 접근했다던가 하는 식으로
		// 다른 조건을 넣고 그에 맞게 코드를 구성하여 맵 이동을 구현하도록 하게 될 것
	{
		stage++;
		if (stage > 1) stage = 0;

		fade_time = 1.0f;
	}

	/*
	위와 같이 화면을 전환하게 되는 트리거는 만들어두었음
	그러나 실제로 해보니 화면 전환이 너무 급작스러운 면이 있어서 자연스럽지는 않음
	+ 화면에 출력할 데이터들을 로딩을 해야 하는데, 그 로딩이 완료되기 전에 화면에 노출이 되어버리면
	그건 그것대로 부자연스러움

	그래서
	화면 전환을 자연스럽게 하는 동시에, 다음 화면에 출력할 오브젝트들을 미리 배치해두기 위해
	영상적으로 시간을 버는 트릭을 사용하게 됨
	(록맨처럼 다음 화면으로 넘어가는 과정을 좀 길게 해서 다음 맵을 미리 로딩해두는 식이라던가,
	화면을 검게 만든 뒤에 화면이 검어졌을 때 그래픽을 바꾸는 처리를 완료하고 나서
	다시 화면이 밝아지게 하는 방법 등)

	여기서는 그 중 화면 전체를 검어지게 만드는 방법을 이용할 예정
	-> 모든 오브젝트의 컬러버퍼를 건드리는 방법,
	혹은 우리가 사용하는 셰이더 자체에서 추가적으로 흑백 혹은 알파값을 건드리는 방법

	여기선 모든 오브젝트의 컬러버퍼를 건드리는 방법을 써봄

	필요한 것 : 화면이 검어지는 시간을 기록할 필요가 있음 -> 시간을 기록할 변수

	*/
	if (fade_time <= 0) // 현재 화면 전환중이 아닌 경우
		// 일반적인 진행
	{
		Vector2 obstackle_area;
		// 플레이어와 다른 충돌체가 충돌했을 때,
		// 정확히 충돌한 범위가 어떻게 되는지 그 영역(의 크기)을 저장할 함수

		for (auto p : stage_list[stage])
		{

			if (player->GetCollider()->isCollision(p->GetCollider(), &obstackle_area))
				// AABB 충돌을 다룰 때 정확히 어느 범위가 충돌했는지를 입력받은 포인터를 통해 반환한다 했는데
				// 그게 바로 지금을 위해서 만들어둔 구조
			{
				// 충돌을 했다면, 필연적으로 충돌한 만큼 = 겹친 만큼의 영역이 만들어질 것
				// 그렇게 받아온 영역과 플레이어, 충돌체 각각의 중심점을 확인하여
				// 어느 방향에서 충돌했는지를 검사

				Vector2 player_pos = player->GetCollider()->pos;
				Vector2 obstackle_pos = p->GetCollider()->pos;
				// 그냥 쓰기는 코드가 너무 길으므로 조금이라도 더 짧게 쓰도록 변수를 이용

				if (obstackle_area.x > obstackle_area.y)
					// 충돌한 영역의 크기가 가로가 세로보다 더 길 경우
					// == 위나 아래에서 충돌하기 시작한 상황
					// (세로축에서 막 파고들기 시작했단 이야기니 위나 아래에서 접근하기 시작했을 때의 이야기)
				{
					if (player_pos.y > obstackle_pos.y) // 플레이어의 위치가 충돌체의 위치보다 더 낮다면
					// 아래에서 올라가고 있던 상황
					{
						player->pos.y += obstackle_area.y;
						// 충돌한 영역만큼 더하는 것으로 더 밑으로 내려서
						// 사실상 충돌하지 않고 더 이상 진입하지 못하는 상황으로 만드는 것
						player->JumpCollide(1);
					}
					else // 위에서 떨어지고 있던 상황
					{
						player->pos.y -= obstackle_area.y;
						// 반대로 충돌한 영역만큼 위로 올려서
						// 더 이상 내려가지 않도록 처리
						player->JumpCollide(0);
					}
				}
				else // 위가 아닌 경우, 즉 충돌 영역의 세로가 가로보다 큰 경우
				// = 좌우에서 충돌이 발생했을 경우
				{
					if (player_pos.x > obstackle_pos.x) // 플레이어의 위치가 충돌체의 위치보다 더 낮다면
					// 아래에서 올라가고 있던 상황
					{
						player->pos.x += obstackle_area.x;
						// 충돌한 영역만큼 더하는 것으로 더 밑으로 내려서
						// 사실상 충돌하지 않고 더 이상 진입하지 못하는 상황으로 만드는 것
						player->JumpCollide(2);
					}
					else // 위에서 떨어지고 있던 상황
					{
						player->pos.x -= obstackle_area.x;
						// 반대로 충돌한 영역만큼 위로 올려서
						// 더 이상 내려가지 않도록 처리
						player->JumpCollide(3);
					}
				}
			}
		}

		/*
		if (player->GetCollider()->isCollision(ground->GetCollider(), &obstackle_area))
			// 위의 모든 작업들을 땅을 담당하는 충돌체에도 마찬가지로 처리
		{
			// 충돌을 했다면, 필연적으로 충돌한 만큼 = 겹친 만큼의 영역이 만들어질 것
			// 그렇게 받아온 영역과 플레이어, 충돌체 각각의 중심점을 확인하여
			// 어느 방향에서 충돌했는지를 검사

			Vector2 player_pos = player->GetCollider()->pos;
			Vector2 ground_pos = ground->GetCollider()->pos;
			// 그냥 쓰기는 코드가 너무 길으므로 조금이라도 더 짧게 쓰도록 변수를 이용

			if (obstackle_area.x > obstackle_area.y)
				// 충돌한 영역의 크기가 가로가 세로보다 더 길 경우
				// == 위나 아래에서 충돌하기 시작한 상황
				// (세로축에서 막 파고들기 시작했단 이야기니 위나 아래에서 접근하기 시작했을 때의 이야기)
			{
				if (player_pos.y > ground_pos.y) // 플레이어의 위치가 충돌체의 위치보다 더 낮다면
				// 아래에서 올라가고 있던 상황
				{
					player->pos.y += obstackle_area.y;
					// 충돌한 영역만큼 더하는 것으로 더 밑으로 내려서
					// 사실상 충돌하지 않고 더 이상 진입하지 못하는 상황으로 만드는 것
					player->JumpCollide(1);
				}
				else // 위에서 떨어지고 있던 상황
				{
					player->pos.y -= obstackle_area.y;
					// 반대로 충돌한 영역만큼 위로 올려서
					// 더 이상 내려가지 않도록 처리
					player->JumpCollide(0);
				}
			}
		}
		*/

		player->Update();
		for (auto p : stage_list[stage])
			p->Update();
	}
	else // 현재 페이드아웃 중인 경우
	{
	fade_time -= DELTA;

	Float4 fadecolor;
	if (fade_time > 0) // 현재 아직 검게 변해있어야 할 시간이 남아있다면
		fadecolor = Float4(0, 0, 0, 1); // 흑백을 처리할 색상코드를 미리 만들어둠
	else // 더 이상 검은 색이 될 필요가 없다면
		fadecolor = Float4(1, 1, 1, 1); // 다시 원래 색을 표기하도록

	player->SetColor(fadecolor); // 이를 통해 각 오브젝트들의 색을 검은색으로 지정
	for (auto p : stage_list[stage])
		p->SetColor(fadecolor);

	if (fade_time <= 0)
		change_stage(stage);

	}
}

void AnimateScene::Render()
{
	for (auto p : stage_list[stage])
		p->Render();
	player->Render();
}

void AnimateScene::PostRender()
{
	player->PostRender();
}
