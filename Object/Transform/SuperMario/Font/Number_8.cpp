#include "framework.h"
#include "Number_8.h"

Number_8::Number_8(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_8.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_8::~Number_8()
{
}

void Number_8::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_8::Render()
{
	((Quad*)this)->Render();
}
