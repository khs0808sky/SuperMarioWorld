#pragma once
#include <framework.cpp>
class Number_8 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_8(Vector2 pos, Vector2 size, Float2 s);
	~Number_8();

	void Update();
	void Render();
};