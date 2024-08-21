#include "framework.h"

Hexagon::Hexagon(float pos_x, float pos_y, float size, D3D11_PRIMITIVE_TOPOLOGY t)
	:	Shape(pos_x, pos_y), type(t)
{
	// Hexagon���� �Ű� ������ ������ ����� vector�� ���� ���� :
	// �� ������ �ȿ��� �� ������ ��ü�� ���� ���� ���̱� ����

	float angle = 2 * M_PI;
	// ���� ������ 360���� ���ϴ� ��(pi�� 2��)
	// M_PI : math.h���� _USE_MATH_DEFINE�� ���ǵǾ��ִ� ��� ���Խ�ų �� ����� �� �ְ� �Ǵ�
	// �ﰢ�Լ��� ����� �� �ϳ�, ������ pi�� ��

	float screen_ratio = float(WIN_HEIGHT) / float(WIN_WIDTH);
	// â�� ���ο� ���δ� ���� ���밪�� ���Ͽ� ������ ���� �ٸ��� ������
	// �̸� �������� ���� �̸� ������� �ʿ䰡 ����

	Float2 this_pos = Float2(ratio_pos_x(pos_x), ratio_pos_y(pos_y));
	// ��� �Էµ� �� ��ü�� float�̱� ������ �̰� ������ �߰��� �۾��� �ʿ䰡 ����� ��
	// ������ �̷��� ������ �̸� �����δ� �� �� ratio_pos_x ���� ��� �̿��ϴ� �ͺ��� ����

	switch (type)
	{
	case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
		for(int i = 0; i < 6; i++)
		{
			verticies.emplace_back(this_pos.x, this_pos.y, 1.0f, 0.4f, 0.4f);
			// �ﰢ���� ù��° ������ �����, �������� ������ �Է�
			verticies.emplace_back(
				this_pos.x - cos(angle) * size * screen_ratio,
				this_pos.y - sin(angle) * size,
				0.4f, 0.4f, 1.0f
			);
			// �ﰢ�Լ��� ���� Ȯ���� �������� �� �� �ϳ��� �߰�

			angle -= 2 * M_PI / 6.0f;
			// ���� ����

			verticies.emplace_back(
				this_pos.x - cos(angle) * size * screen_ratio,
				this_pos.y - sin(angle) * size,
				0.4f, 0.4f, 1.0f
			);
			// �ﰢ�Լ��� ���� Ȯ���� �������� ���� ���� �߰�
		}
		break;
		// �̸� �� 6���� �ﰢ���� �������� �׸��� �ϵ��� �ϰ� ����

	case D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP:
		for (int i = 0; i <= 6; i++)
		{
			verticies.emplace_back(
				this_pos.x - cos(angle) * size * screen_ratio,
				this_pos.y - sin(angle) * size,
				0.4f, 0.4f, 1.0f
			);
			angle -= 2 * M_PI / 6.0f;
		}
		// �� ���� �������� �߰��� ������� �Ѵٴ� �� ���� �������鸸 ���������� �߰��ϸ� ��
		break;
	}

	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(Vertex) * verticies.size(); // ������ ������ �������� �� ����
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = verticies.data();

	Device::Get()->GetDevice()->CreateBuffer(&bd, &initData, &VB);
}
