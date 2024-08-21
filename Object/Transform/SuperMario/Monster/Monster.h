#pragma once
class Monster : public Transform
{
public:
	enum class MONSTER_NAME
	{
		//NONE,
		BAMBA,  // 밤바
		DDANG_GAMBA,  // 땡감바
		BLACK_PIRANHA // 블랙뻐끔

	} monster_name;

	enum class MONSTER_TYPE
	{
		//NONE,
		MOVE, // 이동형 몬스터
		STOP, // 고정형 몬스터
		CONDITION_MOVE // 조건부 이동형 몬스터
	} monster_type;

	enum class MONSTER_MOVE
	{
		//NONE,
		STRAIGHT, // 절벽을 만나면 그대로 직진
		NO_STRAIGHT // 절벽을 만나면 방향을 전환
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

	bool is_stepped; // 밟혔을 때

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