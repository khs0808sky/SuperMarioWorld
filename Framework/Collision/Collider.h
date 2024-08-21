#pragma once
class Collider : public Transform
// �׷��� ���α׷��ֿ��� ������Ʈ�� ������Ʈ�� �浹�ߴ��� �Ǵ��� ����
// �� ������Ʈ���� "�浹����"�� �����صΰ�
// �� �� ������Ʈ�� �浹������ Ư�� �˰����� ���� ���ؼ�
// �� �˰����� ����ߴ��� �ɷȴ��� �����ϴ� ������ �浹���θ� �˻���

// ������ �� �浹���� �� ����ϴ� �˰����̶�� ���� ����� ������ ſ��,
// ������ ���Ǵ� �˰��� �ϴ��� �پ���

// Ŭ���� ��ü�� �ϼ��� ���� �ð��� �� ���̸�,
// �̹��� �ϴ� ����� ���� �� ����
{
public:
    enum class TYPE
    {
        RECT,
        CIRCLE
    };
    // 2D ȯ�濡�� �ַ� ���Ǵ� �浹 ������ �簢�� ������ ���� ���� 2������ ����
    // �� 2���� ������ ����ϴ� �浹 ��������� �ٸ��� ������, ���� �ٸ� �ڽ� Ŭ�����μ� ���� ����

protected:
    TYPE type; // �θ� Ŭ������ ȣ���� �� �ڽ� Ŭ������ ���� ��Ȳ�̸� �̰� ���� Ŭ�������� �𸣴�
    // ���� �����ߴ� ������ Ŭ������ ����� � Ŭ�������� ����صδ� ��

    VertexShader* VS;
    PixelShader* PS;

    VertexBuffer* VB;

    ColourBuffer* CB;
    MatrixBuffer* WB;

    vector<VertexPos> verticies;
    // �ڱ� �ڽ��� ��輱�� ǥ���ϱ� ���� �뵵�μ� ��¿� �ʿ��� ������� ���� �̷��� �����ص� ��
    // �ٸ�, ��ǥ �ܿ� �ٸ� �����ʹ� ���� �ʿ���� ������ ��ǥ �����͸� ���� ������ �̿��ؾ� ��
    
    static bool debug_mode; // ����� ��� ���θ� �����ϴ� ���
    // �̰� True���� ��� �浹������ �ڱ� �ڽ��� �浹������ ǥ���ϵ��� ��

public:
    Collider();
    virtual ~Collider();

    void Render();
    TYPE GetType() { return type; }

    static void SetDebugMode() { debug_mode = !debug_mode; }

    virtual bool isCollision(Collider* collider, Vector2* overwrap = NULL);
    // �Է¹��� �浹������ � Ÿ���̳Ŀ� ���� �Ʒ��� �ִ� �ٸ� �Լ��� ȣ���ϴ� �߰� �Լ�

    // �� �Ʒ��� �Լ����� ���� "Ư���� ���� �浹�ߴ���"�� �˻��ϴ� �Լ�

    virtual bool isPointCollision(Vector2 point) = 0;
    virtual bool isCircleCollision(class CircleCollider* collider) = 0;
    virtual bool isRectCollision(class RectCollider* collider,
        Vector2* overwrap = NULL) = 0;
    virtual bool isLineCollision(Vector2 line_start, Vector2 line_end) = 0;

    static bool isLineCrossCollision(Vector2 l1_start, Vector2 l1_end,
        Vector2 l2_start, Vector2 l2_end);

    void SetColor(float r, float g, float b)
    {
        CB->data.colour = Float4(r, g, b, 1);
    }

protected:
    virtual void CreateLine() = 0;
};

/*
���� : �������� �̾߱��ߵ�, �浹 ���θ� �˻��ϴ� �˰����� �ѵΰ����� �ƴ�

�� �߿��� �츮�� AABB�� OBB��� �ϴ� 2���� �˰����� �ַ� ���� ���ε�,
�� ���� ���� � �˰������� �����ؿ���
*/
