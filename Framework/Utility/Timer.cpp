#include "framework.h"
#include "Timer.h"

Timer::Timer()
	: frame_rate(0), frame_count(0), time_elapsed(0), one_sec_count(0), run_time(0)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&period_frequency);
	// �⺻������ wWinMain �Լ��� ������ ���� �󵵷� �ݺ��ǰ� ����
	// �� �ݺ��Ǵ� Ƚ���� �ʴ� �������� Ȯ���Ͽ� �Ű������� �Է¹��� �����Ϳ� �����ϴ� �Լ�
	// -> ���� ��ǻ���� ����� ���� ������ �ʴ� �� �� ���� �� �ִ����� �˻��ϴ� �Լ�

	QueryPerformanceCounter((LARGE_INTEGER*)&last_time);
	// ���� ī���Ͱ� ���� ������ �ִ� ��
	// = �ý��ۻ����� ��ϵ� ���� �ð��� �޾ƿ��� �Լ�

	time_scale = 1.0f / (float)period_frequency;
	// long long int�� period_frequency�� 1�ʿ��� ������ ������
	// 1���� ī���Ͱ� �뷫������ 0.���������� ���⼭ ����� ����

}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&cur_time);
	// ����ð� ����

	time_elapsed = (float)(cur_time - last_time) * time_scale;
	// ���������� ��ϵ� ���� ī���͸� ���� ������ ���� ī���Ϳ��� ����
	// �׷��� ���� ī������ �������� time_scale�� ���� ���� ����� �ð��� üũ

	if (time_elapsed > 0.01f)
		time_elapsed = 0.01f;

	last_time = cur_time;

	frame_count++;
	// 1�ʴ� �� ���� �۾��� ����Ǿ����� �츮�� ���� üũ

	one_sec_count += time_elapsed;
	// ����� �� �ð��� ����ؼ� ���� ����

	if (one_sec_count >= 1.0f) // �� 1�ʰ� ����Ǿ��� Ȯ��
	{
		frame_rate = frame_count;
		one_sec_count = frame_count = 0;
		// 1�ʰ� ����Ǿ��ٸ� �� ������ �ʴ� ������ ����Ʈ�� �����ϰ�
		// ���꿡 ���� ������ �ʱ�ȭ
	}

	run_time += time_elapsed;
	// �̹� ������Ʈ�� �ɸ� �� �ð��� run_time�� ���
}
