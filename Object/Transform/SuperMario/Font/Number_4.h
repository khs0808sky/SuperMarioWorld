#pragma once
#include <framework.cpp>
class Number_4 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_4(Vector2 pos, Vector2 size, Float2 s);
	~Number_4();

	void Update();
	void Render();
};