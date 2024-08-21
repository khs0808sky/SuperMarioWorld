#pragma once
class Play_Message : public Quad
{
private:
	Vector2 size; // 이 오브젝트의 크기를 관리하는 데 사용할 값


public:
	Play_Message(Vector2 pos, Vector2 size, Float2 s);
	~Play_Message();

	void Update();
	void Render();
};