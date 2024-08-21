#include "framework.h"

SRTTriangle::SRTTriangle(Float2 size, D3D11_PRIMITIVE_TOPOLOGY type)
	: Shape(0, 0), type(type)
	// Shape�� ���� ������ ��� ��Ƶ� �� �������
	// ������ ������ ��ġ ���� Transform�� ���� ������ ���̹Ƿ� Shape�� ������ �ִ� ��ǥ�� ����
	// �� �̻� �߿����� �ʴ�
{
	Float2 half_size = Float2(size.x / 2.0f, size.y / 2.0f);
	// �� ������ ũ��� �Է¹��� ���� �������� �ɰ� ��, 
	// �̸� ������ ��ġ�� �����ϱ� ���� �����μ� ���

	Float2& hf = half_size;
	// ���۷��� ����� �̿��ؼ� half_size�� hf��� ª�� ������ �ٿ���

	switch (type)
	{
	case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
		verticies.emplace_back(0, -hf.y, 1.0f, 0.0f, 0.0f);
		verticies.emplace_back(hf.x, hf.y, 0.0f, 1.0f, 0.0f);
		verticies.emplace_back(-hf.x, hf.y, 0.0f, 0.0f, 1.0f);
		// ���� ������ ��쿣 "������ ȭ���� ��� �����ִ���"�� ��ǥ�μ� �Է�����
		// ������ SRT ��ȯ�� �̿��ؼ� �׸��� ������,
		// �� ������ ����ִ����� Transform�� pos�� ������
		// �׷��Ƿ� �� ������Ʈ�� �׷����� ����ϴ� �� shape��
		// ������ �������� ������Ʈ�� ������ �������� ��� �ִ��� �� ���� ���͸� �����ϸ� ��
		// �װ� ���� �Է��� "�������� ��� �������� ��ŭ �������ִ���"�� ��Ÿ���� ����
		break;

	default:
		break;
	}

	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);

	VB = new VertexBuffer(verticies.data(), sizeof(Vertex), verticies.size());
	CB = new ColourBuffer();

	// ���� ��¿� �ʿ��� ���̴���� ���۵��� ����
}

SRTTriangle::~SRTTriangle()
{
	delete VS;
	delete PS;
	delete VB;
	delete CB;
}

void SRTTriangle::Render()
{
	CB->SetPS(0);
	// �ȼ� ���̴��� 0�� ���Կ� �� ���۸� ����� �����͸� ����

	VB->Set(type);
	VS->Set();
	PS->Set();
	DVC->Draw(verticies.size(), 0);
}
