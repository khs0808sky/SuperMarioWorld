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

struct VertexInput
{
    float4 pos : POSITION;
    float4 uv : UV;
    // �ؽ��ĸ� �̿��ϱ� ���ؼ� ����ϴ� 2��° ��ǥ�� uvw
    // ������ pos�� ������ ��ġ�� ��Ÿ���� ���� ����ϴ� ��ǥ���ٸ�,
    // UVW�� �� ������Ʈ ��ü�� ǥ���� �� �� ������ ��ü �׸� ��
    // ��� �κ��� ����� ����ϰ� �ִ� �������� ����ϴ� �Ǵٸ� ��ǥ
    
    // �ؽ��� ���Ͽ����� x, y, z��ǥ�� �� u, v, w�� �����ϴ� ��
};

struct PixelInput
{
    float4 position : SV_Position;
    float4 uv : UV;
};

PixelInput VS(VertexInput input)
{
    PixelInput output;
    output.position = mul(input.pos, world);
    output.position = mul(output.position, view);
    output.position = mul(output.position, projection);
    
    output.uv = input.uv;

    return output;
}