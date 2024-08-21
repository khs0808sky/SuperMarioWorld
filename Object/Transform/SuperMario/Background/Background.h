#pragma once
class Background : public Transform
{
private:
	GroundBackground* groundBackground[6];

public:
	Background();
	~Background();

	void Update();
	void Render();
	void PostRender();

	void SetClear();
};