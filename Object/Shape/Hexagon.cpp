#include "framework.h"

Hexagon::Hexagon(float pos_x, float pos_y, float size, D3D11_PRIMITIVE_TOPOLOGY t)
	:	Shape(pos_x, pos_y), type(t)
{
	// Hexagon에선 매개 변수로 정점이 저장된 vector를 받지 않음 :
	// 이 생성자 안에서 그 정점들 자체를 직접 만들 것이기 때문

	float angle = 2 * M_PI;
	// 라디안 법에서 360도를 뜻하는 값(pi의 2배)
	// M_PI : math.h에서 _USE_MATH_DEFINE이 정의되어있는 경우 포함시킬 때 사용할 수 있게 되는
	// 삼각함수용 상수들 중 하나, 원주율 pi의 값

	float screen_ratio = float(WIN_HEIGHT) / float(WIN_WIDTH);
	// 창의 가로와 세로는 같은 절대값에 대하여 비율이 서로 다르기 때문에
	// 이를 보정해줄 값을 미리 계산해줄 필요가 있음

	Float2 this_pos = Float2(ratio_pos_x(pos_x), ratio_pos_y(pos_y));
	// 사실 입력된 값 자체가 float이기 때문에 이걸 가지고 추가로 작업할 필요가 없기는 함
	// 하지만 이렇게 변수로 미리 만들어두는 게 저 ratio_pos_x 등을 계속 이용하는 것보단 쉬움

	switch (type)
	{
	case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
		for(int i = 0; i < 6; i++)
		{
			verticies.emplace_back(this_pos.x, this_pos.y, 1.0f, 0.4f, 0.4f);
			// 삼각형의 첫번째 점으로 사용할, 육각형의 중점을 입력
			verticies.emplace_back(
				this_pos.x - cos(angle) * size * screen_ratio,
				this_pos.y - sin(angle) * size,
				0.4f, 0.4f, 1.0f
			);
			// 삼각함수를 통해 확보한 육각형의 점 중 하나를 추가

			angle -= 2 * M_PI / 6.0f;
			// 각도 보정

			verticies.emplace_back(
				this_pos.x - cos(angle) * size * screen_ratio,
				this_pos.y - sin(angle) * size,
				0.4f, 0.4f, 1.0f
			);
			// 삼각함수를 통해 확보한 육각형의 다음 점을 추가
		}
		break;
		// 이를 총 6개의 삼각형이 육각형을 그리게 하도록 하고 종료

	case D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP:
		for (int i = 0; i <= 6; i++)
		{
			verticies.emplace_back(
				this_pos.x - cos(angle) * size * screen_ratio,
				this_pos.y - sin(angle) * size,
				0.4f, 0.4f, 1.0f
			);
			angle -= 2 * M_PI / 6.0f;
		}
		// 이 쪽은 시작점만 추가로 적어줘야 한다는 점 빼면 꼭지점들만 순차적으로 추가하면 됨
		break;
	}

	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(Vertex) * verticies.size(); // 위에서 구성한 정점들의 총 개수
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = verticies.data();

	Device::Get()->GetDevice()->CreateBuffer(&bd, &initData, &VB);
}
