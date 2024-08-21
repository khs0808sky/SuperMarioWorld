#include "framework.h"

SRTScene::SRTScene()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	// ���̴� ������ �ʿ��� �÷��׸� �̸� ����

	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);

	world = new MatrixBuffer();

	triangle = new SRTTriangle(Float2(100,100), D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	newt = new NewTriangle(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(1, 1), M_PI / 2,
		Float2(100, 100), D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	newt->SetColor(Float4(1.0f, 1.0f, 1.0f, 1.0f));

	newt2 = new NewTriangle(Vector2(WIN_CENTER_X * 4.0f / 3.0f, WIN_CENTER_Y / 2), Vector2(1, 1), M_PI / 2,
		Float2(100, 100), D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	newt2->SetColor(Float4(1.0f, 1.0f, 1.0f, 1.0f));

	c1 = new NewCircle(Float2(WIN_CENTER_X, WIN_CENTER_Y * 3.0f / 2.0f), Float2(1, 1), 0,
		75.0f, -0.0001f);
	c1->SetColor(Float4(1.0f, 1.0f, 0.0f, 1.0f));

	c2 = new NewCircle(Float2(200, 0), Float2(1, 1), 0,
		75.0f, -0.001f);
	// �� NewCircle�� Update���� �����ϰ����� newt��� �ٸ� ������Ʈ�� �������� ��� �����ϴ� ������Ʈ
	// ���� �� ������Ʈ�� ��ġ�� newt�� ��ġ�� �������� ��� �����
	// -> ���⿡ ���� ��ǥ�� "newt�� �������� �� ��ǥ�迡�� ��� ��ġ�� �ִ��� ����δ� ����"
	c2->SetColor(Float4(0.0f, 1.0f, 1.0f, 1.0f));

	c3 = new NewCircle(Float2(-200, 0), Float2(1, 1), 0,
		50.0f, 0.001f);
	c3->SetColor(Float4(0.0f, 1.0f, 1.0f, 1.0f));

	c4 = new NewCircle(Float2(0, -150), Float2(1, 1), 0,
		40.0f, 0.001f);
	c4->SetColor(Float4(0.1f, 0.1f, 0.1f, 1.0f));

	// ������ �⺻������ ������ ������Ʈ�� ������ ������ ���ۿ� ���� ������
	// �ٸ� ������Ʈ�� ���еǴ� ������ �������� �� �ӵ��� ������ ���ؼ�
	// ������ ������ å���� ���̸� ����� �̿��ؾ� ��

	// �׷��� �ʰ� �°� ������ ���� �̿��Ѵٸ� �׷� ���� � ��ü�� ������ ���� ������,
	// �׳� �̷��� ����� �� �ξ� ������ ����
	stub1 = new NewCircle(Float2(newt->pos.x, newt->pos.y), Float2(1, 1), 0,
		0, 0.0005f);
	stub2 = new NewCircle(Float2(newt->pos.x, newt->pos.y), Float2(1, 1), 0,
		0, -0.0003f);
	stub3 = new NewCircle(Float2(newt->pos.x, newt->pos.y), Float2(1, 1), 0,
		0, -0.0003f);

	// ������ ���ϸ� �� ���̵��� �ǽð����� ������ �� ������Ʈ�� ��ġ�� ���޹ޱ� ������
	// �����ڿ��� ��ǥ�� ������ �ʿ䵵 ���� ��
	// �ٸ�, ó���� ȭ���� �������ִٰ� �����̱� ������ ��츦 ����ϸ�
	// �̸��̸� ó������ �����ϴ� �� �� �����ϱ⿡ �̷��� ������ ��

	is_pause = false;
	// �Ͻ������� �����ϱ� ���� ���� bool �÷���
}

SRTScene::~SRTScene()
{
	delete VS;
	delete PS;
	delete world;
	delete triangle;
	delete newt;
	delete newt2;
	delete c1;
	delete c2;
	delete c3;
	delete stub1;
	delete stub2;
	delete stub3;
}

void SRTScene::Update()
{
	if (KEY_CON->Down('P'))
	{
		is_pause = !is_pause;
	}
	// P�� ������ �Ͻ������� �ǵ��� �ϴ� Ʈ����
	// �� Ʈ���Ŵ� �� �� ������ �� �� ���� �ߵ��Ǿ�� �����ϴ�
	// ��� ������ ������ ��� �۵��ϴ� Press�� �ƴ� ó�� ���� �������� �۵��ϴ� Down�� �̿��ؾ� ��

	// �������� �츮�� ����� ������Ʈ���� Update �Լ��� ���߰� �����Ƿ�
	// ������Ʈ�� ������ Update �Լ��� ����ٰ� ȣ��
	if (is_pause == false)
	{
		newt->Update();
		newt2->Update();
		c1->Update();

		// ������ pos�� �ǽð����� �� ������ �� ������Ʈ�� pos ��ġ�� �޾Ƽ� �̿�
		// �� ������Ʈ���� �ٸ� ������Ʈ�� �������� �ʰ� �� ��ü�� ��ü ������ ��ǥ�� ������ �����Ƿ�
		// �״�� �̿��ص� ��
		stub1->pos = newt->pos;
		stub1->Update();

		// �ٸ�, ���ϼ��� ���� �� �ʵ� GlobalPos()�� �̿��ϴ� ���� ����
		stub2->pos = newt->GlobalPos();
		stub2->Update();


		c2->Update(stub1->GetWorld());
		// c2�� ���, newt�� ���带 �������� �ϹǷ� �翬�� ������Ʈ�� newt�� �����͸� �޾ƿ;� ��
		// �׷��� ������Ʈ �Լ��� newt�� ���带 �Է��ϰ�,
		// Update �Լ� ���ο��� �׷��� �Է¹��� �Լ��� Transform�� ������ �� �̸� �̿��ϴ� WorldUpdate��
		// �θ� ������Ʈ�� ���� ����� �ݿ��� �� ������Ʈ�� ���� ����� ����س��� ��
		c3->Update(stub2->GetWorld());

		// �׷��� �ٸ� ������Ʈ�� ��ġ�� ������� ������Ʈ�� ������Ʈ�� �߽����� �Ͽ� �����ϴ� ��ü��
		// �� �θ� ������Ʈ ���� �ٸ� ������Ʈ�� ������� �����ϴ�, �¾��� ġ�� �����̹Ƿ�
		// ���� ��ü�� �¾翡�� �󸶳� ������������ ����ϰ� ������
		// �� ������ ��� ȭ�� ��ü = �¾�� ��ü���� ��� ��ġ�� �ִ����� ���ؾ�
		// ���������� �߽����� ���� �� ����
		stub3->pos = c2->GlobalPos();
		stub3->Update();

		c4->Update(stub3->GetWorld());
	}
	
}

void SRTScene::Render()
{
	DVC->VSSetShader(VS->GetVertexShader(), nullptr, 0);
	DVC->PSSetShader(PS->GetPixelShader(), nullptr, 0);
	DVC->IASetInputLayout(VS->GetInputLayout());

	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	world->SetVS(0);
	// ���̴��� ���� ����� �ѱ�
	// �̹� ��, �������� ����� Program Ŭ���� ������ �Ѿ���Ƿ�
	// ���⼭�� ������ ���� world�� �����ָ� ��
	// �׷��� �������� ȭ�鿡 ����� ���� ����
	// -> WVP ��ȯ�� ������� �ʰ� ��¸� �ϵ��� ������� ���� �ڵ�ʹ� �޸�
	// ������ ������Ʈ ���õ� WVP ��ȯ�� �̿��� ����� �� �ֵ��� �������� �ʿ䰡 ����

	triangle->Render();
	newt->Render();
	newt2->Render();
	c1->Render();
	c2->Render();
	c3->Render();
	c4->Render();
}

void SRTScene::PostRender()
{
}

/*

���� - ���ݱ��� ���� �� ������� �¾�踦 ������ ��

���� :
1. ��� �༺�� Transform�� ��ӹ��� Ŭ������ ���� ��
2. �¾��� ��ġ�� �߾��̾ �ǰ� �߾� �ϴ��̾ �ǰ� 0,0(ȭ�� ���� �ֻ��)�̾ ���� ����
ũ�⵵ �������
3. ��� �༺���� �����ֱ�� ���� �����ֱ� ���� ���� �޶�� ��
- �����ֱ��� ��쿣 ���� ������ �� �ʿ���� ����
4. �� �༺�� �����̳� ��� ���� ��� �����ص� �������
- �ﰢ���̾ OK, �簢���̾ OK
5. ���� �¾��� ��ġ���� �ʾƵ� ����
- �༺�轺���� ����⸸ �ϸ� ��
- �伺�� ���� �޾��شٴ��� �ϴ� �� ���������� �� �ʿ� ����
- ������ȭ����õ��(��) ���� ���� �ʿ�� ������,
��� ����+�ޱ����� ������� ��

*/
