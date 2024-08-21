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

���� : �츰 �̷��� ImageRect�� ���ؼ� �̹����� ����غ���,
RectUV�� UV���� �ٲٴ� ������ � ������ �����ϴ��� ���� Ȯ���غ���

�̸� �����ؼ� "�ڵ������� ��ũ�ѵǴ� ���ȭ���� ���� ��"

������ ũ�� 2�� - ����̹����� �������� ���� ���ؼ� ����� ��
1) �¿� ��ũ��/���� ��ũ���� �������
�ڵ������� ���ȭ���� �����̱⸸ �ϸ� ��

2) ���ȭ�� ��ü�� ���� ȭ�鿡 �̹��� �ϳ� �з��� ���� ��
+ �ش� �������� ������ ��ũ�ѵǾ�� ��
����� ������ ���� �ڿ�������, ������ �ݺ��ǵ��� ���� ��

*/
