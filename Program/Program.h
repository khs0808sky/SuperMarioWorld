#pragma once
class Program
// DirectX�� �������� ������ ������ �ν��Ͻ��μ� ���Ǵ� Ŭ����

// ������ ����� �Լ��� �����ϳ�, DirectX�� ���� �����س����鼭 ���⿡ �߰��Ǵ� ������ ���� ������ ����
{
private:
	Scene* scene;

public:
	Program();
	~Program();

	void Update();
	void Render();

	void Create();
	void Delete();
};