#include "framework.h"

RectUV::RectUV(Vector2 size, Vector2 StartUV, Vector2 EndUV,
	D3D11_PRIMITIVE_TOPOLOGY type)
	: Shape(0, 0), type(type)
{
	Float2 half_size = Float2(size.x / 2.0f, size.y / 2.0f);
	// �� ������ ũ��� �Է¹��� ���� �������� �ɰ� ��, 
	// �̸� ������ ��ġ�� �����ϱ� ���� �����μ� ���

	Float2& hf = half_size;
	// ���۷��� ����� �̿��ؼ� half_size�� hf��� ª�� ������ �ٿ���

	verticies_uv.emplace_back(-hf.x, -hf.y, StartUV.x, StartUV.y);
	verticies_uv.emplace_back(+hf.x, -hf.y, StartUV.x, EndUV.y);
	verticies_uv.emplace_back(-hf.x, +hf.y, EndUV.x, StartUV.y);
	verticies_uv.emplace_back(-hf.x, +hf.y, EndUV.x, StartUV.y);
	verticies_uv.emplace_back(+hf.x, -hf.y, StartUV.x, EndUV.y);
	verticies_uv.emplace_back(+hf.x, +hf.y, EndUV.x, EndUV.y);

	VS = new VertexShader(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = new PixelShader(L"Shader/PixelShader/PixelUV.hlsl");

	VB = new VertexBuffer(verticies_uv.data(), sizeof(VertexUV), verticies_uv.size());
	CB = new ColourBuffer();

}

RectUV::~RectUV()
{
	delete VS;
	delete PS;
	delete VB;
	delete CB;
}

void RectUV::Render()
{
	CB->SetPS(0);

	VB->Set(type);
	VS->Set();
	PS->Set();
	DVC->Draw(verticies_uv.size(), 0);
}
