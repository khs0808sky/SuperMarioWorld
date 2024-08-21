#pragma once
class AnimateScene : public Scene
{
private:
	AnimatePlayer* player;
	Platform* obstackle;

	Platform* ground;

	vector<Platform*> platform_list; // 스테이지에 배치해두는 플랫폼을 정리한 리스트
	// 다만, 아래의 stage_list를 만든 시점에서 반드시 멤버로 만들어야 할 이유는 사라졌음
	
	vector<vector<Platform*>> stage_list; // 플랫폼이 배치되어 있는 스테이지 구성도를
	// vector<Platform*>라는 자료형을 다루는 벡터로서 다루는 리스트
	// 여기에 들어있는 원소(=vector<Platform*>)하나하나가 하나의 스테이지를 이룬다

	// 각각의 스테이지가 어떤 플랫폼으로 구성되어 있는지 편성한 후,
	// 현재 이 중 어느 스테이지를 사용할 것인지를 결정해 그 쪽만을 사용

	int stage;

	float fade_time;

	void change_stage(int stage);
public:
	AnimateScene();
	~AnimateScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void PostRender() override;

};
