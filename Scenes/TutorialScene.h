#pragma once
class TutorialScene : public Scene
// Scene�� ��ӹ޾�, ������ ȭ���� ������ Scene
// ȭ���� �������� ������ ���⼭ ����
{
private:
	Triangle* list_triangle;
	Triangle* list_rect;
	
	Hexagon* list_hexagon[10] = {};
	Hexagon* line_hexagon;
	
	// ���� �� Ŭ�������� "�츮�� ����� �ϰ� �;� ���� ���� Ŭ����"��
	// ����ϰ� ���� ������ �ִٸ� �̸� ����ϴ� Ŭ������ ��ü�� ����� ������ ������ ����
	
public:
	// �Լ� ���� �־�� �� �Ͱ� ��ӹ��� �� �ܿ� �ٷ� �� ����
	TutorialScene();
	~TutorialScene();


	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

};