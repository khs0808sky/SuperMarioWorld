#pragma once
class NewCircle : public Transform
{
private:
    SRTCircle* circle;
    float dir;
    // 원의 회전방향(인 동시에 회전속도)를 이 멤버 변수로 관리

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