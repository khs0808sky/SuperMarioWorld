#include "framework.h"

AnimatePlayer::AnimatePlayer()
{
	wstring file = L"Texture/AnimateScene/Animation/SuperMarioWorld_Character.png";
	//wstring file = L"Texture/AnimateScene/Animation/SuperMarioMaker2.png";
	Texture* t = Texture::Add(file);

	/* 스프라이트의 크기가 전부 동일하고, 간격이 일정할 경우
	아래와 같은 식으로 이용할 수 있음
	
	만약 간격이 일정하지 않거나 스프라이트의 크기 자체가 다른 것이 섞여있을 경우는
	모든 스프라이트들의 데이터를 일일이 입력해줘야 함*/

	// 현재 사용할 스프라이트의 크기
	Vector2 this_frame_size = { 32.0f, 32.0f };
	// 스프라이트의 맵에서 각 스프라이트의 영역의 크기가 얼마인지를 여기서 Vector2로 저장

	// 사용할 스프라이트가 맵 상에서 시작되는 왼쪽 위 좌표
	Vector2 init_pos = { 1, 233 };

	vector<Frame*> frames; // 각 애니메이션들을 clips에 저장하기 위해 임시로 만든 자료구조
	

	// CHAR_STATUS::IDLE에 대응하는 애니메이션을 넣는 파트
	// 
	// 그 자료구조에 실제로 애니메이션 재생에 사용될 스프라이트들을 한 컷 한 컷 입력
	frames.push_back(new Frame(file, init_pos.x, init_pos.y, 
		this_frame_size.x, this_frame_size.y));

	// 하나의 애니메이션에 이용될 컷들을 Frames에 전부 저장해뒀다면
	// 이를 Clip으로 만들어 clips에 저장
	clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));

	// 하나의 애니메이션을 clips에 저장했다면,
	// 다음 애니메이션을 추가하기 위해 frames를 비움

	frames.clear(); // 어디까지나 이 벡터에 저장하고 있던 주소들만을 지울 뿐이지
	// 할당 해제까지는 하지 않기 때문에, 이렇게 clear를 이용해도 frames 안에 있던 각 프레임들은 무사
	// 이를 이용해서 다음 애니메이션을 등록할 때 사용할 frames가 마련됨

	// 나머지는 넣고 싶은 애니메이션에 맞게 위 작업을 반복

	// CHAR_STATUS::WALK에 대응하는 애니메이션을 넣는 파트
	init_pos = { 145, 233 };
	// 걷기 등의 애니메이션은 처음 프레임부터 끝 프레임까지 재생한 뒤에
	// 첫 프레임으로 돌아올 경우 부자연스럽게 돌아가는 것을 자주 확인할 수 있음
	// 이는 어지간하면 스프라이트 맵에 같은 스프라이트가 2개 이상 들어가도록 만들지 않기 때문

	// 그렇기 때문에, 이렇게 첫 프레임에서 마지막 프레임까지 갔다가 첫 프레임으로 돌아오기 전까지
	// 움직임을 부드럽게 만들고자 할 경우 여기서는 두 가지 방법을 생각할 수 있음 :
	// 1) 클립 자체의 타입을 PINGPONG으로 만드는 것
	// - 특히 이 방법은 모든 움직임이 정순->역순의 반복으로 자연스럽게 연결되는 경우 제일 이상적
	// - 그러나 지금 당장은 어째선지 사용해보니까 vector의 범위를 벗어나는,
	// 정확히는 왠지는 몰라도 클립 내부의 데이터가 전혀 이상한 값으로 변경되고 있는 것이 확인되므로
	// 이를 해결하기 전까지는 사용할 수 없음
	// 2) 중간의 연결을 담당할 스프라이트를 중복된 것이라 하더라도 또 넣어두는 방법
	// 아예 같은 프레임이 한 애니메이션에 2번 이상 사용되는 경우를 가정하고,
	// 실제로 같은 내용의 프레임을 넣어주는 것으로 애니메이션의 반복이나
	// 전체 애니메이션 중 특정 컷의 길이를 늘려주는 것으로
	// 모든 컷이 같은 시간 동안 나오도록 하지 않는 것으로 더 많은 애니메이션을 연출할 수 있음

	// 걷는 과정은 총 3개의 스프라이트 중 2번째 스프라이트부터 시작하도록
	// 그 스프라이트를 먼저 넣어둠
	frames.push_back(new Frame(file, 178.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));

	// 그 뒤, 순서에 맞게 프레임을 추가
	frames.push_back(new Frame(file, init_pos.x, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 178.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 211.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));

	clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 8.0f));
	frames.clear();

	// CHAR_STATUS::RUN에 대응하는 애니메이션을 넣는 파트
	init_pos = { 248, 233 };

	frames.push_back(new Frame(file, 281.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));

	// 그 뒤, 순서에 맞게 프레임을 추가
	frames.push_back(new Frame(file, init_pos.x, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 281.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 314.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));

	clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 12.0f));
	frames.clear();

	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();

	collider = new RectCollider(Vector2(38, 80));
	collider->pos = pos;

	collider->is_active = true;
	// 그냥 충돌판정을 임의대로 사이즈를 지정해서 출력해보면
	// 이 시점에서는 스프라이트의 크기와 충돌판정의 크기가 일치하지 않음을 확인 가능
	// 스프라이트가 출력되는 크기를 조정하지 않았으니 당연한 내용

	// 이를 조정하는 방법은 굉장히 많음
	// 충돌판정의 크기 자체를 조정하는 방식
	// 혹은 충돌판정의 크기를 스프라이트의 크기에 맞추는 방식
	// 그도 아니면 반대로 스프라이트의 크기를 충돌판정에 맞추는 방식

	// 당장 해결하고자 한다면 첫번째 방법이 제일 빠른 건 맞음
	// 아래의 2개 방법은 얼만큼 보정을 해줘야 하는지 계산하는 식을 만드는 등의 과정이 필요하나,
	// 이 쪽은 그럴 필요 없이 직접 수치를 조정해보면서 적절히 깎으면 됨

	// 하지만 이는 어디까지나 그렇게 만들 오브젝트의 개수가 그리 많지 않을 때나 편한 방법
	// 게임에서 다루는 오브젝트의 개수가 일반적으로 최소 100종은 넘어간다는 것을 생각해보면
	// 모든 오브젝트를 이렇게 다루는 것은 심각하게 많은 시간이 걸릴 것

	// 그렇다고 이 방법이 안 쓰이는 것은 아님
	// 하나의 오브젝트가 둘 이상의 충돌판정을 다뤄야 한다던가 하는 경우는
	// 사용하는 스프라이트의 크기와는 완전히 별개로 사이즈를 지정해준다던가 해야 하기 때문에,
	// 이런 것이 필요한 게임인 경우는 이렇게 할 수 밖에 없음

	// 우리가 본격적으로 다뤄볼 것은
	// 스프라이트의 크기를 충돌판정의 크기에 맞춰서 출력해보는 방식

	action_status = CHAR_STATUS::IDLE;
	is_looking_left = false;

	jump_height = 0.0f;
	jump_speed = 0.0f;
}

AnimatePlayer::~AnimatePlayer()
{
	for (Clip* c : clips)
		delete c;

	delete collider;

	delete CB;
}

void AnimatePlayer::Update()
{
	/*
	이 방식은 점프를 구현하는 방법 중 하나일 뿐
	다른 방식으로 점프를 구현하는 방법은 충분히 많고,

	무엇보다 이 방식은 "땅에서 벗어났을 때 자유낙하한다"라는 개념을 적용시키는 게 불가능한 방식

	1. 트랜스폼의 Y좌표 위치를 곧바로 더하는 식이 아닌,
	현재 점프 높이가 얼만큼 되어있는지를 따로 기록

	2. 업데이트가 실행됐을 때 "직전에 실제 위치를 확인하기 위해 반영되었던 점프 높이"를
	트랜스폼의 pos.y에서 제거하는 것으로 "점프하지 않은 상태에서의 위치"를 복원함

	3. 키 입력이나 중력가속도 등을 고려하여 점프 속도를 관리

	4. 속도 관리가 완료되었다면 현 시점에서 원점으로 돌아가있는 이 오브젝트의 y좌표에
	점프 높이를 반영

	이 방식을 사용할 경우 "점프하지 않은 상태에서의 원래 Pos 값이
	적어도 Update 도중에는 그대로 유지되어 있다는 것이 최대 특징
	이를 이용하면 실제 게임 캐릭터는 맵의 해당 칸에 그대로 있는데
	우리 눈에 보이는 캐릭터의 이미지는 점프하는 것처럼 보이도록 만들 수 있음
	*/

	pos.y += jump_height;

	if (KEY_CON->Down(VK_UP) || KEY_CON->Down('X'))
	{
		jump_speed = 200.0f;
	} // 특정 키가 눌렸을 때 점프하는 힘을 위와 같이 설정

	jump_height += jump_speed * DELTA;
	jump_speed -= GRAVITY * 2 * DELTA;


	switch (action_status) // 현재 상태에 따라 같은 키가 입력됐더래도 다른 작업을 하도록
		// 분기문을 각 상태마다 만들어둠
	{
	case AnimatePlayer::CHAR_STATUS::IDLE: // 멈춰있는 상태
	{
		if (KEY_CON->Press(VK_LEFT))
		{
			SetClip(CHAR_STATUS::WALK);
		}
		else if (KEY_CON->Press(VK_RIGHT))
		{
			SetClip(CHAR_STATUS::WALK);
		}
	}
		break;
	case AnimatePlayer::CHAR_STATUS::WALK: // 걷고 있는 상태
	{
		if (KEY_CON->Press(VK_LEFT))
		{
			pos.x -= 100.0f * DELTA;
			is_looking_left = true;
		}
		if (KEY_CON->Press(VK_RIGHT))
		{
			pos.x += 100.0f * DELTA;
			is_looking_left = false;
		}
		if (!KEY_CON->Press(VK_LEFT) && !KEY_CON->Press(VK_RIGHT))
		{
			SetClip(CHAR_STATUS::IDLE);
		}
		// 한 번 이렇게 걷기를 구현해서 움직여보니까 2가지 문제점이 확인되고 있음
		// 1) 걷기 모션에 들어갈 때의 스프라이트가 매번 다르게 나오고 있음
		// - 이는 클립을 전환할 때 전환하기 전의 클립의 데이터를
		// 제대로 멈췄다고 초기화하지 않아 생기는 문제
		// 이걸 해결하기 위해서는 클립을 바꾸는 기능을 전담하는 함수를 만들어야 하나,
		// 이는 다음 시간에 진행
		// 2) 분명히 좌우 움직임에 따라 진행하는 방향을 봐야 하는데
		// 항상 같은 방향만을 보고 있다는 것을 확인 가능
		// 이는 말 그대로 향하는 방향에 맞게 이미지를 뒤집어주는 작업을 하지 않은 것이 원인
		// 좌우 각각의 작업을 진행할 때마다 좌우를 보고 있다는 멤버의 값을 변경해주고
		// 이를 scale에 반영해주면 됨
	}
		break;
	case AnimatePlayer::CHAR_STATUS::RUN:
		break;
	default:
		break;
	}


	// 이 부분은 키 입력 등의 다른 상호작용이 다 끝나서
	// 어떤 애니메이션을 출력할지, 이 오브젝트의 위치나 회전 같은 것이 어떻게 됐는지
	// 이런 정보들이 전부 정해진 상황에서 월드업데이트를 하는 상황

	clips[(UINT)action_status]->Update(); // 현재 재생해야 할 애니메이션을 업데이트

	scale = clips[(UINT)action_status]->GetFrameSize() * 2.7f;
	// 기본적으로 Frame에서 사용되는 이미지는 전체 이미지의 일부를 "잘라와서 사용하는 것"이 아니고
	// 전체 이미지를 "그대로 가져와서" 그 중 일부만 출력하는 데 사용하는 것
	// 다르게 말하면, 사용하는 이미지파일의 크기 자체는 맵 전체의 크기를 그대로 가지고 있다는 이야기
	// 따라서 실제 스프라이트의 크기를 정상적으로 출력하고자 한다면,
	// 파일 전체의 크기에서 해당 스프라이트의 크기의 비율을 받아낸 뒤
	// 이를 해당 이미지를 실제로 출력하는 Player의 scale에 반영하여
	// 전체 파일 중 그만큼의 사이즈으로만 나오도록 보정할 필요가 있음

	// 다만, 이렇게 곧바로 반영할 경우엔 스프라이트의 실제 크기를 화면에 출력하도록 만들게 됨
	// 따라서 우리가 원하는 크기로 출력되지 않으며, 원하는 크기로 만들고자 한다면
	// 위에서 구한 저 scale에 추가적으로 보정을 해줄 필요가 있음

	// 직접 저 scale에 값을 곱해주는 것도 고려할 수 있지만,
	// 이 역시 오브젝트 개수가 적을 때나 편한 방법

	// 따라서, 저 기본값에다가 어느 값을 곱하면
	// 충돌판정의 크기와 동일한 크기가 될 것인지 그 값을 역산하여 곱해주면 됨

	/*
	우리가 출력하고 싶은 값(=충돌판정의 크기) : 스프라이트의 원래 크기(이하 원본)
	= x : 스프라이트의 원래 크기를 출력하는 데 사용된 scale값(이하 FrameSize())
	충돌판정의 크기 * FrameSize() = x * 원본
	x = (충돌판정의 크기 * FrameSize()) / 원본

	충돌판정의 크기는 우리가 아예 입력(지정)해주는 것이니 추가적인 처치 불요
	FrameSize() 역시 이미 구할 방법이 있음
	남은 건 원본 스프라이트의 크기를 어떻게 구할 것인가?
	-> Frame에 GetFrameOrigSize()를 구현하는 것으로 해결
	*/

	//scale = scale * Vector2(38, 80) / clips[0]->GetFrameOrigSize();

	// 이렇게 하면 스프라이트의 크기 자체를 충돌판정에 맞춰서 출력할 수 있음
	// 단, 사용하는 스프라이트 자체가 추가적으로 커다란 배경을 가지고 있을 경우엔
	// 그 배경마저 충돌판정 내부에 들어가도록 맞춰지는 문제가 있기 때문에
	// 이 방법이 별 문제없이 쓰이려면 사용하는 스프라이트가 
	// 추가적인 배경 같은 게 없이 그 스프라이트만 지정되도록 프레임을 만들 필요가 있음
	// 아니면 여기서 그 원본 스프라이트의 크기를 직접 입력하던가

	// 스프라이트들을 전부 직접 배경이 없도록 자르는 게 아닌 한,
	// 이 방식으로는 그렇게 배경이 있는 것들을 제대로 지정하지 못한다는 것이 흠
	// 그렇기에 이런 방식은 모든 스프라이트 맵에서 제대로 사용할 수 있는 게 아님

	// 따라서, 이 방식들 중 어떤 방식을 사용할 것인지는
	// 스프라이트 맵에 맞춰서 따라가는 수 밖에 없음
	
	if (is_looking_left) // 사용하는 스프라이트가 본래 보던 방향을 기준으로,
		// 현재 바라보는 방향이 그와 반대되는지를 검사
	{
		scale.x *= -1; // 서로 반대라면, 현재 진행중인 방향을 보도록 스프라이트를 좌우반전
	}

	/*
	if (jump_height <= 0)
		jump_height = 0;
	*/

	pos.y -= jump_height;


	WorldUpdate(); // 이 오브젝트가 가진 트랜스폼의 모든 정보가 전부 확정됐으면
	// 이를 이용해 월드업데이트

	// 이 오브젝트의 월드가 확정됐다면 이에 따라 충돌판정 역시 월드업데이트
	collider->pos = pos + Vector2(0, 5);
	collider->WorldUpdate();
}

void AnimatePlayer::Render()
{
	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	clips[(UINT)action_status]->Render();

	collider->Render();
}

void AnimatePlayer::PostRender()
{
	ImGui::SliderFloat2("Player's pos", (float*)&pos, 0, WIN_WIDTH);
	ImGui::Text("Jump_Height : %f, Jump_Speed : %f", jump_height, jump_speed);
}

void AnimatePlayer::SetClip(CHAR_STATUS stat)
// 이 오브젝트가 지금 당장 출력하고 있는 애니메이션 클립을
// 다른 애니메이션으로 바꾸면서, 동시에 그 과정에서 필연적으로 진행돼야 할
// 여러 작업들을 같이 수행하도록 하는 함수
{
	if (action_status != stat) // 이 함수에 입려된 스탯이 현 시점의 스탯과 동일한지 검사
		// 동일하지 않다면 이 오브젝트의 상태를 바꾸는 코드를 실행함
	{
		switch (stat) // 입력받은 상태에 따라 다른 작업을 하도록 분기
		{
		case AnimatePlayer::CHAR_STATUS::IDLE:
		{
			clips[(int)action_status]->Stop();
			action_status = stat;
			clips[(int)action_status]->Play();
		}
			break;
		case AnimatePlayer::CHAR_STATUS::WALK:
		{
			clips[(int)action_status]->Stop();
			action_status = stat;
			clips[(int)action_status]->Play();
		}
			break;
		case AnimatePlayer::CHAR_STATUS::RUN:
		{
			clips[(int)action_status]->Stop();
			action_status = stat;
			clips[(int)action_status]->Play();
		}
			break;
		default:
			break;
		}
	}
}

void AnimatePlayer::JumpCollide(UINT dir)
// 지금의 매개변수는 공중에서 충돌하는 것이 장애물 한 종류밖에 없을 때를 기준으로 하는 코드
// 만약 이것 말고 공중에서 충돌 가능한 오브젝트가 더 존재한다면,
// 어떤 오브젝트인지 판별할 수 있도록 매개변수나 기타 무언가를 더 받도록 해서
// 그 각각을 switch를 통해 관리할 것
{
	switch(dir)
	{
	case 0: // 하강중
		jump_height = 0;
		jump_speed = 0; // 바닥에 닿은 시점에서 더 이상 떨어지지 않고 있으므로
		// 떨어지는 속도가 가속될 일이 없으니 0으로 고정

		// 허나, 점프의 높이를 jump_height에서 전적으로 관리하고 있는 시점에서
		// 이렇게만 만들어뒀을 경우엔 자유낙하를 어떤 식으로 관리해야 할 것인지 구현하기가 힘듦
		// 발판을 밟지 않고 있을 경우 자유낙하를 하게 만들고자 한다면 
		// 점프의 매커니즘을 크건 작건 바꿔나가야 함

		break;

	case 1: // 상승중
		jump_height -= jump_speed * DELTA;
		jump_speed = 0;
		// 부딪히자마자 하강하지 시작하도록 짤 생각이라면 0으로 만들기
		// 부딪히고도 점프하는 시간 자체는 좀 유지하고 싶다면 스피드는 그대로 놔두기
		break;

	case 2: // 왼쪽으로 이동 중
		break;

	case 3: // 오른쪽으로 이동 중
		break;

	default:
		break;
	}
}

/*
이제부터의 과제 : 개인 포트폴리오 작업 시작
앞으로의 과제는 항상 개인 포트폴리오로서 각각 작업한 제작물을 제출해주셔야 함

첫 주는 "개인 포트폴리오로서 만들고 싶은 것이 무엇인지, 텍스트로서 정리하여 제출할 것"이 과제

1) 만들고 싶은 게임 - 어떤 종류의 게임을 만들어보고 싶다는 것보다는
어떤 게임을 벤치마킹해서 만들어보고 싶다, 라는 방향으로 구상하는 것을 추천
2) 그렇게 만들고 싶은 게임을 만들고자 할 때 "무엇을 먼저 만들지"를 간단한 계획을 세워서 설명할 것


===>
이를 수행하면서 어떤 게임을 만들 것인지 그 방향을 잡았음

앞으로도 본 수업시간엔 게임에서 주로 만들게/다루게 되는 개념들을 설명할 예정
그러나 이는 여러분이 만들 개인 포트폴리오와는 기본적으로는 무관하며,
어디까지나 개인 포트폴리오를 만드는 과정에서 힌트를 얻어보고자 하는 느낌으로 진행할 예정이니
"이 부분은 내가 만들고자 하는 부분에서 절대 쓰일 일이 없겠다"라는 확신이 든다면
무시하고 이 자리에서 개인 포트폴리오를 계속해서 만들 것


===

2주차 이후의 개인 포트폴리오 : 

1) 이번주에 만들고자 목표했던 내용

2) 실제로 만들어진 결과물의 코드(디버그 폴더는 삭제하고, 프로젝트 하나만 제출해도 OK)
1번의 구현에 실패했어도 제출
(어디서 막혔는지 파악하고 이에 대해서 조언하기 위한 의도로 제출하라 하는 것
막힌 부분이 있다면 필히 어디서 막혔는지까지 같이 제시하여 어디가 문제인지 같이 파악할 수 있도록 할 것)

3) 다음 주까지 완성하고자 하는 목표 및 이에 대한 계획표
(어느어느 순서대로 만드는 것으로 충분)
*/
