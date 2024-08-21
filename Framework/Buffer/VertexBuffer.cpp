#include "framework.h"

VertexBuffer::VertexBuffer(void* data, UINT s, UINT count)
	: stride(s), offset(0)
{
	// ������ �� ������ �����ڿ��� ���۸������ �����ߴ� �κ��� ��������,
	// �� 3�κ��� �� Ŭ������ �°� ��ü��
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = stride * count;
	// (1)ByteWidth
	// �� ���۰� ������ �ִ� �������� �� ũ�⸦ ����ϴ� ����
	// �������� ����� ���� �� ������ ������ �� �� �̿��ߴ��� Ȯ���ؼ� ������ ũ�� * ������ ������ ���ϸ� ������
	// ���⼭�� � ������ ������ �� Ŭ���� ������ ���� ���ϰ� stride�μ� �Է¹޾ƾ� ��
	// ���� ���� �ϳ��� �뷮 + ���⿡ �Էµ� ���� �������� �� �������� ������ �Է¹޾Ƽ� �� �뷮�� ����ϴ� ��

	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	// �� ���۰� � ���� �����صδ� ���������� �˸��� ���
	// ������ ������ ����ϴ� �����̹Ƿ� ��ĥ �ʿ� ����

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;
	// (2)pSysMem
	// ���� �������� �ٷ� ���� ������ ��ϵ� ����� ������ ���ο��� ������� ������ �̸� �̿��ϸ� �ƾ���
	// ������ ���⼱ ������ �����͸� �Ű������� void*�� �ޱ� ������, �̿��� �ʿ����� ���� �״�� �� �ּҸ� �Է�

	DEVICE->CreateBuffer(&bd, &initData, &buffer);
	// (3)�Լ� ����������
	// ������ ���ƴ� ��ġ������ ������ ��� �� Ŭ�������� ����ϴ� ����� �̸����� �ٲ��ֱ�
	// �׸��� ������ ���Ǿ��� �ڵ�� �߿����� ��ũ�� ������ ���� �� �ִ� �κ��� �ٿ��α�
}

VertexBuffer::~VertexBuffer()
{
	buffer->Release();
}

void VertexBuffer::Set(D3D11_PRIMITIVE_TOPOLOGY type)
{
	DVC->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
	DVC->IASetPrimitiveTopology(type);
}
