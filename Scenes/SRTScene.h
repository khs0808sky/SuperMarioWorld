#pragma once
class SRTScene : public Scene
{
private:
	MatrixBuffer* world;

	SRTTriangle* triangle;
	NewTriangle* newt;
	NewTriangle* newt2;
	// NewTriangle *newt, *newt2;

	NewCircle* c1, * c2 , * c3, * c4;
	NewCircle* stub1, * stub2, * stub3;

	bool is_pause;

public:
	SRTScene();
	~SRTScene();


	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;


	// Scene��(��) ���� ��ӵ�
	virtual void PostRender() override;

};