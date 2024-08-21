#include "framework.h"

Triangle::Triangle(vector<Vertex> v, D3D11_PRIMITIVE_TOPOLOGY t)
	: Shape(0.0f, 0.0f), type(t)
{
	verticies.resize(v.size());
	// 현재 이 쪽 벡터는 빈 공간조차 할당 안 된 상태이므로
	// 제대로 복사할 수 있도록 입력받은 벡터와 동일한 사이즈만큼 할당

	copy(v.begin(), v.end(), verticies.begin());
	// STL에서 지원하는, 자료구조끼리 복사하는 함수
	// 복사할 데이터의 시작지점과 끝지점을 입력한 후, 그 행선지를 입력해 복사하는 식

	// 그렇게 다른 곳에서 정의된 정점들을 이 도형이 가지고 있도록 복사

	// 기존의 InitDevice() 중, 정점을 정의한 뒤 이를 세팅하는 부분의 코드를 여기에 복사

		// 위에서 설정된 정점들의 정보를 가지고
	// 정점 셰이더에서 입력받을 수 있는 형태의 데이터 저장 버퍼를 만들어내는 부분
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(Vertex) * verticies.size(); // 위에서 구성한 정점들의 총 개수
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = verticies.data();

	Device::Get()->GetDevice()->CreateBuffer(&bd, &initData, &VB);
	// 이 7줄의 코드를 통해, 정점 셰이더에 우리가 구성했던 정점 데이터들을 전달
}

// 소멸자는 만들지 않음 : 동적 할당한 게 없음