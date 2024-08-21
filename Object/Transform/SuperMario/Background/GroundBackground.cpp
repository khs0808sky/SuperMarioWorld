#include "framework.h"
#include "GroundBackground.h"

GroundBackground::GroundBackground(BACKGROUND_TYPE type)
{
	background_type = type;

	wstring file = L"Texture/SuperMario/SuperMarioWorld_Background.png";
	Texture* t = Texture::Add(file);

	Vector2 this_frame_size = { 512.0f, 512.0f };
	vector<Frame*> frames; // �� �ִϸ��̼ǵ��� clips�� �����ϱ� ���� �ӽ÷� ���� �ڷᱸ��
	Vector2 init_pos;

	switch (background_type)
	{
	case GroundBackground::BACKGROUND_TYPE::UP:
		// �� ��� (�ϴ� �κ�)
		init_pos = { 514, 12 };
		frames.push_back(new Frame(file, init_pos.x, init_pos.y,
			this_frame_size.x, this_frame_size.y));

		clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
		frames.clear();
		break;
	case GroundBackground::BACKGROUND_TYPE::DOWN:
		// �Ʒ� ��� (�� �κ�)
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
	clips[0]->Update(); // ���� ����ؾ� �� �ִϸ��̼��� ������Ʈ

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
