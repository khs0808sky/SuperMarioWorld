#pragma once
class Restart_Message : public Quad
{
private:
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��


public:
	Restart_Message(Vector2 pos, Vector2 size, Float2 s);
	~Restart_Message();

	void Update();
	void Render();
};