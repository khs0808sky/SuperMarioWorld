#pragma once

class VertexShader
{
private:
	ID3D11VertexShader* VS;
	// ���� ���̴��� ����� Ŭ���� ��ü
	ID3D11InputLayout* input_layout;
	// DirectX ��ġ�� � ���� �����͸� ������ ������
	// �� ���̾ƿ�(=����)�� ������ �����صδ� ��ü
	// ���⿡ ����� �����͸� ���� ������ �Էµ��� �� ���̴� ������ �̸� �ؼ��Ͽ� �̿�

	ID3DBlob* vertex_blob; // �����ڿ��� ����ߴ�, ���̴� ������ �ʿ��� �ӽ� ��ü�� ����� ���� ��
	ID3D11ShaderReflection* reflection; // ���� �ݻ� ����, ������ �ǹ��� �ݻ縦 �����ϴ� �� �ʿ��� ���
	// ��, �츮�� ���� �� ���� ����. ������ �ڵ��� ȣȯ�� ������ �ۼ��� �Ϳ� �Ұ�

	static unordered_map<wstring, VertexShader*> shader_data;
	// ���� ������ �̿��� ���� ���̴���,
	// ������ �̸��� Ű�� ��Ƽ� ������ �ʿ����� ���� map�� ������
	// �� ��, ���� ������ �̸��� ���� VertexShader�� ��ü�� ȣ��ȴٸ�
	// ���⿡ �ֳ� üũ�Ͽ� ������ �� �ڸ����� ����, ������ �ش� ��ü�� ��ȯ

	void CreateInputLayout();
	void CreateInputLayoutByPos();
	UINT type;

public:
	VertexShader(wstring file_loc, UINT type = 0,
		DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG);
	~VertexShader();

	static VertexShader* GetInstance(wstring file_loc, UINT type = 0);
	static void Delete();
	// Singleton�� ���� ��, �ܺο��� �����ڸ� ��ٷ� ȣ���� �� ������
	// ������ ������ ���ϴ� �ν��Ͻ� �����ڸ� ������� ���� ��ﳯ ��
	// ���� �� ����� Ŭ������ Singleton�� �ƴ�.
	// ������, ��ü�� �ҷ��� �� new�� �׳� ���� �� �ƴ϶� �� �Լ��� �̿��ϴ� ������
	// �̹� ������� ��ü�� ���� ��� �߰��� ������ ��Ȥ �������� ���� ����
	// �̸� ���� static���� �ڷᱸ���� ����������,
	// ���������� static���� �ش� �ڷᱸ���� �Ҵ� �����ϱ� ���� delete �Լ��� ������ ��

	void Release();
	ID3D11InputLayout* GetInputLayout() { return input_layout; }
	ID3D11VertexShader* GetVertexShader() { return VS; }

	void Set();
};