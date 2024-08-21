cbuffer world : register(b0)
{
    matrix world;
}
cbuffer view : register(b1)
{
    matrix view;
}
cbuffer projection : register(b2)
{
    matrix projection;
}
// cbuffer(= Construct Buffer = ��� ����) 3���� �����ϰ�, �� ���۵��� ������ ���Կ� ����Ѵٴ� ��
// ������ ���ۿ��� ���� 4x4 ũ���� ����� ������
// �̰͵��� ���� W, V, P ��ȯ�� ���� C++ �ʿ��� �޾ƿ;� �ϴ� ����/����/��ȯ�� ��ϵǾ��ִ� ������

// world��� �ϴ�, world ����� �����ϴ� ��� ���۴� b0��� "����"�� ����� �� ������ ���� �����͸� �Է¹ްڴ�
// view��� �ϴ�, view ����� �����ϴ� ��� ���۴� b1��� "����"�� ����� �� ������ ���� �����͸� �Է¹ްڴ�
// projection��� �ϴ�, projection ����� �����ϴ� ��� ���۴� b2��� "����"�� ����� �� ������ ���� �����͸� �Է¹ްڴ�

// ��� ������, ���̴��� �����͸� �Է¹޴� ���� ������ � �����͸� �޾ƿ������� ���� �� ��Ī�� �����ϴ� ����

// �̷��� ���̴� ������ ��� ������ ���� �����͸� ���� ������ �����صθ�
// ���� ���� ������Ʈ(= C++ �� �ڵ�) �ʿ��� ��� ���Կ� �����͸� �����ڴٰ� ����ϰ� �����⸸ �ϸ�
// ���̴����� �ش� ������ ���� �˾Ƽ� �����͸� �޾� ������ ó���� ����

struct VertexInput
{
    float4 pos : POSITION;
    float4 color : COLOR;
};

struct PixelInput
{
    float4 position : SV_Position;
    float4 color : COLOR;
};

PixelInput VS(VertexInput input)

{
    PixelInput output;
    output.position = mul(input.pos, world);
    // mul : HLSL���� �����ϴ� ��İ� ��� �� ������ �������ִ� �����
    // ��Ȯ���� ���� X ��ĵ� �������ְ�, ������ ���� ���⼭�� ���� X ������μ� ����ϴ� ��
    output.position = mul(output.position, view);
    output.position = mul(output.position, projection);
    
    // �� 3���� ���� World ��ȯ, View ��ȯ, Projection ��ȯ�� ����ϴ� �ڵ�
    // -> WVP��ȯ�� ������Ʈ�� ������ �ִ� ��ǥ�� ����/��/�������� ������ ���ϴ� �ܰ�
    
    output.color = input.color; // ������ WVP ��ȯ�� ��������Ƿ� ���� �����͸� �״�� �ø�ƽ�� �����ϴ� �������� �ű��

	return output;
}