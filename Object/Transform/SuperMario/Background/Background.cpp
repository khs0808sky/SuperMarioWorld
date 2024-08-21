#include "framework.h"

Background::Background()
{
	// 배경화면 한 장의 가로 세로는 768px

	groundBackground[0] = new GroundBackground(GroundBackground::BACKGROUND_TYPE::DOWN);
	groundBackground[1] = new GroundBackground(GroundBackground::BACKGROUND_TYPE::DOWN);
	groundBackground[2] = new GroundBackground(GroundBackground::BACKGROUND_TYPE::DOWN);
	groundBackground[3] = new GroundBackground(GroundBackground::BACKGROUND_TYPE::UP);
	groundBackground[4] = new GroundBackground(GroundBackground::BACKGROUND_TYPE::UP);
	groundBackground[5] = new GroundBackground(GroundBackground::BACKGROUND_TYPE::UP);

	groundBackground[0]->pos = pos + Vector2(WIN_CENTER_X, WIN_CENTER_Y);
	groundBackground[1]->pos = pos + Vector2(WIN_CENTER_X - 768, WIN_CENTER_Y);
	groundBackground[2]->pos = pos + Vector2(WIN_CENTER_X + 768, WIN_CENTER_Y);
	groundBackground[3]->pos = pos + Vector2(WIN_CENTER_X, WIN_CENTER_Y - 768);
	groundBackground[4]->pos = pos + Vector2(WIN_CENTER_X -768, WIN_CENTER_Y - 768);
	groundBackground[5]->pos = pos + Vector2(WIN_CENTER_X + 768, WIN_CENTER_Y - 768);
}

Background::~Background()
{
	for (auto b : groundBackground)
		delete b;
}

void Background::Update()
{
	groundBackground[0]->pos = pos + Vector2(WIN_CENTER_X, WIN_CENTER_Y);
	groundBackground[1]->pos = pos + Vector2(WIN_CENTER_X - 768, WIN_CENTER_Y);
	groundBackground[2]->pos = pos + Vector2(WIN_CENTER_X + 768, WIN_CENTER_Y);
	groundBackground[3]->pos = pos + Vector2(WIN_CENTER_X, WIN_CENTER_Y - 768);
	groundBackground[4]->pos = pos + Vector2(WIN_CENTER_X - 768, WIN_CENTER_Y - 768);
	groundBackground[5]->pos = pos + Vector2(WIN_CENTER_X + 768, WIN_CENTER_Y - 768);

	for (auto b : groundBackground)
	{
		b->Update();
	}
}

void Background::Render()
{
	for (auto b : groundBackground)
		b->Render();
}

void Background::PostRender()
{
}

void Background::SetClear()
{
	for (auto b : groundBackground)
		b->SetColor(Float4(0.5f, 0.5f, 0.5f, 1.0f));
}
