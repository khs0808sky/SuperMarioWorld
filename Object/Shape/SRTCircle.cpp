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
            // �ﰢ���� ù��° ������ �����, �������� ������ �Է�
            verticies.emplace_back(
                -cos(angle) * this->size.x,
                sin(angle) * this->size.y,
                angle / (2 * M_PI), (2 * M_PI - angle) / (2 * M_PI), 1.0f
            );
            // �ﰢ�Լ��� ���� Ȯ���� �������� �� �� �ϳ��� �߰�

            angle -= 2 * M_PI / float(vertex_count);
            // ���� ����

            verticies.emplace_back(
                -cos(angle) * this->size.x,
                sin(angle) * this->size.y,
                angle / (2 * M_PI), (2 * M_PI - angle) / (2 * M_PI), 1.0f
            );
            // �ﰢ�Լ��� ���� Ȯ���� �������� ���� ���� �߰�
        }
        break;
        // �̸� �� 6���� �ﰢ���� �������� �׸��� �ϵ��� �ϰ� ����

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
        // �� ���� �������� �߰��� ������� �Ѵٴ� �� ���� �������鸸 ���������� �߰��ϸ� ��
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
    // ���� �����ڴ� �ڱ� �ڽ��� �ٸ� �����ڷε� �̿��� �� �ִ�
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
    // �÷����ۿ� ����� ������ ����� �ƴ϶��
    // �� �÷����۸� ���̴��� �Է��� ��

    VB->Set(type);
    VS->Set();
    PS->Set();
    DVC->Draw(verticies.size(), 0);
}