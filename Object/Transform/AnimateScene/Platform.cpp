#include "framework.h"
#include "Platform.h"

Platform::Platform(Vector2 pos, Vector2 size, Vector2 scale, float angle, Matrix* parent)
	: Quad(L"Texture/AnimateScene/Animation/SuperMarioPlatform.png")
{
	this->scale = size / Size() * scale;
	// �� �÷���(����)�� ��� ũ��� �� �������� size�� ���ؼ� �Է¹���
	// �� ����� ���缭 �̹����� ���� ũ�⿡ ���ؾ� �� �������� ���ؾ� �ϴ�
	// (�츮�� �Է��� ������) / (�̹����� ������) * (�߰��� �⺻�� �̿��� �������� �� �����ϰ��� �Ѵٸ�
	// ���� �Է��� ������ ���� �߰��� ���ϱ�)

	this->pos = pos;

	collider = new RectCollider(size);
	collider->pos = pos;

}

Platform::~Platform()
{
	delete collider;
}

void Platform::Update()
{
	WorldUpdate();

	collider->pos = pos;
	collider->WorldUpdate();
}

void Platform::Render()
{
	WB->SetVS(0);
	
	Quad::Render();
	collider->Render();
}
