#pragma once
class Number_1 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_1(Vector2 pos, Vector2 size, Float2 s);
	~Number_1();

	void Update();
	void Render();
};