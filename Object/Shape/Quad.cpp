#include "Framework.h"

void Quad::SetPixelShader(wstring file)
{
	PixelShader::GetInstance(file);
	// 같은 셰이더를 중복해서 생성하는 걸 막기 위해서
	// 픽셀 셰이더를 싱글톤과 비슷한 느낌으로 하나의 같은 파일을 이용하는 셰이더는 하나만 존재하도록
	// 그런 방식으로 객체를 생성하는 디자인 패턴으로 개조를 거친 바 있음
	// 지금 이 부분은 Quad의 생성을 위해, 여기서 사용할 픽셀 셰이더를 생성하는(혹은 불러오는) 작업
}

Quad::Quad(wstring file, Vector2 scale, Vector2 startUV, Vector2 EndUV)
	: Transform()
{
	this->scale = scale;
	texture = Texture::Add(file);

	Vector2 size = texture->GetSize();
	Vector2 half_size = size * 0.5f;
	// 입력받은 파일명을 통해 확보한 파일 이미지의 크기를 받아,
	// 그 크기의 절반 사이즈를 기록한 벡터2를 만듦

	float left = -half_size.x;
	float right = half_size.x;
	float top = -half_size.y;
	float bottom = half_size.y;
	// 입력받은 크기를 이용해서 이미지를 표기할 영역을 지정할 2개의 좌표를 여기서 정의

	vertices.emplace_back(left, top, startUV.x, startUV.y);
	vertices.emplace_back(right, top, EndUV.x, startUV.y);
	vertices.emplace_back(left, bottom, startUV.x, EndUV.y);
	vertices.emplace_back(right, bottom, EndUV.x, EndUV.y);
	// 출력에 사용할 총 4개의 정점을 만들어둠

	indices = { 0, 1, 2, 3, 2, 1 };
	// 위에서 정의된 4개의 정점을 도형을 출력할 때 어떤 순서로 사용할 것인지 정의하는 
	// 인덱스 버퍼에 들어갈 내용 - 자세한 것은 IndexBuffer 클래스를 만들면서 설명

	Create();
	// 사전 세팅(특히 정점 세팅)이 끝났으면 본격적으로 생성 함수 시동

}

Quad::Quad(wstring file, float x, float y, float w, float h)
{
	// 파일 주소와 함께 해당 파일 중
// "이미지 내부에서 출력하고자 하는 영역의 절대좌표를 받았을 때"의 생성자
// x, y : 이미지 파일 내에서 출력하고자 하는 사각형 영역이 시작되는 왼쪽 위 점의 좌표
// w, h : width, height로서 출력하고자 하는 이미지의 가로/세로 범위를 지정하는 매개 변수

	texture = Texture::Add(file); // 파일 불러오기

	Vector2 size = texture->GetSize(); // 불러온 파일의 크기를 받아서 size에 입력

	Vector2 half_size = size * 0.5f; // 정점의 위치를 정의하는 데 쓸 변수

	float left = -half_size.x;
	float right = half_size.x;
	float top = -half_size.y;
	float bottom = half_size.y;
	// 이를 통해 이 이미지가 표시될 상,하,좌,우 정점의 각각의 좌표들을 정의


	Vector2 cut_start = Vector2(x, y) / size;
	// 출력하고자 하는 위치의 이미지상의 상대좌표(uv값)

	Vector2 cut_size = Vector2(w, h) / size;
	// 출력하고자 하는 그림 사이즈의 상대좌표로서의 길이

	Vector2 cut_end = cut_start + cut_size;
	// 출력하고자 하는 이미지가 끝나는, 이미지의 범위를 가리키는 사각형의 오른쪽 아래 점

	vertices.emplace_back(left, top, cut_start.x, cut_start.y);
	vertices.emplace_back(right, top, cut_end.x, cut_start.y);
	vertices.emplace_back(left, bottom, cut_start.x, cut_end.y);
	vertices.emplace_back(right, bottom, cut_end.x, cut_end.y);

	indices = { 0, 1, 2, 2, 1, 3 };
	// 정점과 인덱스를 등록


	frame_size = Vector2(w / texture->GetSize().x, h / texture->GetSize().y);

	Create();
}

Quad::~Quad()
{
	delete VB;
	delete IB;
	delete CB;
	delete WB;
}

void Quad::Render()
{
	if (!is_active) return;
	// 자기 자신이 현재 활성화중이 아니라면 출력하지 않고 함수 종료
	// 앞으로 우리는 게임에 사용될 오브젝트들을 대부분 게임이 시작하기 전에 미리 만들어둔 뒤
	// 게임 시작 직전에 이를 게임판에 배치하는 식으로 게임판을 구성할 예정
	// -> 처음에 배치되기 전에는 같은 곳에 모여있다는 이야기가 됨
	// 다르게 말하면 서로 부딪히면 상호작용을 하게 만들어져있는 오브젝트들이
	// 게임이 시작되지도 않았는데 불필요하게 상호작용하는 경우가 일어날 수 있음
	
	// 이를 막기 위해서 해당 오브젝트가 활성화되어있는지의 여부를
	// 플래그를 이용해서 관리, 활성화되어있지 않다면 상호작용을 하지 않도록 조건문을 구성해둔 것

	WB->Set(world);
	WB->SetVS(0);
	CB->SetPS(0);

	VB->Set(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	IB->Set();

	texture->Set();

	VS->Set();
	PS->Set();

	DVC->DrawIndexed(indices.size(), 0, 0);
	// 그냥 Draw는 정점의 순서 상관없이 앞에서부터 이용했으나,
	// DrawIndexed는 입력받은 인덱스 버퍼에 적힌 순서대로 정점을 이용

}

void Quad::Create()
{
	VS = VertexShader::GetInstance(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = PixelShader::GetInstance(L"Shader/PixelShader/PixelUV.hlsl");

	VB = new VertexBuffer(vertices.data(), sizeof(VertexUV), vertices.size());
	IB = new IndexBuffer(indices.data(), indices.size());

	CB = new ColourBuffer();
	WB = new MatrixBuffer();
}