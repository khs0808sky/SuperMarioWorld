#pragma once
class Game_Clear : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Game_Clear(Vector2 pos, Vector2 size, Float2 s);
	~Game_Clear();

	void Update();
	void Render();
};