#include "framework.h"
#include "Restart_Message.h"

Restart_Message::Restart_Message(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/RESTART_MESSAGE.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Restart_Message::~Restart_Message()
{
}

void Restart_Message::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Restart_Message::Render()
{
	((Quad*)this)->Render();
}
