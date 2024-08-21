#pragma once
// Quad : �Ϲ������� "��"�� ���ϴ� ��������,
// ���⼭�� �簢���̶� ���� ��
// -> �簢���� "�̹���"�� ����ϱ� ���� Ŭ����

// ������ Shape�� SRT ��ȯ�� ���� ��ġ ������ ���� �� �� ���� Ŭ���������Ƿ�,
// �̸� ������ ������ �� �ְ� Transform�� ��ӽ�Ų �� Ŭ������ �ʿ�����
// -> �׷��� ��� �κ��� �����ؼ� ���� ������ �� �ִ� Ŭ������ ���� ����� ��

class Quad : public Transform
{

protected:
    vector<VertexUV> vertices = {};
    vector<UINT> indices = {}; // ������ ����� ������ ��ϵ� ����

    VertexShader* VS;
    PixelShader* PS;

    VertexBuffer* VB;
    IndexBuffer* IB; // �ε���(����) ���� : ��� ������� ������ ����� ������ �����ϴ� ����

    ColourBuffer* CB;
    MatrixBuffer* WB;

    Texture* texture; // �̹��� ������ ����ϴ� �ν��Ͻ�
    // �̹��� ���� ���� �� �� ���α׷� ������ �� �� �̻� �θ� ��� ����ȭ ������ ����� �����̴�
    // �̸� �ذ��ϰ��� ���� Ŭ����

    void SetPixelShader(wstring file);
    // �츮�� ������ ����� �� ����ϴ� ���̴��� �ٲٴ� ��Ȳ�� ���� �� ����
    // �׷� �� �ٸ� ���̴��� �̿��ϰڴٰ� �������ִ� �Լ�

    Vector2 frame_size;

public:
    Quad(wstring file, Vector2 scale = Vector2(1, 1),
        Vector2 startUV = Vector2(0, 0), Vector2 EndUV = Vector2(1, 1));
    Quad(wstring file, float x, float y, float w, float h);
    virtual ~Quad();

    Vector2 Size() { return texture->GetSize() * scale; }
    void Render();

private:
    void Create();

};