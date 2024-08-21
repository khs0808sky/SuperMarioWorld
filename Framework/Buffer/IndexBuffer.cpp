#include "Framework.h"
#include "IndexBuffer.h"
/*
�ε��� ���� : ������ ������ ����ϴ� ����
���ݱ��� �츮�� ������ �׸� �� ������ ������ �׳� ��� ����� �� ���� �Էµ� ������� 0������ �̿��ؿ���
�� ����� �� ��� ���� �ϳ��� ������ ��ü�� ������ Ŀ���� �� ������ ������ ���̴� ���̵��� ����� ����

�̸� �ذ��ϱ� ����, ���� ��ü�� ����� ���� �ϳ����� �� ������ �Է��ϰ�
������ ����� �� �� ���� �� �� ���� �θ� ������ �� ������ ����� �ٸ� ���۸� �̿��ؼ�
�ϳ��� ������ ������ �̿��� ���� �ְ�, �츮�� ������ �Է��ϴ� ������
�ݵ�� ó������ �ð������ ���Ѽ� ���� �ʿ䰡 ������ �Ͽ� ������ �ٷ�� ���̵��� ���ߴ� �� �̿��ϴ� ����
*/
IndexBuffer::IndexBuffer(void* data, UINT count)
{
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(UINT) * count;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	// VertexBuffer�� ũ�� �ٸ� ���� ������,
	// � ���ۿ� ���� ���������� �翬�� �ٸ��� ǥ��Ǿ� �־�� ��

	// �߰���, ���̴����� �ٷ�� ������ �ε����� UINT�� �� �ۿ� �����Ƿ�(-1��° ���� ���� �� ����)
	// �� ������ ũ��� �Է¹��� �����Ϳ� ����ִ� �ڷ��� �� * sizeof(UINT)�� �� �ۿ� ����

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;

	DEVICE->CreateBuffer(&bd, &initData, &buffer);

}

IndexBuffer::~IndexBuffer()
{
	buffer->Release();
}

void IndexBuffer::Set()
{
	DVC->IASetIndexBuffer(buffer, DXGI_FORMAT_R32_UINT, 0);
}
