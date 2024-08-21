#pragma once
class TutorialScene : public Scene
// Scene을 상속받아, 실제로 화면을 구성한 Scene
// 화면의 실질적인 구성은 여기서 수행
{
private:
	Triangle* list_triangle;
	Triangle* list_rect;
	
	Hexagon* list_hexagon[10] = {};
	Hexagon* line_hexagon;
	
	// 위의 두 클래스들은 "우리가 출력을 하고 싶어 만든 도형 클래스"들
	// 출력하고 싶은 도형이 있다면 이를 담당하는 클래스의 객체를 멤버로 가지는 식으로 구성
	
public:
	// 함수 쪽은 있어야 할 것과 상속받은 것 외엔 다룰 게 없음
	TutorialScene();
	~TutorialScene();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

};