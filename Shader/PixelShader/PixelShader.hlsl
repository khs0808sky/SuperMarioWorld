cbuffer Color : register(b0)
{
    float4 color;
}
// VS���� ���������� ������۸� 0�� �������� �޾Ƶ��̵��� ����

struct PixelInput
{
    float4 position : SV_Position;
    float4 color : COLOR;
};

float4 PS(PixelInput input) : SV_TARGET

{
    return input.color * color;
    // ������ ������ ���� �޾ƿ� ���� ���۸� �״�� ������
    // �̸� ���� ������ ������ �ִ� ���� �߰��� �����͸� ���۰� ������ �ִ� ���� �����Ͽ� ȭ�鿡 ����ϵ��� ��

}

/*
������⺸�� �غ� :

��� ������ �ٶ󺸰� �ִ��� �� ���� �� �� �ִ� �̹����� �ϳ� �غ��ؿ� ��

*/
