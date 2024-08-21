#include "framework.h"
#include "RectCollider.h"

bool RectCollider::isPointCollision(Vector2 point)
// �� �簢�� �浹���� �ȿ� �Է¹��� ���� �����ִ����� �˻��ϴ� �Լ�
{
    Vector2 half = Size() * 0.5f;

    float left = GlobalPos().x - half.x;
    float right = GlobalPos().x + half.x;
    float top = GlobalPos().y - half.y;
    float bottom = GlobalPos().y + half.y;
    // ���� ������ ���� �� �簢���� ������ ���

    // �׷��� ����� ���� �ȿ� �Էµ� ��ǥ�� ����ִ����� �Ǵ�
    if (point.x > left && point.x < right)
        if (point.y > top && point.y < bottom)
            return true;

    return false;
}

bool RectCollider::isCircleCollision(CircleCollider* collider)
{
    return isOBB(collider);
}

bool RectCollider::isRectCollision(RectCollider* collider, Vector2* overwrap)
{
    /* �������� �̾߱������� �浹���θ� �����ϴ� �˰����� ������ ����� ����
    �� �߿��� �츮�� �����ؿԴ� �˰����� AABB�� OBB 2�������µ�,
    �̷� �˰����� �̿����� �ʰ� �������� �Ѵٸ� �̷� ������ ���� �� �ִٴ� �͵� �˾Ƶΰ� ���� ����
    
    �� ó���� �� 2������ �ƴ� �ٸ� �˰����� �̿��� �浹���θ� ó���ϴ� ���� �õ��غ�*/

    /* �� ����� ���̵�� ��ü�� �ſ� �����ϸ�, ȸ���� ���� ��ǥ�� ���� �� �ִٸ�
    ȸ������ �����ϴ� �浹 ����̱�� ��
    
    �׷��� ������ ������ 8���� �����ϱ� ������ �ʿ������� �ӵ��� ������ �� �ۿ� ����,
    �������� �� �簢���� �ٸ� �簢���� �մ� ������ ��Ȳ������ �浹�ߴٰ� �ν����� ���ϱ� ������
    �����δ� ����� �� ���� �˰���

    �� �߿��� ��, ���� �˰��� ���� ����� ���� ��Ȳ������ ���� ���ø� �� ���� ���� �˰����̶� ��
    �ٸ� �˰����� �������� �ʰ� �عٴڿ������� ������ ������ ��쿣 ����� �����ϴ��� ����ϱⰡ ����
    �� ������ �̹� ������ ������ �ٸ� �˰����� ����� �̿��ϴ� ��

    Vector2 half = Size() * 0.5f;

    float left = GlobalPos().x - half.x;
    float right = GlobalPos().x + half.x;
    float top = GlobalPos().y - half.y;
    float bottom = GlobalPos().y + half.y;
    // �� �ڽ��� ��ǥ���� ���ϴ� ����

    half = collider->Size() * 0.5f;

    float desc_left = collider->GlobalPos().x - half.x;
    float desc_right = collider->GlobalPos().x + half.x;
    float desc_top = collider->GlobalPos().y - half.y;
    float desc_bottom = collider->GlobalPos().y + half.y;
    // ������ ��ǥ���� ���ϴ� ����

    // �̷��� �ϸ� ���� �簢������ ���������� ��ġ�� ������ �� ����
    // ���� ���ʰ� ��, ������ �����ʰ� �Ʒ� ���� ��
    // �׷��� �ؼ� ���� �� �ִ� �� 8���� ��������
    // ���� �� Ŭ������ ���浹 �Լ��� ȣ���Ͽ�
    // ������ �������� ������ �ȿ� ���ִ����� üũ�ϴ� ������ �浹���θ� �˻��� �� ����
    if (collider->isPointCollision(Vector2(left, top))
        || collider->isPointCollision(Vector2(left, bottom))
        || collider->isPointCollision(Vector2(right, top))
        || collider->isPointCollision(Vector2(right, bottom))
        || isPointCollision(Vector2(desc_left, desc_top))
        || isPointCollision(Vector2(desc_left, desc_bottom))
        || isPointCollision(Vector2(desc_right, desc_top))
        || isPointCollision(Vector2(desc_right, desc_bottom)))
        return true;
    else
        return false;
        
    */

    // �����δ� ��Ȳ�� ���� AABB�� OBB �˰��� ���� �̿��ϴ� ��
    // ������ �� �� �ϼ����� ���� ��Ȳ�̶� AABB�� ���⼭ ȣ���ϴ� ������ �̿��� ���̳�
    // ���߿��� AABB�� OBB �� ������ ������ ������ �Ű������� ���� Ȯ���ϴ� ������ ������ ��
    if (overwrap != NULL)
        return isAABB(collider, overwrap);
    else
        return isOBB(collider);
}

bool RectCollider::isLineCollision(Vector2 line_start, Vector2 line_end)
{
    return false;
}

void RectCollider::CreateLine()
{
    Vector2 half = size * 0.5f;

    verticies.emplace_back(-half.x, +half.y);
    verticies.emplace_back(+half.x, +half.y);
    verticies.emplace_back(+half.x, -half.y);
    verticies.emplace_back(-half.x, -half.y);
    verticies.emplace_back(-half.x, +half.y);

    VB = new VertexBuffer(verticies.data(), sizeof(VertexPos), verticies.size());
}

bool RectCollider::isAABB(RectCollider* rect, Vector2* overwrap)
// Axis-Aligned Bounding Box�� ���Ӹ�
// ���� ������ ������ -> �浹������ �̷�� ��� ������ ������ �⺻ ��� �����ϵ��� ������� ���
// ����ϴ� �˰���
// �⺻������ �ſ� �����ٴ� ���� ����
// �׷���, (������ �����δ�)ȸ������ ���� ��쿡�� ���������� �����Ѵٴ� ���� ���� ū ����
{
    float min_right = min(RightVX(), rect->RightVX());
    // 2���� �簢�� �浹������ ����,
    // �� �� ��� ���� ������ ���� X���� �������� �� ���ʿ� �ִ��� ���
    float max_left = max(LeftVX(), rect->LeftVX());
    // ���� ������ �� �� ��� �簢���� ���� ���� �� �����ʿ� �ִ��� ���

    // �� ������ Y�࿡�� �Ȱ��� ������ ���� ���� �Ʒ��� ���� ����
    float min_down = min(DownVX(), rect->DownVX());
    float max_up = max(UpVX(), rect->UpVX());

    // �̷��� ���� 4���� ���� ����, �簢���� �ϳ� ������ �� �ְ� ��
    // �� 4���� ���� ���� �簢���� ������ ���� X��ǥ/���� ���� X��ǥ/�Ʒ��� ���� Y��ǥ/���� ���� Y��ǥ�� ���
    Vector2 obstackle = Vector2(min_right - max_left, min_down - max_up);
    // �̷��� ������� �簢���� ���� ���̸� Ȯ���ؼ�,
    // �� �� �ϳ��� 0�̰ų� �� �̸��� ������ ��� �� �簢���� �������� �ʴ´ٴ� ����� ���� �� ����
    // �ݴ��, �� �� ������ �� �簢�� = �浹�ϴ� ������ �����Ѵٴ� ����� ���� �� ����

    if (obstackle.x > 0 && obstackle.y > 0)
    {
        // overwrap = �� �Լ� �ۿ��� �浹������ ��Ȯ�� ��� �ǳ� �� �����͸� �޾ƿ� �� ����� �ּ�
        // ���� �̰� �ԷµǾ� �ִٸ�, ������ ���� �浹������ ����ٰ� �Է��� �Լ� ������ ��ȯ��
        if (overwrap != NULL)
            *overwrap = obstackle;
        return true;
    }
    else
        return false;

    // �� ���������� �� �Լ��� ȸ������ �󸶰� �ǵ� ���ġ �ʰ�
    // �׻� ������ �������� �浹������ ��� ������ ȸ���� ����� �������� ����

    // ȸ���� �� ������� �� �ִ� ���� ū �簢���� �������� ��� ���� �����غ� ���� ������,
    // �� ��쿣 ������ ���� �ʾ������� ��Ҵ� �����Ǵ� ��찡 ���� ���ɼ��� ���� ������ ����
    // -> �ƿ� ȸ���� ����ϴ� �˰����� �ٸ� �˰������� �и����Ѽ� �ʿ��� �� �� ���� �̿���
    // (�װ� OBB �˰���)

}

bool RectCollider::isOBB(RectCollider* rect)
// Oriented Bounding Box�� ����
// ���⼺ ������ - ȸ�������� ���󰡴� �浹���� ó����

// ���ν� ������ �������ڸ� :
// �� ��ü�� � �࿡ "����"(Ȥ�� "�翵")������ ��
// ������ �� ��ü�� ���� ��ġ�� �ʴ´ٸ�
// �� ��ü�� ���������� ���θ� �и���Ű�� ������ �и����� �����Ѵٰ� Ȯ���� �� ����
// �׷� �и����� �����ϴ����� �˻��ؼ� �����Ѵٸ� �浹���� ���� ��,
// ���ٸ� �浹�� ���̶� �Ǵ��ϴ� �浹 �˻��
{
    ObbDesc this_obb = GetObbDesc();
    // �� �浹������ ������ �� ����� �����͸� ����
    // ��Ȯ���� ȸ���� �ݿ��� �浹���� ������

    ObbDesc rect_obb = rect->GetObbDesc();
    // ��� �浹 ������ ��������

    // �� �浹������ �󸶳� ȸ���ߵ�, �� �浹������ Ʈ������ ��ü�� ����Ű�� ���� �������� Ȯ���� �� �ֵ���
    // �ش� ������ �����ϴ� �ν��Ͻ��� ����� ������ ��

    Vector2 nea1 = this_obb.Axis[0];
    Vector2 nea2 = this_obb.Axis[1];
    Vector2 ea1 = nea1 * this_obb.half_size.x;
    Vector2 ea2 = nea2 * this_obb.half_size.y;
    // �� �簢���� ������ ���� ���� �� �ʿ��� ��������
    // ���� ObbDesc���� ������� ȸ���� �ݿ��� �浹������ �̿��� �ۼ�

    Vector2 neb1 = rect_obb.Axis[0];
    Vector2 neb2 = rect_obb.Axis[1];
    Vector2 eb1 = neb1 * rect_obb.half_size.x;
    Vector2 eb2 = neb2 * rect_obb.half_size.y;
    // ���� ���� ���� ���� �� �ʿ��� ������ ���������� ����

    Vector2 distance = this_obb.pos - rect_obb.pos;
    // �� �浹���� ������ �Ÿ��� ����

    // ������, �� �浹�������� ���� ������ �ִ� ������, ���� ���� 2���� ���� ��������
    // �� 4���� ���� �������� �и����� �����ϴ����� ������ ��

    // A : �� �ڽ�, B : ��� �浹����
    // �׽�Ʈ�� : nea1(A.right)
    float lengthA = ea1.GetLength();
    // this_obb, �� �� �ڽ��� �� �浹�������� �������� �ٶ���� ���� ��
    // �޸� ���ϸ� �� �ڽ��� �浹������ �߾ӿ��� ������ �� ������ �������� ������ ���� �� ����
    // ���� �׽�Ʈ�ϴ� �������� �� �ڽ��� �������̹Ƿ� �� ���̸� ������ �̿��� �� ����
    // �׸��� ���� ���� ������ ���̴� �� ���� �������δ� �ƿ� �¿�� ����� �����Ƿ� 0�� �Ǿ� ���� ����

    float lengthB = seperateAxis(nea1, eb1, eb2);
    // �� �Լ��� �̿��� ���� ���������� ����ϴ� A.right�࿡
    // ���� ���� ���� ���̿� ���� ���̸� �翵�� ������� �� �׸����� ������ ���� ���⿡ ���

    float length = abs(Vector2::Dot(distance, nea1));
    // ������ ����� ���ؼ��� distance(�� ������ �߾��� ������ �Ÿ�)��
    // nea1(A.right, ���� üũ�� ������ ����Ű�� ���� ����)�� �̿��� �����Ͽ� �� ���밪�� ����
    // �츮�� ����� ���ؼ��� ���̸� ���� ��

    if (length > lengthA + lengthB)
        // �׷��� ���� �� ��ü�� �翵�� ���ؼ��� ���̸� ���� ���ؼ��� �� ��ٸ�
        return false; // �� ��ü ���̿� ���� ����� ƴ�� �����Ѵ� : �� ��ü�� ���� �������ִٴ� �ǹ��̹Ƿ�
    // �и����� �����Ѵٴ� ����� ���� �� �ְ�, �ϳ��� �����Ѵٸ� �浹���� �ʴ´ٴ� ���̴�
    // �浹ġ �ʾҴٰ� ��ȯ

     // �и��� : nea2(A.Up())
    lengthA = ea2.GetLength();
    lengthB = seperateAxis(nea2, eb1, eb2);

    length = abs(Vector2::Dot(distance, nea2));

    if (length > lengthA + lengthB)
        return false;

    // �и��� : neb1(B.right())
    lengthA = eb1.GetLength();
    lengthB = seperateAxis(neb1, ea1, ea2);

    length = abs(Vector2::Dot(distance, neb1));

    if (length > lengthA + lengthB)
        return false;

    // �и��� : neb2(B.Up())
    lengthA = eb2.GetLength();
    lengthB = seperateAxis(neb2, ea1, ea2);

    length = abs(Vector2::Dot(distance, neb2));

    if (length > lengthA + lengthB)
        return false;

    return true;    // � ��Ȳ������ ��ģ�ٸ� �浹�Ѵ�.
}

bool RectCollider::isAABB(CircleCollider* circle)
{
    return circle->isRectCollision(this);
}

bool RectCollider::isOBB(CircleCollider* circle)
{
    return circle->isRectCollision(this);
}

float RectCollider::seperateAxis(Vector2 seperate, Vector2 e1, Vector2 e2)
// ���� �׽�Ʈ�ϰ� �ִ� ���� ������ �̿���,
// �ش� ���� ������� �ʴ� ����� ������������ 
// �� ���� ���ؼ����� �翵���� �� ��������� ���̸� �����ϴ� �Լ�
{
    float r1 = abs(Vector2::Dot(seperate, e1));
    float r2 = abs(Vector2::Dot(seperate, e2));
    // seperate���, ���� ���� ����� ������ ����Ű�� ���� ���͸� �������� �Ͽ�
    // e1�� e2�� ���� �ش� ���� �������� �󸶸�ŭ�� ��ǥ��(=����) ������ �ִ�����
    // ������ ���� ����� ��

    return r1 + r2;
    // e1, e2�� ���� ������� 2�� ���͸� �̿��� ���� �����̹Ƿ�
    // ���� ������ �翵�� �� ���̴� �� ���� �ȴ�
}

RectCollider::RectCollider(Vector2 size)
    : size(size)
{
    type = TYPE::RECT;

    CreateLine();
}

RectCollider::~RectCollider()
{
    delete VB;
}

RectCollider::ObbDesc RectCollider::GetObbDesc()
// ȸ���� ���¿����� �浹������ ������ �����ϱ� ���� �ʿ��� �����͸� ��Ƶ� ����ü
{
    // �̸� ǥ���ϱ� ���� �ʿ��� �����ʹ� �� 4��
    obb_desc.pos = GlobalPos(); // 1. �浹������ ��ġ
    obb_desc.half_size = Size() * 0.5f; // 2. �浹������ ũ��(�¿� �� ������ ����)

    obb_desc.Axis[0] = Right(); 
    // 3. �� �浹������ ���� ���� ������ �������� �������� ����Ű�� ��������
    obb_desc.Axis[1] = Up(); 
    // 4. �� �浹������ ���� ���� ������ �������� ������ ����Ű�� ��������
       
    return obb_desc;
}
