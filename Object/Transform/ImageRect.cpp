#include "framework.h"

ImageRect::ImageRect(Vector2 pos, Vector2 size, Vector2 scale, float angle, Matrix* parent)
	: Transform(pos, scale, angle)
{
	image = new RectUV(size);

	ScratchImage img;
	// 이 클래스의 인스턴스는 실제 이미지 파일을 로딩해와 저장하는 역할

	LoadFromWICFile(L"Texture/Image/marioRocket.png", WIC_FLAGS_NONE, nullptr, img); // 슈퍼마리오 로켓
	//LoadFromWICFile(L"Texture/Image/pixelSword.png", WIC_FLAGS_NONE, nullptr, img); // 픽셀 검
	// 실존하는 파일을 불러와 img에 저장하는 함수
	// 제대로 실행됐으면 img의 값이 변경됨

	CreateShaderResourceView(DEVICE, img.GetImages(), img.GetImageCount(), img.GetMetadata(), &srv);
	// 멤버 변수 srv에 DEVICE와 img를 이용해 "셰이더 리소스 뷰"라는 것을 생성,
	// 이걸 통해서 셰이더에 사진 데이터를 보냄
	// PixelUV.hlsl 쪽에서 다루는 samp와 map 등을 다루기 위해 필요한 내용
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
	// 디바이스 컨텍스트에 사진 데이터가 들어가있는 셰이더 리소스 뷰를 등록

	image->Render();
}
