#include "framework.h"

ConstBuffer::ConstBuffer(void* data, UINT data_size)
	: data(data), data_size(data_size)
{
	// ���� ���ۿ� �Ȱ��� ���� �ڵ带 ������ �Ϻθ� ����
	// �̹��� �� 4�κ��� �� Ŭ������ �°� ��ü��
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = data_size;
	// (1)ByteWidth
	// �̹��� �� �뷮 �� ��ü�� �Է¹޾����� �״�� ���

	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	// (2)�� ���۰� � ���� �����صδ� ���������� �˸��� ���
	// �� ���۴� ��� �����̹Ƿ� "����� �ٷ�� ���۴�"��� ���̴��� �˸��� ���� ���� ���� ����

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;
	// (3)pSysMem
	// ���� ���ۿ� ���������� �Է¹��� void*�� �״�� �̿�

	DEVICE->CreateBuffer(&bd, &initData, &buffer);
	// (4)�Լ� ����������
	// ������ ���ƴ� ��ġ������ ������ ��� �� Ŭ�������� ����ϴ� ����� �̸����� �ٲ��ֱ�
	// �׸��� ������ ���Ǿ��� �ڵ�� �߿����� ��ũ�� ������ ���� �� �ִ� �κ��� �ٿ��α�
	// �̰� ���� ���� �ʿ��� ���ƴ� �Ͱ� �Ȱ����Ƿ� �� �ʿ��� �����Դٸ� ���� �� �ص� ����
}

ConstBuffer::~ConstBuffer()
{
	buffer->Release();
}

void ConstBuffer::SetVS(UINT slot)
{
	DVC->UpdateSubresource(buffer, 0, NULL, data, 0, 0);
	// ���ۿ� �����͸� �����ϴ� �Լ�

	DVC->VSSetConstantBuffers(slot, 1, &buffer);
	// ����� ���۸� VS(=���� ���̴�)�� �ѱ�µ�,
	// ��Ȯ���� ���̴��� slot�� ���Կ� �ش� �����͸� �ѱ�
}

void ConstBuffer::SetPS(UINT slot)
{
	DVC->UpdateSubresource(buffer, 0, NULL, data, 0, 0);
	// ���ۿ� �����͸� �����ϴ� �Լ�

	DVC->PSSetConstantBuffers(slot, 1, &buffer);
	// ����� ���۸� PS(=�ȼ� ���̴�)�� �ѱ�µ�,
	// ��Ȯ���� ���̴��� slot�� ���Կ� �ش� �����͸� �ѱ�
}
// �� slot�̶�� ������ ������ ����ߴ� �Ͱ��� ���� �ٸ� ���ο� ���̴��� ���� ����
