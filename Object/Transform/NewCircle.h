#pragma once
class NewCircle : public Transform
{
private:
    SRTCircle* circle;
    float dir;
    // ���� ȸ������(�� ���ÿ� ȸ���ӵ�)�� �� ��� ������ ����

public:
    NewCircle(Float2 p, Float2 s, float a, Float2 size, float dir,
        D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    NewCircle(Float2 p, Float2 s, float a, float radius, float dir,
        D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    ~NewCircle();

    void Update(Matrix* parent = NULL);
    void Render();

    void SetColor(Float4 colour)
    {
        circle->SetColor(colour);
    }

};