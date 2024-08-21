#include "framework.h"
#include "GroundBackground.h"

GroundBackground::GroundBackground(BACKGROUND_TYPE type)
{
	background_type = type;

	wstring file = L"Texture/SuperMario/SuperMarioWorld_Background.png";
	Texture* t = Texture::Add(file);

	Vector2 this_frame_size = { 512.0f, 512.0f };
	vector<Frame*> frames; // 각 애니메이션들을 clips에 저장하기 위해 임시로 만든 자료구조
	Vector2 init_pos;

	switch (background_type)
	{
	case GroundBackground::BACKGROUND_TYPE::UP:
		// 위 배경 (하늘 부분)
		init_pos = { 514, 12 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GroundBackground::BACKGROUND_TYPE::DOWN:
		// 아래 배경 (땅 부분)
		init_pos = { 1, 12 };
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
}

GroundBackground::~GroundBackground()
{
	for (Clip* c : clips)
		delete c;

	delete CB;
}

void GroundBackground::Update()
{
	clips[0]->Update(); // 현재 재생해야 할 애니메이션을 업데이트

	scale = clips[0]->GetFrameSize() * 1.5f;
	WorldUpdate();
}

void GroundBackground::Render()
{

	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	clips[0]->Render();
}
