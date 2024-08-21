#include "framework.h"
#include "Play_Message.h"

Play_Message::Play_Message(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/PLAY_MESSAGE.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Play_Message::~Play_Message()
{
}

void Play_Message::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Play_Message::Render()
{
	((Quad*)this)->Render();
}
