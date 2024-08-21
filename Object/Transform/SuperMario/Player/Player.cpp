#include "framework.h"

Player::Player()
{
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Character.png";
	Texture* t = Texture::Add(file);

	// ���� ����� ��������Ʈ�� ũ��
	Vector2 this_frame_size = { 32.0f, 32.0f };
	Vector2 init_pos;


	vector<Frame*> frames; // �� �ִϸ��̼ǵ��� clips�� �����ϱ� ���� �ӽ÷� ���� �ڷᱸ��

	//�����������PLAYER_STATUS::IDLE�����������
	{
		init_pos = { 1, 233 };  // �Ϲ�
			//init_pos = { 1, 22 }; // �̴�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::UP�����������
	{
		init_pos = { 38, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::CROUCH�����������
	{
		init_pos = { 75, 233 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::WALK�����������
	{
		init_pos = { 145, 233 };
		// 2��° ������
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));
		// ���Ŀ� 1��° ������ -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 211.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 14.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::RUN�����������
	{
		init_pos = { 248, 233 };
		// 2��° ������
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		// ���Ŀ� 1��° ������ -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 314.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::SKID�����������
	{
		init_pos = { 351, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::JUMP_UP�����������
	{
		init_pos = { 388, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::JUMP_DOWN�����������
	{
		init_pos = { 421, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::CROUCH_JUMP�����������
	{
		init_pos = { 108, 233 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::RUN_JUMP�����������
	{
		init_pos = { 458, 233 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::SPIN_JUMP�����������
	{
		init_pos = { 528, 233 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 561.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 594.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 627.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::KICK�����������
	{
		init_pos = { 388, 343 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_IDLE�����������
	{
		init_pos = { 1, 22 }; // �̴�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_UP�����������
	{
		init_pos = { 38, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_CROUCH�����������
	{
		init_pos = { 75, 22 }; // �̴�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_WALK�����������
	{
		init_pos = { 145, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 14.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_RUN�����������
	{
		init_pos = { 215, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 248.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_SKID�����������
	{
		init_pos = { 285, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_JUMP_UP�����������
	{
		init_pos = { 322, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_JUMP_DOWN�����������
	{
		init_pos = { 355, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_CROUCH_JUMP�����������
	{
		init_pos = { 108, 22 }; // �̴�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_RUN_JUMP�����������
	{
		init_pos = { 392, 22 }; // �̴�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_SPIN_JUMP�����������
	{
		init_pos = { 462, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 495.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 528.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 561.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::MINI_KICK�����������
	{
		init_pos = { 355, 132 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_IDLE�����������
	{
		init_pos = { 1, 514 };  // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_UP�����������
	{
		init_pos = { 38, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_CROUCH�����������
	{
		init_pos = { 75, 514 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_WALK�����������
	{
		init_pos = { 145, 514 };
		// 2��° ������
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		// ���Ŀ� 1��° ������ -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 211.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 14.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_RUN�����������
	{
		init_pos = { 248, 514 };
		// 2��° ������
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		// ���Ŀ� 1��° ������ -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 314.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_SKID�����������
	{
		init_pos = { 351, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_JUMP_UP�����������
	{
		init_pos = { 388, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_JUMP_DOWN�����������
	{
		init_pos = { 421, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_CROUCH_JUMP�����������
	{
		init_pos = { 108, 514 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_RUN_JUMP�����������
	{
		init_pos = { 458, 514 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_SPIN_JUMP�����������
	{
		init_pos = { 528, 514 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 561.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 594.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 627.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_KICK�����������
	{
		init_pos = { 388, 624 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::FIRE_ATTACK�����������
	{
		init_pos = { 346, 569 }; // �Ϲ�
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//�����������PLAYER_STATUS::DEAD�����������
	{
		init_pos = { 243, 77 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 276.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 3.0f));
		frames.clear();
	}

	//������������������������������������
	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();

	collider[0] = new RectCollider(Vector2(28, 48)); // �Ϲ� ����
	collider[1] = new RectCollider(Vector2(28, 24)); // �Ϲ� �ޱ׸�
	collider[2] = new RectCollider(Vector2(28, 32)); // �̴� ����
	collider[3] = new RectCollider(Vector2(28, 20)); // �̴� �ޱ׸�

	for (auto col : collider)
	{
		col->pos = pos;
		col->is_active = false;
	}

	player_pow = PLAYER_POW::FIRE;
	player_status = PLAYER_STATUS::JUMP_DOWN;

	is_looking_right = true; // �⺻���´� �������̱� ������ true�Է�
	is_ground = false;

	is_hit = false;
	is_change = false;
	is_dead = false;
	is_invincible = false;

	invincible_time = 2.0f;
	dead_stop_time = 1.0f;

	max_walk_speed = 175.0f; // �ִ� �ȱ� ���ǵ�
	max_run_speed = 350.0f;

	speed = 0.0f; // �ʱ� ���ǵ�
	acceleration = 500.0f; // ���ӵ� ���� -> ���ӵ� = ���� �ѷ� / ����
	deceleration = 250.0f;

	
	gravity = 100.0f;

	max_jump_speed = 600.0f;
	jump_speed = max_jump_speed;
}

Player::~Player()
{
	for (Clip* c : clips)
		delete c;

	for (auto col : collider)
		delete col;

	delete CB;
}

void Player::Update()
{

	// �÷��̾�� �ż��� �߷��� ������ ����
	jump_speed += (gravity * 13.0f) * DELTA;

	if (jump_speed > max_jump_speed)
	{
		jump_speed = max_jump_speed;
	}

	// Ƣ�� ������ ���� ����ȭ
	if (is_ground && jump_speed > 0.0f)
	{
		jump_speed -= (gravity * 13.0f) * DELTA - 1.0f;
		//jump_speed -= 1.0f;
	}

	// Press : ������ �ִ� ���ȿ���
	// Down : �� �� ������ ��
	// Up : �� �� ������ ��
	switch (player_status)
	{
		//����������밡���� �ִ� ���¡����������
	case Player::PLAYER_STATUS::IDLE:
	case Player::PLAYER_STATUS::MINI_IDLE:
	case Player::PLAYER_STATUS::FIRE_IDLE:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_IDLE);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::IDLE);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_IDLE);
			break;
		default:
			break;
		}

		if (jump_speed > 20.0f) // �������̸� (��������ؼ� 20���� �˳��ϰ�)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_DOWN);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
				break;
			default:
				break;
			}
		}

		if (KEY_CON->Press(VK_LEFT))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_WALK);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::WALK);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_WALK);
				break;
			default:
				break;
			}
		}
		else if (KEY_CON->Press(VK_RIGHT))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_WALK);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::WALK);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_WALK);
				break;
			default:
				break;
			}
		}
		else if (KEY_CON->Press(VK_UP))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_UP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::UP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_UP);
				break;
			default:
				break;
			}
		}
		else if (KEY_CON->Press(VK_DOWN))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_CROUCH);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::CROUCH);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_CROUCH);
				break;
			default:
				break;
			}
		}
		//##########���� Ű##########
		if (KEY_CON->Down('X'))
		{
			jump_speed = -max_jump_speed;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_UP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_UP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
				break;
			default:
				break;
			}
		}

		//##########�������� Ű##########
		if (KEY_CON->Down('Z'))
		{
			jump_speed = -525.0f;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::SPIN_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
				break;
			default:
				break;
			}
		}
		break;
	}
		//��������������� �����ִ� ���¡����������
	case Player::PLAYER_STATUS::UP:
	case Player::PLAYER_STATUS::MINI_UP:
	case Player::PLAYER_STATUS::FIRE_UP:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_UP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::UP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_UP);
			break;
		default:
			break;
		}

		if (jump_speed > 20.0f) // �������̸� (��������ؼ� 20���� �˳��ϰ�)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_DOWN);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
				break;
			default:
				break;
			}
		}

		if (KEY_CON->Press(VK_LEFT))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_WALK);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::WALK);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_WALK);
				break;
			default:
				break;
			}
		}
		else if (KEY_CON->Press(VK_RIGHT))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_WALK);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::WALK);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_WALK);
				break;
			default:
				break;
			}
		}
		//##########���� Ű##########
		if (KEY_CON->Down('X'))
		{
			jump_speed = -max_jump_speed;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_UP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_UP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
				break;
			default:
				break;
			}
		}

		//##########�������� Ű##########
		if (KEY_CON->Down('Z'))
		{
			jump_speed = -525.0f;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::SPIN_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
				break;
			default:
				break;
			}
		}

		if (!KEY_CON->Press(VK_UP))
		{		
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_IDLE);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::IDLE);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_IDLE);
				break;
			default:
				break;
			}
		}
		break;
	}
		//������������ޱ׸��� �ִ� ���¡����������
	case Player::PLAYER_STATUS::CROUCH:
	case Player::PLAYER_STATUS::MINI_CROUCH:
	case Player::PLAYER_STATUS::FIRE_CROUCH:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_CROUCH);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::CROUCH);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_CROUCH);
			break;
		default:
			break;
		}

		if (jump_speed > 20.0f) // �������̸� (��������ؼ� 20���� �˳��ϰ�)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_CROUCH_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::CROUCH_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_CROUCH_JUMP);
				break;
			default:
				break;
			}
		}

		if (KEY_CON->Press(VK_DOWN))
		{
			if (speed < 0)
			{
				speed += (deceleration * 1.5f) * DELTA;
				if (speed >= 0)
				{
					speed = 0.0f;
				}
			}
			else if (speed > 0)
			{
				speed -= (deceleration * 1.5f) * DELTA;
				if (speed <= 0)
				{
					speed = 0.0f;
				}
			}
		}
		//##########���� Ű##########
		if (KEY_CON->Down('X'))
		{
			if (speed > 50.0f || speed < -50.0f)
			{
				jump_speed = -675.0f;
			}
			else
			{
				jump_speed = -max_jump_speed;
			}
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_CROUCH_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::CROUCH_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_CROUCH_JUMP);
				break;
			default:
				break;
			}
		}

		//##########�������� Ű##########
		if (KEY_CON->Down('Z'))
		{
			jump_speed = -525.0f;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::SPIN_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
				break;
			default:
				break;
			}
		}

		if (KEY_CON->Press(VK_LEFT))
		{
			is_looking_right = false;
		}
		else if (KEY_CON->Press(VK_RIGHT))
		{
			is_looking_right = true;
		}

		if (KEY_CON->Press(VK_UP))
		{
			if (speed == 0.0f)
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_IDLE);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::IDLE);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_IDLE);
					break;
				default:
					break;
				}
			}
		}

		if (!KEY_CON->Press(VK_DOWN))
		{
			if (speed != 0)
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_IDLE);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::IDLE);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_IDLE);
					break;
				default:
					break;
				}
			}
		}
		break;
	}
		//�����������Ȱ� �ִ� ���¡����������
	case Player::PLAYER_STATUS::WALK:
	case Player::PLAYER_STATUS::MINI_WALK:
	case Player::PLAYER_STATUS::FIRE_WALK:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_WALK);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::WALK);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_WALK);
			break;
		default:
			break;
		}

		if (jump_speed > 20.0f) // �������̸� (��������ؼ� 20���� �˳��ϰ�)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_DOWN);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
				break;
			default:
				break;
			}
		}

		if (speed == 0.0f)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_IDLE);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::IDLE);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_IDLE);
				break;
			default:
				break;
			}
		}

		//##########�Ʒ��� Ű##########
		if (KEY_CON->Press(VK_DOWN))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_CROUCH);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::CROUCH);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_CROUCH);
				break;
			default:
				break;
			}
		}

		//##########���� Ű##########
		if (KEY_CON->Press(VK_LEFT))
		{
			is_looking_right = false;

			if (speed > max_run_speed - 30.0f && speed < max_run_speed)
			{
				is_looking_right = true;
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_SKID);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::SKID);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_SKID);
					break;
				default:
					break;
				}
			}

			if (!KEY_CON->Press('C'))
			{
				if (speed > -max_walk_speed)
					// �ִ� �ȱ� �ӵ�����
				{
					// �ӵ� = ���ӵ� * �ð�
					speed -= (acceleration * 1.5f) * DELTA; // �ӵ� ���� ���� (�� ����� �´��� �𸣰���)(����)
				}
				else if (speed <= -max_walk_speed) // �����ϴٰ� �ӵ��� �ٿ��� ��
				{
					speed += deceleration * DELTA; // ���� �ӵ��� ���̴ٰ�(����)

					if (speed >= -max_walk_speed) // �ӵ��� ���� �ӵ����� ���� �پ��ٸ�
					{
						speed = -max_walk_speed; // �ӵ��� ����
					}
				}
			}
			else if (KEY_CON->Press('C'))
			{
				if (speed > -max_walk_speed)
					// �ִ� �ȱ� �ӵ�����
				{
					speed -= (acceleration * 1.5f) * DELTA; // �ӵ� ���� ���� (�� ����� �´��� �𸣰���) (����)
				}
				else if (speed <= -max_walk_speed && speed > -max_run_speed)
					// �ִ� �ȱ� �ӵ� ���Ŀ��� �ִ� �޸��� �ӵ��� ������ ������
				{
					speed -= (acceleration / 2.0f) * DELTA; // �ӵ��� ���� ���� (����)
				}
				else if (speed <= max_run_speed)
					// �Ҽ����� ���� �Ѿ�ٸ�
				{
					speed = -max_run_speed;
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_RUN);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::RUN);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_RUN);
						break;
					default:
						break;
					}
				}
			}
		}
		//##########������ Ű##########
		else if (KEY_CON->Press(VK_RIGHT))
		{
			is_looking_right = true;

			if (speed < -max_run_speed + 30.0f && speed > -max_run_speed)
			{
				is_looking_right = false;
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_SKID);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::SKID);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_SKID);
					break;
				default:
					break;
				}
			}

			if (!KEY_CON->Press('C'))
			{
				if (speed < max_walk_speed)
					// �ִ� �ȱ� �ӵ�����
				{
					speed += (acceleration * 1.5f) * DELTA; // �ӵ� ���� ���� (�� ����� �´��� �𸣰���)(����)
				}
				else if (speed >= max_walk_speed) // �����ϴٰ� �ӵ��� �ٿ��� ��
				{
					speed -= deceleration * DELTA; // ���� �ӵ��� ���̴ٰ�(����)

					if (speed <= max_walk_speed) // �ӵ��� ���� �ӵ����� ���� �پ��ٸ�
					{
						speed = max_walk_speed; // �ӵ��� ����
					}
				}
			}
			else if (KEY_CON->Press('C'))
			{
				if (speed < max_walk_speed)
					// �ִ� �ȱ� �ӵ�����
				{
					speed += (acceleration * 1.5f) * DELTA; // �ӵ� ���� ���� (�� ����� �´��� �𸣰���)(����)
				}
				else if (speed >= max_walk_speed && speed < max_run_speed)
					// �ִ� �ȱ� �ӵ� ���Ŀ��� �ִ� �޸��� �ӵ��� ������ ������
				{
					speed += (acceleration / 2.0f) * DELTA; // �ӵ��� ���� ����(����)
				}
				else if (speed >= max_run_speed)
					// �Ҽ����� ���� �Ѿ�ٸ�
				{
					speed = max_run_speed;
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_RUN);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::RUN);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_RUN);
						break;
					default:
						break;
					}
				}
			}
		}
		//##########���� Ű##########
		if (KEY_CON->Down('X'))
		{
			if (speed > 50.0f || speed < -50.0f)
			{
				jump_speed = -675.0f;
			}
			else
			{
				jump_speed = -max_jump_speed;
			}
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_UP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_UP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
				break;
			default:
				break;
			}
		}

		//##########�������� Ű##########
		if (KEY_CON->Down('Z'))
		{
			jump_speed = -525.0f;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::SPIN_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
				break;
			default:
				break;
			}
		}

		//##########����Ű �Է¾���##########
		if (!KEY_CON->Press(VK_LEFT) && !KEY_CON->Press(VK_RIGHT))
		{
			if (speed < 0)
			{
				if (is_looking_right) // �� ���� �ݴ����Ű�� ��� �̲�������(SKID)�� �ٷ� Ű�� ���� ��
				{
					speed += (deceleration * 2.0f) * DELTA; //(����)
				}
				else // �� ���� �׳� �ƹ� Ű�� ������ �ʾ��� ��
				{
					speed += deceleration * DELTA; //(����)
				}

				if (speed >= 0)
				{
					speed = 0.0f;
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_IDLE);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::IDLE);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_IDLE);
						break;
					default:
						break;
					}
				}
			}
			else if (speed > 0)
			{
				if (!is_looking_right) // �� ���� �ݴ����Ű�� ��� �̲�������(SKID)�� �ٷ� Ű�� ���� ��
				{
					speed -= (deceleration * 2.0f) * DELTA; //(����)
				}
				else // �� ���� �׳� �ƹ� Ű�� ������ �ʾ��� ��
				{
					speed -= deceleration * DELTA; //(����)
				}
				if (speed <= 0)
				{
					speed = 0.0f;
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_IDLE);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::IDLE);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_IDLE);
						break;
					default:
						break;
					}
				}
			}
		}
		break;
	}
		//�����������޸��� �ִ� ���¡����������
	case Player::PLAYER_STATUS::RUN:
	case Player::PLAYER_STATUS::MINI_RUN:
	case Player::PLAYER_STATUS::FIRE_RUN:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_RUN);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::RUN);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_RUN);
			break;
		default:
			break;
		}

		if (jump_speed > 20.0f) // �������̸� (��������ؼ� 20���� �˳��ϰ�)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_DOWN);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
				break;
			default:
				break;
			}
		}

		if (speed == 0.0f)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_IDLE);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::IDLE);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_IDLE);
				break;
			default:
				break;
			}
		}

		//##########�Ʒ��� Ű##########
		if (KEY_CON->Press(VK_DOWN))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_CROUCH);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::CROUCH);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_CROUCH);
				break;
			default:
				break;
			}
		}

		//##########���� Ű##########
		if (KEY_CON->Down('X'))
		{
			jump_speed = -675.0f;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_RUN_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::RUN_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_RUN_JUMP);
				break;
			default:
				break;
			}
		}

		//##########�������� Ű##########
		if (KEY_CON->Down('Z'))
		{
			jump_speed = -525.0f;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::SPIN_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
				break;
			default:
				break;
			}
		}

		//##########���� Ű##########
		if (KEY_CON->Press(VK_LEFT))
		{
			if (speed > 0) // ���������� �����־��µ� ���� Ű�� ���� ��
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_SKID);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::SKID);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_SKID);
					break;
				default:
					break;
				}
			}
		}
		//##########������ Ű##########
		else if (KEY_CON->Press(VK_RIGHT))
		{
			if (speed < 0) // �������� �����־��µ� ������ Ű�� ���� ��
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_SKID);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::SKID);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_SKID);
					break;
				default:
					break;
				}
			}
		}

		//##########����Ű �Է¾���##########
		if (!KEY_CON->Press(VK_LEFT) && !KEY_CON->Press(VK_RIGHT))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_WALK);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::WALK);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_WALK);
				break;
			default:
				break;
			}
		}

		//##########�뽬 Ű �Է¾���##########
		if (!KEY_CON->Press('C'))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_WALK);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::WALK);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_WALK);
				break;
			default:
				break;
			}
		}
		break;
	}
		//�����������̲������� �ִ� ���¡����������
	case Player::PLAYER_STATUS::SKID:
	case Player::PLAYER_STATUS::MINI_SKID:
	case Player::PLAYER_STATUS::FIRE_SKID:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_SKID);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::SKID);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_SKID);
			break;
		default:
			break;
		}

		if (jump_speed > 20.0f) // �������̸� (��������ؼ� 20���� �˳��ϰ�)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_DOWN);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
				break;
			default:
				break;
			}
		}

		if (speed == 0.0f)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_IDLE);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::IDLE);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_IDLE);
				break;
			default:
				break;
			}
		}

		//##########���� Ű##########
		if (KEY_CON->Down('X'))
		{
			if (speed > 50.0f || speed < -50.0f)
			{
				jump_speed = -675.0f;
			}
			else
			{
				jump_speed = -max_jump_speed;
			}

			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_UP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_UP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
				break;
			default:
				break;
			}
		}


		//##########�������� Ű##########
		if (KEY_CON->Down('Z'))
		{
			jump_speed = -525.0f;
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::SPIN_JUMP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
				break;
			default:
				break;
			}
		}

		// �������� �̵� �� 
		if (speed < 0)
		{
			if (KEY_CON->Press(VK_LEFT))
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
			else if (KEY_CON->Press(VK_RIGHT))
			{
				speed += (deceleration * 3.0f) * DELTA; //(����)
				if (speed >= 0)
				{
					speed = 0.0f;
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_IDLE);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::IDLE);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_IDLE);
						break;
					default:
						break;
					}
				}
			}
			else if (!KEY_CON->Press(VK_LEFT))
			{
				is_looking_right = true;
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
			else if (!KEY_CON->Press(VK_RIGHT))
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
		}
		// ���������� �̵� ��
		else if (speed > 0)
		{
			if (KEY_CON->Press(VK_RIGHT))
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
			else if (KEY_CON->Press(VK_LEFT))
			{
				speed -= (deceleration * 3.0f) * DELTA; //(����)
				if (speed <= 0)
				{
					speed = 0.0f;
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_IDLE);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::IDLE);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_IDLE);
						break;
					default:
						break;
					}
				}
			}
			else if (!KEY_CON->Press(VK_RIGHT))
			{
				is_looking_right = false;
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
			else if (!KEY_CON->Press(VK_LEFT))
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
		}
		break;
	}
		//��������������� ���� �߿� �ִ� ���¡����������
	case Player::PLAYER_STATUS::JUMP_UP:
	case Player::PLAYER_STATUS::MINI_JUMP_UP:
	case Player::PLAYER_STATUS::FIRE_JUMP_UP:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_JUMP_UP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::JUMP_UP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
			break;
		default:
			break;
		}

		if (KEY_CON->Up('X'))
		{
			if (jump_speed < -250.0f)
			{
				jump_speed = -250.0f;
			}
		}

		if (jump_speed < 0)
		{
			jump_speed += (gravity * 1.0f) * DELTA;
		}
		else if (jump_speed >= 0)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_DOWN);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
				break;
			default:
				break;
			}
		}
		Jump_Move();
		break;
	}
		//�����������Ʒ��� �������� �ִ� ���¡����������
	case Player::PLAYER_STATUS::JUMP_DOWN:
	case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
	case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::JUMP_DOWN);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
			break;
		default:
			break;
		}

		if (is_ground)
		{
			if (speed != 0)
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_WALK);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::WALK);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_WALK);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_IDLE);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::IDLE);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_IDLE);
					break;
				default:
					break;
				}
			}
		}
		Jump_Move();
		break;
	}
		//������������ޱ׷��� ���������������
	case Player::PLAYER_STATUS::CROUCH_JUMP:
	case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
	case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_CROUCH_JUMP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::CROUCH_JUMP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_CROUCH_JUMP);
			break;
		default:
			break;
		}

		if (is_ground && jump_speed >= 0.0f)
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_CROUCH);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::CROUCH);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_CROUCH);
				break;
			default:
				break;
			}
		}

		if (KEY_CON->Up('X'))
		{
			if (jump_speed < -250.0f)
			{
				jump_speed = -250.0f;
			}
		}

		if (jump_speed < 0)
		{
			jump_speed += (gravity * 1.0f) * DELTA;
		}

		if (!KEY_CON->Press(VK_DOWN))
		{
			switch (player_pow)
			{
			case Player::PLAYER_POW::MINI:
				SetClip(PLAYER_STATUS::MINI_JUMP_UP);
				break;
			case Player::PLAYER_POW::NORMAL:
				SetClip(PLAYER_STATUS::JUMP_UP);
				break;
			case Player::PLAYER_POW::FIRE:
				SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
				break;
			default:
				break;
			}
		}
		Jump_Move();
		break;
	}
		//�����������޷��� ���������������
	case Player::PLAYER_STATUS::RUN_JUMP:
	case Player::PLAYER_STATUS::MINI_RUN_JUMP:
	case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_RUN_JUMP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::RUN_JUMP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_RUN_JUMP);
			break;
		default:
			break;
		}

		if (is_ground)
		{
			if (speed != 0)
			{
				if (speed == max_run_speed || speed == -max_run_speed)
				{
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_RUN);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::RUN);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_RUN);
						break;
					default:
						break;
					}
				}
				else
				{
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_WALK);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::WALK);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_WALK);
						break;
					default:
						break;
					}
				}
			}
			else
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_IDLE);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::IDLE);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_IDLE);
					break;
				default:
					break;
				}
			}
		}

		if (KEY_CON->Up('X'))
		{
			if (jump_speed < -250.0f)
			{
				jump_speed = -250.0f;
			}
		}

		if (jump_speed < 0)
		{
			jump_speed += (gravity * 1.0f) * DELTA;
		}
		Jump_Move();
		break;
	}
		//����������뽺�����������������
	case Player::PLAYER_STATUS::SPIN_JUMP:
	case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
	case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
	{
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::SPIN_JUMP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
			break;
		default:
			break;
		}

		if (is_ground)
		{
			if (speed != 0)
			{
				if (speed == max_run_speed || speed == -max_run_speed)
				{
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_RUN);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::RUN);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_RUN);
						break;
					default:
						break;
					}
				}
				else
				{
					switch (player_pow)
					{
					case Player::PLAYER_POW::MINI:
						SetClip(PLAYER_STATUS::MINI_WALK);
						break;
					case Player::PLAYER_POW::NORMAL:
						SetClip(PLAYER_STATUS::WALK);
						break;
					case Player::PLAYER_POW::FIRE:
						SetClip(PLAYER_STATUS::FIRE_WALK);
						break;
					default:
						break;
					}
				}
			}
			else
			{
				switch (player_pow)
				{
				case Player::PLAYER_POW::MINI:
					SetClip(PLAYER_STATUS::MINI_IDLE);
					break;
				case Player::PLAYER_POW::NORMAL:
					SetClip(PLAYER_STATUS::IDLE);
					break;
				case Player::PLAYER_POW::FIRE:
					SetClip(PLAYER_STATUS::FIRE_IDLE);
					break;
				default:
					break;
				}
			}
		}
		if (KEY_CON->Up('Z'))
		{
			if (jump_speed < -250.0f)
			{
				jump_speed = -250.0f;
			}
		}

		if (jump_speed < 0)
		{
			jump_speed += (gravity * 1.0f) * DELTA;
		}
		Jump_Move();
		break;
	}
		//��������������������������
	case PLAYER_STATUS::KICK:
	case PLAYER_STATUS::MINI_KICK:
	case PLAYER_STATUS::FIRE_KICK:
		break;
		//�����������ҵ��̰��ݡ����������
	case PLAYER_STATUS::FIRE_ATTACK:
		break;
		//��������������������������
	case PLAYER_STATUS::DEAD:
		/*speed = 0.0f;
		dead_stop_time -= DELTA;
		if (dead_stop_time > 0.0f)
			jump_speed = 0.0f;
		else if (dead_stop_time < 0.0f && dead_stop_time > -0.5f)
			jump_speed = -200.0f;
		else if (dead_stop_time < -0.5f)
		{
			jump_speed = 200.0f;
		}*/
		break;
		//�����������DEFAULT�����������
	default:
		break;
	}
	clips[(UINT)player_status]->Update(); // ���� ����ؾ� �� �ִϸ��̼��� ������Ʈ

	scale = clips[(UINT)player_status]->GetFrameSize() * 2.0f;


	if (!is_looking_right)
	{
		scale.x *= -1;
	}

	// �� ���¸��� �浹���� ���� ����
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
	case Player::PLAYER_STATUS::MINI_KICK:
		col_cursor = 2;
		break;
	case Player::PLAYER_STATUS::MINI_CROUCH:
	case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
		col_cursor = 3;
		break;
	default:
		break;
	}

	// �켱 ��ü�� false�� �ٲ� ��
	for (auto col : collider)
	{
		col->is_active = false;
	}
	// Ȱ��ȭ �� collider�� true�� ����
	collider[col_cursor]->is_active = true;

	if (player_status == PLAYER_STATUS::DEAD)
		collider[col_cursor]->is_active = false;

	
	// �� ���º� ���� �ִ����� ����
	switch (player_status)
	{
	case Player::PLAYER_STATUS::IDLE:
	case Player::PLAYER_STATUS::MINI_IDLE:
	case Player::PLAYER_STATUS::FIRE_IDLE:
	case Player::PLAYER_STATUS::UP:
	case Player::PLAYER_STATUS::MINI_UP:
	case Player::PLAYER_STATUS::FIRE_UP:
	case Player::PLAYER_STATUS::CROUCH:
	case Player::PLAYER_STATUS::MINI_CROUCH:
	case Player::PLAYER_STATUS::FIRE_CROUCH:
	case Player::PLAYER_STATUS::WALK:
	case Player::PLAYER_STATUS::MINI_WALK:
	case Player::PLAYER_STATUS::FIRE_WALK:
	case Player::PLAYER_STATUS::RUN:
	case Player::PLAYER_STATUS::MINI_RUN:
	case Player::PLAYER_STATUS::FIRE_RUN:
	case Player::PLAYER_STATUS::SKID:
	case Player::PLAYER_STATUS::MINI_SKID:
	case Player::PLAYER_STATUS::FIRE_SKID:
		is_ground = true;
		break;
	case Player::PLAYER_STATUS::JUMP_UP:
	case Player::PLAYER_STATUS::MINI_JUMP_UP:
	case Player::PLAYER_STATUS::FIRE_JUMP_UP:
	case Player::PLAYER_STATUS::JUMP_DOWN:
	case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
	case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
	case Player::PLAYER_STATUS::CROUCH_JUMP:
	case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
	case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
	case Player::PLAYER_STATUS::RUN_JUMP:
	case Player::PLAYER_STATUS::MINI_RUN_JUMP:
	case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
	case Player::PLAYER_STATUS::SPIN_JUMP:
	case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
	case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
	case Player::PLAYER_STATUS::DEAD:
		is_ground = false;
		break;
	case Player::PLAYER_STATUS::KICK:
	case Player::PLAYER_STATUS::MINI_KICK:
	case Player::PLAYER_STATUS::FIRE_KICK:
	case Player::PLAYER_STATUS::FIRE_ATTACK:
		break;
	default:
		break;
	}

	// �÷��̾� �̵�����
	pos.y += jump_speed * DELTA;
	pos.x += speed * DELTA;

	if (is_hit)
	{
		/*if (player_pow == PLAYER_POW::MINI)
			SetClip(PLAYER_STATUS::DEAD);*/

		if (invincible_time > 1.0f)
		{
			if ((int)(invincible_time * 10) % 2 == 0)
			{
				SetColor(Float4(1, 1, 1, 1));
			}
			else
			{
				SetColor(Float4(1, 1, 1, 0));
			}
		}
		else
		{
			if ((int)(invincible_time * 20) % 2 == 0)
				SetColor(Float4(1, 1, 1, 1));
			else
				SetColor(Float4(1, 1, 1, 0));
		}
		invincible_time -= DELTA;

		if (invincible_time <= 0.0f)
		{
			invincible_time = 2.0f;
			is_hit = false;
		}
	}

	// �÷��̾� �ǰ� ������ �����ð�
	// �ǰ� ��
	

	WorldUpdate(); // �� ������Ʈ�� ���� Ʈ�������� ��� ������ ���� Ȯ��������
	// �̸� �̿��� ���������Ʈ


	// �� ������Ʈ�� ���尡 Ȯ���ƴٸ� �̿� ���� �浹���� ���� ���������Ʈ
	collider[0]->pos = pos + Vector2(0, 6); // �Ϲ� ����
	collider[1]->pos = pos + Vector2(0, 18); // �Ϲ� �ޱ׸�
	collider[2]->pos = pos + Vector2(0, 14); // �̴� ����
	collider[3]->pos = pos + Vector2(0, 20); // �̴� �ޱ׸�

	for (auto col : collider)
	{
		col->WorldUpdate();
	}
}


void Player::StopTimeUpdate()
{
	switch (player_status)
	{
	case Player::PLAYER_STATUS::IDLE:
	case Player::PLAYER_STATUS::MINI_IDLE:
	case Player::PLAYER_STATUS::FIRE_IDLE:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_IDLE);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::IDLE);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_IDLE);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::UP:
	case Player::PLAYER_STATUS::MINI_UP:
	case Player::PLAYER_STATUS::FIRE_UP:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_UP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::UP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_UP);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::CROUCH:
	case Player::PLAYER_STATUS::MINI_CROUCH:
	case Player::PLAYER_STATUS::FIRE_CROUCH:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_CROUCH);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::CROUCH);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_CROUCH);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::WALK:
	case Player::PLAYER_STATUS::MINI_WALK:
	case Player::PLAYER_STATUS::FIRE_WALK:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_WALK);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::WALK);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_WALK);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::RUN:
	case Player::PLAYER_STATUS::MINI_RUN:
	case Player::PLAYER_STATUS::FIRE_RUN:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_RUN);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::RUN);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_RUN);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::SKID:
	case Player::PLAYER_STATUS::MINI_SKID:
	case Player::PLAYER_STATUS::FIRE_SKID:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_SKID);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::SKID);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_SKID);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::JUMP_UP:
	case Player::PLAYER_STATUS::MINI_JUMP_UP:
	case Player::PLAYER_STATUS::FIRE_JUMP_UP:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_JUMP_UP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::JUMP_UP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::JUMP_DOWN:
	case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
	case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_JUMP_DOWN);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::JUMP_DOWN);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_JUMP_DOWN);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::CROUCH_JUMP:
	case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
	case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_CROUCH_JUMP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::CROUCH_JUMP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_CROUCH_JUMP);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::RUN_JUMP:
	case Player::PLAYER_STATUS::MINI_RUN_JUMP:
	case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_RUN_JUMP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::RUN_JUMP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_RUN_JUMP);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::SPIN_JUMP:
	case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
	case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::SPIN_JUMP);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::KICK:
	case Player::PLAYER_STATUS::MINI_KICK:
	case Player::PLAYER_STATUS::FIRE_KICK:
		switch (player_pow)
		{
		case Player::PLAYER_POW::MINI:
			SetClip(PLAYER_STATUS::MINI_KICK);
			break;
		case Player::PLAYER_POW::NORMAL:
			SetClip(PLAYER_STATUS::KICK);
			break;
		case Player::PLAYER_POW::FIRE:
			SetClip(PLAYER_STATUS::FIRE_KICK);
			break;
		default:
			break;
		}
		break;
	case Player::PLAYER_STATUS::FIRE_ATTACK:
		break;
	case Player::PLAYER_STATUS::DEAD:
		//SetClip(PLAYER_STATUS::DEAD);
		break;
	default:
		break;
	}

	if (is_dead == true)
	{
		SetClip(Player::PLAYER_STATUS::DEAD);
		collider[col_cursor]->is_active = false;
	}

	//scale = clips[(UINT)player_status]->GetFrameSize() * 2.0f;

	/*if (!is_looking_right)
	{
		scale.x *= -1;
	}*/

	WorldUpdate();
}

void Player::Render()
{
	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	clips[(UINT)player_status]->Render();

	for (auto col : collider)
	{
		col->Render();
	}
}

void Player::PostRender()
{
	ImGui::SliderFloat2("Player's pos", (float*)&pos, 0, WIN_WIDTH);
	//ImGui::Text("PLAYER_POW : %s", PlayerPowToString(player_pow));
	ImGui::Text("PLAYER_STATUS : %s", PlayerStatusToString(player_status));
	//ImGui::Text("Looking Right : %d", is_looking_right);
	//ImGui::Text("Speed : %f", speed);
	//ImGui::Text("Jump_Speed : %f", jump_speed);
	//ImGui::Text("is_ground : %d", is_ground);*/
	ImGui::Text("is_hit : %d", is_hit);
	ImGui::Text("is_change : %d", is_change);
	ImGui::Text("is_dead : %d", is_dead);
	ImGui::Text("invincible_time : %f", invincible_time);
	ImGui::Text("dead_stop_time : %f", dead_stop_time);
	ImGui::Text("col_cursor : %d", col_cursor);
}

void Player::SetClip(PLAYER_STATUS stat)
{
	if (player_status != stat) // �� �Լ��� �Է��� ������ �� ������ ���Ȱ� �������� �˻�
		// �������� �ʴٸ� �� ������Ʈ�� ���¸� �ٲٴ� �ڵ带 ������
	{
		switch (stat) // �Է¹��� ���¿� ���� �ٸ� �۾��� �ϵ��� �б�
		{
		case Player::PLAYER_STATUS::IDLE:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::UP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::CROUCH:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::WALK:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::RUN:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::SKID:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::JUMP_UP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::JUMP_DOWN:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::CROUCH_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::RUN_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::SPIN_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::KICK:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_IDLE:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_UP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_CROUCH:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_WALK:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_RUN:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_SKID:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_JUMP_UP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_RUN_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::MINI_KICK:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_IDLE:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_UP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_CROUCH:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_WALK:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_RUN:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_SKID:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_JUMP_UP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_KICK:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::FIRE_ATTACK:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		case Player::PLAYER_STATUS::DEAD:
		{
			clips[(int)player_status]->Stop();
			player_status = stat;
			clips[(int)player_status]->Play();
		}
		break;
		default:
			break;
		}
	}
}

void Player::SetPow(PLAYER_POW stat)
{
	switch (stat)
	{
	case Player::PLAYER_POW::MINI:
		player_pow = stat;
		break;
	case Player::PLAYER_POW::NORMAL:
		player_pow = stat;
		break;
	case Player::PLAYER_POW::FIRE:
		player_pow = stat;
		break;
	default:
		break;
	}
}

void Player::Jump_Move()
{
	if (KEY_CON->Press(VK_LEFT))
	{
		is_looking_right = false;
		if (!KEY_CON->Press('C'))
		{
			if (speed > -max_walk_speed)
			{
				speed -= acceleration * DELTA;
			}
			else if (speed <= -max_walk_speed)
			{
				//speed += deceleration * DELTA; // ���� �߿� ���� ����

				if (speed >= -max_walk_speed)
				{
					speed = -max_walk_speed;
				}
			}
		}
		else if (KEY_CON->Press('C'))
		{
			if (speed > -max_walk_speed)
			{
				speed -= (acceleration * 1.5f) * DELTA;
			}
			else if (speed <= -max_walk_speed && speed > -max_run_speed)
			{
				speed -= (acceleration / 6.0f) * DELTA;
			}
			else if (speed <= max_run_speed)
			{
				speed = -max_run_speed;
			}
		}
	}
	else if (KEY_CON->Press(VK_RIGHT))
	{
		is_looking_right = true;
		if (!KEY_CON->Press('C'))
		{
			if (speed < max_walk_speed)
			{
				speed += acceleration * DELTA;
			}
			else if (speed >= max_walk_speed)
			{
				/*speed -= deceleration * DELTA;*/ // ���� �߿� ���� ����

				if (speed <= max_walk_speed)
				{
					speed = max_walk_speed;
				}
			}
		}
		else if (KEY_CON->Press('C'))
		{
			if (speed < max_walk_speed)
			{
				speed += (acceleration * 1.5f) * DELTA;
			}
			else if (speed >= max_walk_speed && speed < max_run_speed)
			{
				speed += (acceleration / 6.0f) * DELTA;
			}
			else if (speed >= max_run_speed)
			{
				speed = max_run_speed;
			}
		}
	}
}

// ���� �浹 ����
void Player::TopographyCollide(RectCollider* obj)
{
	Vector2 collide_area;
	switch (obj->GetColType())
	{
	case 0: // ����� ���� ��
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			obj->SetColor(1, 0, 0); // ���������� �ٲ�
			if (collide_area.x >= collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				if (pos.y < obj->pos.y) // ������ �浹
				{
					jump_speed = 0.0f;
					pos.y -= collide_area.y;
					is_ground = true;
				}
				else // �Ʒ����� �浹
				{
					jump_speed = 0.0f;
					pos.y += collide_area.y;
				}
			}
			else // x���� y�ຸ�� ª�� �� (���� or �����ʿ��� �浹)
			{
				if (collide_area.y < 0.1f)
				{
					break;
				}
				if (pos.x < obj->pos.x) // ���ʿ��� �浹
				{
					speed = 0.0f;
					pos.x -= collide_area.x;
				}
				else // �����ʿ��� �浹
				{
					speed = 0.0f;
					pos.x += collide_area.x;
				}
			}
		}
		else
		{
			obj->SetColor(0, 1, 0);
		}
		break;
	}
	case 1: // �������� ���� �� �ִ� �ݺ�
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			obj->SetColor(1, 0, 0); // ���������� �ٲ�

			if (collide_area.x > collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				if (pos.y < obj->pos.y) // ������ �浹
				{
					if ((pos.y + (46.0f - 4.5f) < obj->pos.y) && jump_speed >= 0.0f)// obj�� ���� ���� ���κп� ���� ��
						// -4.0f�� ������ �̰ź��� -4���� ũ�� ��Ȥ �ݺ��� �հ� ������
					{
						jump_speed = 0.0f;
						pos.y -= collide_area.y;
						is_ground = true;
					}
				}
				else // �Ʒ����� �浹
				{
				}
			}
			else
			{
				if (pos.x < obj->pos.x) // ���ʿ��� �浹
				{
				}
				else // �����ʿ��� �浹
				{
				}
			}
		}
		else
		{
			obj->SetColor(0, 1, 0);
		}
		break;
	}
	default:
		break;
	}
}

// ���� �浹 ����
void Player::MonsterCollide(RectCollider* obj)
{
	Vector2 collide_area;
	switch (obj->GetColType())
	{
	case 0: // �Ϲ����� ���� (�������� ���� �� ����)
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			if (collide_area.x >= collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				if (pos.y < obj->pos.y) // ������ �浹
				{
					obj->SetColor(1, 0, 0); // ���������� �ٲ�
					// ������ ������ ���� ����
					if (jump_speed >= 20.0f)
					{
						if (KEY_CON->Press('X') || KEY_CON->Press('Z'))
						{
							jump_speed = -675.0f;
						}
						else if (KEY_CON->Up('X') || KEY_CON->Up('Z'))
						{
							jump_speed = -470.0f;
						}
						else
						{
							jump_speed = -264.0f;
						}
						pos.y -= collide_area.y;
					}

					switch (player_status)
					{
					case Player::PLAYER_STATUS::IDLE:
					case Player::PLAYER_STATUS::MINI_IDLE:
					case Player::PLAYER_STATUS::FIRE_IDLE:
					case Player::PLAYER_STATUS::UP:
					case Player::PLAYER_STATUS::MINI_UP:
					case Player::PLAYER_STATUS::FIRE_UP:
					case Player::PLAYER_STATUS::WALK:
					case Player::PLAYER_STATUS::MINI_WALK:
					case Player::PLAYER_STATUS::FIRE_WALK:
						break;
					case Player::PLAYER_STATUS::RUN:
					case Player::PLAYER_STATUS::MINI_RUN:
					case Player::PLAYER_STATUS::FIRE_RUN:
					case Player::PLAYER_STATUS::SKID:
					case Player::PLAYER_STATUS::MINI_SKID:
					case Player::PLAYER_STATUS::FIRE_SKID:
					case Player::PLAYER_STATUS::JUMP_UP:
					case Player::PLAYER_STATUS::MINI_JUMP_UP:
					case Player::PLAYER_STATUS::FIRE_JUMP_UP:
					case Player::PLAYER_STATUS::JUMP_DOWN:
					case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
					case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
					case Player::PLAYER_STATUS::RUN_JUMP:
					case Player::PLAYER_STATUS::MINI_RUN_JUMP:
					case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
						switch (player_pow)
						{
						case Player::PLAYER_POW::MINI:
							SetClip(PLAYER_STATUS::MINI_JUMP_UP);
							break;
						case Player::PLAYER_POW::NORMAL:
							SetClip(PLAYER_STATUS::JUMP_UP);
							break;
						case Player::PLAYER_POW::FIRE:
							SetClip(PLAYER_STATUS::FIRE_JUMP_UP);
							break;
						default:
							break;
						}
						break;
					case Player::PLAYER_STATUS::SPIN_JUMP:
					case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
					case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
						switch (player_pow)
						{
						case Player::PLAYER_POW::MINI:
							SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
							break;
						case Player::PLAYER_POW::NORMAL:
							SetClip(PLAYER_STATUS::SPIN_JUMP);
							break;
						case Player::PLAYER_POW::FIRE:
							SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
							break;
						default:
							break;
						}
						obj->is_active = false;
						break;
					case Player::PLAYER_STATUS::CROUCH:
					case Player::PLAYER_STATUS::MINI_CROUCH:
					case Player::PLAYER_STATUS::FIRE_CROUCH:
					case Player::PLAYER_STATUS::CROUCH_JUMP:
					case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
					case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
						switch (player_pow)
						{
						case Player::PLAYER_POW::MINI:
							SetClip(PLAYER_STATUS::MINI_CROUCH_JUMP);
							break;
						case Player::PLAYER_POW::NORMAL:
							SetClip(PLAYER_STATUS::CROUCH_JUMP);
							break;
						case Player::PLAYER_POW::FIRE:
							SetClip(PLAYER_STATUS::FIRE_CROUCH_JUMP);
							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
				}
				else // �Ʒ����� �浹
				{
					if (is_invincible == false)
					{
						is_hit = true;
						if (invincible_time == 2.0f)
						{
							if (player_pow == PLAYER_POW::MINI)
							{
								is_change = false;
								is_dead = true;
							}
							else
							{
								is_change = true;
								is_dead = false;
							}
						}
					}
					GetCollider()->SetColor(1, 0, 0);
				}
			}
			else // x���� y�ຸ�� ª�� �� (���� or �����ʿ��� �浹)
			{
				if (pos.x < obj->pos.x) // ���ʿ��� �浹
				{
					if (is_invincible == false)
					{
						is_hit = true;
						if (invincible_time == 2.0f)
						{
							if (player_pow == PLAYER_POW::MINI)
							{
								is_change = false;
								is_dead = true;
							}
							else
							{
								is_change = true;
								is_dead = false;
							}
						}
					}
					GetCollider()->SetColor(1, 0, 0);
				}
				else // �����ʿ��� �浹
				{
					if (is_invincible == false)
					{
						is_hit = true;
						if (invincible_time == 2.0f)
						{
							if (player_pow == PLAYER_POW::MINI)
							{
								is_change = false;
								is_dead = true;
							}
							else
							{
								is_change = true;
								is_dead = false;
							}
						}
					}
					GetCollider()->SetColor(1, 0, 0);
				}
			}
		}
		else
		{
			obj->SetColor(0, 1, 0);
			GetCollider()->SetColor(0, 1, 0);
		}
		break;
	}
	case 1: // �Ϲ����� �������� ����
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			if (collide_area.x >= collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				if (pos.y < obj->pos.y) // ������ �浹
				{
					if (jump_speed >= 20.0f)
					{
						if (player_status == PLAYER_STATUS::SPIN_JUMP ||
							player_status == PLAYER_STATUS::MINI_SPIN_JUMP ||
							player_status == PLAYER_STATUS::FIRE_SPIN_JUMP)
						{
							if (KEY_CON->Press('Z'))
							{
								jump_speed = -675.0f;
							}
							else if (KEY_CON->Up('Z'))
							{
								jump_speed = -470.0f;
							}
							else
							{
								jump_speed = -264.0f;
							}
							pos.y -= collide_area.y;
						}
					}

					switch (player_status)
					{
					case Player::PLAYER_STATUS::IDLE:
					case Player::PLAYER_STATUS::MINI_IDLE:
					case Player::PLAYER_STATUS::FIRE_IDLE:
					case Player::PLAYER_STATUS::UP:
					case Player::PLAYER_STATUS::MINI_UP:
					case Player::PLAYER_STATUS::FIRE_UP:
					case Player::PLAYER_STATUS::WALK:
					case Player::PLAYER_STATUS::MINI_WALK:
					case Player::PLAYER_STATUS::FIRE_WALK:
						break;
					case Player::PLAYER_STATUS::RUN:
					case Player::PLAYER_STATUS::MINI_RUN:
					case Player::PLAYER_STATUS::FIRE_RUN:
					case Player::PLAYER_STATUS::SKID:
					case Player::PLAYER_STATUS::MINI_SKID:
					case Player::PLAYER_STATUS::FIRE_SKID:
					case Player::PLAYER_STATUS::JUMP_UP:
					case Player::PLAYER_STATUS::MINI_JUMP_UP:
					case Player::PLAYER_STATUS::FIRE_JUMP_UP:
					case Player::PLAYER_STATUS::JUMP_DOWN:
					case Player::PLAYER_STATUS::MINI_JUMP_DOWN:
					case Player::PLAYER_STATUS::FIRE_JUMP_DOWN:
					case Player::PLAYER_STATUS::RUN_JUMP:
					case Player::PLAYER_STATUS::MINI_RUN_JUMP:
					case Player::PLAYER_STATUS::FIRE_RUN_JUMP:
						break;
					case Player::PLAYER_STATUS::SPIN_JUMP:
					case Player::PLAYER_STATUS::MINI_SPIN_JUMP:
					case Player::PLAYER_STATUS::FIRE_SPIN_JUMP:
						switch (player_pow)
						{
						case Player::PLAYER_POW::MINI:
							SetClip(PLAYER_STATUS::MINI_SPIN_JUMP);
							break;
						case Player::PLAYER_POW::NORMAL:
							SetClip(PLAYER_STATUS::SPIN_JUMP);
							break;
						case Player::PLAYER_POW::FIRE:
							SetClip(PLAYER_STATUS::FIRE_SPIN_JUMP);
							break;
						default:
							break;
						}
						obj->is_active = false;
						break;
					case Player::PLAYER_STATUS::CROUCH:
					case Player::PLAYER_STATUS::MINI_CROUCH:
					case Player::PLAYER_STATUS::FIRE_CROUCH:
					case Player::PLAYER_STATUS::CROUCH_JUMP:
					case Player::PLAYER_STATUS::MINI_CROUCH_JUMP:
					case Player::PLAYER_STATUS::FIRE_CROUCH_JUMP:
						break;
					default:
						break;
					}
				}
				else // �Ʒ����� �浹
				{
					GetCollider()->SetColor(1, 0, 0);
				}
			}
			else // x���� y�ຸ�� ª�� �� (���� or �����ʿ��� �浹)
			{
				if (pos.x < obj->pos.x) // ���ʿ��� �浹
				{
					GetCollider()->SetColor(1, 0, 0);
				}
				else // �����ʿ��� �浹
				{
					GetCollider()->SetColor(1, 0, 0);
				}
			}
		}
		else
		{
			obj->SetColor(0, 1, 0);
			GetCollider()->SetColor(0, 1, 0);
		}
		break;
	}
	case 2: // ���� �� ���� ����
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			if (collide_area.x >= collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				if (pos.y < obj->pos.y) // ������ �浹
				{
					jump_speed = 0.0f;
					pos.y -= collide_area.y;
					is_ground = true;
					if (is_invincible == false)
					{
						is_hit = true;
						if (invincible_time == 2.0f)
						{
							if (player_pow == PLAYER_POW::MINI)
							{
								is_change = false;
								is_dead = true;
							}
							else
							{
								is_change = true;
								is_dead = false;
							}
						}
					}
					GetCollider()->SetColor(1, 0, 0);
				}
				else // �Ʒ����� �浹
				{
					jump_speed = 0.0f;
					pos.y += collide_area.y;
					if (is_invincible == false)
					{
						is_hit = true;
						if (invincible_time == 2.0f)
						{
							if (player_pow == PLAYER_POW::MINI)
							{
								is_change = false;
								is_dead = true;
							}
							else
							{
								is_change = true;
								is_dead = false;
							}
						}
					}
					GetCollider()->SetColor(1, 0, 0);
				}
			}
			else // x���� y�ຸ�� ª�� �� (���� or �����ʿ��� �浹)
			{
				if (pos.x < obj->pos.x) // ���ʿ��� �浹
				{
					speed = 0.0f;
					pos.x -= collide_area.x;
					if (is_invincible == false)
					{
						is_hit = true;
						if (invincible_time == 2.0f)
						{
							if (player_pow == PLAYER_POW::MINI)
							{
								is_change = false;
								is_dead = true;
							}
							else
							{
								is_change = true;
								is_dead = false;
							}
						}
					}
					GetCollider()->SetColor(1, 0, 0);
				}
				else // �����ʿ��� �浹
				{
					speed = 0.0f;
					pos.x += collide_area.x;
					if (is_invincible == false)
					{
						is_hit = true;
						if (invincible_time == 2.0f)
						{
							if (player_pow == PLAYER_POW::MINI)
							{
								is_change = false;
								is_dead = true;
							}
							else
							{
								is_change = true;
								is_dead = false;
							}
						}
					}
					GetCollider()->SetColor(1, 0, 0);
				}
			}
		}
		else
		{
			obj->SetColor(0, 1, 0);
			GetCollider()->SetColor(0, 1, 0);
		}
		break;
	default:
		break;
	}
}