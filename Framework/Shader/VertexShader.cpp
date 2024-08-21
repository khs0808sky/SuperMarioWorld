#include "framework.h"
// �̸� �����ϵ� ����� �ش� ����� �̸� ����ص״ٸ�
// ���� �ڵ� ������ �ڵ� �������� �� �˾Ƽ� �̸� �����ϵ� ����� ���Ե�

unordered_map<wstring, VertexShader*> VertexShader::shader_data;
void VertexShader::CreateInputLayout()
// ������ �츮�� �����ڿ��� Input_Layout�� ������� �κ��� ���� �Լ��� ���� ���̶� ����ϸ� ��
{
    D3D11_INPUT_ELEMENT_DESC layouts[] =
    {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,
        0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
        ,{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
        D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    D3D11_INPUT_ELEMENT_DESC layouts_UV[] =
    {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,
        0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"UV", 0, DXGI_FORMAT_R32G32_FLOAT,
        0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    UINT layoutSize;
    switch (type)
    {
    case 0: // ó���� �츮�� �ߴ� �Ϲ����� ����, ��ġ�� ���� ����ϴ� ������ �̿��� ��
        layoutSize = ARRAYSIZE(layouts);
        Device::Get()->GetDevice()->CreateInputLayout(layouts, layoutSize, vertex_blob->GetBufferPointer(),
            vertex_blob->GetBufferSize(), &input_layout);
        break;
    case 1: // ��ġ�� �̹����� ����ϴ� ����
        layoutSize = ARRAYSIZE(layouts_UV);
        Device::Get()->GetDevice()->CreateInputLayout(layouts_UV, layoutSize, vertex_blob->GetBufferPointer(),
            vertex_blob->GetBufferSize(), &input_layout);
        break;
    }
}
void VertexShader::CreateInputLayoutByPos()
// ����ϴ� ������ ��ǥ �ܿ� �ƹ��� �����͵� ������� ���� ��쿡 �̿��ϴ� ���̾ƿ���
// ���� �� �����ϴ� �κ�
// ����� ���⼭ �ݻ�� ���õ� ó������ ��
{
    D3DReflect(vertex_blob->GetBufferPointer(), vertex_blob->GetBufferSize(),
        IID_ID3D11ShaderReflection, (void**)&reflection);
    // �� ���� �ݻ縦 �ٷ�� ��ü�� �ҷ��� reflection�� �����ϴ� �Լ�
    // �ٸ� �츮�� 2D������ ���� �ݻ縦 �ٷ��� ���� ���̱� ������,
    // �츮�� ���� �ٷ� ���� �� �ݿ��� ����

    // Ư�� �̰� �߿��� �� 3D ȯ�濡�� �츮�� ȭ�� ��򰡸� Ŭ������ ��
    // ȭ�鿡�� �� Ŭ���� �κп� �ִ� ������Ʈ�� "���� ���� Ŭ���Ǿ�����"�� �ν��� �� ���Ǵ� ��Ŀ����
    // �� ��(��Ȯ���� ������� ����)�� ��Ҵ��� �ƴ���(=�ݻ簡 �Ͼ���� �ƴ���)��
    // �Ǵ��ؼ� �����ϴ� ��쵵 �ִٺ��ϱ� �������� �ݵ�� ������ �� ������
    // �װ� 2D���� ���� �츮 ���ʹ��� �ƴ� ��

    D3D11_SHADER_DESC shader_desc;
    reflection->GetDesc(&shader_desc);

    // ������ ������ 2D���ٴ� 3D �ʿ��� �� ���� �ٷ�� �� �����̶�,
    // ���⼭�� �԰��� ���߱� ���� �츮�� �� ������ �ұ��ϰ� �Ϻη� ���ߴ� ���� ��
    // ���� �� ������� �ٷ����� ���� ��

    vector<D3D11_INPUT_ELEMENT_DESC> input_layouts;

    for (UINT i = 0; i < shader_desc.InputParameters; i++)
    {
        D3D11_SIGNATURE_PARAMETER_DESC paramDesc;
        reflection->GetInputParameterDesc(i, &paramDesc);

        D3D11_INPUT_ELEMENT_DESC elementDesc;
        elementDesc.SemanticName = paramDesc.SemanticName;
        elementDesc.SemanticIndex = paramDesc.SemanticIndex;
        elementDesc.InputSlot = 0;
        elementDesc.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
        elementDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
        elementDesc.InstanceDataStepRate = 0;

        if (paramDesc.Mask == 1)
        {
            if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32)
                elementDesc.Format = DXGI_FORMAT_R32_UINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
                elementDesc.Format = DXGI_FORMAT_R32_SINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
                elementDesc.Format = DXGI_FORMAT_R32_FLOAT;
        }
        else if (paramDesc.Mask < 4)
        {
            if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32)
                elementDesc.Format = DXGI_FORMAT_R32G32_UINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
                elementDesc.Format = DXGI_FORMAT_R32G32_SINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
                elementDesc.Format = DXGI_FORMAT_R32G32_FLOAT;
        }
        else if (paramDesc.Mask < 8)
        {
            if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32)
                elementDesc.Format = DXGI_FORMAT_R32G32B32_UINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
                elementDesc.Format = DXGI_FORMAT_R32G32B32_SINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
                elementDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;
        }
        else if (paramDesc.Mask < 16)
        {
            if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_UINT32)
                elementDesc.Format = DXGI_FORMAT_R32G32B32A32_UINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_SINT32)
                elementDesc.Format = DXGI_FORMAT_R32G32B32A32_SINT;
            else if (paramDesc.ComponentType == D3D_REGISTER_COMPONENT_FLOAT32)
                elementDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
        }

        string temp = paramDesc.SemanticName;
        if (temp == "POSITION")
            elementDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;

        input_layouts.push_back(elementDesc);
    }

    DEVICE->CreateInputLayout(input_layouts.data(), input_layouts.size(),
        vertex_blob->GetBufferPointer(), vertex_blob->GetBufferSize(), &input_layout);
}
VertexShader::VertexShader(wstring file_loc, UINT type, DWORD flags)
// ���� �ϳ��� ǥ���ϴ� �� 2����Ʈ�� ����ϴ� ���ڿ��� �ٷ�� Ŭ����
// �ѱ� ���� �����ڵ带 �ٷ�� �� ���
    : type(type)
{
    D3DCompileFromFile(file_loc.c_str(), nullptr, nullptr, "VS",
        "vs_5_0", flags, 0, &vertex_blob, nullptr);

    DEVICE->CreateVertexShader(vertex_blob->GetBufferPointer(),
        vertex_blob->GetBufferSize(), nullptr, &VS);

    // �̹� ����(DX_Animated)�� �ٽ��� �����ڿ��� ���� ������ �����ϰ� �ִ� layout ���� �κ��� �и��ϴ� ���̶�,
    // �������� ũ�� �޶��� ���� ����

    if (type == 2)
        CreateInputLayoutByPos();
    else
        CreateInputLayout();


}

VertexShader::~VertexShader()
{
    Release();
}

void VertexShader::Release()
{
    VS->Release();
    input_layout->Release();
}

void VertexShader::Set()
{
    DVC->IASetInputLayout(input_layout);
    DVC->VSSetShader(VS, nullptr, 0);
}
// ���� ���̴��� DX �ý��ۿ� ����ϴ� �κ�

VertexShader* VertexShader::GetInstance(wstring file_loc, UINT type)
// Singleton�� Get �Լ��� ���� ������ �۾��� �ϴ� �Լ�
{
    if (shader_data.count(file_loc) > 0) // �Էµ� ���ϸ��� ���� ������� ��ü�� �̹� ������ ���
        return shader_data[file_loc]; // �ʿ� �̹� ����Ǿ��ִ� ��ü�� ��ȯ

    VertexShader* instance = new VertexShader(file_loc, type);
    shader_data[file_loc] = instance; // �ƴ϶�� ���� ������ ��ü�� ���� �ش� Ű�� ����

    return instance;
}

void VertexShader::Delete()
{
    // ���̴����� ����� ���� �����ٸ� ��� ���̴����� �Ҵ� ������ �� ����� �Լ�����,
    // �׷� ��Ȳ�̸� �ƿ� ���α׷� ��ü�� ����Ǵ� ��Ȳ�̹Ƿ� ���� ó���� ������ ����
    // ���� ���⼱ �ۼ����� ����, ������ �ۼ��ϴ� ���� ����ȴٰ� ����
}