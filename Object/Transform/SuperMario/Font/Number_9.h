#pragma once
#include <framework.cpp>
class Number_9 : public Quad
{
private:
	Vector2 size; // 이 오브젝트의 크기를 관리하는 데 사용할 값


public:
	Number_9(Vector2 pos, Vector2 size, Float2 s);
	~Number_9();

	void Update();
	void Render();
};