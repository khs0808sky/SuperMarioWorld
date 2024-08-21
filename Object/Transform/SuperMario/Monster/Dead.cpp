#include "framework.h"

Dead::Dead()
{
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Object2.png";
	Texture* t = Texture::Add(file);

	// ���� ����� ��������Ʈ�� ũ��
	Vector2 this_frame_size = { 16.0f, 16.0f };
	Vector2 init_pos;


	vector<Frame*> frames; // �� �ִϸ��̼ǵ��� clips�� �����ϱ� ���� �ӽ÷� ���� �ڷᱸ��

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
		this_frame_size.x, this_frame_size.y)); // �������� ������

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
	clips[0]->Update(); // ���� ����ؾ� �� �ִϸ��̼��� ������Ʈ
	

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
