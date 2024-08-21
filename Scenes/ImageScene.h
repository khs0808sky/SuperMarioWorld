#pragma once
class ImageScene : public Scene
{
private:
	ScrollingBG* BG;

public:
	ImageScene();
	~ImageScene();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;


	// Scene을(를) 통해 상속됨
	virtual void PostRender() override;

};
