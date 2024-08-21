#include "framework.h"
#include "Platform.h"

Platform::Platform(Vector2 pos, Vector2 size, Vector2 scale, float angle, Matrix* parent)
	: Quad(L"Texture/AnimateScene/Animation/SuperMarioPlatform.png")
{
	this->scale = size / Size() * scale;
	// 이 플랫폼(발판)을 어느 크기로 할 것인지를 size를 통해서 입력받음
	// 그 사이즈에 맞춰서 이미지의 원래 크기에 곱해야 할 스케일을 구해야 하니
	// (우리가 입력한 사이즈) / (이미지의 사이즈) * (추가로 기본값 이외의 스케일을 더 적용하고자 한다면
	// 같이 입력한 스케일 값을 추가로 곱하기)

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
