#include "framework.h"

bool Collider::debug_mode = true;

Collider::Collider()
{
	is_active = false;

	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexPos.hlsl", 2);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelPos.hlsl");

	CB = new ColourBuffer();
	CB->data.colour = { 0, 1, 0, 1 };

	WB = new MatrixBuffer();
}

Collider::~Collider()
{
	delete CB;
	delete WB;
}

void Collider::Render()
// �� Ŭ������ ���� �����Լ��� �ִ� �߻� Ŭ�����̹Ƿ�,
// �� Ŭ���� ��ü�� �ν��ͽ��� ������ �� ����
// -> ������ ���ǵǾ� ���������� ��ϵ� �ڽ� Ŭ���������� �� �Լ��� ȣ��� ���� �ִٴ� ���̹Ƿ�
// �� Ŭ���� ���ο��� ��ϵ��� �ʾ��� ����� �̿��ص� ������ ����
{
	if (!is_active || !debug_mode) return;
	// �� �浹 ������ Ȱ��ȭ�Ǿ����� �ʴٸ� �� �浹������ ȭ�鿡 ������� ����

	WB->Set(world);
	WB->SetVS(0);
	CB->SetPS(0);

	VB->Set(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	// ���������� ���� �׷��� ����ϵ��� ��
	VS->Set();
	PS->Set();
	DVC->Draw(verticies.size(), 0);
}

bool Collider::isCollision(Collider* collider, Vector2* overwrap)
{
	if (!is_active || !(collider->is_active)) return false;
	// �� �浹������ Ȱ��ȭ�� ���°� �ƴϸ� ���ʿ� �浹�� ���� ����

	switch (collider->type)
	// collider�� �ּ� 2���� �̻��� �ڽ� Ŭ������ ���� �߻� Ŭ����
	// ���� �ڽ� Ŭ���� ������ ���� ����ؾ� �� �浹 ��Ŀ������ �ٸ��� ������,
	// �б⹮�� ���ؼ� �̸� �и�
	{
	case TYPE::RECT:
		return isRectCollision((RectCollider*)collider, overwrap);

	case TYPE::CIRCLE:
		return isCircleCollision((CircleCollider*)collider);

	default:
		return false;
	}
}

bool Collider::isLineCrossCollision(Vector2 l1_start, Vector2 l1_end, Vector2 l2_start, Vector2 l2_end)
// �̸� �״�� "�� ���� ������ �浹�ϴ���"�� �˻��ϴ� �Լ�
// �̰� �浹���� = �浹�ϴ� ������ ���ƴ����� �ƴ϶� �ܼ��� �� ���� �浹���θ��� �˻��ϴ� ���̹Ƿ�
// ���� �� Ŭ������ �ٷ�� �簢�� Ȥ�� ������ �浹���� �� ��ü�� �ٷ�� �ν��Ͻ��� �䱸���� ����
// ���� �ν��Ͻ� ���̵� �񱳰� ������ static �Լ��μ� ������ ��

// �׷��� ������ ������ ������Ʈ�� ������ �ִ� �浹���� ���� �̿��ϴ� ���� �����ϰ��� �ϱ⿡,
// �� ���� ���� �صΰ� ���� ������ ���� �� �ð���
{
	return false;
}
