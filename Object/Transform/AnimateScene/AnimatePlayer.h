#pragma once
class AnimatePlayer : public Transform
{
private:
	enum class CHAR_STATUS
	{
		IDLE, WALK, RUN
	} action_status; // 이 캐릭터의 현재 상태를 가리키는 열거형
	// 이 열거형을 통해 이 인스턴스의 "상태"를 규정,
	// 각 상태마다 같은 명령이 들어와도 다른 작업 혹은 다른 결과물을 내도록 하는 식으로
	// 프로그램을 구성하는 디자인 패턴을
	// "유한 상태 머신"이라고 부름

	// 이를 이용해서 같은 키를 입력했을 때의 실제 상호작용이나 출력되는 애니메이션 등을 관리

	/* 이 각각에 사용될 애니메이션들을 직접 편성하여 만들어볼 것*/

	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;
	RectCollider* collider;

	bool is_looking_left;

	/*
	Q. 점프를 어떻게 구현할 것인가?
	A. Y축을 움직여서 점프 높이만큼 올렸다가 내릴 것

	Q. 그렇다면, 올렸다가 내렸다라고 하는데
	어디까지 "올라갔는지"는 그냥 점프의 힘을 결정해주면 되니 별 필요 없음
	하지만, 어디까지 "내려가는지"는 어떻게 정해야 할까?
	A. 제자리인 경우 점프했던 높이만큼 내려오면 끝나는 것으로 한다
	제자리가 아니라면 "땅"에 닿았을 때 멈추도록 한다

	Q. 그러면 지금 테스트하고 있는 이 씬에서는 어떻게 바닥이라는 개념이 만들어지지 않은 상황인데,
	어떻게 그 바닥에 닿았다라는 것을 체크할 것인가?
	A. 바닥을 만들면 되지 않는가?

	Q. 그 바닥을 지금 만들 수가 없는 상황
	그러면 이 상황에서 점프가 제대로 작동하는지만이라도 테스트를 해보고 싶으면
	어떤 식으로 만들어야 할까?
	A. 아예 점프를 통해서 이동할 수 있는 총 거리에 제한을 두는 것도 생각해볼 수 있음

	이제 점프를 구현하는 데 필요한 내용들을 생각해봐야 함

	1. 점프하는 힘 - 얼마만큼 점프할 것인지를 지정해줘야 하므로
	다만 이는 멤버로서 구현하는 것도 가능은 하겠으나,
	멤버로 구현하지 않고 Update에서 직접 처리하는 방법도 있다
	이렇게 하면 멤버를 추가적으로 만들지 않고 끝낼 수 있음

	2. 점점 점프의 속도를 줄여나가는 힘 = 중력의 정의가 필요
	그런데 이 중력이라고 하는 건 플레이어에게만 적용되는 것이 아니라
	게임판 안에 있는 대부분의 오브젝트에는 적용되어야 하니
	이 AnimatePlayer 클래스 내부에서 만들어두고 이를 다른 클래스에서 참조하도록 만드는 것은
	중력을 바꿔야 할 때 이 클래스로 돌아와야 한다 & 귀찮게 접근자 등을 통해 접근해야 하는 등
	여러 문제가 있음
	따라서 여기가 아닌 미리 컴파일된 헤더 쪽에 저장해둬야 할 내용

	3. 어디까지 하강할 것인지를 결정하는 뭔가가 필요함
	여기서는 "점프한 총 높이"를 기록하는 멤버를 하나 만들어둠
	*/

	float jump_speed; // 현재 점프 속도
	float jump_height; // 현재 점프 높이

public:
	AnimatePlayer();
	~AnimatePlayer();

	RectCollider* GetCollider() { return collider; }

	void Update();
	void Render();
	void PostRender();

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}

	void SetClip(CHAR_STATUS stat);
	
	/// <summary>
	/// 어느 방향에서 충돌했는지에 따라 그에 걸맞는 점프 중 충돌 시의 행동을 처리하는 함수
	/// </summary>
	/// <param name="dir">충돌한 방향, 0~3까지 각각 캐릭터의 아래/위/왼쪽/오른쪽</param>
	void JumpCollide(UINT dir); 
};
