#pragma once
class Player : public Transform
{
public:
	// �÷��̾��� �Ŀ��� ����
	enum class PLAYER_POW
	{
		MINI, NORMAL, FIRE
	} player_pow;

	// PostRender��¿�
	const char* PlayerPowToString(PLAYER_POW pow)
	{
		switch (pow)
		{
		case Player::PLAYER_POW::MINI:
			return "MINI";
		case Player::PLAYER_POW::NORMAL:
			return "NORMAL";
		case Player::PLAYER_POW::FIRE:
			return "FIRE";
		default:
			break;
		}
	}

	// �÷��̾��� ���� ����
	enum class PLAYER_STATUS
	{
		IDLE, UP, CROUCH, WALK, RUN, SKID, JUMP_UP, JUMP_DOWN, CROUCH_JUMP, RUN_JUMP, SPIN_JUMP, KICK,
		MINI_IDLE, MINI_UP, MINI_CROUCH, MINI_WALK, MINI_RUN, MINI_SKID, MINI_JUMP_UP, MINI_JUMP_DOWN, MINI_CROUCH_JUMP, MINI_RUN_JUMP, MINI_SPIN_JUMP, MINI_KICK,
		FIRE_IDLE, FIRE_UP, FIRE_CROUCH, FIRE_WALK, FIRE_RUN, FIRE_SKID, FIRE_JUMP_UP, FIRE_JUMP_DOWN, FIRE_CROUCH_JUMP, FIRE_RUN_JUMP, FIRE_SPIN_JUMP, FIRE_KICK, FIRE_ATTACK,
		DEAD
	} player_status;

	// PostRender��¿�
	const char* PlayerStatusToString(PLAYER_STATUS stat)
	{
		switch (stat)
		{
		case Player::PLAYER_STATUS::IDLE:
			return "IDLE";
		case Player::PLAYER_STATUS::UP:
			return "UP";
		case Player::PLAYER_STATUS::CROUCH:
			return "CROUCH";
		case Player::PLAYER_STATUS::WALK:
			return "WALK";
		case Player::PLAYER_STATUS::RUN:
			return "RUN";
		case Player::PLAYER_STATUS::SKID:
			return "SKID";
		case Player::PLAYER_STATUS::JUMP_UP:
			return "JUMP_UP";
		case Player::PLAYER_STATUS::JUMP_DOWN:
			return "JUMP_DOWN";
		case Player::PLAYER_STATUS::CROUCH_JUMP:
			return "CROUCH_JUMP";
		case Player::PLAYER_STATUS::RUN_JUMP:
			return "RUN_JUMP";
		case Player::PLAYER_STATUS::SPIN_JUMP:
			return "SPIN_JUMP";
		case Player::PLAYER_STATUS::KICK:
			return "KICK";
		case Player::PLAYER_STATUS::MINI_IDLE:
			return "MINI_IDLE";
		case Player::PLAYER_STATUS::MINI_UP:
			return "MINI_UP";
		case Player::PLAYER_STATUS::MINI_CROUCH:
			return "MINI_CROUCH";
		case Player::PLAYER_STATUS::MINI_WALK:
			return "MINI_WALK";
		case Player::PLAYER_STATUS::MINI_RUN:
			return "MINI_RUN";
		case Player::PLAYER_STATUS::MINI_SKID:
			return "MINI_SKID";
		case Player::PLAYER_STATUS::MINI_JUMP_UP:
			return "MINI_JUMP_UP";
		case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
			return "MINI_JUMP_DOWN";
		case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
			return "MINI_CROUCH_JUMP";
		case Player::PLAYER_STATUS::MINI_RUN_JUMP:
			return "MINI_RUN_JUMP";
		case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
			return "MINI_SPIN_JUMP";
		case Player::PLAYER_STATUS::MINI_KICK:
			return "MINI_KICK";
		case Player::PLAYER_STATUS::FIRE_IDLE:
			return "FIRE_IDLE";
		case Player::PLAYER_STATUS::FIRE_UP:
			return "FIRE_UP";
		case Player::PLAYER_STATUS::FIRE_CROUCH:
			return "FIRE_CROUCH";
		case Player::PLAYER_STATUS::FIRE_WALK:
			return "FIRE_WALK";
		case Player::PLAYER_STATUS::FIRE_RUN:
			return "FIRE_RUN";
		case Player::PLAYER_STATUS::FIRE_SKID:
			return "FIRE_SKID";
		case Player::PLAYER_STATUS::FIRE_JUMP_UP:
			return "FIRE_JUMP_UP";
		case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
			return "FIRE_JUMP_DOWN";
		case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
			return "FIRE_CROUCH_JUMP";
		case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
			return "FIRE_RUN_JUMP";
		case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
			return "FIRE_SPIN_JUMP";
		case Player::PLAYER_STATUS::FIRE_KICK:
			return "FIRE_KICK";
		case Player::PLAYER_STATUS::FIRE_ATTACK:
			return "FIRE_ATTACK";
		case Player::PLAYER_STATUS::DEAD:
			return "DEAD";
		default:
			break;
		}
	}

private:

	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;
	RectCollider* collider[4]; // �Ϲ�(����), �Ϲ�(�ޱ׸�), �̴�(����), �̴�(�ޱ׸�)

	RectCollider* target;

	PLAYER_POW collide_state; // �浹 �� ����

	int col_cursor;

	bool is_looking_right;
	bool is_ground; // ���� ���� �ִ��� üũ

	bool is_hit; // �÷��̾ �������� �Ծ������� ����
	bool is_change; // �÷��̾ ���ϴ� �������� ����
	bool is_dead; // �÷��̾ ���� ���������� ����
	bool is_invincible; // �÷��̾ �������������� ����

	float invincible_time; // �ǰ� �� ���� �ð�
	//float change_time; // �ǰ� �� �Ŀ��� ���� ��ȯ �ð�
	float dead_stop_time; // �״� ���� �� ��� ���ߴ� �ð�

	float acceleration; // ���ӵ�
	float deceleration; // ���ӵ�
	float speed; // ���� �ӵ�

	float max_walk_speed; // �ִ� �ȱ� ���ǵ�
	float max_run_speed; // �ִ� �޸��� ���ǵ�

	float gravity; // �߷�
	
	float jump_speed;
	float max_jump_speed; // �ִ� ���� ���ǵ�



public:
	Player();
	~Player();

	RectCollider* GetCollider() { 
		switch (player_status)
		{
		case Player::PLAYER_STATUS::IDLE:
		case Player::PLAYER_STATUS::FIRE_IDLE:
		case Player::PLAYER_STATUS::UP:
		case Player::PLAYER_STATUS::FIRE_UP:
		case Player::PLAYER_STATUS::WALK:
		case Player::PLAYER_STATUS::FIRE_WALK:
		case Player::PLAYER_STATUS::RUN:
		case Player::PLAYER_STATUS::FIRE_RUN:
		case Player::PLAYER_STATUS::SKID:
		case Player::PLAYER_STATUS::FIRE_SKID:
		case Player::PLAYER_STATUS::JUMP_UP:
		case Player::PLAYER_STATUS::FIRE_JUMP_UP:
		case Player::PLAYER_STATUS::JUMP_DOWN:
		case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
		case Player::PLAYER_STATUS::RUN_JUMP:
		case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
		case Player::PLAYER_STATUS::SPIN_JUMP:
		case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
		case Player::PLAYER_STATUS::KICK:
		case Player::PLAYER_STATUS::MINI_KICK:
		case Player::PLAYER_STATUS::FIRE_KICK:
		case Player::PLAYER_STATUS::FIRE_ATTACK:
			col_cursor = 0;
			break;
		case Player::PLAYER_STATUS::CROUCH:
		case Player::PLAYER_STATUS::FIRE_CROUCH:
		case Player::PLAYER_STATUS::CROUCH_JUMP:
		case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
			col_cursor = 1;
			break;
		case Player::PLAYER_STATUS::MINI_IDLE:
		case Player::PLAYER_STATUS::MINI_UP:
		case Player::PLAYER_STATUS::MINI_WALK:
		case Player::PLAYER_STATUS::MINI_RUN:
		case Player::PLAYER_STATUS::MINI_SKID:
		case Player::PLAYER_STATUS::MINI_JUMP_UP:
		case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
		case Player::PLAYER_STATUS::MINI_RUN_JUMP:
		case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
			col_cursor = 2;
			break;
		case Player::PLAYER_STATUS::MINI_CROUCH:
		case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
			col_cursor = 3;
			break;
		case Player::PLAYER_STATUS::DEAD:
			break;
		default:
			break;
		}
		return collider[col_cursor];
	}

	void Update();
	void StopTimeUpdate();
	void Render();
	void PostRender();

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}

	void SetClip(PLAYER_STATUS stat);
	void SetPow(PLAYER_POW stat);

	/// <summary>
	/// ��� ���⿡�� �浹�ߴ����� ���� �׿� �ɸ´� ���� �� �浹 ���� �ൿ�� ó���ϴ� �Լ�
	/// </summary>
	/// <param name="dir">�浹�� ����, 0~3���� ���� ĳ������ �Ʒ�/��/����/������</param>
	//void JumpCollide(UINT dir);



	void SetPlace(float x, float y)
	{
		pos = Vector2((32 * x) + 16, (32 * y) - 14);
	}

	void Jump_Move();

	void TopographyCollide(RectCollider* obj);
	void MonsterCollide(RectCollider* obj);

	//float GetChangeTime() { return change_time; }

	bool GetIsChange() { return is_change; }
	void SetIsChange(bool a) { this->is_change = a; }

	bool GetIsHit() { return is_hit; }
	void SetIsHit(bool a) { this->is_hit = a; }

	bool GetIsDead() { return is_dead; }
	void SetIsDead(bool a) { this->is_dead = a; }

	bool GetIsInvincible() { return is_invincible; }
	void SetIsInvincible(bool a) { this->is_invincible = a; }

	PLAYER_POW GetPlayerPow() { return player_pow; }
};