#pragma once
// Vertex(����) Buffer - ���̴��� ������ �����͸� �ѱ� �� ����Ϸ��� �뵵�� ������� Ŭ����
class VertexBuffer
{
private:
	ID3D11Buffer* buffer;
	// DX11���� ����ϴ� �԰��� ����

	UINT stride;
	// �� �ν��Ͻ����� �����ϰ� �ִ� ���۰� �� ĭ���� ����ϴ� �뷮��
	// �� UINT(unsigned int)�� �����صδ� ����

	UINT offset;
	// ����� �������� ����ϴ� ���

public:
	VertexBuffer(void* data, UINT s, UINT count);
	~VertexBuffer();

	void Set(D3D11_PRIMITIVE_TOPOLOGY type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// ������ ����ϴ� ����� ���� ���ۿ��� �����ϵ��� ���ִ� �Լ�
};