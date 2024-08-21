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


	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;


	// Scene을(를) 통해 상속됨
	virtual void PostRender() override;

};
