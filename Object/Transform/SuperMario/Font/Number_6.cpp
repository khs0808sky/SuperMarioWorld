#include "framework.h"
#include "Number_6.h"

Number_6::Number_6(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_6.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_6::~Number_6()
{
}

void Number_6::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_6::Render()
{
	((Quad*)this)->Render();
}
