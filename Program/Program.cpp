#include "framework.h"
#include "Program.h"





Program::Program()
{
	Create(); // �ϼ�
	scene = new SuperMarioTutorialScene();
	// �� ���α׷��� ����� Scene�� �����ϴ� �κ�
	// scene ��ü�� ���� ����
}

Program::~Program()
{
	delete scene;
}

void Program::Update()
{
	Control::Get()->Update();
	Timer::Get()->Update();
	// ��ƿ��Ƽ�ʵ� �Բ� ������Ʈ

	if (KEY_CON->Down(VK_F9))
	{
		Collider::SetDebugMode();
	}

	scene->Update();
	CAM->Update(); // Scene�� ���� ������Ʈ�ؼ�,
	// Scene ���ο��� ī�޶��� ��ġ ���� ���� �����ϰ� ���� ��
	// �׿� ���� ī�޶� �����̵��� ������Ʈ ������ �ļ����� �о��ֱ�
}

void Program::Render()
{
	Device::Get()->Clear();
	// Scene�� ����ϱ� ���� ������� ȭ���� �ʱ�ȭ��Ű�� �۾�

	/*ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();*/
	// ���� 2���� DX11 / Win �ü������ �� ������(=â)�� ����ڴٰ� �˸��� �Լ�
	// �׷��� ������ ���� ���� ������ ����� �� ���� NewFrame �Լ�

	/*string fps = "FPS : " + to_string(Timer::Get()->GetFPS());
	ImGui::Text(fps.c_str());
	ImGui::Text("Total Run Time : %f", Timer::Get()->GetRunTime());*/
	// Text : ImGui �� printf
	// �̸� �̿��� ����׿� â�� ����� ������ ����

	scene->Render();
	// Scene�� ������
	// ������(Rendering) : �׷��� ���α׷��ֿ��� ������Ʈ�� ȭ�鿡 ����� �� �ֵ��� �����δ� ���� ����

	//scene->PostRender();

	//ImGui::Render(); // ImGui ��ü�� �������ϴ� �Լ�
	//ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	// ImGui ������ ���޵� �����͵���, �������� ��ü(=â)���� ǥ���� �� �ֵ��� ������ִ� �Լ�

	Device::Get()->Present();
	// ����ۿ� �������� ���� �������� �̸� ������� ȭ��� �����Ͽ� ������۸� ó���� ����
	// ���������� ���⼭ ȭ�� ����� ���� �� �Ϸᰡ ��

}

void Program::Create()
// ���α׷��� ó�� ��������� �� ���� �����Ű�� �ʱ�ȭ���Ѿ� �� ������� ��Ƶ� �Լ�
// ���������δ� �����ڳ� ������������, ���߿� �����ڿ��� �� �κ� �ܿ��� �߰������� ���� ������� ���Ƽ�
// �̸��̸� �и����ѵдٴ� �������� ������ ��
{
	Device::Get();
	// �̱��� ��ü�� Device�� �ҷ��� �ʱ�ȭ�� ���ÿ� ����
	Control::Get();
	Timer::Get();
	// ���������� �̱������� �����Ǿ�� �� �ν��Ͻ����� ���⼭ �ʱ�ȭ�� ���ÿ� ����

	Environment::Get();

	

	ImGui::CreateContext(); // ImGui ��ü�� ������ �Լ�
	ImGui::StyleColorsDark(); // ��������� ImGui â�� ������ ������ ������� �����ϴ� �Լ�
	// Lignt, Classic�� �����Ƿ� ���ϴ� �׸��� �̿����ָ� ��

	ImGui_ImplDX11_Init(DEVICE, DVC);
	// DX11 ȯ�濡�� ����ϴ� ImGui��� ����
	ImGui_ImplWin32_Init(hWnd);
	// ������ �ü������ ����ϴ� ImGui��� ����
	// �̷��� �� 4���� �̿��� �� ���α׷����� ImGui�� ����ϰڴ� ���� �� �ʱ�ȭ
}



void Program::Delete()
{
	Device::Delete();
	Control::Delete();
	Timer::Delete();
}
