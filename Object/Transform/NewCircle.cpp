#include "framework.h"
#include "NewCircle.h"

NewCircle::NewCircle(Float2 p, Float2 s, float a,
    Float2 size, float dir, D3D11_PRIMITIVE_TOPOLOGY t)
    : Transform(p, s, a), dir(dir)
{
    circle = new SRTCircle(size, 30, t);
}

NewCircle::NewCircle(Float2 p, Float2 s, float a,
    float radius, float dir, D3D11_PRIMITIVE_TOPOLOGY t)
    : NewCircle(p, s, a, Float2(radius, radius), dir, t)
{
}

NewCircle::~NewCircle()
{
    delete circle;
}

void NewCircle::Update(Matrix* parent)
{
    rot.z += dir;
    // �� �״�� Z�� ������ ȸ������ �� Update �Լ��� ȣ��� ������ 0.001�� ������Ű��� �ǹ�
    // �׸��� �� Update �Լ��� Scene�� Update �Լ��� ȣ��� ��,
    // �ٽø��� Program.Update()�� ȣ��� ������ �� �ڵ尡 ����Ǵ� ��

    // �׿� ���� �� �Լ��� ������(����� ȣ��� ��������) �ֱ⿡ ����
    // �� Ʈ�������� ȸ������ ����ؼ� �����̴� ���̴�

    if (this->parent != parent)
        SetParent(parent);

    WorldUpdate();
    // WorldTransform�� parent�� �ٸ� ������Ʈ�� World�� �Է��� ������ �� �� ����
    // �̹����� F12�� �ش� �Լ��� ���Ƿ� �̵�
}

void NewCircle::Render()
{
    WB->SetVS(0);
    circle->Render();
}