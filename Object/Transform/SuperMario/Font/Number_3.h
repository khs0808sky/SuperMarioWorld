#pragma once
class Number_3 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_3(Vector2 pos, Vector2 size, Float2 s);
	~Number_3();

	void Update();
	void Render();
};