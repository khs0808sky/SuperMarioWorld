#include "framework.h"
#include "Game_Clear.h"

Game_Clear::Game_Clear(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/GAME_CLEAR.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Game_Clear::~Game_Clear()
{
}

void Game_Clear::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Game_Clear::Render()
{
	((Quad*)this)->Render();
}
