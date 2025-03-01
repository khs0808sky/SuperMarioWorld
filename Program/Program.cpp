#include "framework.h"
#include "Program.h"





Program::Program()
{
	Create(); // 하술
	scene = new SuperMarioTutorialScene();
	// 이 프로그램이 사용할 Scene을 관리하는 부분
	// scene 자체는 추후 설명
}

Program::~Program()
{
	delete scene;
}

void Program::Update()
{
	Control::Get()->Update();
	Timer::Get()->Update();
	// 유틸리티쪽도 함께 업데이트

	if (KEY_CON->Down(VK_F9))
	{
		Collider::SetDebugMode();
	}

	scene->Update();
	CAM->Update(); // Scene을 먼저 업데이트해서,
	// Scene 내부에서 카메라의 위치 등을 먼저 수정하게 만든 뒤
	// 그에 따라서 카메라가 움직이도록 업데이트 순서를 후순위로 밀어주기
}

void Program::Render()
{
	Device::Get()->Clear();
	// Scene을 출력하기 전에 백버퍼의 화면을 초기화시키는 작업

	/*ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();*/
	// 위의 2개는 DX11 / Win 운영체제에서 새 프레임(=창)을 만들겠다고 알리는 함수
	// 그렇게 설정된 값을 통해 실제로 만드는 게 밑의 NewFrame 함수

	/*string fps = "FPS : " + to_string(Timer::Get()->GetFPS());
	ImGui::Text(fps.c_str());
	ImGui::Text("Total Run Time : %f", Timer::Get()->GetRunTime());*/
	// Text : ImGui 판 printf
	// 이를 이용해 디버그용 창에 출력할 내용을 설정

	scene->Render();
	// Scene을 렌더링
	// 렌더링(Rendering) : 그래픽 프로그래밍에서 오브젝트를 화면에 출력할 수 있도록 만들어두는 것을 말함

	//scene->PostRender();

	//ImGui::Render(); // ImGui 객체를 렌더링하는 함수
	//ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	// ImGui 쪽으로 전달된 데이터들을, 렌더링된 객체(=창)에서 표기할 수 있도록 등록해주는 함수

	Device::Get()->Present();
	// 백버퍼에 렌더링이 전부 끝났으면 이를 모니터의 화면과 스왑하여 더블버퍼링 처리를 시행
	// 실질적으로 여기서 화면 출력이 실행 및 완료가 됨

}

void Program::Create()
// 프로그램이 처음 만들어졌을 때 같이 실행시키고 초기화시켜야 할 내용들을 모아둔 함수
// 실질적으로는 생성자나 마찬가지지만, 나중에 생성자에서 이 부분 외에도 추가적으로 넣을 내용들이 많아서
// 미리미리 분리시켜둔다는 느낌으로 만들어둔 것
{
	Device::Get();
	// 싱글톤 객체인 Device를 불러서 초기화를 동시에 실행
	Control::Get();
	Timer::Get();
	// 마찬가지로 싱글톤으로 생성되어야 할 인스턴스들을 여기서 초기화와 동시에 실행

	Environment::Get();

	

	ImGui::CreateContext(); // ImGui 객체를 만들어내는 함수
	ImGui::StyleColorsDark(); // 만들어지는 ImGui 창의 색상을 검은색 기반으로 설정하는 함수
	// Lignt, Classic도 있으므로 원하는 테마를 이용해주면 됨

	ImGui_ImplDX11_Init(DEVICE, DVC);
	// DX11 환경에서 사용하는 ImGui라고 설정
	ImGui_ImplWin32_Init(hWnd);
	// 윈도우 운영체제에서 사용하는 ImGui라고 설정
	// 이렇게 총 4줄을 이용해 본 프로그램에서 ImGui를 사용하겠다 선언 및 초기화
}



void Program::Delete()
{
	Device::Delete();
	Control::Delete();
	Timer::Delete();
}
