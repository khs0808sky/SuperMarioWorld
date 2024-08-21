#include "framework.h"

SRTScene::SRTScene()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	// 셰이더 생성에 필요한 플래그를 미리 설정

	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);

	world = new MatrixBuffer();

	triangle = new SRTTriangle(Float2(100,100), D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	newt = new NewTriangle(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(1, 1), M_PI / 2,
		Float2(100, 100), D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	newt->SetColor(Float4(1.0f, 1.0f, 1.0f, 1.0f));

	newt2 = new NewTriangle(Vector2(WIN_CENTER_X * 4.0f / 3.0f, WIN_CENTER_Y / 2), Vector2(1, 1), M_PI / 2,
		Float2(100, 100), D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	newt2->SetColor(Float4(1.0f, 1.0f, 1.0f, 1.0f));

	c1 = new NewCircle(Float2(WIN_CENTER_X, WIN_CENTER_Y * 3.0f / 2.0f), Float2(1, 1), 0,
		75.0f, -0.0001f);
	c1->SetColor(Float4(1.0f, 1.0f, 0.0f, 1.0f));

	c2 = new NewCircle(Float2(200, 0), Float2(1, 1), 0,
		75.0f, -0.001f);
	// 이 NewCircle은 Update에서 설명하겠지만 newt라는 다른 오브젝트를 원점으로 삼아 공전하는 오브젝트
	// 따라서 이 오브젝트의 위치는 newt의 위치를 원점으로 삼아 계산함
	// -> 여기에 적힌 좌표는 "newt를 기준으로 한 좌표계에서 어느 위치에 있는지 적어두는 내용"
	c2->SetColor(Float4(0.0f, 1.0f, 1.0f, 1.0f));

	c3 = new NewCircle(Float2(-200, 0), Float2(1, 1), 0,
		50.0f, 0.001f);
	c3->SetColor(Float4(0.0f, 1.0f, 1.0f, 1.0f));

	c4 = new NewCircle(Float2(0, -150), Float2(1, 1), 0,
		40.0f, 0.001f);
	c4->SetColor(Float4(0.1f, 0.1f, 0.1f, 1.0f));

	// 공전은 기본적으로 공전할 오브젝트의 자전에 의존할 수밖에 없는 구조니
	// 다른 오브젝트와 구분되는 고유의 공전방향 및 속도를 가지기 위해선
	// 각각의 공전을 책임질 더미를 만들어 이용해야 함

	// 그러지 않고 온갖 복잡한 식을 이용한다면 그런 원형 운동 자체를 구현할 수는 있지만,
	// 그냥 이렇게 만드는 게 훨씬 빠르고 쉬움
	stub1 = new NewCircle(Float2(newt->pos.x, newt->pos.y), Float2(1, 1), 0,
		0, 0.0005f);
	stub2 = new NewCircle(Float2(newt->pos.x, newt->pos.y), Float2(1, 1), 0,
		0, -0.0003f);
	stub3 = new NewCircle(Float2(newt->pos.x, newt->pos.y), Float2(1, 1), 0,
		0, -0.0003f);

	// 엄밀히 말하면 이 더미들은 실시간으로 원형이 될 오브젝트의 위치를 전달받기 때문에
	// 생성자에서 좌표를 선언할 필요도 없긴 함
	// 다만, 처음에 화면이 정지해있다가 움직이기 시작할 경우를 고려하면
	// 미리미리 처음부터 구성하는 게 더 안전하기에 이렇게 생성한 것

	is_pause = false;
	// 일시정지를 구현하기 위해 만든 bool 플래그
}

SRTScene::~SRTScene()
{
	delete VS;
	delete PS;
	delete world;
	delete triangle;
	delete newt;
	delete newt2;
	delete c1;
	delete c2;
	delete c3;
	delete stub1;
	delete stub2;
	delete stub3;
}

void SRTScene::Update()
{
	if (KEY_CON->Down('P'))
	{
		is_pause = !is_pause;
	}
	// P를 누르면 일시정지가 되도록 하는 트리거
	// 이 트리거는 한 번 눌렀을 때 한 번만 발동되어야 안전하니
	// 계속 누르고 있으면 계속 작동하는 Press가 아닌 처음 누른 순간에만 작동하는 Down을 이용해야 함

	// 이제부턴 우리가 만드는 오브젝트들이 Update 함수를 갖추고 있으므로
	// 오브젝트들 각각의 Update 함수를 여기다가 호출
	if (is_pause == false)
	{
		newt->Update();
		newt2->Update();
		c1->Update();

		// 더미의 pos은 실시간으로 그 원형이 될 오브젝트의 pos 위치를 받아서 이용
		// 이 오브젝트들은 다른 오브젝트에 의존하지 않고 그 자체가 전체 월드의 좌표를 가지고 있으므로
		// 그대로 이용해도 됨
		stub1->pos = newt->pos;
		stub1->Update();

		// 다만, 통일성을 위해 이 쪽도 GlobalPos()를 이용하는 것이 안전
		stub2->pos = newt->GlobalPos();
		stub2->Update();


		c2->Update(stub1->GetWorld());
		// c2의 경우, newt의 월드를 기준으로 하므로 당연히 업데이트된 newt의 데이터를 받아와야 함
		// 그래서 업데이트 함수에 newt의 월드를 입력하고,
		// Update 함수 내부에서 그렇게 입력받은 함수를 Transform에 적용한 뒤 이를 이용하는 WorldUpdate로
		// 부모 오브젝트의 월드 행렬을 반영한 이 오브젝트의 월드 행렬을 계산해내는 것
		c3->Update(stub2->GetWorld());

		// 그렇게 다른 오브젝트의 위치를 기반으로 업데이트한 오브젝트를 중심으로 하여 공전하는 객체는
		// 그 부모 오브젝트 역시 다른 오브젝트를 기반으로 공전하는, 태양계로 치면 지구이므로
		// 지구 자체는 태양에서 얼마나 떨어졌는지만 기억하고 있으니
		// 그 데이터 대신 화면 전체 = 태양계 전체에서 어느 위치에 있는지를 구해야
		// 정상적으로 중심으로 삼을 수 있음
		stub3->pos = c2->GlobalPos();
		stub3->Update();

		c4->Update(stub3->GetWorld());
	}
	
}

void SRTScene::Render()
{
	DVC->VSSetShader(VS->GetVertexShader(), nullptr, 0);
	DVC->PSSetShader(PS->GetPixelShader(), nullptr, 0);
	DVC->IASetInputLayout(VS->GetInputLayout());

	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	world->SetVS(0);
	// 셰이더에 월드 행렬을 넘김
	// 이미 뷰, 프로젝션 행렬은 Program 클래스 측에서 넘어갔으므로
	// 여기서는 마지막 남은 world만 보내주면 됨
	// 그렇게 했음에도 화면에 출력이 되지 않음
	// -> WVP 변환을 고려하지 않고 출력만 하도록 만들었던 저번 코드와는 달리
	// 이제는 오브젝트 역시도 WVP 변환을 이용해 출력할 수 있도록 구성해줄 필요가 있음

	triangle->Render();
	newt->Render();
	newt2->Render();
	c1->Render();
	c2->Render();
	c3->Render();
	c4->Render();
}

void SRTScene::PostRender()
{
}

/*

과제 - 지금까지 만든 걸 기반으로 태양계를 만들어올 것

조건 :
1. 모든 행성은 Transform을 상속받은 클래스로 만들 것
2. 태양의 위치는 중앙이어도 되고 중앙 하단이어도 되고 0,0(화면 좌측 최상단)이어도 문제 없음
크기도 상관없음
3. 모든 행성들은 자전주기는 물론 공전주기 역시 전부 달라야 함
- 자전주기의 경우엔 눈에 보여야 할 필요까진 없음
4. 각 행성의 색상이나 모양 등은 어떻게 구성해도 상관없음
- 삼각형이어도 OK, 사각형이어도 OK
5. 실제 태양계와 일치하지 않아도 무방
- 행성계스럽게 만들기만 하면 됨
- 토성에 고리를 달아준다던가 하는 건 마찬가지로 할 필요 없음
- 수금지화목토천해(명) 전부 넣을 필요는 없지만,
적어도 지구+달까지는 만들어줄 것

*/
