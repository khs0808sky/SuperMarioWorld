#pragma once
class CloudBlock : public Transform
{
private:
	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;

	RectCollider* collider;

public:
	CloudBlock();
	~CloudBlock();

	RectCollider* GetCollider() { return collider; }

	void Update();
	void Render();

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}

	void SetPlace(float x, float y)
	{
		pos = Vector2((32 * x) + 16, (32 * y));
	}
};