#pragma once
class Hexagon : public Shape
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	// D3D11_PRIMITIVE_TOPOLOGY는 열거형이므로
	// 매번 번거롭게 치지 않게 아예 변수로서 저장

public:
	Hexagon(float pos_x, float pos_y, float size,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; };

	virtual void Render() override {};
};