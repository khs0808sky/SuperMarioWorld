#pragma once
class Triangle : public Shape
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	// D3D11_PRIMITIVE_TOPOLOGY�� �������̹Ƿ�
	// �Ź� ���ŷӰ� ġ�� �ʰ� �ƿ� �����μ� ����

public:
	Triangle(vector<Vertex> v,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; };

	virtual void Render() override {};
};