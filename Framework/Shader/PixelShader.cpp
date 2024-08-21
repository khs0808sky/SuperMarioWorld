#include "framework.h"

unordered_map<wstring, PixelShader*> PixelShader::shader_data;

PixelShader::PixelShader(wstring file_loc, DWORD flags)
{
    ID3DBlob* pixelBlob;
    D3DCompileFromFile(file_loc.c_str(), nullptr, nullptr, "PS",
        "ps_5_0", flags, 0, &pixelBlob, nullptr);

    Device::Get()->GetDevice()->CreatePixelShader(pixelBlob->GetBufferPointer(),
        pixelBlob->GetBufferSize(), nullptr, &PS);
    pixelBlob->Release();
}

PixelShader::~PixelShader()
{
    Release();
}

PixelShader* PixelShader::GetInstance(wstring file_loc)
{
    if (shader_data.count(file_loc) > 0) // 입력된 파일명을 통해 만들어진 객체가 이미 존재할 경우
        return shader_data[file_loc];

    PixelShader* instance = new PixelShader(file_loc);
    shader_data[file_loc] = instance;

    return instance;
}

void PixelShader::Delete()
{
    for (auto shader : shader_data)
    {
        delete shader.second;
    }
    // 이 코드를 그대로 이용해 VertexShader::Delete() 역시 만들어도 무방
}

void PixelShader::Release()
{
    PS->Release();
}

void PixelShader::Set()
{
    DVC->PSSetShader(PS, nullptr, 0);
}
