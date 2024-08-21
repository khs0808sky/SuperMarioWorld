#include "framework.h"

Dead::Dead()
{
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Object2.png";
	Texture* t = Texture::Add(file);

	// 현재 사용할 스프라이트의 크기
	Vector2 this_frame_size = { 16.0f, 16.0f };
	Vector2 init_pos;


	vector<Frame*> frames; // 각 애니메이션들을 clips에 저장하기 위해 임시로 만든 자료구조

	init_pos = { 777, 453 };
	frames.push_back(new Frame(file, init_pos.x, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 794.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 811.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 828.0f, init_pos.y,
		this_frame_size.x, this_frame_size.y));
	frames.push_back(new Frame(file, 86.0f, 350.0f,
		this_frame_size.x, this_frame_size.y)); // 투명으로 끝나게

	clips.push_back(new Clip(frames, Clip::CLIP_TYPE::END, 1.0f / 15.0f));
	frames.clear();

	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();
}

Dead::~Dead()
{
	for (Clip* c : clips)
		delete c;

	delete CB;
}

void Dead::Update()
{
	clips[0]->Update(); // 현재 재생해야 할 애니메이션을 업데이트
	

	scale = clips[0]->GetFrameSize() * 2.0f;
	WorldUpdate();
}

void Dead::Render()
{
	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	clips[0]->Render();
}
