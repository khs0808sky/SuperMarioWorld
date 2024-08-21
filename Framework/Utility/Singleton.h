#pragma once
// Singleton 디자인 패턴을 이용하기 위해,
// 템플릿 클래스로 Singleton을 적용시킨 클래스를 만들어두고
// 이 디자인 패턴을 적용시킬 클래스에 상속해서 이용
template<typename T> // 템플릿을 적용시키고 있음
// : 이에 대해서는 이 클래스를 상속받은 클래스 측에서 설명
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