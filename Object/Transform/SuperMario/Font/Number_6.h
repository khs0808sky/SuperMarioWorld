#pragma once
#include <framework.cpp>
class Number_6 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_6(Vector2 pos, Vector2 size, Float2 s);
	~Number_6();

	void Update();
	void Render();
};