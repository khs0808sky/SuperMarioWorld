#pragma once
class ImageScene : public Scene
{
private:
	ScrollingBG* BG;

public:
	ImageScene();
	~ImageScene();


	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;


	// Scene��(��) ���� ��ӵ�
	virtual void PostRender() override;

};
