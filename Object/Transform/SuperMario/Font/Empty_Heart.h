#pragma once
class Empty_Heart : public Quad
{
private:
	Vector2 size; // 이 오브젝트의 크기를 관리하는 데 사용할 값


public:
	Empty_Heart(Vector2 pos, Vector2 size, Float2 s);
	~Empty_Heart();

	void Update();
	void Render();

};