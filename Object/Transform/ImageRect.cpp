#include "framework.h"

ImageRect::ImageRect(Vector2 pos, Vector2 size, Vector2 scale, float angle, Matrix* parent)
	: Transform(pos, scale, angle)
{
	image = new RectUV(size);

	ScratchImage img;
	// �� Ŭ������ �ν��Ͻ��� ���� �̹��� ������ �ε��ؿ� �����ϴ� ����

	LoadFromWICFile(L"Texture/Image/marioRocket.png", WIC_FLAGS_NONE, nullptr, img); // ���۸����� ����
	//LoadFromWICFile(L"Texture/Image/pixelSword.png", WIC_FLAGS_NONE, nullptr, img); // �ȼ� ��
	// �����ϴ� ������ �ҷ��� img�� �����ϴ� �Լ�
	// ����� ��������� img�� ���� �����

	CreateShaderResourceView(DEVICE, img.GetImages(), img.GetImageCount(), img.GetMetadata(), &srv);
	// ��� ���� srv�� DEVICE�� img�� �̿��� "���̴� ���ҽ� ��"��� ���� ����,
	// �̰� ���ؼ� ���̴��� ���� �����͸� ����
	// PixelUV.hlsl �ʿ��� �ٷ�� samp�� map ���� �ٷ�� ���� �ʿ��� ����
}

ImageRect::~ImageRect()
{
	delete image;
	srv->Release();
}

void ImageRect::Update()
{
	WorldUpdate();
}

void ImageRect::Render()
{
	WB->SetVS(0);
	DVC->PSSetShaderResources(0, 1, &srv);
	// ����̽� ���ؽ�Ʈ�� ���� �����Ͱ� ���ִ� ���̴� ���ҽ� �並 ���

	image->Render();
}
