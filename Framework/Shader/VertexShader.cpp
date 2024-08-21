#include "framework.h"
// 미리 컴파일된 헤더에 해당 헤더를 미리 등록해뒀다면
// 이후 코드 파일을 자동 생성했을 때 알아서 미리 컴파일된 헤더가 포함됨

unordered_map<wstring, VertexShader*> VertexShader::shader_data;
void VertexShader::CreateInputLayout()
// 기존에 우리가 생성자에서 Input_Layout을 만들었던 부분을 따로 함수로 빼온 것이라 기억하면 됨
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
    case 0: // 처음에 우리가 했던 일반적인 정점, 위치와 색을 사용하는 정점을 이용할 떄
        layoutSize = ARRAYSIZE(layouts);
        Device::Get()->GetDevice()->CreateInputLayout(layouts, layoutSize, vertex_blob->GetBufferPointer(),
            vertex_blob->GetBufferSize(), &input_layout);
        break;
    case 1: // 위치와 이미지를 사용하는 정점
        layoutSize = ARRAYSIZE(layouts_UV);
        Device::Get()->GetDevice()->CreateInputLayout(layouts_UV, layoutSize, vertex_blob->GetBufferPointer(),
            vertex_blob->GetBufferSize(), &input_layout);
        break;
    }
}
void VertexShader::CreateInputLayoutByPos()
// 사용하는 정점이 좌표 외에 아무런 데이터도 사용하지 않을 경우에 이용하는 레이아웃을
// 선언 및 적용하는 부분
// 겸사겸사 여기서 반사와 관련된 처리까지 함
{
    D3DReflect(vertex_blob->GetBufferPointer(), vertex_blob->GetBufferSize(),
        IID_ID3D11ShaderReflection, (void**)&reflection);
    // 빛 등의 반사를 다루는 객체를 불러와 reflection에 저장하는 함수
    // 다만 우리는 2D에서는 빛의 반사를 다루지 않을 것이기 때문에,
    // 우리가 직접 다룰 일은 이 반에선 없음

    // 특히 이게 중요한 건 3D 환경에서 우리가 화면 어딘가를 클릭했을 때
    // 화면에서 그 클릭한 부분에 있는 오브젝트가 "내가 지금 클릭되었구나"를 인식할 때 사용되는 매커니즘에
    // 이 빛(정확히는 뻗어나가는 직선)이 닿았는지 아닌지(=반사가 일어났는지 아닌지)를
    // 판단해서 판정하는 경우도 있다보니까 언젠가는 반드시 익혀야 할 개념임
    // 그게 2D만을 배우는 우리 기초반은 아닐 뿐

    D3D11_SHADER_DESC shader_desc;
    reflection->GetDesc(&shader_desc);

    // 이하의 내용은 2D보다는 3D 쪽에서 더 자주 다루게 될 내용이라,
    // 여기서는 규격을 맞추기 위해 우리가 안 씀에도 불구하고 일부러 맞추는 것일 뿐
    // 직접 이 내용들을 다루지는 않을 것

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
// 문자 하나를 표기하는 데 2바이트를 사용하는 문자열을 다루는 클래스
// 한글 등의 유니코드를 다루는 데 사용
    : type(type)
{
    D3DCompileFromFile(file_loc.c_str(), nullptr, nullptr, "VS",
        "vs_5_0", flags, 0, &vertex_blob, nullptr);

    DEVICE->CreateVertexShader(vertex_blob->GetBufferPointer(),
        vertex_blob->GetBufferSize(), nullptr, &VS);

    // 이번 변경(DX_Animated)의 핵심은 생성자에서 많은 지분을 차지하고 있던 layout 관련 부분을 분리하는 것이라,
    // 나머지는 크게 달라진 점은 없음

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
// 정점 셰이더를 DX 시스템에 등록하는 부분

VertexShader* VertexShader::GetInstance(wstring file_loc, UINT type)
// Singleton의 Get 함수와 거의 동일한 작업을 하는 함수
{
    if (shader_data.count(file_loc) > 0) // 입력된 파일명을 통해 만들어진 객체가 이미 존재할 경우
        return shader_data[file_loc]; // 맵에 이미 저장되어있는 객체를 반환

    VertexShader* instance = new VertexShader(file_loc, type);
    shader_data[file_loc] = instance; // 아니라면 새로 생성한 객체를 맵의 해당 키에 저장

    return instance;
}

void VertexShader::Delete()
{
    // 셰이더들의 사용이 전부 끝났다면 모든 셰이더들을 할당 해제할 때 사용할 함수지만,
    // 그럴 상황이면 아예 프로그램 자체가 종료되는 상황이므로 굳이 처리할 이유가 없음
    // 따라서 여기선 작성하지 않음, 본래는 작성하는 것이 권장된다고만 정리
}