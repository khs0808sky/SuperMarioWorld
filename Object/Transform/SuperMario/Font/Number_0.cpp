#include "framework.h"
#include "Number_0.h"

Number_0::Number_0(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_0.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_0::~Number_0()
{
}

void Number_0::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_0::Render()
{
	((Quad*)this)->Render();
}
