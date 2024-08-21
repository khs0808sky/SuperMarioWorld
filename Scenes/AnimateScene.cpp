#include "framework.h"

void AnimateScene::change_stage(int stage)
{
	for (auto p : stage_list[this->stage]) 
		// ���������� �ٲ�ٸ� ���� ���������� �ִ� �͵��� ��Ȱ��ȭ�� �ؾ� �ϴ�
		// �׿� �°� ��Ȱ��ȭ �۾��� �׷��� ��ħ
	{
		p->SetActive(false);
		p->GetCollider()->SetActive(false);
	}

	for (auto p : stage_list[stage]) // �̹��� ������ ���͸� �̿��ϴ� ��Ȳ�̴�
		// �̿� �°�ǥ�⸦ �ٲ��ִ� ��
	{
		p->SetActive(true);
		p->GetCollider()->SetActive(true);
		// �̸� ���� ������ ���� ���������� �ִ� ��ֹ����� �� �������� Ȱ��ȭ
	}
	// ���� ���� �ִ� ���� ���� ��Ȱ��ȭ��Ų �� ���� ����� �͵�
	// (+������ ����ߴ� �� ��Ȱ���ϴ� ��Ʈ) <- �̰� ��Ȱ��ȭ�Ǵ� �һ�縦 ���� �� ����

	this->stage = stage;

}

AnimateScene::AnimateScene()
	: stage(0), fade_time(0)
{
	player = new AnimatePlayer();
	player->pos = Vector2(WIN_CENTER_X, WIN_CENTER_Y);

	obstackle = new Platform(Vector2(200, 200), Vector2(400, 200), Vector2(1, 1), 0.0f);
	/*obstackle->SetActive(true);
	obstackle->GetCollider()->SetActive(true);*/

	ground = new Platform(Vector2(WIN_CENTER_X, WIN_HEIGHT - 50), 
		Vector2(WIN_WIDTH - 200, 30), Vector2(1, 1), 0.0f);
	/*ground->SetActive(true);
	ground->GetCollider()->SetActive(true);*/

	platform_list.push_back(obstackle);
	platform_list.push_back(ground);


	platform_list.push_back(new Platform(Vector2(800, 200), 
		Vector2(100, 100), Vector2(1, 1), 90.0f));
	/*platform_list[2]->SetActive(true);
	platform_list[2]->GetCollider()->SetActive(true);*/

	stage_list.push_back(platform_list); // ������ ������� �÷��� ����Ʈ����
	// ù��° �������� �����Ͱ� �ϼ��Ǿ����� �������� ����Ʈ�� �߰�

	vector<Platform*> temp_pList; // �ι�° ���������� ����
	temp_pList.push_back(obstackle);
	temp_pList.push_back(ground);

	temp_pList.push_back(new Platform(Vector2(700, 400),
		Vector2(300, 400), Vector2(1, 1), 0.0f));
	temp_pList.push_back(new Platform(Vector2(120, 600),
		Vector2(50, 50), Vector2(1, 1), 0.0f));

	stage_list.push_back(temp_pList); // �ϼ������� �������� ����Ʈ�� ����

	change_stage(1);

	/*
	��� �ϸ� �̷��� 2�� �̻� ������� ����������
	"�Ѽ�����" �ٲ� �� ������, �ڵ������ � �ڵ带 �ۼ��� ������ �� �� �����غ���

	�ٲ�� ��Ȳ�� �ϴ� D�� ������ �� ���������� �ڵ� ��ȯ��Ű�� ġƮŰ�� ���� ����� �������� ��
	*/
}

AnimateScene::~AnimateScene()
{
	delete player;
	for (auto p : stage_list[stage])
		delete p;
	platform_list.clear();
}

void AnimateScene::Update()
{
	// �������� �浹ó���� ���� ���ε�
	/*
	�浹���� ��� ��� ó���� ���ΰ��� ����غ� ��
	
	�浹 ��ü�� �������� ������� �ۿ��ϵ��� ������ �� ������,
	���������� � ����� ä���ϵ� "��� ���⿡�� �浹�ߴ����� �Ǵ��� �� �ִ� ����� �ʿ���
	*/

	if (KEY_CON->Down('D') && fade_time <= 0)
		// ������ �׸�Ʈ�� ���� ��ư���� ������
		// ���߿��� �̰� ���� �÷��̾� ĳ���Ͱ� ���� ������ ���� �Ǵ� ��ġ�� �����ߴٴ��� �ϴ� ������
		// �ٸ� ������ �ְ� �׿� �°� �ڵ带 �����Ͽ� �� �̵��� �����ϵ��� �ϰ� �� ��
	{
		stage++;
		if (stage > 1) stage = 0;

		fade_time = 1.0f;
	}

	/*
	���� ���� ȭ���� ��ȯ�ϰ� �Ǵ� Ʈ���Ŵ� �����ξ���
	�׷��� ������ �غ��� ȭ�� ��ȯ�� �ʹ� ���۽����� ���� �־ �ڿ��������� ����
	+ ȭ�鿡 ����� �����͵��� �ε��� �ؾ� �ϴµ�, �� �ε��� �Ϸ�Ǳ� ���� ȭ�鿡 ������ �Ǿ������
	�װ� �װʹ�� ���ڿ�������

	�׷���
	ȭ�� ��ȯ�� �ڿ������� �ϴ� ���ÿ�, ���� ȭ�鿡 ����� ������Ʈ���� �̸� ��ġ�صα� ����
	���������� �ð��� ���� Ʈ���� ����ϰ� ��
	(�ϸ�ó�� ���� ȭ������ �Ѿ�� ������ �� ��� �ؼ� ���� ���� �̸� �ε��صδ� ���̶����,
	ȭ���� �˰� ���� �ڿ� ȭ���� �˾����� �� �׷����� �ٲٴ� ó���� �Ϸ��ϰ� ����
	�ٽ� ȭ���� ������� �ϴ� ��� ��)

	���⼭�� �� �� ȭ�� ��ü�� �˾����� ����� ����� �̿��� ����
	-> ��� ������Ʈ�� �÷����۸� �ǵ帮�� ���,
	Ȥ�� �츮�� ����ϴ� ���̴� ��ü���� �߰������� ��� Ȥ�� ���İ��� �ǵ帮�� ���

	���⼱ ��� ������Ʈ�� �÷����۸� �ǵ帮�� ����� �ẽ

	�ʿ��� �� : ȭ���� �˾����� �ð��� ����� �ʿ䰡 ���� -> �ð��� ����� ����

	*/
	if (fade_time <= 0) // ���� ȭ�� ��ȯ���� �ƴ� ���
		// �Ϲ����� ����
	{
		Vector2 obstackle_area;
		// �÷��̾�� �ٸ� �浹ü�� �浹���� ��,
		// ��Ȯ�� �浹�� ������ ��� �Ǵ��� �� ����(�� ũ��)�� ������ �Լ�

		for (auto p : stage_list[stage])
		{

			if (player->GetCollider()->isCollision(p->GetCollider(), &obstackle_area))
				// AABB �浹�� �ٷ� �� ��Ȯ�� ��� ������ �浹�ߴ����� �Է¹��� �����͸� ���� ��ȯ�Ѵ� �ߴµ�
				// �װ� �ٷ� ������ ���ؼ� ������ ����
			{
				// �浹�� �ߴٸ�, �ʿ������� �浹�� ��ŭ = ��ģ ��ŭ�� ������ ������� ��
				// �׷��� �޾ƿ� ������ �÷��̾�, �浹ü ������ �߽����� Ȯ���Ͽ�
				// ��� ���⿡�� �浹�ߴ����� �˻�

				Vector2 player_pos = player->GetCollider()->pos;
				Vector2 obstackle_pos = p->GetCollider()->pos;
				// �׳� ����� �ڵ尡 �ʹ� �����Ƿ� �����̶� �� ª�� ������ ������ �̿�

				if (obstackle_area.x > obstackle_area.y)
					// �浹�� ������ ũ�Ⱑ ���ΰ� ���κ��� �� �� ���
					// == ���� �Ʒ����� �浹�ϱ� ������ ��Ȳ
					// (�����࿡�� �� �İ��� �����ߴ� �̾߱�� ���� �Ʒ����� �����ϱ� �������� ���� �̾߱�)
				{
					if (player_pos.y > obstackle_pos.y) // �÷��̾��� ��ġ�� �浹ü�� ��ġ���� �� ���ٸ�
					// �Ʒ����� �ö󰡰� �ִ� ��Ȳ
					{
						player->pos.y += obstackle_area.y;
						// �浹�� ������ŭ ���ϴ� ������ �� ������ ������
						// ��ǻ� �浹���� �ʰ� �� �̻� �������� ���ϴ� ��Ȳ���� ����� ��
						player->JumpCollide(1);
					}
					else // ������ �������� �ִ� ��Ȳ
					{
						player->pos.y -= obstackle_area.y;
						// �ݴ�� �浹�� ������ŭ ���� �÷���
						// �� �̻� �������� �ʵ��� ó��
						player->JumpCollide(0);
					}
				}
				else // ���� �ƴ� ���, �� �浹 ������ ���ΰ� ���κ��� ū ���
				// = �¿쿡�� �浹�� �߻����� ���
				{
					if (player_pos.x > obstackle_pos.x) // �÷��̾��� ��ġ�� �浹ü�� ��ġ���� �� ���ٸ�
					// �Ʒ����� �ö󰡰� �ִ� ��Ȳ
					{
						player->pos.x += obstackle_area.x;
						// �浹�� ������ŭ ���ϴ� ������ �� ������ ������
						// ��ǻ� �浹���� �ʰ� �� �̻� �������� ���ϴ� ��Ȳ���� ����� ��
						player->JumpCollide(2);
					}
					else // ������ �������� �ִ� ��Ȳ
					{
						player->pos.x -= obstackle_area.x;
						// �ݴ�� �浹�� ������ŭ ���� �÷���
						// �� �̻� �������� �ʵ��� ó��
						player->JumpCollide(3);
					}
				}
			}
		}

		/*
		if (player->GetCollider()->isCollision(ground->GetCollider(), &obstackle_area))
			// ���� ��� �۾����� ���� ����ϴ� �浹ü���� ���������� ó��
		{
			// �浹�� �ߴٸ�, �ʿ������� �浹�� ��ŭ = ��ģ ��ŭ�� ������ ������� ��
			// �׷��� �޾ƿ� ������ �÷��̾�, �浹ü ������ �߽����� Ȯ���Ͽ�
			// ��� ���⿡�� �浹�ߴ����� �˻�

			Vector2 player_pos = player->GetCollider()->pos;
			Vector2 ground_pos = ground->GetCollider()->pos;
			// �׳� ����� �ڵ尡 �ʹ� �����Ƿ� �����̶� �� ª�� ������ ������ �̿�

			if (obstackle_area.x > obstackle_area.y)
				// �浹�� ������ ũ�Ⱑ ���ΰ� ���κ��� �� �� ���
				// == ���� �Ʒ����� �浹�ϱ� ������ ��Ȳ
				// (�����࿡�� �� �İ��� �����ߴ� �̾߱�� ���� �Ʒ����� �����ϱ� �������� ���� �̾߱�)
			{
				if (player_pos.y > ground_pos.y) // �÷��̾��� ��ġ�� �浹ü�� ��ġ���� �� ���ٸ�
				// �Ʒ����� �ö󰡰� �ִ� ��Ȳ
				{
					player->pos.y += obstackle_area.y;
					// �浹�� ������ŭ ���ϴ� ������ �� ������ ������
					// ��ǻ� �浹���� �ʰ� �� �̻� �������� ���ϴ� ��Ȳ���� ����� ��
					player->JumpCollide(1);
				}
				else // ������ �������� �ִ� ��Ȳ
				{
					player->pos.y -= obstackle_area.y;
					// �ݴ�� �浹�� ������ŭ ���� �÷���
					// �� �̻� �������� �ʵ��� ó��
					player->JumpCollide(0);
				}
			}
		}
		*/

		player->Update();
		for (auto p : stage_list[stage])
			p->Update();
	}
	else // ���� ���̵�ƿ� ���� ���
	{
	fade_time -= DELTA;

	Float4 fadecolor;
	if (fade_time > 0) // ���� ���� �˰� �����־�� �� �ð��� �����ִٸ�
		fadecolor = Float4(0, 0, 0, 1); // ����� ó���� �����ڵ带 �̸� ������
	else // �� �̻� ���� ���� �� �ʿ䰡 ���ٸ�
		fadecolor = Float4(1, 1, 1, 1); // �ٽ� ���� ���� ǥ���ϵ���

	player->SetColor(fadecolor); // �̸� ���� �� ������Ʈ���� ���� ���������� ����
	for (auto p : stage_list[stage])
		p->SetColor(fadecolor);

	if (fade_time <= 0)
		change_stage(stage);

	}
}

void AnimateScene::Render()
{
	for (auto p : stage_list[stage])
		p->Render();
	player->Render();
}

void AnimateScene::PostRender()
{
	player->PostRender();
}
