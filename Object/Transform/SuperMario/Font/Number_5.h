#pragma once
#include <framework.cpp>
class Number_5 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_5(Vector2 pos, Vector2 size, Float2 s);
	~Number_5();

	void Update();
	void Render();
};