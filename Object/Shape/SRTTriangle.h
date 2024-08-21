#pragma once
class SRTTriangle : public Shape
	// Transform�� �̿��ؼ� SRT ��ȯ ����� �����Ų ������ ����ϴ� Ŭ����
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	Float2 size;

public:
	SRTTriangle(Float2 size,
		D3D11_PRIMITIVE_TOPOLOGY type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	~SRTTriangle();


	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; };

	virtual void Render() override;
};