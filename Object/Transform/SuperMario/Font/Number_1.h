#pragma once
class Number_1 : public Quad
{
private:
	Vector2 size; // 이 오브젝트의 크기를 관리하는 데 사용할 값


public:
	Number_1(Vector2 pos, Vector2 size, Float2 s);
	~Number_1();

	void Update();
	void Render();
};