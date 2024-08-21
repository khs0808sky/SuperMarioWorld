#include "framework.h"

Triangle::Triangle(vector<Vertex> v, D3D11_PRIMITIVE_TOPOLOGY t)
	: Shape(0.0f, 0.0f), type(t)
{
	verticies.resize(v.size());
	// ���� �� �� ���ʹ� �� �������� �Ҵ� �� �� �����̹Ƿ�
	// ����� ������ �� �ֵ��� �Է¹��� ���Ϳ� ������ �����ŭ �Ҵ�

	copy(v.begin(), v.end(), verticies.begin());
	// STL���� �����ϴ�, �ڷᱸ������ �����ϴ� �Լ�
	// ������ �������� ���������� �������� �Է��� ��, �� �༱���� �Է��� �����ϴ� ��

	// �׷��� �ٸ� ������ ���ǵ� �������� �� ������ ������ �ֵ��� ����

	// ������ InitDevice() ��, ������ ������ �� �̸� �����ϴ� �κ��� �ڵ带 ���⿡ ����

		// ������ ������ �������� ������ ������
	// ���� ���̴����� �Է¹��� �� �ִ� ������ ������ ���� ���۸� ������ �κ�
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(Vertex) * verticies.size(); // ������ ������ �������� �� ����
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = verticies.data();

	Device::Get()->GetDevice()->CreateBuffer(&bd, &initData, &VB);
	// �� 7���� �ڵ带 ����, ���� ���̴��� �츮�� �����ߴ� ���� �����͵��� ����
}

// �Ҹ��ڴ� ������ ���� : ���� �Ҵ��� �� ����