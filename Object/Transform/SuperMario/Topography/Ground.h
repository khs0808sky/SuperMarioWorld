#pragma once
class Ground : public Transform
{
public:
	// ���� 1 2 3
	// ���� 4 5 6
	// ���� 7 8 9
	enum class GROUND_TYPE
	{
		TILE_1, // ��  (�� ��)
		TILE_2, //  �� (��)
		TILE_3, //  �� (�� ����)
		TILE_4, //��   (��)
		TILE_5, // ��  (����)
		TILE_6, //  �� (����)
		TILE_7, // ��  (�Ʒ� ��)
		TILE_8, // ��  (�Ʒ�)
		TILE_9 //  �� (�Ʒ� ����)
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