#include "framework.h"

ImageScene::ImageScene()
{
	BG = new ScrollingBG(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(WIN_WIDTH, WIN_HEIGHT));
}

ImageScene::~ImageScene()
{
	delete BG;
}

void ImageScene::Update()
{
	BG->Update();
}

void ImageScene::Render()
{
	BG->Render();
}

void ImageScene::PostRender()
{
}

/*

과제 : 우린 이렇게 ImageRect를 통해서 이미지를 출력해보고,
RectUV의 UV값을 바꾸는 것으로 어떤 식으로 도배하는지 등을 확인해봤음

이를 응용해서 "자동적으로 스크롤되는 배경화면을 만들어볼 것"

조건은 크게 2개 - 배경이미지는 여러분이 직접 구해서 사용할 것
1) 좌우 스크롤/상하 스크롤은 상관없음
자동적으로 배경화면이 움직이기만 하면 됨

2) 배경화면 자체는 현재 화면에 이미지 하나 분량만 들어가야 함
+ 해당 방향으로 끝없이 스크롤되어야 함
끊기는 느낌이 없이 자연스럽게, 무한히 반복되도록 만들 것

*/
