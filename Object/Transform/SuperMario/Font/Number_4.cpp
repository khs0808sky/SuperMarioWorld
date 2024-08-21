#include "framework.h"
#include "Number_4.h"

Number_4::Number_4(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_4.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_4::~Number_4()
{
}

void Number_4::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_4::Render()
{
	((Quad*)this)->Render();
}
