#pragma once
class Number_0 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_0(Vector2 pos, Vector2 size, Float2 s);
	~Number_0();

	void Update();
	void Render();

};