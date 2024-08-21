#include "framework.h"

ScrollingBG::ScrollingBG(Vector2 pos, Vector2 size, Vector2 scale, float angle, Matrix* parent)
	: size(size), speed(200.0f)
{
	image[0] = new Quad(L"Texture/Image/pixelBackground.jpg", Vector2(1, 1),
		Vector2(0, 0), Vector2(2, 1));
	image[1] = new Quad(L"Texture/Image/pixelBackground.jpg", Vector2(1, 1),
		Vector2(0, 0), Vector2(2, 1));
	// UV값을 지정하는 것으로 이미지를 몇 번 표기할 것인지 등을 결정
	// 자세한 건 저번에도 했듯 CreateSamplerState에 설명되어 있음

	image[0]->pos = pos;
	image[0]->scale = size / image[0]->Size();
	// 우리는 이 오브젝트를 배경화면으로서 쓰고자 하는 것이므로, 
	// 하나의 이미지는 기본적으로 화면을 꽉 채워야 함
	// 그러나 각 이미지의 scale이 1이라면 당연히 원래 이미지의 사이즈만큼만 출력되고 끝이므로,
	// 전체 화면에 맞게 출력하려면 그에 걸맞는 스케일 설정이 필요한 것
	// 이를 입력받은 사이즈(화면 전체 사이즈) / 사용하고자 하는 이미지의 크기

	image[1]->pos = pos + Vector2(size.x, 0);
	image[1]->scale = size / image[1]->Size();

	for (Quad* q : image)
		q->is_active = true;
}

ScrollingBG::~ScrollingBG()
{
	for (auto i : image)
		delete i;
}

void ScrollingBG::Update()
{
	for (Quad* q : image)
	{
		q->pos.x -= float(size.x) / 5.0f * DELTA;

		if (q->pos.x <= -size.x / 2.0f) // 현재 스크린이 화면을 완전히 나간 순간
			// = 이미지 전체 크기의 절반만큼의 거리만큼 이 이미지의 중심이 화면 왼쪽으로 나간 순간
			q->pos.x += size.x * 2;
	}

	for (Quad* q : image)
		q->WorldUpdate();

	// 사실 지금 상황에선 각각의 화면의 위치를 조정하는 것과 
	// 그렇게 업데이트된 데이터들을 월드 행렬에 반영시키는 것과 굳이 다른 순서로 실행될 필요가 없음
	// 그러나 다른 모든 배경의 위치를 업데이트 끝낸 뒤에
	// 최종적으로 월드 행렬에 반영시켜야 하는 경우가 있다보니
	// -> 각 이미지의 위치가 두 번 이상에 걸쳐서 결정되어야 하는 경우 등
	// 이런 경우를 대비해 일단은 분리시켜둔 것

	// 이렇게 Quad를 통해서 스크롤링을 구현해보니
	// 정점 자체의 데이터를 바꾸지 않고도 스크롤하는 것을 구현할 수 있었고,
	// 스크롤되는 형식이 약간 맘에 안드는 것을 그 자리에서 수치 살짝 조정해주는 것으로
	// 간단히 자연스럽게 만들 수 있었음
	// + 나중에 스크롤 방향 등을 바꾸고자 할 경우는, 혹은 회전까지 시켜야 할 경우는
	// 그냥 이 이미지들의 pos, rot 등을 이용하면 간단히 해결할 수 있음

	// 그래서 하나의 오브젝트가 여러 이미지를 이용해야 하는 경우는 Quad를 이용하면 더 쉽게 구축할 수 있음
	// (대신 이 Quad를 구축하는 데 시간이 더 많이 걸리기는 했지만, 쉽게 이용하기 위한 공사비로 여깁시다)
}

void ScrollingBG::Render()
{
	image[0]->Render();
	image[1]->Render();
}
