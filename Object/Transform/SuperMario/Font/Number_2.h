#pragma once
class Number_2 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_2(Vector2 pos, Vector2 size, Float2 s);
	~Number_2();

	void Update();
	void Render();
};