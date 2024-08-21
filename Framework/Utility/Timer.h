#pragma once
class Timer : public Singleton<Timer>
// �� ���α׷� ���ο��� �ð� ��� ���� ������ �� ����� Singleton Ŭ����
// ��ӹ��� Ŭ������ ���� ���ø����� ���� ������� �ϴ� Timer��� Ŭ������ �̿��ϴ� Singleton��
// �̿��ϰ� ������ �� �� ����
// �̷��� �θ� Ŭ���� �� ���ø��� ��� ���ø� ���˿� �ڽ�Ŭ���� �� ��ü�� �ִ� �����ε� �̿밡��
{

private:
	Timer();
	~Timer();

public:
	friend class Singleton;
	// friend : ������ ���ϸ� private �����̿��
	// friend class�� ������ Ŭ������
	// �� Ŭ������ ���ο��� �ش� Ŭ������ private, protected ���� �����Ӱ� ����� �� ����

	// Singleton�� Get() �Լ��� �̿��� ��, �� ������ ������
	// �� Control �Լ������� Singleton�� instance�� ������ ���� ���
	// �ƿ� Get �Լ� ��ü�� �̿��� ���� ����

	float time_scale; // 1�ʸ� ǥ���ϴµ� �ʿ��� "���� ī����"
	float time_elapsed; // ����� �ð��� üũ�ϴ� ���

	// ���� 2���� Ÿ�� �������� ����� ���� 2��
	// �ڷ����� long long int -> 64��Ʈ�� ����ϴ� int
	__int64 cur_time; 
	__int64 last_time;  
	__int64 period_frequency;
	// ���� ��ǻ���� ����� ���� ������ �� �� ���� �� �ִ����� �����ϴ� �Լ�

	int frame_rate; // FPS
	int frame_count; // ���α׷� ���� �� ����� �������� ����

	float one_sec_count; // 1�ʰ� ���������� ���θ� �����ϴ� ����
	float run_time; // ���α׷��� ����Ǳ� ������ �� �󸶳� �ð��� �귶���� �����ϴ� ����

	void Update();

	int GetFPS() { return frame_rate; } // FPS ��� �Լ� 
	float GetDeltaTime() { return time_elapsed; } // �̹� ƽ�� ����� �ð��� ��ȯ�ϴ� �Լ�
	float GetRunTime() { return run_time; } // ���α׷� ���� �� ����� �ð��� ��ȯ�ϴ� �Լ�

};