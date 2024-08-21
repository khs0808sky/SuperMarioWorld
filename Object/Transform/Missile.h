#pragma once
class Missile : public Quad
{
private:
	float speed;
	Vector2 size; // �� ������Ʈ�� ũ�⸦ �����ϴ� �� ����� ��

	RectCollider* collider;
	Transform* target;
	
	float sleep_time;

public:
	Missile(Vector2 pos, Vector2 size, Float2 s, float a, Transform* target = NULL);
	~Missile();

	void Update();
	void Render();
	void PostRender();
	RectCollider* GetCollider() { return collider; }

	bool isHit(RectCollider* obj);
};
