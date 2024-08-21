#include "framework.h"

NewTriangle::NewTriangle(Vector2 p, Vector2 s, float a, Float2 size, D3D11_PRIMITIVE_TOPOLOGY type)
	: Transform(p,s,a)
{
	triangle = new SRTTriangle(size, type);
}

NewTriangle::~NewTriangle()
{
	delete triangle;
}

void NewTriangle::Update(Matrix* parent)
{
	this->rot.z += M_PI / 2.0f * DELTA;
	// �� Update �Լ��� ȣ��� ������ �� Transform�� rot.z�� �� = Z�� ���������� ȸ������ ����

	this->pos.x += (float(WIN_WIDTH) / 2.0f) * DELTA;
	if (this->pos.x > WIN_WIDTH)
		this->pos.x = 0;

	if (KEY_CON->Press(VK_UP)) // ���� ���� ȭ��ǥ Ű�� �������ִٸ�
	{
		this->pos.y -= 200.0f * DELTA;
	}
	if (KEY_CON->Press(VK_DOWN)) // ���� �Ʒ��� ȭ��ǥ Ű�� �������ִٸ�
	{
		this->pos.y += 200.0f * DELTA;
	}


	// ������Ʈ�� �� �� parent�� �Է¹��� ������ ������ ���

	if (this->parent != parent) 
		this->parent = parent; // �� parent�� ���� �� ������Ʈ�� parent�� ��ġ���� ������ ����
	WorldUpdate(); // ���带 ������Ʈ�Ͽ� �� ������Ʈ�� ���� ���θ� ���� ��Ŀ� �ݿ�
	
}

void NewTriangle::Render()
{
	// WB->Set(World); �� Ʈ�������� ���̴��� �ѱ� �����͸� ������ۿ� �����ϴ� �ڵ�
	// �̴� �̹� WorldUpdate�� ���� ������ ��������� �� �ʿ䰡 ����
	WB->SetVS(0);
	// ���, ���̴��� �����͸� �ѱ�� Ÿ�̹��� �� ������Ʈ�� ��µǱ� ������ Ÿ�̹��̹Ƿ�
	// ���� ���̴��� 0�� ���Կ� ���� ������ �����͸� �ѱ�

	triangle->Render();
	// ������� ������ �������� triangle�� ���
}
