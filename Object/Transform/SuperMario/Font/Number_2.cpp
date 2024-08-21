#include "framework.h"
#include "Number_2.h"

Number_2::Number_2(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_2.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_2::~Number_2()
{
}

void Number_2::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_2::Render()
{
	((Quad*)this)->Render();
}
