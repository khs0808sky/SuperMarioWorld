#pragma once
class Ground : public Transform
{
public:
	// □□□ 1 2 3
	// □□□ 4 5 6
	// □□□ 7 8 9
	enum class GROUND_TYPE
	{
		TILE_1, // ┌  (위 왼)
		TILE_2, //  ─ (위)
		TILE_3, //  ┐ (위 오른)
		TILE_4, //│   (왼)
		TILE_5, // ■  (내부)
		TILE_6, //  │ (오른)
		TILE_7, // └  (아래 왼)
		TILE_8, // ─  (아래)
		TILE_9 //  ┘ (아래 오른)
	} ground_type;

private:
	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;
	RectCollider* collider;

public:
	Ground(GROUND_TYPE type);
	~Ground();

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