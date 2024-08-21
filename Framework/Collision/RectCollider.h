#pragma once
class RectCollider : public Collider
{
public:
	struct ObbDesc // OBB �浹 �� �����,
		// ���� �� �浹������ ȸ�� ��Ȳ�� �ݿ��ؼ� ������ ����� �� �̿��� �����͸� ������ ����ü
	{
		Vector2 pos; // ��ǥ(=�߾���)
		Vector2 Axis[2]; // ȸ���� �浹������ ���� ���� ����صδ� �迭
		Vector2 half_size; // �� ȸ���� �浹������ ����/�¿� ũ��
	};

private:
	Vector2 size;
	ObbDesc obb_desc;
	UINT col_type;

	
	virtual void CreateLine() override;

	bool isAABB(RectCollider* rect, Vector2* overwrap = NULL);
	// AABB �˰������� �簢�� �浹������ �浹 ���θ� �˻��ϴ� �Լ�
	bool isOBB(RectCollider* rect);
	// OBB �˰������� �簢�� �浹������ �浹 ���θ� �˻��ϴ� �Լ�
	bool isAABB(CircleCollider* circle);
	// AABB �˰������� ���� �浹������ �浹 ���θ� �˻��ϴ� �Լ�
	bool isOBB(CircleCollider* circle);
	// OBB �˰������� ���� �浹������ �浹 ���θ� �˻��ϴ� �Լ�

	float seperateAxis(Vector2 seperate, Vector2 e1, Vector2 e2);
	// OBB �浹ó���� ������� ���� ����� �Լ�
	// �� �Լ��� OBB �˰����� ���� �� �����ϸ鼭 ����



public:
	RectCollider(Vector2 size);
	~RectCollider();

	ObbDesc GetObbDesc();  // ȣ��� �������� �� �浹������ ȸ���� �ݿ���,
	// ���� �浹���� �����͸� ��ȯ�ϴ� �ڵ�

	// Collider��(��) ���� ��ӵ�
	virtual bool isPointCollision(Vector2 point) override;

	virtual bool isCircleCollision(CircleCollider* collider) override;

	virtual bool isRectCollision(RectCollider* collider, Vector2* overwrap = NULL) override;

	virtual bool isLineCollision(Vector2 line_start, Vector2 line_end) override;

	Vector2 Size() { return size * GlobalScale(); }
	// �� �浹������ ȭ�� �������� ������ �󸶸�ŭ�� ����� ������ �ִ���
	// ��ü ȭ�� ������ ���̷� ȯ���� ��ȯ

	void SetColType(UINT dir) { col_type = dir; }
	UINT GetColType() { return col_type; }

	float RightVX() { return GlobalPos().x + size.x * 0.5f; }
	float LeftVX() { return GlobalPos().x - size.x * 0.5f; }
	float UpVX() { return GlobalPos().y - size.y * 0.5f; }
	float DownVX() { return GlobalPos().y + size.y * 0.5f; }
	// �̻��� 4�� �Լ����� AABB �浹 ó�� �������� ���Ǵ� �Լ���
	// ��Ȯ���� �� �浹������ ��/��/��/�� ������ ���ڶ��� ��ǥ�� ����ϴ� �Լ�
};
