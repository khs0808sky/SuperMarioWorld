#include "framework.h"

Device* Device::instance = nullptr;

UINT width = WIN_WIDTH;
UINT height = WIN_HEIGHT;

Device::Device()
{
	CreateDeviceAndSwapChain();
	CreateBackBuffer();
	SetViewPoint();
}

Device::~Device()
{
	device->Release();
	device_context->Release();

	swap_chain->Release();
	render_target_view->Release();
}

void Device::CreateDeviceAndSwapChain()
// ������۸� ���� ������ �ʱ�ȭ�ϴ� �Լ�
// �� ���ÿ� Device ��ü�� �ʱ�ȭ��
{
    DXGI_SWAP_CHAIN_DESC sd = {};
    // ����� ���� ������ �����ص� �ν��Ͻ�
    // �̷��� �����ص� �� �Ʒ��� ������� �Է��Ͽ� ����۸� ���� �Ҵ��� �� ���

    sd.BufferCount = 1; 

    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    // ����۰� �ٷ� ȭ���� ũ��

    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    // ����۰� �ٷ� �׷����� ����ϴ� ������ �԰�
    // R8G8B8A8 = ���� 8��Ʈ, ��� 8��Ʈ, û�� 8��Ʈ, ���İ� 8��Ʈ�� �̿��ϴ� 32��Ʈ �׷���

    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    // FPS�� ������ �����̶�� ����ϸ� OK
    // 2D������ �̰� �̿��� FPS�� �������� ���� ���̹Ƿ� ���ϰ� �ٷ� ���� ����

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    // �� ���۰� ��� ���� ������ ���

    sd.OutputWindow = hWnd;
    // �� ����۰� �׸��� ����� â�� �������� �����ϴ� �κ�

    // �� hWnd��ŭ�� �ܺο��� �޾ƿͼ� ����ؾ� ��
    // �� ������ �̸� extern ���� ������ �����ϰ�
    // ���� ���Ͽ��� �̸� �ʱ�ȭ�ϴ� ��

    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    // 3D �ʿ��� ����ϴ� ����̶� �츮�� �� ��
    
    sd.Windowed = true;
    // â�� ��üȭ������ â��������� �����ϴ� ���

    D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        0,
        D3D11_CREATE_DEVICE_DEBUG,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &sd,
        &swap_chain,
        &device,
        nullptr,
        &device_context
    );
    // �׷��� ������ sd�� �̿��ؼ� ������۸��� ����ü��, DX�� Ȱ���ϱ� ���� device�� device_context��
    // �ѹ��� �ʱ�ȭ
    
}

void Device::CreateBackBuffer()
// ������۸��� ����۸� �ʱ�ȭ�ϰ� ����̽��� ����ϴ� �Լ�
{
    ID3D11Texture2D* backBuffer = nullptr;

    swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, nullptr, &render_target_view);
    // ����ü�ΰ� ����̽� �������� ����۸� �������ִ� �Լ�

    backBuffer->Release();

    device_context->OMSetRenderTargets(1, &render_target_view, nullptr);
    // ������ ����۸� ������ �׸� �׸��� �� �Ѱ��ϴ� device_context�� ���

    // API �ʿ��� �츮�� ���� ����۸� �̷����� �Ű����� �����ؼ� ��ü����� ������,
    // DX������ ó�� ������ ���� �̰����� �������ְ�
    // ���߿� ����۸� ��ü�� ���� ������ �Լ� �ϳ��� ȣ�����ִ� ������ ���� �� ����
}

void Device::SetViewPoint()
// ����Ʈ�� �����ϴ� �κ�
{
    // 2D���ٴ� 3D���� �� ���� ����� �����̱� ������
    // ���⼭�� �׳� �̷� �� �ִ� �����θ� ����ϸ� ��

    D3D11_VIEWPORT viewPort;
    viewPort.Width = width; // �츮�� ������ â�� ũ�� ��ü�� ȭ�鿡 ǥ���ϰڴ�
    viewPort.Height = height; // ��������
    viewPort.MinDepth = 0.0f; // ���̸� ������ ����
    viewPort.MaxDepth = 1.0f; // �̿� ���ؼ��� ���� 3D�� ��� �� �ٷ�� �� ��
    viewPort.TopLeftX = 0.0f;
    viewPort.TopLeftY = 0.0f;
    device_context->RSSetViewports(1, &viewPort);

    // ������ ����Ʈ�� ������ �� ����ߴ� �ڵ带 �״�� ������ ���

}

void Device::Clear()
// ȭ���� �ʱ�ȭ�ϴ� �Լ�
{
    // float clear_color[4] = { 0.0f, 0.125f, 0.3f, 1.0f };
    float clear_color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    // float clear_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    // ������ ����

    device_context->ClearRenderTargetView(render_target_view, clear_color);
    // ������ �������� ȭ���� ��� ������ ������ device_context�� ��û
}

void Device::Present()
// ������۸��� �����ϴ� �Լ� -> ȭ���� ����ϴ� �Լ�
{
    swap_chain->Present(0, 0);
    // ����ü�ο� ȭ���� �ٲٶ�� ��û�ϴ� �Լ��� ȣ�������μ� ����ۿ� ���� ȭ���� ��ü
}
