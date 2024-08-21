#include "framework.h"
#include "Game_Over.h"

Game_Over::Game_Over(Vector2 pos, Vector2 size, Float2 s)
	: Quad(L"Texture/SuperMario/GAME_OVER.png")
{
	this->pos = pos;
	this->scale = s;
	this->size = size;
}

Game_Over::~Game_Over()
{
}

void Game_Over::Update()
{
	//((Quad*)this)->WorldUpdate();
	WorldUpdate();
}

void Game_Over::Render()
{
	((Quad*)this)->Render();
}
