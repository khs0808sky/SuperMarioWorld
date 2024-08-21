#include "framework.h"

TutorialScene::TutorialScene()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	// ���̴� ������ �ʿ��� �÷��׸� �̸� ����

	VS = new VertexShader(L"Shader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/VertexShader.hlsl", flags);
	// ���� ���̴��� �ȼ� ���̴��� ���̴� �ּҰ� �ִ� ���Ͽ� ����

	// �� ���� ���̴� ���� ������ �� �� �ٷ�



	// DX�� �Լ��� �̿��ؼ� �˾Ƽ� ������ �׸� �� ����,
	// �⺻�����δ� ���� �ﰢ������ �׸� �� �ְ� �Ǿ�����
	// ������ �׸��� �ʹٸ� �ﰢ���� ���� �����ؼ� �׸� �� �ۿ� ����

	// �� �ﰢ���� "������(Polygon)"�̶� �θ�
	// 3D �׷����� �⺻������ �� �������� �̿��ؼ� �׷����� �����ϰ� ���

	// �������� �׸��� ���ؼ� �� ������=�ﰢ���� �����ϴ� 3���� ������ �Է��ؾ� ��
	// �� ù��°��, �ﰢ�� �ϳ��� �׸��� �� ����� ���� ����
	vector<Vertex> vx_triangle_list =
	{
		Vertex(-0.1f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.8f, 0.17f, 0.8f, 0.8f),
		// Vertex : �츮�� �׷���, ��Ȯ���� �������� �� ������ �����ϱ� ���� ���� ����ü
		// ���ʿ������� x,y��ǥ / ���� R,G,B�� �Է��� ��
		// ��ǥ���� ȭ�� �߾��� �������� ����, �Ʒ��� ���� -1 / ������, ���� ���� 1�� ���� �����ǥ
		// �� ������ API ���ʹ� �޸� ������ 0~255�� �ƴ� 0~1������ �Ǽ���

		// API���� �ٸ��� DX������ ���� ���� �ƴ� ���� �Ʒ��� �������� +, -�� �����
		// ���߿� �̸� �츮�� �˴� ������� �ٷ����� �����̳�, ������ �̷� ���̶�� ����ص� ��

		// 3D�׷��ȿ��� �������� 
		// "ȭ���(����)���� ���� �� �ո��� ���̴� ��쿡�� ����ϵ��� �Ǿ�����"
		// �� �ո鸸 ��µǴ����� ���ؼ��� 3D���� �ٷ�� �Ǵ� �����̹Ƿ� �����ϰ�,
		// ���⼭�� �� "�ո�"�� ���ؿ� ���ؼ��� ����

		// �������� �ո��� ���� : �������� �̷�� �ִ� �������� ���������� ��¿� �̿�Ǵµ�,
		// �� �������� �ð������ �������� �����Ǿ� �ִ����� ���η� �Ǵ���
		// �ð�����̸� �ո�, �ð� �ݴ�����̸� �޸����� �����
		// ������ ���� �� ���� �Ű� �� ���� �޸� ������� �νĵǾ� ȭ�鿡 ������ �ʴ� ��찡 ������ ����
	};

	// ������ ���� ���� ����Ʈ�� �̿��� �ﰢ���� ����ϴ� ���� Ŭ������ �ʱ�ȭ�� ����
	list_triangle = new Triangle(vx_triangle_list,
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// D3D11_PRIMITIVE_TOPOLOGY : ���߿� DX ����̽��� �� ������ ����ش޶�� ��û�� ��
	// �� ������ � ���������� �ý��ۿ� �˸��� ������ ����
	// �� ���� �˸��°�? -> � �����̶�� �˸��Ŀ� ���� ������ ����ϴ� ������ ����
	// TRIANGLELIST : 3���� ������ ����ϴ� �ﰢ������, ����� ������ ���ο� 3���� ������ ����
	// �̴� �ٷ� ���� rect_list���� �ٷ�



	// ȭ����� ���� �Ʒ��� �簢���� ����ϴ� ������
	vector<Vertex> vx_rect_list =
	{
		Vertex(-0.8f, -0.1f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.1f, -0.1f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.8f, -0.8f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.8f, -0.8f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.1f, -0.1f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.1f, -0.8f, 0.8f, 0.1f, 0.6f),
	};

	list_rect = new Triangle(vx_rect_list,
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// TRIANGLELIST�� �� �ﰢ���� �׸� ������ ���ο� 3���� ������ ����
	// �̸� �̿��ؼ�, ���� ���� ����� �ﰢ������ ������ �Ʒ��� ����� �ﰢ���� 2�� �׷�
	// ��������� �簢���� �ǵ��� �׸� ��

	// �� ����� DX���� �ﰢ�� ���� ������ �׸��� ���
	// API�ʹ� �޸� �簢���̳� �� ���� �׸��� ����� ���� ���� 
	// -> �ﰢ���� ���� �׷��� ��ġ�� ������ ���� ǥ���� �����ϴϱ�


	

	// �������� ��쿣 ���ʹ� �޸� �������� �����ϴ� �κ��� ���µ�,
	// �̴� ������ �� Scene�� �ƴ϶� �ش� ������ �ٷ�� Ŭ������ Hexagon���� ���� �����ϱ� ����
	// � �������� �ñ��ϴٸ� �� �� �ش� ������ �����غ� ��
	list_hexagon[0] = new Hexagon(860, 540,
		0.4f, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// �����ڿ����� ��ġ�� X, Y��ǥ, ������ ũ��, ������ ��� ����� �Է¹ް� ����
	// �̷� ������ ������ ũ�� ���� ������ ���� �Ϲ������� �����ڿ��� ���� �Ű������� �޾�
	// Ŭ������ ������ ���ο��� ó���ϵ��� �ϰ� ����

	list_hexagon[1] = new Hexagon(760, 360,
		0.3f, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	line_hexagon = new Hexagon(960, 180,
		0.4f, D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	
}

TutorialScene::~TutorialScene()
{
	delete(list_triangle);
	delete list_rect;
	for (int i = 0; i < 10; i++)
	{
		if(list_hexagon[i] != NULL)
			delete list_hexagon[i];
	}
	delete line_hexagon;
	
	VS->Release();
	PS->Release();
}

void TutorialScene::Update()
{


}

void TutorialScene::Render()
{
	// Device::Get()->Clear();
	// Device�� ȭ���� �ʱ�ȭ�ش޶�� ��û�ϴ� �ڵ�
	// ȭ���� �ʱ�ȭ�� Ÿ�̹��� "Scene�� ȣ���� ��"�� �ϴ���, "���Ϸ� ��ü�� ����� ������ ��"�� �ϴ����� ����
	// �������ϸ� ���ڷ� ���� ���� ����, �̰� ������ ���� ��� ����� �����״� ��

	UINT stride = sizeof(Vertex);
	// ������ ũ�Ⱑ �������� ����ϴ� ����
	// DirectX���� ����� ����ϰ� �ִ� Ŭ�����鿡���� � ������ �����ִ����� �ڵ����� �������� ����
	// ���� �츮�� � ������ ����ϰ� �ִٰ� ���� �����͸� �ѱ� �� ���� ��� �ϴµ�,
	// �� �� �� ������ �����Ʈ�� �����ϰ� �ִ��� ���� �Ѱܼ� ������ �����͸� ��Ȯ�� �������µ� ����ϵ��� ��

	UINT offset = 0;
	// � �������� ����� ������ �����ϴ� ����
	// ��� �츮�� ����� ���� �����Ƿ� 0���� �����Ѵٰ� �����ص� ����

	// ��Ȯ���� � �����ͼ�(=������)�� ����� �������� �����ϴ� ��..�ε�,
	// �츮�� �� �����ͼ��� �� �̻� ���� ���� �����Ƿ� 0���� �������� ������ ����� ��µ��� ����


	Device::Get()->GetDeviceContext()->VSSetShader(VS->GetVertexShader(), nullptr, 0);
	Device::Get()->GetDeviceContext()->PSSetShader(PS->GetPixelShader(), nullptr, 0);
	// ���� DirectX�� DeviceContext�� ���� ���̴��� �ȼ� ���̴��� ����ϴ� �Լ���
	// DirectX�� �׷����� ����� �� �Էµ� �������� �����͸� ���� �ܰ��� ���̴��� �̿��ؼ� ��ȯ��Ű�� ������
	// ����Ϳ� ��� ������ �����ͷ� ��ȯ�� ��Ű�µ�,
	// �� �������� � ���̴��� ����� ������ �����ϴ� �Լ�
	// ���⼱ Scene Ŭ���� ��ü�� ������ �ִ� ����� �Է��ϴ� ��


	Device::Get()->GetDeviceContext()->IASetInputLayout(VS->GetInputLayout());
	// ���� ���̴��� �̿��� �� �츮�� ����ϴ� ������ � ������ �̷����ִ�����
	// InputLayout�̶�� Ŭ������ �̿��� �����ϰ� �ִµ�,
	// �̸� DeviceContext�� ����Ͽ� ������ �Էµ� �������� ��� ����Ʈ���� ��� ����Ʈ������
	// � ������ �ϴ� �������� ���̾ƿ��� �ν��� �� �ֵ��� �ϴ� ����


	// ������ �ڵ���� (�ݺ����� �����ϰ�) �⺻������ �Ʒ� 3���� �Լ��� �̿��ؼ�
	// �ϳ��� ������ �׸��� �� �̿�ȴٰ� ���� ���� 
	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, list_triangle->GetBuffer(), &stride, &offset);
	// ������ ������ ����ϰ� �ִ� �����͸� ���̴��� �ѱ�
	// ���� 0�� 1�� �츮�� �ǵ帱 ���� ���� ���̹Ƿ� �����ص� ����
	// �� �ڿ��� ���� ������ ��ϵǾ� �ִ� ����(ID3D11Buffer*), �� ���ۿ� ���ִ� ������ �뷮,
	// �� ������ ����� �������� �Է�

	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_triangle->GetType());
	// DeviceContext���ٰ� ���� �츮�� ����ϰ��� �ϴ� ���� � ������ ��µ� �������� �˷���
	// �ش� �������� ����ϵ��� �������ִ� �Լ�
	// D3D11_PRIMITIVE_TOPOLOGY �������� ����ٰ� �Է�

	Device::Get()->GetDeviceContext()->Draw(list_triangle->GetVertexSize(), 0);
	// DirectX ��ġ�� "���� ��ġ�� ��ϵ� ���ۿ���
	// list_triangle->GetVertexSize()��ŭ�� ������ 0��° �ε����������� ������ ���ʴ�� ����϶�"�� ���
	// �� ������ �ﰢ���� �׸��� �����̰� ������ �ʿ��� ������ �� 3���� �Է��߾����Ƿ�
	// �ش� ���ۿ� ���ִ� ������ ������ �� 3����
	// "list_triangle�� ������ ��ϵ� ���ۿ��� ó�� �������� ������ �� 3���� �������� �׸��� �׷���"��� ��



	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, list_rect->GetBuffer(), &stride, &offset);
	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_rect->GetType());

	Device::Get()->GetDeviceContext()->Draw(list_rect->GetVertexSize(), 0);

	

	for (int i = 0; i < 10; i++)
	{
		if (list_hexagon[i] == NULL)
			break;
		Device::Get()->GetDeviceContext()->IASetVertexBuffers
		(0, 1, list_hexagon[i]->GetBuffer(), &stride, &offset);
		Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_hexagon[i]->GetType());

		Device::Get()->GetDeviceContext()->Draw(list_hexagon[i]->GetVertexSize(), 0);
	}

	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, line_hexagon->GetBuffer(), &stride, &offset);
	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(line_hexagon->GetType());

	Device::Get()->GetDeviceContext()->Draw(line_hexagon->GetVertexSize(), 0);

}


/*
���� : ���� �� ������Ʈ�� ������ ����ϱ� ���� ���� Ŭ�������� ������ ��Ȳ

�� Ŭ�������� ������ ���鼭 � ������ ������ �����ϰ� �ִ��� üũ�غ���,
������ �̹� ������� �ִ� �������� ���鼭(=������ ������� ���鼭) � ������ ������Ʈ�� ������� �ľ��� �ڿ�

������ �̷��� ��(������)�� �� �� ���� ��

���� ������ ��� �ϵ� ������� -> ������ �ǰ� �׳� �߰��� �׷��� �ǰ�

*/