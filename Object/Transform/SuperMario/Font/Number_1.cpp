#include "framework.h"
#include "Number_1.h"

Number_1::Number_1(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_1.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_1::~Number_1()
{
}

void Number_1::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_1::Render()
{
	((Quad*)this)->Render();
}
