#pragma once
class Topography : public Transform
{
public:
	enum class TOPOGRAPHY_NAME
	{
		GROUND_1,GROUND_2, GROUND_3, GROUND_4, GROUND_5, GROUND_6, GROUND_7, GROUND_8, GROUND_9,
		CLOUD_BLOCK, STONE_BLOCK, 
		MUSHROOM_STALK,
		RED_MUSHROOM_LEFT, RED_MUSHROOM_CENTER, RED_MUSHROOM_RIGHT,
		YELLOW_MUSHROOM_LEFT, YELLOW_MUSHROOM_CENTER, YELLOW_MUSHROOM_RIGHT,
		GREEN_MUSHROOM_LEFT, GREEN_MUSHROOM_CENTER, GREEN_MUSHROOM_RIGHT,
		UP_BRIDGE, DOWN_BRIDGE
	} topography_name;

private:
	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;
	RectCollider* collider;

public:
	Topography(TOPOGRAPHY_NAME topography_name);
	~Topography();

	void Update();
	void Render();

	RectCollider* GetCollider() { return collider; }

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}

	void SetPlace(float x, float y)
	{
		pos = Vector2((32 * x) + 16, (32 * y));
	}
};