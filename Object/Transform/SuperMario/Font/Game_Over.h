#pragma once
class Game_Over : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Game_Over(Vector2 pos, Vector2 size, Float2 s);
	~Game_Over();

	void Update();
	void Render();
};