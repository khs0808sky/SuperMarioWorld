#include "framework.h"

TutorialScene::TutorialScene()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	// 셰이더 생성에 필요한 플래그를 미리 설정

	VS = new VertexShader(L"Shader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/VertexShader.hlsl", flags);
	// 정점 셰이더와 픽셀 셰이더를 셰이더 주소가 있는 파일에 생성

	// 위 둘은 셰이더 관련 설명을 할 때 다룸



	// DX는 함수를 이용해서 알아서 도형을 그릴 수 없고,
	// 기본적으로는 선과 삼각형만을 그릴 수 있게 되어있음
	// 도형을 그리고 싶다면 삼각형을 여럿 생성해서 그릴 수 밖에 없음

	// 이 삼각형을 "폴리곤(Polygon)"이라 부름
	// 3D 그래픽은 기본적으로 이 폴리곤을 이용해서 그래픽을 관리하고 출력

	// 폴리곤을 그리기 위해선 이 폴리곤=삼각형을 구성하는 3개의 정점을 입력해야 함
	// 그 첫번째로, 삼각형 하나를 그리는 데 사용할 정점 생성
	vector<Vertex> vx_triangle_list =
	{
		Vertex(-0.1f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.8f, 0.17f, 0.8f, 0.8f),
		// Vertex : 우리가 그래픽, 정확히는 폴리곤의 각 정점을 정의하기 위해 만든 구조체
		// 왼쪽에서부터 x,y좌표 / 색상값 R,G,B를 입력한 것
		// 좌표값은 화면 중앙을 기점으로 왼쪽, 아래쪽 끝을 -1 / 오른쪽, 위쪽 끝을 1로 잡은 상대좌표
		// 이 색상값은 API 때와는 달리 범위가 0~255가 아닌 0~1까지의 실수값

		// API랑은 다르게 DX에서는 왼쪽 위가 아닌 왼쪽 아래를 기준으로 +, -를 계산함
		// 나중에 이를 우리가 알던 방식으로 바로잡을 예정이나, 당장은 이런 식이라고 기억해둘 것

		// 3D그래픽에서 폴리곤은 
		// "화면상(시점)에서 봤을 때 앞면이 보이는 경우에만 출력하도록 되어있음"
		// 왜 앞면만 출력되는지에 대해서는 3D에서 다루게 되는 영역이므로 생략하고,
		// 여기서는 그 "앞면"의 기준에 대해서만 설명

		// 폴리곤의 앞면의 기준 : 폴리곤을 이루고 있는 정점들은 순차적으로 출력에 이용되는데,
		// 그 정점들이 시계방향을 기준으로 나열되어 있는지의 여부로 판단해
		// 시계방향이면 앞면, 시계 반대방향이면 뒷면으로 출력함
		// 도형을 만들 때 순서 신경 안 쓰면 뒷면 출력으로 인식되어 화면에 나오지 않는 경우가 많으니 주의
	};

	// 위에서 만든 정점 리스트를 이용해 삼각형을 출력하는 도형 클래스의 초기화를 시행
	list_triangle = new Triangle(vx_triangle_list,
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// D3D11_PRIMITIVE_TOPOLOGY : 나중에 DX 디바이스에 이 도형을 출력해달라고 요청할 때
	// 이 도형이 어떤 도형인지를 시스템에 알리는 열거형 변수
	// 왜 먼저 알리는가? -> 어떤 도형이라고 알리냐에 따라서 정점을 사용하는 순서가 변함
	// TRIANGLELIST : 3개의 정점을 사용하는 삼각형으로, 출력할 때마다 새로운 3개의 정점을 받음
	// 이는 바로 밑의 rect_list에서 다룸



	// 화면상의 왼쪽 아래의 사각형을 담당하는 정점들
	vector<Vertex> vx_rect_list =
	{
		Vertex(-0.8f, -0.1f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.1f, -0.1f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.8f, -0.8f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.8f, -0.8f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.1f, -0.1f, 0.8f, 0.1f, 0.6f),
		Vertex(-0.1f, -0.8f, 0.8f, 0.1f, 0.6f),
	};

	list_rect = new Triangle(vx_rect_list,
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// TRIANGLELIST는 매 삼각형을 그릴 때마다 새로운 3개의 정점을 받음
	// 이를 이용해서, 왼쪽 위를 담당할 삼각혀오가 오른쪽 아래를 담당할 삼각형을 2개 그려
	// 결과적으로 사각형이 되도록 그린 것

	// 이 방식이 DX에서 삼각형 외의 도형을 그리는 방식
	// API와는 달리 사각형이나 원 등을 그리는 기능이 없는 이유 
	// -> 삼각형을 여럿 그려서 합치는 것으로 전부 표현이 가능하니까


	

	// 육각형의 경우엔 위와는 달리 정점들을 정의하는 부분이 없는데,
	// 이는 정점을 이 Scene이 아니라 해당 도형을 다루는 클래스인 Hexagon에서 직접 정의하기 때문
	// 어떤 구조인지 궁금하다면 한 번 해당 파일을 참조해볼 것
	list_hexagon[0] = new Hexagon(860, 540,
		0.4f, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// 생성자에서는 위치의 X, Y좌표, 도형의 크기, 도형의 출력 방식을 입력받고 있음
	// 이런 식으로 도형의 크기 등을 관리할 때는 일반적으로 생성자에서 관련 매개변수를 받아
	// 클래스의 생성자 내부에서 처리하도록 하고 있음

	list_hexagon[1] = new Hexagon(760, 360,
		0.3f, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	line_hexagon = new Hexagon(960, 180,
		0.4f, D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	
}

TutorialScene::~TutorialScene()
{
	delete(list_triangle);
	delete list_rect;
	for (int i = 0; i < 10; i++)
	{
		if(list_hexagon[i] != NULL)
			delete list_hexagon[i];
	}
	delete line_hexagon;
	
	VS->Release();
	PS->Release();
}

void TutorialScene::Update()
{


}

void TutorialScene::Render()
{
	// Device::Get()->Clear();
	// Device에 화면을 초기화해달라고 요청하는 코드
	// 화면을 초기화할 타이밍을 "Scene을 호출할 때"로 하느냐, "프록램 자체의 출력을 시작할 때"로 하느냐의 차이
	// 어지간하면 전자로 잡을 일은 없고, 이건 설명을 위해 잠깐 여기다 만들어뒀던 것

	UINT stride = sizeof(Vertex);
	// 정점의 크기가 얼마인지를 기록하는 역할
	// DirectX에서 출력을 담당하고 있는 클래스들에서는 어떤 정점이 들어와있는지를 자동으로 구분하지 못함
	// 따라서 우리가 어떤 정점을 사용하고 있다고 정점 데이터를 넘길 때 같이 써야 하는데,
	// 그 때 이 정점이 몇바이트를 차지하고 있는지 같이 넘겨서 정점의 데이터를 정확히 구분짓는데 사용하도록 함

	UINT offset = 0;
	// 어떤 오프셋을 사용할 것인지 결정하는 변수
	// 적어도 우리는 사용할 일이 없으므로 0으로 고정한다고 생각해도 무방

	// 정확히는 어떤 데이터셋(=오프셋)을 사용할 것인지를 결정하는 값..인데,
	// 우리는 그 데이터셋을 둘 이상 만들 일이 없으므로 0으로 고정하지 않으면 제대로 출력되지 않음


	Device::Get()->GetDeviceContext()->VSSetShader(VS->GetVertexShader(), nullptr, 0);
	Device::Get()->GetDeviceContext()->PSSetShader(PS->GetPixelShader(), nullptr, 0);
	// 각각 DirectX의 DeviceContext에 정점 셰이더와 픽셀 셰이더를 등록하는 함수들
	// DirectX는 그래픽을 출력할 때 입력된 정점들의 데이터를 여러 단계의 셰이더를 이용해서 변환시키는 것으로
	// 모니터에 출력 가능한 데이터로 변환을 시키는데,
	// 그 과정에서 어떤 셰이더를 사용할 것인지 설정하는 함수
	// 여기선 Scene 클래스 자체가 가지고 있는 멤버를 입력하는 것


	Device::Get()->GetDeviceContext()->IASetInputLayout(VS->GetInputLayout());
	// 정점 셰이더를 이용할 때 우리가 사용하는 정점이 어떤 구조로 이뤄져있는지를
	// InputLayout이라는 클래스를 이용해 저장하고 있는데,
	// 이를 DeviceContext에 등록하여 앞으로 입력될 정점들의 어느 바이트부터 어느 바이트까지가
	// 어떤 역할을 하는 값인지의 레이아웃을 인식할 수 있도록 하는 역할


	// 이하의 코드들은 (반복문을 제외하고) 기본적으로 아래 3개의 함수를 이용해서
	// 하나의 도형을 그리는 데 이용된다고 봐도 무방 
	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, list_triangle->GetBuffer(), &stride, &offset);
	// 도형의 정점을 기록하고 있는 데이터를 셰이더에 넘김
	// 앞의 0과 1은 우리가 건드릴 일이 없는 값이므로 무시해도 무방
	// 그 뒤에는 각각 정점이 기록되어 있는 버퍼(ID3D11Buffer*), 그 버퍼에 들어가있는 정점의 용량,
	// 이 정점이 사용할 오프셋을 입력

	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_triangle->GetType());
	// DeviceContext에다가 지금 우리가 출력하고자 하는 것이 어떤 식으로 출력될 것인지를 알려서
	// 해당 내용으로 출력하도록 세팅해주는 함수
	// D3D11_PRIMITIVE_TOPOLOGY 열거형을 여기다가 입력

	Device::Get()->GetDeviceContext()->Draw(list_triangle->GetVertexSize(), 0);
	// DirectX 장치에 "현재 장치에 등록된 버퍼에서
	// list_triangle->GetVertexSize()만큼의 정점을 0번째 인덱스에서부터 시작해 차례대로 출력하라"는 명령
	// 이 도형은 삼각형을 그리는 도형이고 생성자 쪽에서 정점을 총 3개만 입력했었으므로
	// 해당 버퍼에 들어가있는 정점의 개수는 총 3개니
	// "list_triangle의 정점이 등록된 버퍼에서 처음 정점부터 시작해 총 3개의 정점으로 그림을 그려라"라는 뜻



	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, list_rect->GetBuffer(), &stride, &offset);
	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_rect->GetType());

	Device::Get()->GetDeviceContext()->Draw(list_rect->GetVertexSize(), 0);

	

	for (int i = 0; i < 10; i++)
	{
		if (list_hexagon[i] == NULL)
			break;
		Device::Get()->GetDeviceContext()->IASetVertexBuffers
		(0, 1, list_hexagon[i]->GetBuffer(), &stride, &offset);
		Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_hexagon[i]->GetType());

		Device::Get()->GetDeviceContext()->Draw(list_hexagon[i]->GetVertexSize(), 0);
	}

	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, line_hexagon->GetBuffer(), &stride, &offset);
	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(line_hexagon->GetType());

	Device::Get()->GetDeviceContext()->Draw(line_hexagon->GetVertexSize(), 0);

}


/*
과제 : 지금 이 프로젝트는 도형을 출력하기 위해 여러 클래스들을 만들어둔 상황

이 클래스들의 파일을 뜯어보면서 어떤 식으로 도형을 구성하고 있는지 체크해보고,
기존에 이미 만들어져 있는 도형들을 보면서(=빌드한 결과물을 보면서) 어떤 식으로 오브젝트를 만드는지 파악한 뒤에

선으로 이뤄진 별(오망성)을 한 번 만들어볼 것

기존 도형은 어떻게 하든 상관없음 -> 지워도 되고 그냥 추가로 그려도 되고

*/