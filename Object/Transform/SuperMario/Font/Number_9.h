#pragma once
#include <framework.cpp>
class Number_9 : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Number_9(Vector2 pos, Vector2 size, Float2 s);
	~Number_9();

	void Update();
	void Render();
};