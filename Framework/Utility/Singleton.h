#pragma once
// Singleton ������ ������ �̿��ϱ� ����,
// ���ø� Ŭ������ Singleton�� �����Ų Ŭ������ �����ΰ�
// �� ������ ������ �����ų Ŭ������ ����ؼ� �̿�
template<typename T> // ���ø��� �����Ű�� ����
// : �̿� ���ؼ��� �� Ŭ������ ��ӹ��� Ŭ���� ������ ����
class Singleton
{
protected:
	static T* instance;

public:
	static T* Get()
	{
		if (instance == nullptr)
			instance = new T();

		return instance;
	}

	static void Delete() { delete instance; }
};

template<typename T>
T* Singleton<T>::instance = NULL;