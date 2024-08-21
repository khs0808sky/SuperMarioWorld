#include "framework.h"

Ground::Ground(GROUND_TYPE type)
{
	ground_type = type;
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Tileset.png";
	Texture* t = Texture::Add(file);

	Vector2 this_frame_size = { 16.0f, 16.0f };
	vector<Frame*> frames; // 각 애니메이션들을 clips에 저장하기 위해 임시로 만든 자료구조
	Vector2 init_pos;

	// □□□ 1 2 3
	// □□□ 4 5 6
	// □□□ 7 8 9

	switch (ground_type)
	{
	case GROUND_TYPE::TILE_1: // ┌  (위 왼)
		init_pos = { 137, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GROUND_TYPE::TILE_2: //  ─ (위)
		init_pos = { 18, 227 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GROUND_TYPE::TILE_3: //  ┐ (위 오른)
		init_pos = { 154, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GROUND_TYPE::TILE_4: //│   (왼)
		init_pos = { 171, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break; 
	case GROUND_TYPE::TILE_5: // ■  (내부)
		init_pos = { 69, 227 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GROUND_TYPE::TILE_6: //  │ (오른)
		init_pos = { 188, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GROUND_TYPE::TILE_7: // └  (아래 왼)
		init_pos = { 205, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GROUND_TYPE::TILE_8: // ─  (아래)
		init_pos = { 120, 227 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GROUND_TYPE::TILE_9: //  ┘ (아래 오른)
		init_pos = { 222, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	default:
		break;
	}

	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();
	
	switch (ground_type)
	{
	case Ground::GROUND_TYPE::TILE_1:
	case Ground::GROUND_TYPE::TILE_2:
	case Ground::GROUND_TYPE::TILE_3:
	case Ground::GROUND_TYPE::TILE_4:
	case Ground::GROUND_TYPE::TILE_6:
	case Ground::GROUND_TYPE::TILE_7:
	case Ground::GROUND_TYPE::TILE_8:
	case Ground::GROUND_TYPE::TILE_9:
		collider = new RectCollider(Vector2(32, 32));
		collider->pos = pos;
		collider->is_active = true;
		break;
	case Ground::GROUND_TYPE::TILE_5:
		collider = new RectCollider(Vector2(32, 32));
		collider->pos = pos;
		collider->is_active = false;
		break;
	default:
		break;
	}
}

Ground::~Ground()
{
	for (Clip* c : clips)
		delete c;

	delete collider;

	delete CB;
}

void Ground::Update()
{
	clips[0]->Update(); // 현재 재생해야 할 애니메이션을 업데이트

	scale = clips[0]->GetFrameSize() * 2.0f;
	WorldUpdate();
	collider->WorldUpdate();
	collider->pos = pos;
}

void Ground::Render()
{
	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	clips[0]->Render();
	collider->Render();
}
