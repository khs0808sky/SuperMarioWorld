#pragma once
class Hexagon : public Shape
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	// D3D11_PRIMITIVE_TOPOLOGY�� �������̹Ƿ�
	// �Ź� ���ŷӰ� ġ�� �ʰ� �ƿ� �����μ� ����

public:
	Hexagon(float pos_x, float pos_y, float size,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; };

	virtual void Render() override {};
};