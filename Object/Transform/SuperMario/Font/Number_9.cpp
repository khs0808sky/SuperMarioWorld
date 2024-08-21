#include "framework.h"
#include "Number_9.h"

Number_9::Number_9(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/NUMBER_9.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Number_9::~Number_9()
{
}

void Number_9::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Number_9::Render()
{
	((Quad*)this)->Render();
}
