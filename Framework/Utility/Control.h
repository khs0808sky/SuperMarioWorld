#pragma once
#define KEY_MAX 255
// �Ϲ����� Ű������ Ű�� ���ƺ��� 108��
// -> 255���� ���̸� �װ� �������� ���� 128�� �������� ���� 2���μ� Ű�� ǥ���� �� ����

class Control : public Singleton<Control>
{
private:
	friend class Singleton;

	enum {
		NONE,
		DOWN,
		UP,
		PRESS,
		MAX
	};
	// Ư�� Ű�� ���� ���¸� �ǹ�
	// ���������� "������ ����" / "���� ������" / "���� ������" / "���� ������ ����"�� �ǹ�

	BYTE cur_state[KEY_MAX]; // ���� Ű���尡 �����ִ� ���θ� �����ϴ� ĭ
	BYTE old_state[KEY_MAX]; // �������� Ű���尡 �����־��� ���θ� �����ϴ� ĭ
	BYTE map_state[KEY_MAX]; // �� 2���� ������ �̿��� ���������� �� Ű�� ���� ��ư ���¸� Ȯ��,
	// Ȯ���� ����� �����ϴ� ĭ

	// Ű������ �� Ű�� �ԷµǾ������� ���θ� �Ǵ��� �� ����� ��Ʈ �÷��׵�
	// ��, �� 108�� �̻��� Ű�� �ν��� ���� = Ű������ ��� ���� �ν��� �����̴�

	Control();
	~Control();

public:
	void Update();

	bool Down(UINT key) { return map_state[key] == DOWN; }
	bool Up(UINT key) { return map_state[key] == UP; }
	bool Press(UINT key) { return map_state[key] == PRESS; }
};
// ���α׷����� Ű���� ���� �Է���ġ �����͸� �����ϴ� �Ŵ���