#include "framework.h"
#include "Number_7.h"

Number_7::Number_7(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_7.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_7::~Number_7()
{
}

void Number_7::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_7::Render()
{
	((Quad*)this)->Render();
}
