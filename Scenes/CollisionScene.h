#pragma once
class CollisionScene : public Scene
{
private:
	RectCollider* player;
	RectCollider* obstackle;

	CircleCollider* circle;

	Missile* m;
public:
	CollisionScene();
	~CollisionScene();


	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;

	virtual void Render() override;


	// Scene��(��) ���� ��ӵ�
	virtual void PostRender() override;

};
