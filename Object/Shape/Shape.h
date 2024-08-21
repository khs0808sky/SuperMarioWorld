#pragma once
class Shape
{
protected:
	vector<Vertex> verticies = {};
	// vector�� �̿��� �� ������ ��µǴ� �� ����� ������ ����

	vector<VertexUV> verticies_uv = {};

	float pos_x, pos_y;
	// ������ ��ġ�� ����ص� ����
	VertexBuffer* VB;
	// ���� ������ �׷��� ��¿� �ʿ��� �����͸� �˾Ƽ� �����ϵ���,
	// �� ��ü�� ����� ���۸� ����

	VertexShader* VS;
	PixelShader* PS;
	// �����δ� ������Ʈ �ϳ��ϳ����� ���� �ٸ� ������ ���̴��� ����� ����
	// ����, �� ������Ʈ���� ���̴��� ���� ���İ��� �� �ʿ䰡 �ֱ� ������
	// �� ������Ʈ���� ����� ����(=�׷���)�� ����� Shape Ŭ���� ������ �̵��� ����� ����

	ColourBuffer* CB;
	// �ȼ� ���̴��� �Է��� ���� ����ص� �� ����
	// ������ �� ������ �Է��� ���� ������ ���� �Է��ϴ� ���̾��µ�,
	// �̸� ���� ��ü�� ���� ������ ���ۿ� ������ �־
	// �̸� ����°�� ���̴��� �Ѱ� ó���ϴ� ������ ����


public:
	Shape(float x, float y);
	~Shape();

	VertexBuffer** const GetBuffer() { return &VB; }
	int GetVertexSize() { return verticies.size(); }

	virtual void Render() = 0;
	// �ڱ� �ڽ��� ����ϴ� ���, ������ ��� ������Ʈ�� �ڱ� �ڽ��� ����ϴ� ����� ���� ��
	// Ư�� ����ϱ� ���� ������� Ŭ������ Shape ������ ������ ����

	void SetColor(Float4 colour) // �� ���ۿ� ���ο� ���� �����ϴ� �Լ�
	{
		CB->data.colour = colour;
	}
};