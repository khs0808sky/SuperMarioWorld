#pragma once
class Full_Heart : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Full_Heart(Vector2 pos, Vector2 size, Float2 s);
	~Full_Heart();

	void Update();
	void Render();

};