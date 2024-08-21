#pragma once
class PixelShader
// DX의 픽셀 셰이더를 좀 더 편하게 다루기 위해 만든 클래스
{
private:
	ID3D11PixelShader* PS;
	// DX11의 픽셀 셰이더를 다루는 클래스
	static unordered_map<wstring, PixelShader*> shader_data;

public:
	PixelShader(wstring file_loc, DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG);
	// LPCWSTR = WCHAR = 유니코드를 지원하는 문자열 자료형
	// DX에서부턴 기존의 char 문자열을 지원하지 않고
	// 문자 하나당 2바이트를 이용하는 유니코드 형식의 문자열을 이용해야 함
	// 따라서 매개변수 역시 LPCWSTR을 이용해 규격을 맞춰준 것

	// 나중엔 이것 말고 wstring이라는 유니코드 지원 문자열 클래스를 이용할 예정
	~PixelShader();

	static PixelShader* GetInstance(wstring file_loc);
	static void Delete();

	void Release();
	ID3D11PixelShader* GetPixelShader() { return PS; }

	void Set();

};