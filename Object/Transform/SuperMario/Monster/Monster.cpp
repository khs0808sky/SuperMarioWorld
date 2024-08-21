#include "framework.h"
#include "Monster.h"

Monster::Monster(MONSTER_NAME monster_name)
{
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Enemy.png";
	Texture* t = Texture::Add(file);
	// ���� ����� ��������Ʈ�� ũ��

	Vector2 this_frame_size;
	vector<Frame*> frames;
	Vector2 init_pos;
	switch (monster_name)
	{
	/*case Monster::MONSTER_NAME::NONE:
		break;*/
		//������������١����������
	case Monster::MONSTER_NAME::BAMBA:
	{
		// ���� Ÿ�� ���� ����
		monster_type = MONSTER_TYPE::MOVE;
		monster_move = MONSTER_MOVE::STRAIGHT;
		monster_status = MONSTER_STATUS::WALK;

		is_stepped = false;
		upside_down_time = 5.0f;

		// �ӵ� ����
		speed = -62.5f;

		gravity = 100.0f;

		max_jump_speed = 600.0f;
		jump_speed = max_jump_speed;

		is_looking_right = false;
		is_ground = false;

		//�����������MONSTER_STATUS::WALK�����������
		this_frame_size = { 16.0f, 16.0f }; // sprite-cow������ 16, 32�ε� ���ǻ� 16, 16���� ������
		init_pos = { 1, 1 };

		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 18.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 5.0f));
		frames.clear();


		collider = new RectCollider(Vector2(32, 30));
		collider->pos = pos;
		collider->is_active = true;
		collider->SetColType(0); // ������ ������ ���� �� �ִ� ����
		break;
	}
		//����������붯���١����������
	case Monster::MONSTER_NAME::DDANG_GAMBA:
	{
		// ���� Ÿ�� ���� ����
		monster_type = MONSTER_TYPE::MOVE;
		monster_move = MONSTER_MOVE::NO_STRAIGHT;
		monster_status = MONSTER_STATUS::WALK;

		is_stepped = false;
		upside_down_time = 5.0f;

		// �ӵ� ����
		speed = -62.5f;

		gravity = 100.0f;

		max_jump_speed = 600.0f;
		jump_speed = max_jump_speed;

		is_looking_right = false;

		//�����������MONSTER_STATUS::WALK�����������
		this_frame_size = { 16.0f, 16.0f }; // sprite-cow������ 16, 32�ε� ���ǻ� 16, 16���� ������
		init_pos = { 98, 1 };

		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 115.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 5.0f));
		frames.clear();


		collider = new RectCollider(Vector2(32, 30));
		collider->pos = pos;
		collider->is_active = true;
		collider->SetColType(0); // ������ ������ ���� �� �ִ� ����
		break;
	}
		//���������������������������
	case Monster::MONSTER_NAME::BLACK_PIRANHA:
		// ���� Ÿ�� ���� ����
		monster_type = MONSTER_TYPE::STOP;
		monster_move = MONSTER_MOVE::NO_STRAIGHT;
		monster_status = MONSTER_STATUS::IDLE;

		is_stepped = false;
		upside_down_time = 5.0f;

		// �ӵ� ����
		speed = 0.0f;

		gravity = 100.0f;

		max_jump_speed = 600.0f;
		jump_speed = max_jump_speed;

		is_looking_right = false;

		//�����������MONSTER_STATUS::IDLE�����������
		this_frame_size = { 16.0f, 16.0f }; // sprite-cow������ 16, 32�ε� ���ǻ� 16, 16���� ������
		init_pos = { 213, 96 };

		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 230.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 5.0f));
		frames.clear();


		collider = new RectCollider(Vector2(32, 32));
		collider->pos = pos;
		collider->is_active = true;
		collider->SetColType(2); // ������ ������ ���� �� �ִ� ����
		break;
	default:
		break;
	}

	dead = new Dead();
	dead->pos = Vector2(-100.0f, -100.0f);
	dead->Update();

	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();
}

Monster::~Monster()
{
	for (Clip* c : clips)
		delete c;

	delete collider;

	delete CB;
	delete dead;
}

void Monster::Update()
{
	switch (monster_type)
	{
	case Monster::MONSTER_TYPE::MOVE:
		if (jump_speed > 30.0f)
			is_ground = false;

		jump_speed += (gravity * 13.0f) * DELTA;

		if (jump_speed > max_jump_speed)
		{
			jump_speed = max_jump_speed;
		}

		if (is_ground && jump_speed > 0.0f)
		{
			jump_speed -= (gravity * 13.0f) * DELTA - 1.0f;
			//jump_speed -= 1.0f;
		}

		pos.x += speed * DELTA;
		pos.y += jump_speed * DELTA;
		break;
	case Monster::MONSTER_TYPE::STOP:

		jump_speed += (gravity * 13.0f) * DELTA;

		if (jump_speed > max_jump_speed)
		{
			jump_speed = max_jump_speed;
		}

		if (is_ground && jump_speed > 0.0f)
		{
			jump_speed -= (gravity * 13.0f) * DELTA - 1.0f;
			//jump_speed -= 1.0f;
		}
		pos.x += speed * DELTA;
		pos.y += jump_speed * DELTA;
		break;
	case Monster::MONSTER_TYPE::CONDITION_MOVE:
		break;
	default:
		break;
	}


	if (speed > 0)
		is_looking_right = true;
	else
		is_looking_right = false;


	clips[(UINT)monster_name]->Update(); // ���� ����ؾ� �� �ִϸ��̼��� ������Ʈ

	scale = clips[(UINT)monster_name]->GetFrameSize() * 2.0f;

	if (is_looking_right)
	{
		scale.x *= -1;
	}

	if (is_stepped)
	{
		speed = 0.0f;
		//scale.y *= -1;
		if (upside_down_time == 5.0f)
			rot.z = M_PI;
		collider->SetColType(1);

		upside_down_time -= DELTA;

		if (upside_down_time < 2.0f && upside_down_time >= 1.0f)
		{
			if ((int)(upside_down_time * 4) % 2 == 0)
			{
				rot.z = M_PI * 0.9f;
			}
			else
			{
				rot.z = M_PI * -0.9f;
			}
		}
		else if (upside_down_time < 1.0f && upside_down_time > 0.0f)
		{
			if ((int)(upside_down_time * 15) % 2 == 0)
			{
				rot.z = M_PI * 0.9f;
			}
			else
			{
				rot.z = M_PI * -0.9f;
			}
		}


		if (upside_down_time <= 0.0f)
		{
			is_stepped = false;
			upside_down_time = 5.0f;
			//scale.y *= -1;
			rot.z = 0;
			collider->SetColType(0);

			if (is_looking_right)
				speed = 62.5f;
			else
				speed = -62.5;
		}
	}

	if (collider->is_active == true)
		dead->pos = pos;
	else if (collider->is_active == false)
	{
		dead->Update();
	}
	WorldUpdate();
	collider->WorldUpdate();
	collider->pos = pos;
}

void Monster::Render()
{
	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	// �浹 �� �Ⱥ��̰� �Ҷ��
	if (collider->is_active)
		clips[(UINT)monster_name]->Render();
	else
		dead->Render();
	

	collider->Render();
}

void Monster::PostRender()
{
	ImGui::Text("----BamBa Stat----");
	ImGui::SliderFloat2("bamba's pos", (float*)&pos, 0, WIN_WIDTH);
	ImGui::Text("Speed : %f", speed);
	ImGui::Text("Jump_Speed : %f", jump_speed);
	ImGui::Text("is_ground : %d", is_ground);
}

void Monster::TopographyCollide(RectCollider* obj)
{
	Vector2 collide_area;
	switch (obj->GetColType())
	{
	case 0: // ����� ���� ��
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
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
				if (collide_area.y < 1.0f)
				{
					break;
				}
				if (pos.x < obj->pos.x) // ���ʿ��� �浹
				{
					speed *= -1.0f;
					pos.x -= collide_area.x;
				}
				else // �����ʿ��� �浹
				{
					speed *= -1.0f;
					pos.x += collide_area.x;
				}
			}
		}
		else
		{
		}
		break;
	case 1: // �������� ���� �� �ִ� �ݺ�
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			if (collide_area.x > collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				if (pos.y < obj->pos.y) // ������ �浹
				{
					/*if ((pos.y + (46.0f - 17.0f) < obj->pos.y && jump_speed >= 0.0f))// obj�� ���� ���� ���κп� ���� ��
					{
						jump_speed = 0.0f;
						pos.y -= collide_area.y;
						is_ground = true;
					}*/
					jump_speed = 0.0f;
					pos.y -= collide_area.y;
					is_ground = true;
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
		}

	}
	break;
	default:
		break;
	}
}

void Monster::PlayerCollide(RectCollider* obj)
{
	Vector2 collide_area;
	switch (GetCollider()->GetColType())
	{
	case 0: // ������ ������ ���� �� �ִ� ����
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			if (collide_area.x >= collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				//if (pos.y < obj->pos.y) // ������ �浹
				if (obj->pos.y < pos.y)
				{
					is_stepped = true;
				}
				else // �Ʒ����� �浹
				{
				}
			}
			else // x���� y�ຸ�� ª�� �� (���� or �����ʿ��� �浹)
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
		}
		break;
	case 1: // ������ ������ ���� �� �ִ� ����
		break;
	case 2:
		break;
	default:
		break;
	}
}

/*
void Monster::MonsterCollide(RectCollider* obj)
{
	Vector2 collide_area;
	switch (obj->GetColType())
	{
	case 0: // ����� ���� ��
		if (GetCollider()->isCollision(obj, &collide_area)) // ��� �����̴� �浹�� ���� ��
		{
			if (collide_area.x >= collide_area.y) // x���� y�ຸ�� �涧 (�� or �Ʒ����� �浹)
			{
				if (pos.y < obj->pos.y) // ������ �浹
				{
				}
				else // �Ʒ����� �浹
				{
				}
			}
			else // x���� y�ຸ�� ª�� �� (���� or �����ʿ��� �浹)
			{
				if (collide_area.y < 1.0f)
				{
					break;
				}
				if (pos.x < obj->pos.x) // ���ʿ��� �浹
				{
					speed *= -1.0f;
					pos.x -= collide_area.x;
				}
				else // �����ʿ��� �浹
				{
					speed *= -1.0f;
					pos.x += collide_area.x;
				}
			}
		}
		else
		{
		}
		break;
	default:
		break;
	}
}*/
