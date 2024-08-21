#pragma once
class CircleCollider : public Collider
{
private:
    float radius;
    // �簢�� ���ʹ� �޸� ���⼭�� ���� �������� ���
    // 1) �翬�� ���̴ϱ� ���� ũ�⸦ ǥ���ϴµ� �ʿ��� �����ʹ� ������ �ϳ����� ���� ù°
    // 2) �� ���� �浹������ Ÿ���� ����� ���� ����Ѵٸ� �Ǽ� 2���� ������ ����� �ϳ�,
    // Ÿ������ ����� ��쿣 ����� ���̵��� �ʹ� �������� ſ�� ���� ������ ������
    // ���� �ٷ�� �����߱� ������ �������� �̿��ϴ� ��
    UINT vertex_count;
    // ���� �׸� �� ����� ������ ������ �����صδ� ���

    virtual void CreateLine() override;

    bool isAABB(RectCollider* collider);
    bool isOBB(RectCollider* collider);
    // �簢�� �浹������ ȸ���� ����ؾ� ������,
    // ���� �浹������ ���ʿ� ���̶� ȸ���ص� �� �Ȱ����� ����� �ʿ䰡 ����
    // �׷��� AABB, OBB�� ������ �� �簢������ �浹���θ� ���� ���� �����ϸ� ��
public:
    CircleCollider(float rad);
    ~CircleCollider();

    float GetRadius() // �� �浹������ �������� ���ϴ� �Լ�
    {
        return radius * min(GlobalScale().x, GlobalScale().y);
    }

    // Collider��(��) ���� ��ӵ�
    virtual bool isPointCollision(Vector2 point) override;
    virtual bool isCircleCollision(CircleCollider* collider) override;
    virtual bool isRectCollision(RectCollider* collider, Vector2* overwrap = NULL) override;

    // Collider��(��) ���� ��ӵ�
    virtual bool isLineCollision(Vector2 line_start, Vector2 line_end) override;
};