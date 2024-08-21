#include "framework.h"

CloudBlock::CloudBlock()
{
	wstring file = L"Texture/SuperMario/SuperMarioWorld_Object.png";
	Texture* t = Texture::Add(file);

	// ���� ����� ��������Ʈ�� ũ��
	Vector2 this_frame_size = { 16.0f, 16.0f };
	vector<Frame*> frames;


	Vector2 init_pos = { 120, 52 };
	frames.push_back(new Frame(file, init_pos.x, init_pos.y,
		this_frame_size.x, this_frame_size.y));

	clips.push_back(new Clip(frames, Clip::CLIP_TYPE::LOOP));
	frames.clear();

	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");
	CB = new ColourBuffer();

	//collider = new RectCollider(Vector2(32, 1));
	collider = new RectCollider(Vector2(32, 32));
	collider->pos = pos;
	collider->is_active = true;
}

CloudBlock::~CloudBlock()
{
	for (Clip* c : clips)
		delete c;

	delete collider;

	delete CB;
}

void CloudBlock::Update()
{
	clips[0]->Update(); // ���� ����ؾ� �� �ִϸ��̼��� ������Ʈ

	scale = clips[0]->GetFrameSize() * 2.0f;
	WorldUpdate();
	collider->WorldUpdate();
	//collider->pos = pos - Vector2(0, 15);
	collider->pos = pos;

}

void CloudBlock::Render()
{
	VS->Set();
	PS->Set();

	WB->SetVS(0);
	CB->SetPS(0);

	// �浹 �� �Ⱥ��̰� �Ҷ��
	// if (collider->is_active) �߰�
	clips[0]->Render();

	collider->Render();
}
