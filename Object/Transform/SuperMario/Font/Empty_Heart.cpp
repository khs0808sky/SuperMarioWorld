#include "framework.h"
#include "Empty_Heart.h"

Empty_Heart::Empty_Heart(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/EMPTY_HEART.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Empty_Heart::~Empty_Heart()
{
}

void Empty_Heart::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Empty_Heart::Render()
{
	((Quad*)this)->Render();
}
