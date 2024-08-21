#include "framework.h"
#include "Topography.h"

Topography::Topography(TOPOGRAPHY_NAME topography_name)
{
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Tileset.png";
	Texture* t = Texture::Add(file);

	Vector2 this_frame_size = { 16.0f, 16.0f };
	vector<Frame*> frames;
	Vector2 init_pos;

	switch (topography_name)
	{
	case Topography::TOPOGRAPHY_NAME::GROUND_1:
		init_pos = { 137, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_2:
		init_pos = { 18, 227 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_3:
		init_pos = { 154, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_4:
		init_pos = { 171, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_5:
		init_pos = { 69, 227 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_6:
		init_pos = { 188, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_7:
		init_pos = { 205, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_8:
		init_pos = { 120, 227 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_9:
		init_pos = { 222, 210 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::CLOUD_BLOCK:
		init_pos = { 103, 125 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::STONE_BLOCK:
		init_pos = { 103, 23 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK:
		init_pos = { 103, 74 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_LEFT:
		init_pos = { 52, 57 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_CENTER:
		init_pos = { 69, 57 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_RIGHT:
		init_pos = { 86, 57 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_LEFT:
		init_pos = { 52, 74 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_CENTER:
		init_pos = { 69, 74 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_RIGHT:
		init_pos = { 86, 74 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_LEFT:
		init_pos = { 52, 91 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_CENTER:
		init_pos = { 69, 91 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_RIGHT:
		init_pos = { 86, 91 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::UP_BRIDGE:
		init_pos = { 1, 57 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case Topography::TOPOGRAPHY_NAME::DOWN_BRIDGE:
		init_pos = { 1, 74 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	default:
		break;
	}

	// ================================================================
	switch (topography_name)
	{
	case Topography::TOPOGRAPHY_NAME::GROUND_5:
	case Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK:
	case Topography::TOPOGRAPHY_NAME::UP_BRIDGE:
		collider = new RectCollider(Vector2(32, 32));
		collider->pos = pos;
		collider->is_active = false;
		break;
	case Topography::TOPOGRAPHY_NAME::GROUND_1:
	case Topography::TOPOGRAPHY_NAME::GROUND_2:
	case Topography::TOPOGRAPHY_NAME::GROUND_3:
	case Topography::TOPOGRAPHY_NAME::GROUND_4:
	case Topography::TOPOGRAPHY_NAME::GROUND_6:
	case Topography::TOPOGRAPHY_NAME::GROUND_7:
	case Topography::TOPOGRAPHY_NAME::GROUND_8:
	case Topography::TOPOGRAPHY_NAME::GROUND_9:
	case Topography::TOPOGRAPHY_NAME::STONE_BLOCK:
		collider = new RectCollider(Vector2(32, 32));
		collider->pos = pos;
		collider->is_active = true;
		collider->SetColType(0); // 사방이 막힌 블록
		break;
	case Topography::TOPOGRAPHY_NAME::CLOUD_BLOCK:
	case Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_LEFT:
	case Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_CENTER:
	case Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_RIGHT:
	case Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_LEFT:
	case Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_CENTER:
	case Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_RIGHT:
	case Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_LEFT:
	case Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_CENTER:
	case Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_RIGHT:
	case Topography::TOPOGRAPHY_NAME::DOWN_BRIDGE:
		collider = new RectCollider(Vector2(32, 32));
		collider->pos = pos;
		collider->is_active = true;
		collider->SetColType(1); // 위에서 밟을 수 있는 블록
		break;
	default:
		break;
	}

	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();
}

Topography::~Topography()
{
	for (Clip* c : clips)
		delete c;

	delete collider;

	delete CB;
}

void Topography::Update()
{
	clips[(UINT)topography_name]->Update(); // 현재 재생해야 할 애니메이션을 업데이트

	scale = clips[(UINT)topography_name]->GetFrameSize() * 2.0f;
	WorldUpdate();
	collider->WorldUpdate();
	collider->pos = pos;
}

void Topography::Render()
{
	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	clips[(UINT)topography_name]->Render();
	collider->Render();
}
