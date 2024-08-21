#include "framework.h"
#include "Number_3.h"

Number_3::Number_3(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_3.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_3::~Number_3()
{
}

void Number_3::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_3::Render()
{
	((Quad*)this)->Render();
}
