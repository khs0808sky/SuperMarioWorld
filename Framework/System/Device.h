#pragma once

class Device
// DirectX ȯ���� ����� �����ϱ� ���ؼ� �ʿ��� ��ɵ��� �����ϴ� Ŭ����
// �� Ŭ������ ���ؼ� DirectX�� ���õ� ��ü���� �ʱ�ȭ�ϰ�, ���õ� �۾����� ����
{
private:
	ID3D11Device* device;    // CPU�� ����, ���ҽ� �ε� �� ��� �� �ٸ� ��ɵ��� ���������� �ϴ� �⺻ ��ġ
	ID3D11DeviceContext* device_context; // GPU���� �ϴ� ���� ���⼭ ���

	IDXGISwapChain* swap_chain;  // ������۸��� ���Ǵ� ��ü
	ID3D11RenderTargetView* render_target_view;   // �ĸ���ۿ��� ����� �޸�

	static Device* instance;

	Device();
	~Device();

public:
	static Device* Get()
	{
		if (instance == nullptr)
			instance = new Device();

		return instance;
	}

	static void Delete() { delete instance; }

	void CreateDeviceAndSwapChain();
	void CreateBackBuffer();
	void SetViewPoint();

	void Clear();
	void Present();

	ID3D11Device* GetDevice() { return device; }
	ID3D11DeviceContext* GetDeviceContext() { return device_context; }
};