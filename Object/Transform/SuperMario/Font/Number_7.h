#pragma once
#include <framework.cpp>
class Number_7 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_7(Vector2 pos, Vector2 size, Float2 s);
	~Number_7();

	void Update();
	void Render();
};