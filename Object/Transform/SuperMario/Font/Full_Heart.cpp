#include "framework.h"
#include "Full_Heart.h"

Full_Heart::Full_Heart(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/FULL_HEART.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Full_Heart::~Full_Heart()
{
}

void Full_Heart::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Full_Heart::Render()
{
	((Quad*)this)->Render();
}
