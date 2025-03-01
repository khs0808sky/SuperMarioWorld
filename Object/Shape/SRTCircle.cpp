#include "framework.h"

SRTCircle::SRTCircle(Float2 size, int vertex_count, D3D11_PRIMITIVE_TOPOLOGY type)
    : Shape(size.x, size.y), type(type), size(size)
{
    float angle = 2 * M_PI;

    switch (type)
    {
    case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
        for (int i = 0; i < vertex_count; i++)
        {
            verticies.emplace_back(0, 0, 1.0f, 1.0f, 1.0f);
            // 삼각형의 첫번째 점으로 사용할, 육각형의 중점을 입력
            verticies.emplace_back(
                -cos(angle) * this->size.x,
                sin(angle) * this->size.y,
                angle / (2 * M_PI), (2 * M_PI - angle) / (2 * M_PI), 1.0f
            );
            // 삼각함수를 통해 확보한 육각형의 점 중 하나를 추가

            angle -= 2 * M_PI / float(vertex_count);
            // 각도 보정

            verticies.emplace_back(
                -cos(angle) * this->size.x,
                sin(angle) * this->size.y,
                angle / (2 * M_PI), (2 * M_PI - angle) / (2 * M_PI), 1.0f
            );
            // 삼각함수를 통해 확보한 육각형의 다음 점을 추가
        }
        break;
        // 이를 총 6개의 삼각형이 육각형을 그리게 하도록 하고 종료

    case D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP:
        for (int i = 0; i <= vertex_count; i++)
        {
            verticies.emplace_back(
                -cos(angle) * this->size.x,
                sin(angle) * this->size.y,
                angle / (2 * M_PI), (2 * M_PI - angle) / (2 * M_PI), 1.0f
            );
            angle -= 2 * M_PI / float(vertex_count);
        }
        // 이 쪽은 시작점만 추가로 적어줘야 한다는 점 빼면 꼭지점들만 순차적으로 추가하면 됨
        break;
    }

    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
    PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);

    VB = new VertexBuffer(verticies.data(), sizeof(Vertex), verticies.size());
    CB = new ColourBuffer();
}

SRTCircle::SRTCircle(float radius, int vertex_count, D3D11_PRIMITIVE_TOPOLOGY type)
    : SRTCircle(Float2(radius, radius), vertex_count, type)
    // 위임 생성자는 자기 자신의 다른 생성자로도 이용할 수 있다
{
}

SRTCircle::~SRTCircle()
{
    delete VS;
    delete PS;
    delete VB;
    delete CB;
}

void SRTCircle::Render()
{
    CB->SetPS(0);
    // 컬러버퍼에 저장된 색상값이 흰색이 아니라면
    // 이 컬러버퍼를 셰이더에 입력할 것

    VB->Set(type);
    VS->Set();
    PS->Set();
    DVC->Draw(verticies.size(), 0);
}