#pragma once
class Platform : public Quad
{
private:
	RectCollider* collider;

public:
	Platform(Vector2 pos, Vector2 size, Vector2 scale, float angle, Matrix* parent = NULL);
	~Platform();

	RectCollider* GetCollider() { return collider; }

	void Update();
	void Render();

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}
};