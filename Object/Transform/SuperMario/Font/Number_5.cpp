#include "framework.h"
#include "Number_5.h"

Number_5::Number_5(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_5.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_5::~Number_5()
{
}

void Number_5::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_5::Render()
{
	((Quad*)this)->Render();
}
