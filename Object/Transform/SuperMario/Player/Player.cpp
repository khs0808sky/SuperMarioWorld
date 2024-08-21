#include "framework.h"

Player::Player()
{
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Character.png";
	Texture* t = Texture::Add(file);

	// 현재 사용할 스프라이트의 크기
	Vector2 this_frame_size = { 32.0f, 32.0f };
	Vector2 init_pos;


	vector<Frame*> frames; // 각 애니메이션들을 clips에 저장하기 위해 임시로 만든 자료구조

	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::IDLE〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 1, 233 };  // 일반
			//init_pos = { 1, 22 }; // 미니
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::UP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 38, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::CROUCH〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 75, 233 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::WALK〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 145, 233 };
		// 2번째 장면부터
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));
		// 이후엔 1번째 장면부터 -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 211.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 14.0f));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::RUN〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 248, 233 };
		// 2번째 장면부터
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		// 이후엔 1번째 장면부터 -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 314.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::SKID〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 351, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::JUMP_UP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 388, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::JUMP_DOWN〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 421, 233 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::CROUCH_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 108, 233 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::RUN_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 458, 233 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::SPIN_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 528, 233 }; // 일반
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
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::KICK〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 388, 343 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_IDLE〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 1, 22 }; // 미니
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_UP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 38, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_CROUCH〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 75, 22 }; // 미니
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_WALK〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 145, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 14.0f));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_RUN〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 215, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 248.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_SKID〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 285, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_JUMP_UP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 322, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_JUMP_DOWN〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 355, 22 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_CROUCH_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 108, 22 }; // 미니
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_RUN_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 392, 22 }; // 미니
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_SPIN_JUMP〓〓〓〓〓〓〓〓〓〓
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
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::MINI_KICK〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 355, 132 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_IDLE〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 1, 514 };  // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_UP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 38, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_CROUCH〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 75, 514 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_WALK〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 145, 514 };
		// 2번째 장면부터
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		// 이후엔 1번째 장면부터 -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 178.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 211.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 14.0f));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_RUN〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 248, 514 };
		// 2번째 장면부터
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		// 이후엔 1번째 장면부터 -> 2 1 2 3...
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 281.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 314.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 28.0f));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_SKID〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 351, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_JUMP_UP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 388, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_JUMP_DOWN〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 421, 514 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_CROUCH_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 108, 514 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_RUN_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 458, 514 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_SPIN_JUMP〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 528, 514 }; // 일반
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
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_KICK〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 388, 624 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::FIRE_ATTACK〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 346, 569 }; // 일반
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
	}
	//〓〓〓〓〓〓〓〓〓〓PLAYER_STATUS::DEAD〓〓〓〓〓〓〓〓〓〓
	{
		init_pos = { 243, 77 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));
		frames.push_back(new Frame(file, 276.0f, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP, 1.0f / 3.0f));
		frames.clear();
	}

	//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();

	collider[0] = new RectCollider(Vector2(28, 48)); // 일반 평상시
	collider[1] = new RectCollider(Vector2(28, 24)); // 일반 쭈그림
	collider[2] = new RectCollider(Vector2(28, 32)); // 미니 평상시
	collider[3] = new RectCollider(Vector2(28, 20)); // 미니 쭈그림

	for (auto col : collider)
	{
		col->pos = pos;
		col->is_active = false;
	}

	player_pow = PLAYER_POW::FIRE;
	player_status = PLAYER_STATUS::JUMP_DOWN;

	is_looking_right = true; // 기본상태는 오른쪽이기 때문에 true입력
	is_ground = false;

	is_hit = false;
	is_change = false;
	is_dead = false;
	is_invincible = false;

	invincible_time = 2.0f;
	dead_stop_time = 1.0f;

	max_walk_speed = 175.0f; // 최대 걷기 스피드
	max_run_speed = 350.0f;

	speed = 0.0f; // 초기 스피드
	acceleration = 500.0f; // 가속도 설정 -> 가속도 = 힘의 총량 / 질량
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

	// 플레이어는 매순간 중력의 영향을 받음
	jump_speed += (gravity * 13.0f) * DELTA;

	if (jump_speed > max_jump_speed)
	{
		jump_speed = max_jump_speed;
	}

	// 튀는 현상을 조금 안정화
	if (is_ground && jump_speed > 0.0f)
	{
		jump_speed -= (gravity * 13.0f) * DELTA - 1.0f;
		//jump_speed -= 1.0f;
	}

	// Press : 누르고 있는 동안에만
	// Down : 한 번 눌렀을 때
	// Up : 한 번 떼졌을 때
	switch (player_status)
	{
		//〓〓〓〓〓〓〓〓〓〓가만히 있는 상태〓〓〓〓〓〓〓〓〓〓
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

		if (jump_speed > 20.0f) // 낙하중이면 (오류계산해서 20으로 넉넉하게)
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
		//##########점프 키##########
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

		//##########스핀점프 키##########
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
		//〓〓〓〓〓〓〓〓〓〓위를 보고있는 상태〓〓〓〓〓〓〓〓〓〓
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

		if (jump_speed > 20.0f) // 낙하중이면 (오류계산해서 20으로 넉넉하게)
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
		//##########점프 키##########
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

		//##########스핀점프 키##########
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
		//〓〓〓〓〓〓〓〓〓〓쭈그리고 있는 상태〓〓〓〓〓〓〓〓〓〓
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

		if (jump_speed > 20.0f) // 낙하중이면 (오류계산해서 20으로 넉넉하게)
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
		//##########점프 키##########
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

		//##########스핀점프 키##########
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
		//〓〓〓〓〓〓〓〓〓〓걷고 있는 상태〓〓〓〓〓〓〓〓〓〓
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

		if (jump_speed > 20.0f) // 낙하중이면 (오류계산해서 20으로 넉넉하게)
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

		//##########아래쪽 키##########
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

		//##########왼쪽 키##########
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
					// 최대 걷기 속도까지
				{
					// 속도 = 가속도 * 시간
					speed -= (acceleration * 1.5f) * DELTA; // 속도 점차 증가 (이 방식이 맞는진 모르겠음)(가속)
				}
				else if (speed <= -max_walk_speed) // 가속하다가 속도를 줄였을 때
				{
					speed += deceleration * DELTA; // 점점 속도를 줄이다가(감속)

					if (speed >= -max_walk_speed) // 속도가 일정 속도보다 조금 줄었다면
					{
						speed = -max_walk_speed; // 속도를 맞춤
					}
				}
			}
			else if (KEY_CON->Press('C'))
			{
				if (speed > -max_walk_speed)
					// 최대 걷기 속도까지
				{
					speed -= (acceleration * 1.5f) * DELTA; // 속도 점차 증가 (이 방식이 맞는진 모르겠음) (가속)
				}
				else if (speed <= -max_walk_speed && speed > -max_run_speed)
					// 최대 걷기 속도 이후에는 최대 달리기 속도에 도달할 때까지
				{
					speed -= (acceleration / 2.0f) * DELTA; // 속도를 점점 증가 (가속)
				}
				else if (speed <= max_run_speed)
					// 소수점이 조금 넘어섰다면
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
		//##########오른쪽 키##########
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
					// 최대 걷기 속도까지
				{
					speed += (acceleration * 1.5f) * DELTA; // 속도 점차 증가 (이 방식이 맞는진 모르겠음)(가속)
				}
				else if (speed >= max_walk_speed) // 가속하다가 속도를 줄였을 때
				{
					speed -= deceleration * DELTA; // 점점 속도를 줄이다가(감속)

					if (speed <= max_walk_speed) // 속도가 일정 속도보다 조금 줄었다면
					{
						speed = max_walk_speed; // 속도를 맞춤
					}
				}
			}
			else if (KEY_CON->Press('C'))
			{
				if (speed < max_walk_speed)
					// 최대 걷기 속도까지
				{
					speed += (acceleration * 1.5f) * DELTA; // 속도 점차 증가 (이 방식이 맞는진 모르겠음)(가속)
				}
				else if (speed >= max_walk_speed && speed < max_run_speed)
					// 최대 걷기 속도 이후에는 최대 달리기 속도에 도달할 때까지
				{
					speed += (acceleration / 2.0f) * DELTA; // 속도를 점점 증가(가속)
				}
				else if (speed >= max_run_speed)
					// 소수점이 조금 넘어섰다면
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
		//##########점프 키##########
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

		//##########스핀점프 키##########
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

		//##########방향키 입력안함##########
		if (!KEY_CON->Press(VK_LEFT) && !KEY_CON->Press(VK_RIGHT))
		{
			if (speed < 0)
			{
				if (is_looking_right) // 이 경우는 반대방향키로 잠깐 미끄러지고(SKID)후 바로 키를 뗐을 때
				{
					speed += (deceleration * 2.0f) * DELTA; //(감속)
				}
				else // 이 경우는 그냥 아무 키도 누르지 않았을 때
				{
					speed += deceleration * DELTA; //(감속)
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
				if (!is_looking_right) // 이 경우는 반대방향키로 잠깐 미끄러지고(SKID)후 바로 키를 뗐을 때
				{
					speed -= (deceleration * 2.0f) * DELTA; //(감속)
				}
				else // 이 경우는 그냥 아무 키도 누르지 않았을 때
				{
					speed -= deceleration * DELTA; //(감속)
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
		//〓〓〓〓〓〓〓〓〓〓달리고 있는 상태〓〓〓〓〓〓〓〓〓〓
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

		if (jump_speed > 20.0f) // 낙하중이면 (오류계산해서 20으로 넉넉하게)
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

		//##########아래쪽 키##########
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

		//##########점프 키##########
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

		//##########스핀점프 키##########
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

		//##########왼쪽 키##########
		if (KEY_CON->Press(VK_LEFT))
		{
			if (speed > 0) // 오른쪽으로 가고있었는데 왼쪽 키를 누를 때
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
		//##########오른쪽 키##########
		else if (KEY_CON->Press(VK_RIGHT))
		{
			if (speed < 0) // 왼쪽으로 가고있었는데 오른쪽 키를 누를 때
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

		//##########방향키 입력안함##########
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

		//##########대쉬 키 입력안함##########
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
		//〓〓〓〓〓〓〓〓〓〓미끄러지고 있는 상태〓〓〓〓〓〓〓〓〓〓
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

		if (jump_speed > 20.0f) // 낙하중이면 (오류계산해서 20으로 넉넉하게)
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

		//##########점프 키##########
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


		//##########스핀점프 키##########
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

		// 왼쪽으로 이동 중 
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
				speed += (deceleration * 3.0f) * DELTA; //(감속)
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
		// 오른쪽으로 이동 중
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
				speed -= (deceleration * 3.0f) * DELTA; //(감속)
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
		//〓〓〓〓〓〓〓〓〓〓위로 점프 중에 있는 상태〓〓〓〓〓〓〓〓〓〓
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
		//〓〓〓〓〓〓〓〓〓〓아래로 떨어지고 있는 상태〓〓〓〓〓〓〓〓〓〓
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
		//〓〓〓〓〓〓〓〓〓〓쭈그려서 점프〓〓〓〓〓〓〓〓〓〓
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
		//〓〓〓〓〓〓〓〓〓〓달려서 점프〓〓〓〓〓〓〓〓〓〓
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
		//〓〓〓〓〓〓〓〓〓〓스핀점프〓〓〓〓〓〓〓〓〓〓
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
		//〓〓〓〓〓〓〓〓〓〓발차기〓〓〓〓〓〓〓〓〓〓
	case PLAYER_STATUS::KICK:
	case PLAYER_STATUS::MINI_KICK:
	case PLAYER_STATUS::FIRE_KICK:
		break;
		//〓〓〓〓〓〓〓〓〓〓불덩이공격〓〓〓〓〓〓〓〓〓〓
	case PLAYER_STATUS::FIRE_ATTACK:
		break;
		//〓〓〓〓〓〓〓〓〓〓죽음〓〓〓〓〓〓〓〓〓〓
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
		//〓〓〓〓〓〓〓〓〓〓DEFAULT〓〓〓〓〓〓〓〓〓〓
	default:
		break;
	}
	clips[(UINT)player_status]->Update(); // 현재 재생해야 할 애니메이션을 업데이트

	scale = clips[(UINT)player_status]->GetFrameSize() * 2.0f;


	if (!is_looking_right)
	{
		scale.x *= -1;
	}

	// 각 상태마다 충돌판정 범위 설정
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

	// 우선 전체를 false로 바꾼 후
	for (auto col : collider)
	{
		col->is_active = false;
	}
	// 활성화 된 collider만 true로 설정
	collider[col_cursor]->is_active = true;

	if (player_status == PLAYER_STATUS::DEAD)
		collider[col_cursor]->is_active = false;

	
	// 각 상태별 땅에 있는지의 여부
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

	// 플레이어 이동관련
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

	// 플레이어 피격 판정과 무적시간
	// 피격 후
	

	WorldUpdate(); // 이 오브젝트가 가진 트랜스폼의 모든 정보가 전부 확정됐으면
	// 이를 이용해 월드업데이트


	// 이 오브젝트의 월드가 확정됐다면 이에 따라 충돌판정 역시 월드업데이트
	collider[0]->pos = pos + Vector2(0, 6); // 일반 평상시
	collider[1]->pos = pos + Vector2(0, 18); // 일반 쭈그림
	collider[2]->pos = pos + Vector2(0, 14); // 미니 평상시
	collider[3]->pos = pos + Vector2(0, 20); // 미니 쭈그림

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
	if (player_status != stat) // 이 함수에 입려된 스탯이 현 시점의 스탯과 동일한지 검사
		// 동일하지 않다면 이 오브젝트의 상태를 바꾸는 코드를 실행함
	{
		switch (stat) // 입력받은 상태에 따라 다른 작업을 하도록 분기
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
				//speed += deceleration * DELTA; // 점핑 중엔 감속 없음

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
				/*speed -= deceleration * DELTA;*/ // 점핑 중엔 감속 없음

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

// 지형 충돌 관련
void Player::TopographyCollide(RectCollider* obj)
{
	Vector2 collide_area;
	switch (obj->GetColType())
	{
	case 0: // 사방이 막힌 벽
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // 어느 방향이던 충돌을 했을 때
		{
			obj->SetColor(1, 0, 0); // 빨간색으로 바꿈
			if (collide_area.x >= collide_area.y) // x축이 y축보다 길때 (위 or 아래에서 충돌)
			{
				if (pos.y < obj->pos.y) // 위에서 충돌
				{
					jump_speed = 0.0f;
					pos.y -= collide_area.y;
					is_ground = true;
				}
				else // 아래에서 충돌
				{
					jump_speed = 0.0f;
					pos.y += collide_area.y;
				}
			}
			else // x축이 y축보다 짧을 때 (왼쪽 or 오른쪽에서 충돌)
			{
				if (collide_area.y < 0.1f)
				{
					break;
				}
				if (pos.x < obj->pos.x) // 왼쪽에서 충돌
				{
					speed = 0.0f;
					pos.x -= collide_area.x;
				}
				else // 오른쪽에서 충돌
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
	case 1: // 위에서만 밟을 수 있는 반벽
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // 어느 방향이던 충돌을 했을 때
		{
			obj->SetColor(1, 0, 0); // 빨간색으로 바꿈

			if (collide_area.x > collide_area.y) // x축이 y축보다 길때 (위 or 아래에서 충돌)
			{
				if (pos.y < obj->pos.y) // 위에서 충돌
				{
					if ((pos.y + (46.0f - 4.5f) < obj->pos.y) && jump_speed >= 0.0f)// obj의 위쪽 거의 끝부분에 있을 때
						// -4.0f인 이유는 이거보다 -4보다 크면 간혹 반벽을 뚫고 내려감
					{
						jump_speed = 0.0f;
						pos.y -= collide_area.y;
						is_ground = true;
					}
				}
				else // 아래에서 충돌
				{
				}
			}
			else
			{
				if (pos.x < obj->pos.x) // 왼쪽에서 충돌
				{
				}
				else // 오른쪽에서 충돌
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

// 몬스터 충돌 관련
void Player::MonsterCollide(RectCollider* obj)
{
	Vector2 collide_area;
	switch (obj->GetColType())
	{
	case 0: // 일반적인 몬스터 (위에서는 밟을 수 있음)
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // 어느 방향이던 충돌을 했을 때
		{
			if (collide_area.x >= collide_area.y) // x축이 y축보다 길때 (위 or 아래에서 충돌)
			{
				if (pos.y < obj->pos.y) // 위에서 충돌
				{
					obj->SetColor(1, 0, 0); // 빨간색으로 바꿈
					// 위에서 떨어질 때만 적용
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
				else // 아래에서 충돌
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
			else // x축이 y축보다 짧을 때 (왼쪽 or 오른쪽에서 충돌)
			{
				if (pos.x < obj->pos.x) // 왼쪽에서 충돌
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
				else // 오른쪽에서 충돌
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
	case 1: // 일반적인 뒤집어진 몬스터
	{
		if (GetCollider()->isCollision(obj, &collide_area)) // 어느 방향이던 충돌을 했을 때
		{
			if (collide_area.x >= collide_area.y) // x축이 y축보다 길때 (위 or 아래에서 충돌)
			{
				if (pos.y < obj->pos.y) // 위에서 충돌
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
				else // 아래에서 충돌
				{
					GetCollider()->SetColor(1, 0, 0);
				}
			}
			else // x축이 y축보다 짧을 때 (왼쪽 or 오른쪽에서 충돌)
			{
				if (pos.x < obj->pos.x) // 왼쪽에서 충돌
				{
					GetCollider()->SetColor(1, 0, 0);
				}
				else // 오른쪽에서 충돌
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
	case 2: // 밟을 수 없는 몬스터
		if (GetCollider()->isCollision(obj, &collide_area)) // 어느 방향이던 충돌을 했을 때
		{
			if (collide_area.x >= collide_area.y) // x축이 y축보다 길때 (위 or 아래에서 충돌)
			{
				if (pos.y < obj->pos.y) // 위에서 충돌
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
				else // 아래에서 충돌
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
			else // x축이 y축보다 짧을 때 (왼쪽 or 오른쪽에서 충돌)
			{
				if (pos.x < obj->pos.x) // 왼쪽에서 충돌
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
				else // 오른쪽에서 충돌
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