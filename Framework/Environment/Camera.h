#pragma once
class Camera : public Transform
{
private:
	MatrixBuffer* view; // �� ��ȯ�� �̿��ϱ� ���� ������ ����
	// ������ Program���� ����ϰ� �־��� ������� Environment�� ����� �Űܼ� ó���� ����

	float speed; // ī�޶��� �ӵ�

	Transform* target;

	Vector2 offset;
	// ���⼭ ī�޶� ȭ�� ������ �ڸ����� ��ġ�� �����ϴ� �Ͱ� ���ÿ�,
	// �̷����� �뵵�� ����� ���� ����� ���
	// �� ���� �̿��ؼ� ��ü ȭ�� �� ��� �κ��� �������μ� ȭ���� ǥ���� �������� ����

	Vector2 left_top;
	Vector2 right_bottom;

public:
	Camera();
	~Camera();

	void Update();
	void PostRender();

	void SetPos(Vector2 pos)
	{
		this->pos = offset = pos;
	}

	void SetTarget(Transform* tgt)
	{
		this->target = tgt;
	}

private:
	void FreeMode();
	void FollowMode();

	void SetView();
};