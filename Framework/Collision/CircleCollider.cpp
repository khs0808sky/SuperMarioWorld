#include "framework.h"

void CircleCollider::CreateLine()
{
    float angle = 2 * M_PI;
    for (int i = 0; i <= vertex_count; i++)
    {
        verticies.emplace_back(cos(angle) * radius, sin(angle) * radius);
        angle -= 2 * M_PI / vertex_count;
    }

    VB = new VertexBuffer(verticies.data(), sizeof(VertexPos), verticies.size());
}

bool CircleCollider::isAABB(RectCollider* collider)
// ȸ������ ���� �簢�� �浹������ �浹���θ� �˻��ϴ� �Լ�
{
    Vector2 half = collider->Size() * 0.5f;
    Vector2 closest; // ���� �簢�� ���̿��� ���� ����� �Ÿ�

    if (pos.x < collider->pos.x - half.x) // ���� �߽����� ������ ���� ������ �� ������ ���
        closest.x = collider->pos.x - half.x;
    else if (pos.x > collider->pos.x + half.x) // ���� �߽����� ������ ������ ������ �� �������� ���
        closest.x = collider->pos.x + half.x;
    else
        closest.x = pos.x;

    // ���� ������ Y��ǥ�� ���ؼ��� ����
    if (pos.y < collider->pos.y - half.y)
        closest.y = collider->pos.y - half.y;
    else if (pos.y > collider->pos.y + half.y)
        closest.y = collider->pos.y + half.y;
    else
        closest.y = pos.y;


    // �׷��� ���� �簢������ ���� ���� ����� ����
    // ���� �� �ȿ� �����ϴ����� �˻�
    if (isPointCollision(closest))
        return true;
    else
        return false;

    // ���� Ư���� ������ ���� �Ÿ��� �ִ� ������ ���� ��
    // �� ���麸�� ����� �Ÿ��� ������ �� �ȿ� �� ��

    // ���� �츮�� ������ ���� ���� "�簢��"���� "���� ���� ����� ��"�� ���ϴ� ��
    // = �� ���� �ƴ� �簢�� ���� ���� ������ �� ������ ������ �Ÿ��� �� �ִٴ� �̾߱�
    // ���� �� ���� �� �ȿ� ������ �ʴٸ� �翬�� �ٸ� ���� ���� �� �ȿ� ������ ���� ��
    // �ݴ�� ���ϸ�, �� ���� ����� ���� �� �ȿ� ���ִٸ� �� �簢���� ���� ��ġ�� �κ��� �ִ�
}

bool CircleCollider::isOBB(RectCollider* collider)
// �ϴ� ���ǻ� OBB��� �̸����� ������ ������
// �����δ� ���� ���⼭ ���Ǵ� �˰����� OBB��� �θ����� ����
{
    Matrix T = XMMatrixTranslation(pos.x - collider->pos.x, pos.y - collider->pos.y, 0.0f);
    // �� ���� �������� �Ͽ� ���ο� T ����� ������ ��
    // ��Ȯ���� �� �ڽ��� �߱��� �������� �Ͽ� �簢���� �߽����� ��� �ִ����� ����ϰ�,
    // �׷��� ���� ���Ÿ��� �������� ��� ���ο� ���带 ������ ��

    Matrix circle_world = S * R * T;
    // S�� R�� �� ���� ���� Transform���� ���� ������Ʈ�� �� ��� ���� �״�� �̿��ϰ�,
    // T ��ĸ� ���� ��ķ� ��ü�Ͽ� �߾���(=����)�� �簢���� �߽������� �̵�
    circle_world *= XMMatrixRotationZ(-collider->rot.z);
    // �׷��� ���� ���ο� ���� ��Ŀ� �簢���� ȸ�����ִ� ��ŭ�� �ݴ�������� ȸ����Ŵ
    
    // �� �۾��� ���� "�簢���� ȸ������ �ʾҴٰ� �������� ��"�� �簢���� ���� ��ġ�� �ӽ÷� ������ �� ����

    XMFLOAT4X4 temp_matrix;
    XMStoreFloat4x4(&temp_matrix, circle_world);
    // ������ ���� ����� ����ϱ� ���ϰ� Float4x4 ��Ŀ� ����,
    Vector2 circle_obb_center = Vector2(temp_matrix._41, temp_matrix._42);
    // �׷��� ����Ǿ� �̿��ϱ� ������ ��Ŀ��� position ������ ����

    // ������ ������ �ణ�� ������ ���ļ� ���⼭�� ����ϴ� AABB �˰���
    // �׳� �� ��ü�� pos ���� ��� �Ϳ��� ���� circle_obb_center�� ��ü
    Vector2 half = collider->Size() * 0.5f;
    Vector2 closest; // ���� �簢�� ���̿��� ���� ����� �Ÿ�


    // ���� �� �κ��� ���ǽ��� ���� �߽��� �ƴ� �簢���� �߽ɿ��� �ǵ��ϰ� �����Ƿ�
    // �簢���� �߽� ��ǥ�� ���ϴ� �κ��� �� �ʿ䰡 ����
    if (circle_obb_center.x < - half.x) // ���� �߽����� ������ ���� ������ �� ������ ���
        closest.x =  - half.x;
    else if (circle_obb_center.x >  + half.x) // ���� �߽����� ������ ������ ������ �� �������� ���
        closest.x =  + half.x;
    else
        closest.x = circle_obb_center.x;

    // ���� ������ Y��ǥ�� ���ؼ��� ����
    if (circle_obb_center.y <  - half.y)
        closest.y =  - half.y;
    else if (circle_obb_center.y >  + half.y)
        closest.y =  + half.y;
    else
        closest.y = circle_obb_center.y;


    // �� �κ��� AABB�ʹ� ��¦ �ٸ���,
    // ���� ����� ���� ���� �߽ɱ����� �Ÿ��� ��� �Ǵ����� ����� ��,
    // �װ� ���� ���������� ª���� ���� �浹�� ��
    // �ƴϸ� �浹���� ���� ��
    if ((circle_obb_center - closest).GetLength() < GetRadius())
        return true;
    else
        return false;

    // �簢���� ȸ���ߴ�?
    // �׷��� �簢���� �������� �ؼ� �簢���� ȸ������ �ʾҴ� ������ ����� ���� ��ġ�� ���� ��
    // ������ ���� �߽����� �ߴ� �ڵ忡�� �簢���� �߽����� �ϴ� �ڵ�μ� ��¦ ������ AABB �ڵ带 �̿�
}

CircleCollider::CircleCollider(float rad)
    : radius(rad)
{
    type = TYPE::CIRCLE;
    vertex_count = 50;
    CreateLine();
}

CircleCollider::~CircleCollider()
{
    delete VB;
}

/*
�� = �ϳ��� ������ ������ �Ÿ���ŭ ������ ������ ����
-> � ���� �� �ȿ� �����ִ����� �Ǵ��ϴ� ����
�� ���� ���� �߽� ������ �Ÿ��� ���� ���������� �������� �Ǵ�
���� ���� �浹�� ��쿣 ���� ���� �� ���� �����ϴ� ���� ��
�ϳ��� �ٸ� ���� �ȿ� ���ִ��� �Ǵ��ϴ� ���ε�,
�ٸ��� ���ϸ� ��� ���� ������ �ۿ� ���� ���ۿ� ���� ��Ȳ���� �ƴ����� �˻��ϴ� ������
�浹 ���θ� �Ǵ��ϴ� ��
*/
bool CircleCollider::isPointCollision(Vector2 point)
{
    Vector2 dir = pos - point;

    if (dir.GetLength() < radius)
        return true;
    else
        return false;
}

bool CircleCollider::isCircleCollision(CircleCollider* collider)
{
    Vector2 dir = pos - collider->pos;

    if (dir.GetLength() < radius + collider->GetRadius())
        return true;
    else
        return false;
}

bool CircleCollider::isRectCollision(RectCollider* collider, Vector2* overwrap)
{
    return isOBB(collider);
    // ���� �浹���� AABB �浹�� �� ������ �׸� ���� �ʱ� ������ OBB�� ���ٰ� ����صֵ� ��
    // �ٸ� �� �� �õ��غ��� �� ��
}

bool CircleCollider::isLineCollision(Vector2 line_start, Vector2 line_end)
{
    return false;
}
