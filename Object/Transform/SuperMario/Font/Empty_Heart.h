#pragma once
class Empty_Heart : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Empty_Heart(Vector2 pos, Vector2 size, Float2 s);
	~Empty_Heart();

	void Update();
	void Render();

};