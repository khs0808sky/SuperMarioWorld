#pragma once
class Environment : public Singleton<Environment>
{
private:
	friend class Singleton;

	Camera* main_camera;

	MatrixBuffer* projection;
	// ���� WVP ��ȯ �� View ��ȯ�� Projection ��ȯ�� ����� ���(=���) ����

	void CreateProjection(); // �� 2���� ��ȯ ����� �ʱ�ȭ���� �Լ�

	ID3D11SamplerState* samplerState;
	ID3D11BlendState* blendState;
	ID3D11RasterizerState* rasterizerState;

	void CreateSamplerState();
	void CreateBlendState();
	void CreateRasterizerState();

	Environment();
	~Environment();

public:
	Camera* GetMainCamera() { return main_camera; }
};