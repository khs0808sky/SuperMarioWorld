#pragma once
class Monster : public Transform
{
public:
	enum class MONSTER_NAME
	{
		//NONE,
		BAMBA,  // ���
		DDANG_GAMBA,  // ������
		BLACK_PIRANHA // ������

	} monster_name;

	enum class MONSTER_TYPE
	{
		//NONE,
		MOVE, // �̵��� ����
		STOP, // ������ ����
		CONDITION_MOVE // ���Ǻ� �̵��� ����
	} monster_type;

	enum class MONSTER_MOVE
	{
		//NONE,
		STRAIGHT, // ������ ������ �״�� ����
		NO_STRAIGHT // ������ ������ ������ ��ȯ
	} monster_move;

	enum class MONSTER_STATUS
	{
		//NONE,
		WALK,
		IDLE
	} monster_status;

private:
	Dead* dead;

	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;
	RectCollider* collider;


	bool is_looking_right;
	bool is_ground;

	bool is_stepped; // ������ ��

	float upside_down_time;

	float speed;

	float gravity;

	float jump_speed;
	float max_jump_speed;

public:

	Monster(MONSTER_NAME monster_name);
	~Monster();

	RectCollider* GetCollider() { return collider; }

	void Update();
	void Render();
	void PostRender();

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}

	void SetPlace(float x, float y)
	{
		pos = Vector2((32 * x) + 16, (32 * y));
	}


	void TopographyCollide(RectCollider* obj);
	//void MonsterCollide(RectCollider* obj);

	void PlayerCollide(RectCollider* obj);

};