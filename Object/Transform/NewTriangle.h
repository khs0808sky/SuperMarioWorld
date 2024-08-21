#pragma once
class NewTriangle : public Transform
{
private:
	SRTTriangle* triangle;

public:
	NewTriangle(Vector2 p, Vector2 s, float a, Float2 size,
		D3D11_PRIMITIVE_TOPOLOGY type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	~NewTriangle();

	void Update(Matrix* parent = NULL);
	void Render();

	void SetColor(Float4 colour)
	{
		triangle->SetColor(colour);
	}
};