#include "framework.h"

Clip::Clip(vector<Frame*> frames, CLIP_TYPE t, float fps)
	: frames(frames), repeat_type(t), fps(fps),
	cur_frame_num(0), is_play(true), is_reverse(false), time(0.0f)
{
}

Clip::~Clip()
{
	for (auto frame : frames)
		delete frame;
	// 클립에 프레임을 등록한 뒤로는 클립 외에서는 이 프레임들에 접근할 방안이 없으며,
	// 기본적으로 프레임은 동적 할당으로 생성한 것이므로
	// 이 클립이 할당 해제될 때 이 프레임들 역시 할당 해제를 해줘야 함
}

void Clip::Update()
{
	if (!is_play) return;
	// 현재 재생중인 클립이 아니라면 재생 상황 관련 업데이트를 할 필요가 없으니 그대로 종료

	time += DELTA;
	// 애니메이션은 시간 경과에 따라서 현재 컷에서 다음 컷으로 교체하는 것을 반복하는 것으로
	// 그림이 움직이는 것처럼 연출해줘야 하므로,
	// 다음 그림으로 교체하기까지 남은 시간을 카운팅해줘야 함
	if (time <= fps) return; // 교체까지 아직 시간이 남았다면 아무것도 실행하지 않고 종료

	// 전부 통과했다면, 그 때부터는 다음 컷으로 교체하는 작업을 수행	
	switch (repeat_type) // 타입에 따라서 교체하는 컷의 순서가 달라질 수 있으므로
		// 그에 맞게 분기문으로 진행
	{
	case Clip::CLIP_TYPE::END: // 마지막 컷까지 다 재생되면 종료
		cur_frame_num++;
		if (cur_frame_num >= frames.size()) // 이 프레임이 가진 모든 컷을 전부 재생하고,
			// 인덱스가 마지막 프레임의 뒤쪽을 가리킬 경우
		{
			cur_frame_num--; // 무슨 에러가 발생할 지 모르니,
			// 일단은 frames에 저장된 범위 내부로 값을 돌리고
			Stop(); // 이 클립이 재생을 중단하는 작업을 시행
		}
		break;
	case Clip::CLIP_TYPE::LOOP: // 마지막 컷까지 다 재생되면 첫 컷으로 돌아가 다시 재생
		/*cur_frame_num++;
		if (cur_frame_num >= frames.size())
		{
			cur_frame_num == 0; 
		} // 이렇게 모든 재생이 끝났으면 처음 프레임으로 돌아가도록 만드는 것
		*/
		++cur_frame_num %= frames.size();
		// 직관적으로 하자면 위쪽 코드도 가능하겠으나,
		// mod 연산을 통해 총 프레임 개수 범위 내부를 항상 루프하는 식으로 한 줄로 줄일 수 있다
		// mod 연산 : 어떤 수 m을 기준으로 하여, 두 개의 수를 m으로 나눴을 때 그 나머지가 같다면
		// "합동"이라고 판단하는 연산
		// 간단히 말해 같은 mod를 기준으로 했을 때, m으로 나눈 나머지의 수가 같은 수들을
		// 해당 mod 내에서 합동(내지는 같은 수)으로 취급하는 방식의 연산

		// ex) 총 8개 프레임으로 구성된 애니메이션이 있다 치면
		// 3번째로 출력하는 프레임 : 전체 8개의 프레임 중 3번째 프레임을 재생함
		// 51번째로 출력하는 프레임 : 51 mod 8 = (51 % 8) mod 8 = (48 + 3) mod 8
		// = (8 * 6 + 3) mod 8 = (8 * 6) mod 8 + 3 mod 8 = 0 + 3 mod 8 = 3(mod 8)
		// 따라서 이 총 8개의 프레임을 기준으로 했을 때 51번째 프레임은 3번째 프레임과 동일한 프레임
		// 고로 이 51번째 프레임이 출력하는 프레임은 3번째 프레임
		break;
	case Clip::CLIP_TYPE::PINGPONG: // 마지막 컷을 재생하면 컷 재생순서를 반전시켜 거슬러 올라오기
		if (is_reverse) // 현재 역순으로 재생중이라면
		{
			cur_frame_num--;
			if (cur_frame_num <= 0) // 현재 가리키는 프레임이 0 이하가 되었을 경우
				is_reverse = true; // 방향을 다시 순방향으로 바꿈

			// 여담으로 0 이하라고 한 건 0 미만의 값이 존재할 수는 없겠지만
			// 그래도 존재한다 쳤을 경우에 대비해 예외 느낌으로 잡아둔 것
		}
		else // 현재 정순으로 재생중이라면
		{
			cur_frame_num++;
			if (cur_frame_num >= frames.size() - 1) // 마지막 컷의 재생이 끝났으면
				is_reverse = false; // 방향을 역방향으로 바꿈
		}
		break;
	default:
		break;
	}

	time -= fps; // 현재 애니메이션 프레임의 처리가 끝났으니, 그만큼 경과시간을 제거
}

void Clip::Render()
{
	frames[cur_frame_num]->Render();
}

void Clip::Play(UINT type) // 애니메이션 재생을 시작하라는 함수
{
	is_play = true;
	is_reverse = false;
	// 애니메이션을 처음부터 재생하도록 설정
	switch (type)
	{
	case 0: // 말 그대로 처음부터 재생하도록 할 경우
		time = 0.0f;
		cur_frame_num = 0;
		break;

		// 만약 처음이 아니라 중간이나 끝에서부터 재생한다던가 할 경우에는
		// 다른 분기문을 적어줘야 할 것

	default:
		break;
	}
}

void Clip::Pause() // 현재 애니메이션의 재생을 일시적으로 중단하는 코드
// Stop과 Pause, 그러니까 완전 중지와 일시정지를 따로 구현할 필요가 있따면
// 그 차이를 살려서 이 Pause를 구현하면 됨

// 그러나 지금 이 프로젝트에선 그럴 생각이 없으므로
// Pause를 딱히 구현하지 않음 - 나중에 필요가 생기면 그 때 정의
{

}

void Clip::Stop() // 현재 애니메이션의 재생을 완전히 중단하는 코드
{
	is_play = false;
	//cur_frame_num = 0;
}
