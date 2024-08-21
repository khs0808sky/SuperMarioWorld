#pragma once
// Frame : �ִϸ��̼��� ��(=�ִϸ��̼��� ������ �ϳ�) �ϳ��ϳ��� ����ϴ� Ŭ����
class Frame
{
private:
	vector<VertexUV> vertices; // ������ �����ϴ� ����
	vector<UINT> indices; // ����� ������ �ε����� ������ ����

	VertexBuffer* VB;
	IndexBuffer* IB;
	// �� 2���� ���͵��� ����ϴ� ���۵�

	Texture* texture;
	// ��� �������� ���� �� �������� ����ϴ� �̹����� ����ؾ� ��
	// �� �̹����� �� ������ ���� ����

	Vector2 frame_size;
	// �������� ������ ����� ������

public:
	Frame(wstring file, Vector2 startUV = Vector2(0, 0), Vector2 endUV = Vector2(1, 1));
	Frame(wstring file, float x, float y, float w, float h);
	~Frame();

	void Render();
	
	// �� �������� ����ϴ� ��������Ʈ�� ���� ������ ����ϴ� ũ��
	Vector2 Size() { return texture->GetSize(); }
	// �� �������� ������ ����� ����� ����ϴ� �Լ�
	Vector2 GetFrameSize() { return frame_size; }
	// �� �������� ����ϴ� ��������Ʈ�� ���� ���̷ΰ� ������ ����� ����� Ȯ������ ���� ������ �̿�,
	// �� �������� ����ϴ� ��������Ʈ�� ��ü�� ���� ũ�⸦ ����� ��ȯ�ϴ� �Լ�
	Vector2 GetFrameOrigSize() { return frame_size * texture->GetSize(); }
};