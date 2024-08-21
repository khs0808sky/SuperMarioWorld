cbuffer Color : register(b0)
{
    float4 color;
}
// VS���� ���������� ������۸� 0�� �������� �޾Ƶ��̵��� ����

struct PixelInput
{
    float4 position : SV_Position;
    float4 uv : UV;
};

SamplerState samp : register(s0);
Texture2D map : register(t0);
// samp : �ؽ��� �����Ϳ��� Ư���� �� ���� �̾ƿ� �� ���� ������ �ӽ÷� �����ϴ� ����
// map : samp�� ����� �� �ȼ��� ������ ���α׷�(�׷���)���� ����� ��ġ�� �°� �����ϴ� ����
// �� ���� ���ļ� ���������� �׷��� �׷��� �����͸� �����ϴ� ���۷� �̿��ϸ�,
// �̹��� ���� �ؽ�ó ���Ͽ��� ������ ������ ����Ϳ� ����� �׷������� �ٲٴ� �뵵

float4 PS(PixelInput input) : SV_TARGET
{
    return map.Sample(samp, input.uv) * color;
   // �ؽ�ó ���Ͽ��� samp�� ���� �̾ƿ� �����͸� uv���� �ش��ϴ� map�� ��ǥ�� ����
   // ���� ������ۿ� ���� �����ִٸ� �׷��� ������ �̹��� �����Ϳ��ٰ� �߰������� �������� ����
   
}