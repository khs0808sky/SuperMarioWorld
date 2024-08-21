#pragma once
class Game_Over : public Quad
{
private:
	Vector2 size; // 이 오브젝트의 크기를 관리하는 데 사용할 값


public:
	Game_Over(Vector2 pos, Vector2 size, Float2 s);
	~Game_Over();

	void Update();
	void Render();
};