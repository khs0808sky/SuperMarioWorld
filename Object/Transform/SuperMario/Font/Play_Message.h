#pragma once
class Play_Message : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Play_Message(Vector2 pos, Vector2 size, Float2 s);
	~Play_Message();

	void Update();
	void Render();
};