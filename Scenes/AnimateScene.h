#pragma once
class AnimateScene : public Scene
{
private:
	AnimatePlayer* player;
	Platform* obstackle;

	Platform* ground;

	vector<Platform*> platform_list; // ���������� ��ġ�صδ� �÷����� ������ ����Ʈ
	// �ٸ�, �Ʒ��� stage_list�� ���� �������� �ݵ�� ����� ������ �� ������ �������
	
	vector<vector<Platform*>> stage_list; // �÷����� ��ġ�Ǿ� �ִ� �������� ��������
	// vector<Platform*>��� �ڷ����� �ٷ�� ���ͷμ� �ٷ�� ����Ʈ
	// ���⿡ ����ִ� ����(=vector<Platform*>)�ϳ��ϳ��� �ϳ��� ���������� �̷��

	// ������ ���������� � �÷������� �����Ǿ� �ִ��� ���� ��,
	// ���� �� �� ��� ���������� ����� �������� ������ �� �ʸ��� ���

	int stage;

	float fade_time;

	void change_stage(int stage);
public:
	AnimateScene();
	~AnimateScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;

	virtual void PostRender() override;

};
