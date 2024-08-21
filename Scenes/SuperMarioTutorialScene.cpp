#include "framework.h"

SuperMarioTutorialScene::SuperMarioTutorialScene()
{
	SetMap();
}

SuperMarioTutorialScene::~SuperMarioTutorialScene()
{
	delete background;

	for (auto tl : topography_list)
		delete tl;

	for (auto ml : monster_list)
		delete ml;

	delete player;

	delete game_clear;
	delete game_over;
	delete restart_message;
	delete play_message;


	for (int i = 0; i < 6; i++)
	{
		delete number_0[i];
		delete number_1[i];
		delete number_2[i];
		delete number_3[i];
		delete number_4[i];
		delete number_5[i];
		delete number_6[i];
		delete number_7[i];
		delete number_8[i];
		delete number_9[i];
	}
}

void SuperMarioTutorialScene::Update()
{
	// 항상 나오게
	play_message->is_active = true;
	play_message->Update();

	switch (player->GetPlayerPow())
	{
	case Player::PLAYER_POW::MINI:
		full_heart[0]->is_active = true;
		full_heart[1]->is_active = false;
		full_heart[2]->is_active = false;
		empty_heart[0]->is_active = false;
		empty_heart[1]->is_active = true;
		empty_heart[2]->is_active = true;
		break;
	case Player::PLAYER_POW::NORMAL:
		full_heart[0]->is_active = true;
		full_heart[1]->is_active = true;
		full_heart[2]->is_active = false;
		empty_heart[0]->is_active = false;
		empty_heart[1]->is_active = false;
		empty_heart[2]->is_active = true;
		break;
	case Player::PLAYER_POW::FIRE:
		full_heart[0]->is_active = true;
		full_heart[1]->is_active = true;
		full_heart[2]->is_active = true;
		empty_heart[0]->is_active = false;
		empty_heart[1]->is_active = false;
		empty_heart[2]->is_active = false;
		break;
	default:
		break;
	}

	for (int i = 0; i < 3; i++)
	{
		full_heart[i]->Update();
		empty_heart[i]->Update();
	}

	// 평상시
	if (player->GetIsChange() == false && player->GetIsDead() == false)
	{
		background->Update();

		if (bamba->pos.y < -1000.0f)
			bamba->SetPlace(11, 8);

		if (ddang_gamba->pos.y < -1000.0f)
			ddang_gamba->SetPlace(35, 8);

		if (time_count > 100)
		{
			player->SetIsDead(true);
			player->StopTimeUpdate();
		}

		if (bamba->GetCollider()->is_active || ddang_gamba->GetCollider()->is_active)
		{
			play_time += DELTA;
			reset_time += DELTA;
			for (int i = 0; i < 6; i++)
			{
				number_0[i]->Update();
				number_1[i]->Update();
				number_2[i]->Update();
				number_3[i]->Update();
				number_4[i]->Update();
				number_5[i]->Update();
				number_6[i]->Update();
				number_7[i]->Update();
				number_8[i]->Update();
				number_9[i]->Update();
			}

			if (reset_time > 1.0f)
			{
				reset_time = 0.0f;
				time_count++;
			}

			switch (time_count % 10)
			{
			case 0:
				number_1[2]->is_active = false;
				number_0[2]->is_active = true;
				break;
			case 1:
				if (number_0[1]->is_active == false || number_0[0]->is_active == false)
				{
					number_0[2]->is_active = false;
					number_9[2]->is_active = true;
				}
				break;
			case 2:
				number_9[2]->is_active = false;
				number_8[2]->is_active = true;
				break;
			case 3:
				number_8[2]->is_active = false;
				number_7[2]->is_active = true;
				break;
			case 4:
				number_7[2]->is_active = false;
				number_6[2]->is_active = true;
				break;
			case 5:
				number_6[2]->is_active = false;
				number_5[2]->is_active = true;
				break;
			case 6:
				number_5[2]->is_active = false;
				number_4[2]->is_active = true;
				break;
			case 7:
				number_4[2]->is_active = false;
				number_3[2]->is_active = true;
				break;
			case 8:
				number_3[2]->is_active = false;
				number_2[2]->is_active = true;
				break;
			case 9:
				number_2[2]->is_active = false;
				number_1[2]->is_active = true;
				break;
			default:
				break;
			}

			switch (time_count / 10)
			{
			case 0:
				if (time_count % 10 != 0)
				{
					number_0[1]->is_active = false;
					number_9[1]->is_active = true;
				}
				break;
			case 1:
				if (time_count % 10 != 0)
				{
					number_9[1]->is_active = false;
					number_8[1]->is_active = true;
				}
				break;
			case 2:
				if (time_count % 10 != 0)
				{
					number_8[1]->is_active = false;
					number_7[1]->is_active = true;
				}
				break;
			case 3:
				if (time_count % 10 != 0)
				{
					number_7[1]->is_active = false;
					number_6[1]->is_active = true;
				}
				break;
			case 4:
				if (time_count % 10 != 0)
				{
					number_6[1]->is_active = false;
					number_5[1]->is_active = true;
				}
				break;
			case 5:
				if (time_count % 10 != 0)
				{
					number_5[1]->is_active = false;
					number_4[1]->is_active = true;
				}
				break;
			case 6:
				if (time_count % 10 != 0)
				{
					number_4[1]->is_active = false;
					number_3[1]->is_active = true;
				}
				break;
			case 7:
				if (time_count % 10 != 0)
				{
					number_3[1]->is_active = false;
					number_2[1]->is_active = true;
				}
				break;
			case 8:
				if (time_count % 10 != 0)
				{
					number_2[1]->is_active = false;
					number_1[1]->is_active = true;
				}
				break;
			case 9:
				if (time_count % 10 != 0)
				{
					number_1[1]->is_active = false;
					number_0[1]->is_active = true;
				}
				break;
			default:
				break;
			}

			if ((100 - time_count) == 100)
			{
				number_1[0]->is_active = true;
				number_0[0]->is_active = false;
			}
			else
			{
				number_1[0]->is_active = false;
				number_0[0]->is_active = true;
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (black_piranha[i]->pos.y < -1000.0f)
				black_piranha[i]->SetPlace(13 + (i * 13), 7);
		}

		for (auto tl : topography_list)
		{
			tl->Update();

			player->TopographyCollide(tl->GetCollider());

			for (auto ml : monster_list)
				ml->TopographyCollide(tl->GetCollider());
		}

		for (auto ml : monster_list)
		{
			ml->Update();
			player->MonsterCollide(ml->GetCollider());
			ml->PlayerCollide(player->GetCollider());
		}

		player->Update();
	}
	// 데미지를 입었을 때(죽었을 때 X)
	else if (player->GetIsChange() == true)
	{
		if (stop_time == 1.0f)
			pow = player->GetPlayerPow();

		stop_time -= DELTA;

		switch (pow)
		{
		case Player::PLAYER_POW::MINI:
			break;
		case Player::PLAYER_POW::NORMAL:
			if ((int)(stop_time * 5) % 2 == 0)
			{
				player->SetPow(Player::PLAYER_POW::MINI);
			}
			else
			{
				player->SetPow(Player::PLAYER_POW::NORMAL);
			}
			break;
		case Player::PLAYER_POW::FIRE:
			if ((int)(stop_time * 5) % 2 == 0)
			{
				player->SetPow(Player::PLAYER_POW::NORMAL);
			}
			else
			{
				player->SetPow(Player::PLAYER_POW::FIRE);
			}
			break;
		default:
			break;
		}

		player->StopTimeUpdate();

		if (stop_time <= 0.0f)
		{
			player->SetIsChange(false);
			stop_time = 1.0f;
			switch (pow)
			{
			case Player::PLAYER_POW::MINI:
				break;
			case Player::PLAYER_POW::NORMAL:
				player->SetPow(Player::PLAYER_POW::MINI);
				break;
			case Player::PLAYER_POW::FIRE:
				player->SetPow(Player::PLAYER_POW::NORMAL);
				break;
			default:
				break;
			}
		}
	}
	// 죽었을 때
	else if (player->GetIsDead() == true)
	{
		for (int i = 0; i < 3; i++)
		{
			full_heart[i]->is_active = false;
			empty_heart[i]->is_active = true;
		}

		if (stop_time == 1.0f)
		{
			jump_speed = -500.0f;
			gravity = 100.0f;
		}

		stop_time -= DELTA;
		player->StopTimeUpdate();

		if (stop_time < 0.0f)
		{
			if (jump_speed > 600.0f)
			{
				jump_speed = 600.0f;
			}
			jump_speed += (gravity * 13.0f) * DELTA;
			player->pos.y += jump_speed * DELTA;

			restart_message_time -= DELTA;

			// 반 투명화
			background->SetClear();
			for (auto tl : topography_list)
			{
				tl->SetColor(Float4(0.5f, 0.5f, 0.5f, 1.0f));
			}

			for (auto ml : monster_list)
			{
				ml->SetColor(Float4(0.5f, 0.5f, 0.5f, 1.0f));
			}

			for (int i = 0; i < 3; i++)
			{
				number_0[i]->is_active = false;
				number_1[i]->is_active = false;
				number_2[i]->is_active = false;
				number_3[i]->is_active = false;
				number_4[i]->is_active = false;
				number_5[i]->is_active = false;
				number_6[i]->is_active = false;
				number_7[i]->is_active = false;
				number_8[i]->is_active = false;
				number_9[i]->is_active = false;

				full_heart[i]->is_active = false;
				empty_heart[i]->is_active = false;
			}

			player->SetColor(Float4(0.5f, 0.5f, 0.5f, 1.0f));

			play_message->is_active = false;
			play_message->Update();

			game_over->is_active = true;
			game_over->Update();
			if (restart_message_time <= 0.0f)
			{
				restart_message->is_active = true;
				restart_message->Update();
				restart_message_time == 0.0f;
			}
		}
	}

	if (player->pos.y > 1000.0f)
	{
		if (stop_time < 0.0f)
		{
			stop_time = 0.0f;
		}
		player->pos.y = 1000.0f;
	}

	if (!bamba->GetCollider()->is_active && !ddang_gamba->GetCollider()->is_active)
	{
		restart_message_time -= DELTA;

		// 반 투명화
		background->SetClear();
		for (auto tl : topography_list)
		{
			tl->SetColor(Float4(0.5f, 0.5f, 0.5f, 1.0f));
		}

		for (auto ml : monster_list)
		{
			ml->SetColor(Float4(0.5f, 0.5f, 0.5f, 1.0f));
		}

		for (int i = 0; i < 3; i++)
		{
			number_0[i]->is_active = false;
			number_1[i]->is_active = false;
			number_2[i]->is_active = false;
			number_3[i]->is_active = false;
			number_4[i]->is_active = false;
			number_5[i]->is_active = false;
			number_6[i]->is_active = false;
			number_7[i]->is_active = false;
			number_8[i]->is_active = false;
			number_9[i]->is_active = false;
		}

		player->SetColor(Float4(0.5f, 0.5f, 0.5f, 1.0f));
		for (int i = 0; i < 3; i++)
		{
			full_heart[i]->is_active = false;
			empty_heart[i]->is_active = false;
		}

		play_message->is_active = false;
		play_message->Update();
		game_clear->is_active = true;
		game_clear->Update();

		switch ((int)(restart_message_time * 100.0f) % 10)
		{
		case 0:
			for (int i = 0; i < 3; i++)
			{
				number_1[i + 3]->is_active = false;
				number_2[i + 3]->is_active = false;
				number_4[i + 3]->is_active = false;
				number_5[i + 3]->is_active = false;
				number_7[i + 3]->is_active = false;
				number_8[i + 3]->is_active = false;
				number_9[i + 3]->is_active = false;
			}
			number_0[3]->is_active = true;
			number_0[4]->is_active = false;
			number_0[5]->is_active = false;

			number_3[3]->is_active = false;
			number_3[4]->is_active = true;
			number_3[5]->is_active = false;

			number_6[3]->is_active = false;
			number_6[4]->is_active = false;
			number_6[5]->is_active = true;
			break;
		case 1:
			for (int i = 0; i < 3; i++)
			{
				number_0[i + 3]->is_active = false;
				number_2[i + 3]->is_active = false;
				number_3[i + 3]->is_active = false;
				number_5[i + 3]->is_active = false;
				number_6[i + 3]->is_active = false;
				number_8[i + 3]->is_active = false;
				number_9[i + 3]->is_active = false;
			}
			number_1[3]->is_active = true;
			number_1[4]->is_active = false;
			number_1[5]->is_active = false;

			number_4[3]->is_active = false;
			number_4[4]->is_active = true;
			number_4[5]->is_active = false;

			number_7[3]->is_active = false;
			number_7[4]->is_active = false;
			number_7[5]->is_active = true;
			break;
		case 2:
			for (int i = 0; i < 3; i++)
			{
				number_0[i + 3]->is_active = false;
				number_1[i + 3]->is_active = false;
				number_3[i + 3]->is_active = false;
				number_4[i + 3]->is_active = false;
				number_6[i + 3]->is_active = false;
				number_7[i + 3]->is_active = false;
				number_9[i + 3]->is_active = false;
			}
			number_2[3]->is_active = true;
			number_2[4]->is_active = false;
			number_2[5]->is_active = false;

			number_5[3]->is_active = false;
			number_5[4]->is_active = true;
			number_5[5]->is_active = false;

			number_8[3]->is_active = false;
			number_8[4]->is_active = false;
			number_8[5]->is_active = true;
			break;
		case 3:
			for (int i = 0; i < 3; i++)
			{
				number_0[i + 3]->is_active = false;
				number_1[i + 3]->is_active = false;
				number_2[i + 3]->is_active = false;
				number_4[i + 3]->is_active = false;
				number_5[i + 3]->is_active = false;
				number_7[i + 3]->is_active = false;
				number_8[i + 3]->is_active = false;
			}
			number_3[3]->is_active = true;
			number_3[4]->is_active = false;
			number_3[5]->is_active = false;

			number_6[3]->is_active = false;
			number_6[4]->is_active = true;
			number_6[5]->is_active = false;

			number_9[3]->is_active = false;
			number_9[4]->is_active = false;
			number_9[5]->is_active = true;
			break;
		case 4:
			for (int i = 0; i < 3; i++)
			{
				number_1[i + 3]->is_active = false;
				number_2[i + 3]->is_active = false;
				number_3[i + 3]->is_active = false;
				number_5[i + 3]->is_active = false;
				number_6[i + 3]->is_active = false;
				number_8[i + 3]->is_active = false;
				number_9[i + 3]->is_active = false;
			}
			number_4[3]->is_active = true;
			number_4[4]->is_active = false;
			number_4[5]->is_active = false;

			number_7[3]->is_active = false;
			number_7[4]->is_active = true;
			number_7[5]->is_active = false;

			number_0[3]->is_active = false;
			number_0[4]->is_active = false;
			number_0[5]->is_active = true;
			break;
		case 5:
			for (int i = 0; i < 3; i++)
			{
				number_0[i + 3]->is_active = false;
				number_2[i + 3]->is_active = false;
				number_3[i + 3]->is_active = false;
				number_4[i + 3]->is_active = false;
				number_6[i + 3]->is_active = false;
				number_7[i + 3]->is_active = false;
				number_9[i + 3]->is_active = false;
			}
			number_5[3]->is_active = true;
			number_5[4]->is_active = false;
			number_5[5]->is_active = false;

			number_8[3]->is_active = false;
			number_8[4]->is_active = true;
			number_8[5]->is_active = false;

			number_1[3]->is_active = false;
			number_1[4]->is_active = false;
			number_1[5]->is_active = true;
			break;
		case 6:
			for (int i = 0; i < 3; i++)
			{
				number_0[i + 3]->is_active = false;
				number_1[i + 3]->is_active = false;
				number_3[i + 3]->is_active = false;
				number_4[i + 3]->is_active = false;
				number_5[i + 3]->is_active = false;
				number_7[i + 3]->is_active = false;
				number_8[i + 3]->is_active = false;
			}
			number_6[3]->is_active = true;
			number_6[4]->is_active = false;
			number_6[5]->is_active = false;

			number_9[3]->is_active = false;
			number_9[4]->is_active = true;
			number_9[5]->is_active = false;

			number_2[3]->is_active = false;
			number_2[4]->is_active = false;
			number_2[5]->is_active = true;
			break;
		case 7:
			for (int i = 0; i < 3; i++)
			{
				number_1[i + 3]->is_active = false;
				number_2[i + 3]->is_active = false;
				number_4[i + 3]->is_active = false;
				number_5[i + 3]->is_active = false;
				number_6[i + 3]->is_active = false;
				number_8[i + 3]->is_active = false;
				number_9[i + 3]->is_active = false;
			}
			number_7[3]->is_active = true;
			number_7[4]->is_active = false;
			number_7[5]->is_active = false;

			number_0[3]->is_active = false;
			number_0[4]->is_active = true;
			number_0[5]->is_active = false;

			number_3[3]->is_active = false;
			number_3[4]->is_active = false;
			number_3[5]->is_active = true;
			break;
		case 8:
			for (int i = 0; i < 3; i++)
			{
				number_0[i + 3]->is_active = false;
				number_2[i + 3]->is_active = false;
				number_3[i + 3]->is_active = false;
				number_5[i + 3]->is_active = false;
				number_6[i + 3]->is_active = false;
				number_7[i + 3]->is_active = false;
				number_9[i + 3]->is_active = false;
			}
			number_8[3]->is_active = true;
			number_8[4]->is_active = false;
			number_8[5]->is_active = false;

			number_1[3]->is_active = false;
			number_1[4]->is_active = true;
			number_1[5]->is_active = false;

			number_4[3]->is_active = false;
			number_4[4]->is_active = false;
			number_4[5]->is_active = true;
			break;
		case 9:
			for (int i = 0; i < 3; i++)
			{
				number_0[i + 3]->is_active = false;
				number_1[i + 3]->is_active = false;
				number_3[i + 3]->is_active = false;
				number_4[i + 3]->is_active = false;
				number_6[i + 3]->is_active = false;
				number_7[i + 3]->is_active = false;
				number_8[i + 3]->is_active = false;
			}
			number_9[3]->is_active = true;
			number_9[4]->is_active = false;
			number_9[5]->is_active = false;

			number_2[3]->is_active = false;
			number_2[4]->is_active = true;
			number_2[5]->is_active = false;

			number_5[3]->is_active = false;
			number_5[4]->is_active = false;
			number_5[5]->is_active = true;
			break;
		default:
			break;
		}


		if (restart_message_time <= 0.0f)
		{
			//clear_time -= DELTA;
			restart_message_time == 0.0f;

			// 분 기록
			switch (time_count / 60)
			{
			case 0:
				number_0[3]->is_active = true;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 1:
				number_0[3]->is_active = false;
				number_1[3]->is_active = true;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 2:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = true;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 3:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = true;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 4:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = true;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 5:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = true;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 6:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = true;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 7:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = true;
				number_8[3]->is_active = false;
				number_9[3]->is_active = false;
				break;
			case 8:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = true;
				number_9[3]->is_active = false;
				break;
			case 9:
				number_0[3]->is_active = false;
				number_1[3]->is_active = false;
				number_2[3]->is_active = false;
				number_3[3]->is_active = false;
				number_4[3]->is_active = false;
				number_5[3]->is_active = false;
				number_6[3]->is_active = false;
				number_7[3]->is_active = false;
				number_8[3]->is_active = false;
				number_9[3]->is_active = true;
				break;
			default:
				break;
			}

			// 초 기록 표시(10의 자리)
			switch (time_count / 10)
			{
			case 0:
				number_0[4]->is_active = true;
				number_1[4]->is_active = false;
				number_2[4]->is_active = false;
				number_3[4]->is_active = false;
				number_4[4]->is_active = false;
				number_5[4]->is_active = false;
				number_6[4]->is_active = false;
				number_7[4]->is_active = false;
				number_8[4]->is_active = false;
				number_9[4]->is_active = false;
				break;
			case 1:
				number_0[4]->is_active = false;
				number_1[4]->is_active = true;
				number_2[4]->is_active = false;
				number_3[4]->is_active = false;
				number_4[4]->is_active = false;
				number_5[4]->is_active = false;
				number_6[4]->is_active = false;
				number_7[4]->is_active = false;
				number_8[4]->is_active = false;
				number_9[4]->is_active = false;
				break;
			case 2:
				number_0[4]->is_active = false;
				number_1[4]->is_active = false;
				number_2[4]->is_active = true;
				number_3[4]->is_active = false;
				number_4[4]->is_active = false;
				number_5[4]->is_active = false;
				number_6[4]->is_active = false;
				number_7[4]->is_active = false;
				number_8[4]->is_active = false;
				number_9[4]->is_active = false;
				break;
			case 3:
				number_0[4]->is_active = false;
				number_1[4]->is_active = false;
				number_2[4]->is_active = false;
				number_3[4]->is_active = true;
				number_4[4]->is_active = false;
				number_5[4]->is_active = false;
				number_6[4]->is_active = false;
				number_7[4]->is_active = false;
				number_8[4]->is_active = false;
				number_9[4]->is_active = false;
				break;
			case 4:
				number_0[4]->is_active = false;
				number_1[4]->is_active = false;
				number_2[4]->is_active = false;
				number_3[4]->is_active = false;
				number_4[4]->is_active = true;
				number_5[4]->is_active = false;
				number_6[4]->is_active = false;
				number_7[4]->is_active = false;
				number_8[4]->is_active = false;
				number_9[4]->is_active = false;
				break;
			case 5:
				number_0[4]->is_active = false;
				number_1[4]->is_active = false;
				number_2[4]->is_active = false;
				number_3[4]->is_active = false;
				number_4[4]->is_active = false;
				number_5[4]->is_active = true;
				number_6[4]->is_active = false;
				number_7[4]->is_active = false;
				number_8[4]->is_active = false;
				number_9[4]->is_active = false;
				break;
			default:
				break;
			}

			// 초 기록 표시(1의 자리)
			switch (time_count % 10)
			{
			case 0:
				number_0[5]->is_active = true;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 1:
				number_0[5]->is_active = false;
				number_1[5]->is_active = true;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 2:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = true;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 3:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = true;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 4:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = true;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 5:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = true;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 6:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = true;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 7:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = true;
				number_8[5]->is_active = false;
				number_9[5]->is_active = false;
				break;
			case 8:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = true;
				number_9[5]->is_active = false;
				break;
			case 9:
				number_0[5]->is_active = false;
				number_1[5]->is_active = false;
				number_2[5]->is_active = false;
				number_3[5]->is_active = false;
				number_4[5]->is_active = false;
				number_5[5]->is_active = false;
				number_6[5]->is_active = false;
				number_7[5]->is_active = false;
				number_8[5]->is_active = false;
				number_9[5]->is_active = true;
				break;
			default:
				break;
			}


			restart_message->is_active = true;
			restart_message->Update();

			//if (clear_time <= 0.0f)
			//{
			//	clear_time == 0.0f;
			//}
		}
		player->SetIsInvincible(true);
	}


	if (restart_message->is_active)
	{
		if (KEY_CON->Down('R'))
		{
			for (auto tl : topography_list)
				topography_list.pop_back();

			for (auto ml : monster_list)
				monster_list.pop_back();

			SetMap();
		}
	}
}

void SuperMarioTutorialScene::Render()
{
	background->Render();

	for (auto tl : topography_list)
		tl->Render();

	for (auto ml : monster_list)
		ml->Render();

	player->Render();

	game_over->Render();
	game_clear->Render();
	restart_message->Render();
	play_message->Render();

	for (int i = 0; i < 6; i++)
	{
		number_0[i]->Render();
		number_1[i]->Render();
		number_2[i]->Render();
		number_3[i]->Render();
		number_4[i]->Render();
		number_5[i]->Render();
		number_6[i]->Render();
		number_7[i]->Render();
		number_8[i]->Render();
		number_9[i]->Render();
	}

	for (int i = 0; i < 3; i++)
	{
		full_heart[i]->Render();
		empty_heart[i]->Render();
	}
}

void SuperMarioTutorialScene::PostRender()
{
	ImGui::Text("stop_time : %f", stop_time);
	ImGui::Text("play_time : %f", play_time);
	ImGui::Text("reset_time : %f", reset_time);
	ImGui::Text("time_count : %d", time_count);
	//player->PostRender();
	//black_piranha[1]->PostRender();
}

void SuperMarioTutorialScene::SetMap()
{
	// 플레이타임
	play_time = 0.0f;


	restart_message_time = 1.0f;
	//clear_time = 1.0f;

	// 시간 카운트
	time_count = 0;

	// 배경화면 생성
	background = new Background();

	// 땅 생성 & 세팅
	// 아래 땅
	for (int i = 0; i < 40; i++)
	{
		bottom_ground[i] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_2);
		bottom_ground[i + 40] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_5);

		bottom_ground[i]->SetPlace(i, 21);
		bottom_ground[i + 40]->SetPlace(i, 22);

		topography_list.push_back(bottom_ground[i]);
		topography_list.push_back(bottom_ground[i + 40]);
	}

	// 위 땅
	for (int i = 0; i < 40; i++)
	{
		top_ground[i] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_5);
		top_ground[i + 40] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_8);

		top_ground[i]->SetPlace(i, 0);
		top_ground[i + 40]->SetPlace(i, 1);

		topography_list.push_back(top_ground[i]);
		topography_list.push_back(top_ground[i + 40]);
	}

	// 왼쪽 땅1
	left_ground_1[0] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_1);
	left_ground_1[1] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_2);
	left_ground_1[2] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_3);
	left_ground_1[3] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_7);
	left_ground_1[4] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_8);
	left_ground_1[5] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_9);

	left_ground_1[0]->SetPlace(1, 8);
	left_ground_1[1]->SetPlace(2, 8);
	left_ground_1[2]->SetPlace(3, 8);
	left_ground_1[3]->SetPlace(1, 9);
	left_ground_1[4]->SetPlace(2, 9);
	left_ground_1[5]->SetPlace(3, 9);

	for (int i = 0; i < 6; i++)
		topography_list.push_back(left_ground_1[i]);

	// 왼쪽 땅2
	left_ground_2[0] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_1);
	left_ground_2[1] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_2);
	left_ground_2[2] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_3);
	left_ground_2[3] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_7);
	left_ground_2[4] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_8);
	left_ground_2[5] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_9);

	left_ground_2[0]->SetPlace(12, 8);
	left_ground_2[1]->SetPlace(13, 8);
	left_ground_2[2]->SetPlace(14, 8);
	left_ground_2[3]->SetPlace(12, 9);
	left_ground_2[4]->SetPlace(13, 9);
	left_ground_2[5]->SetPlace(14, 9);

	for (int i = 0; i < 6; i++)
		topography_list.push_back(left_ground_2[i]);

	// 오른쪽 땅1
	right_ground_1[0] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_1);
	right_ground_1[1] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_2);
	right_ground_1[2] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_3);
	right_ground_1[3] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_7);
	right_ground_1[4] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_8);
	right_ground_1[5] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_9);

	right_ground_1[0]->SetPlace(25, 8);
	right_ground_1[1]->SetPlace(26, 8);
	right_ground_1[2]->SetPlace(27, 8);
	right_ground_1[3]->SetPlace(25, 9);
	right_ground_1[4]->SetPlace(26, 9);
	right_ground_1[5]->SetPlace(27, 9);

	for (int i = 0; i < 6; i++)
		topography_list.push_back(right_ground_1[i]);

	// 오른쪽 땅2
	right_ground_2[0] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_1);
	right_ground_2[1] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_2);
	right_ground_2[2] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_3);
	right_ground_2[3] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_7);
	right_ground_2[4] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_8);
	right_ground_2[5] = new Topography(Topography::TOPOGRAPHY_NAME::GROUND_9);

	right_ground_2[0]->SetPlace(36, 8);
	right_ground_2[1]->SetPlace(37, 8);
	right_ground_2[2]->SetPlace(38, 8);
	right_ground_2[3]->SetPlace(36, 9);
	right_ground_2[4]->SetPlace(37, 9);
	right_ground_2[5]->SetPlace(38, 9);

	for (int i = 0; i < 6; i++)
		topography_list.push_back(right_ground_2[i]);

	// 돌 블록 생성 & 세팅
	for (int i = 0; i < 19; i++)
	{
		stoneBlock[i] = new Topography(Topography::TOPOGRAPHY_NAME::STONE_BLOCK);
		stoneBlock[i + 19] = new Topography(Topography::TOPOGRAPHY_NAME::STONE_BLOCK);

		stoneBlock[i]->SetPlace(0, i + 2);
		stoneBlock[i + 19]->SetPlace(39, i + 2);

		topography_list.push_back(stoneBlock[i]);
		topography_list.push_back(stoneBlock[i + 19]);
	}

	// 버섯지형 생성 & 세팅

	// 왼쪽 빨간 버섯 기둥
	for (int i = 0; i < 3; i++)
	{
		red_mushroom_1[i] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);
		red_mushroom_1[i]->SetPlace(5, 18 + i);
		topography_list.push_back(red_mushroom_1[i]);
	}
	// 왼쪽 빨간 버섯 지붕
	red_mushroom_1[3] = new Topography(Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_LEFT);
	red_mushroom_1[3]->SetPlace(3, 17);
	topography_list.push_back(red_mushroom_1[3]);

	for (int i = 0; i < 3; i++)
	{
		red_mushroom_1[i + 4] = new Topography(Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_CENTER);
		red_mushroom_1[i + 4]->SetPlace(4 + i, 17);
		topography_list.push_back(red_mushroom_1[i + 4]);
	}

	red_mushroom_1[7] = new Topography(Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_RIGHT);
	red_mushroom_1[7]->SetPlace(7, 17);
	topography_list.push_back(red_mushroom_1[7]);

	//##################################################
	// 오른쪽 빨간 버섯 기둥
	for (int i = 0; i < 3; i++)
	{
		red_mushroom_2[i] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);
		red_mushroom_2[i]->SetPlace(34, 18 + i);
		topography_list.push_back(red_mushroom_2[i]);
	}
	// 오른쪽 빨간 버섯 지붕
	red_mushroom_2[3] = new Topography(Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_LEFT);
	red_mushroom_2[3]->SetPlace(32, 17);
	topography_list.push_back(red_mushroom_2[3]);

	for (int i = 0; i < 3; i++)
	{
		red_mushroom_2[i + 4] = new Topography(Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_CENTER);
		red_mushroom_2[i + 4]->SetPlace(33 + i, 17);
		topography_list.push_back(red_mushroom_2[i + 4]);
	}

	red_mushroom_2[7] = new Topography(Topography::TOPOGRAPHY_NAME::RED_MUSHROOM_RIGHT);
	red_mushroom_2[7]->SetPlace(36, 17);
	topography_list.push_back(red_mushroom_2[7]);


	//##################################################
	// 왼쪽 노란 버섯 기둥
	for (int i = 0; i < 7; i++)
	{
		yellow_mushroom_1[i] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);
		yellow_mushroom_1[i]->SetPlace(12, 14 + i);
		topography_list.push_back(yellow_mushroom_1[i]);
	}
	// 왼쪽 노란 버섯 지붕
	yellow_mushroom_1[7] = new Topography(Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_LEFT);
	yellow_mushroom_1[7]->SetPlace(10, 13);
	topography_list.push_back(yellow_mushroom_1[7]);

	for (int i = 0; i < 3; i++)
	{
		yellow_mushroom_1[i + 8] = new Topography(Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_CENTER);
		yellow_mushroom_1[i + 8]->SetPlace(11 + i, 13);
		topography_list.push_back(yellow_mushroom_1[i + 8]);
	}

	yellow_mushroom_1[11] = new Topography(Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_RIGHT);
	yellow_mushroom_1[11]->SetPlace(14, 13);
	topography_list.push_back(yellow_mushroom_1[11]);

	//##################################################
	// 오른쪽 노란 버섯 기둥
	for (int i = 0; i < 7; i++)
	{
		yellow_mushroom_2[i] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);
		yellow_mushroom_2[i]->SetPlace(27, 14 + i);
		topography_list.push_back(yellow_mushroom_2[i]);
	}
	// 오른쪽 노란 버섯 지붕
	yellow_mushroom_2[7] = new Topography(Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_LEFT);
	yellow_mushroom_2[7]->SetPlace(25, 13);
	topography_list.push_back(yellow_mushroom_2[7]);

	for (int i = 0; i < 3; i++)
	{
		yellow_mushroom_2[i + 8] = new Topography(Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_CENTER);
		yellow_mushroom_2[i + 8]->SetPlace(26 + i, 13);
		topography_list.push_back(yellow_mushroom_2[i + 8]);
	}

	yellow_mushroom_2[11] = new Topography(Topography::TOPOGRAPHY_NAME::YELLOW_MUSHROOM_RIGHT);
	yellow_mushroom_2[11]->SetPlace(29, 13);
	topography_list.push_back(yellow_mushroom_2[11]);


	//##################################################
	// 왼쪽 초록색 버섯 기둥
	for (int i = 0; i < 2; i++)
	{
		green_mushroom_1[i] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);
		green_mushroom_1[i]->SetPlace(2, 6 + i);
		topography_list.push_back(green_mushroom_1[i]);
	}
	// 왼쪽 초록색 버섯 지붕
	green_mushroom_1[2] = new Topography(Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_LEFT);
	green_mushroom_1[2]->SetPlace(1, 5);
	topography_list.push_back(green_mushroom_1[2]);

	green_mushroom_1[3] = new Topography(Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_CENTER);
	green_mushroom_1[3]->SetPlace(2, 5);
	topography_list.push_back(green_mushroom_1[3]);

	green_mushroom_1[4] = new Topography(Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_RIGHT);
	green_mushroom_1[4]->SetPlace(3, 5);
	topography_list.push_back(green_mushroom_1[4]);

	//##################################################
	// 오른쪽 초록색 버섯 기둥
	for (int i = 0; i < 2; i++)
	{
		green_mushroom_2[i] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);
		green_mushroom_2[i]->SetPlace(37, 6 + i);
		topography_list.push_back(green_mushroom_2[i]);
	}
	// 오른쪽 초록색 버섯 지붕
	green_mushroom_2[2] = new Topography(Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_LEFT);
	green_mushroom_2[2]->SetPlace(36, 5);
	topography_list.push_back(green_mushroom_2[2]);

	green_mushroom_2[3] = new Topography(Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_CENTER);
	green_mushroom_2[3]->SetPlace(37, 5);
	topography_list.push_back(green_mushroom_2[3]);

	green_mushroom_2[4] = new Topography(Topography::TOPOGRAPHY_NAME::GREEN_MUSHROOM_RIGHT);
	green_mushroom_2[4]->SetPlace(38, 5);
	topography_list.push_back(green_mushroom_2[4]);

	//##################################################
	// 중앙 버섯 기둥
	for (int i = 0; i < 19; i++)
	{
		center_mushroom_stalk[i] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);
		center_mushroom_stalk[i + 19] = new Topography(Topography::TOPOGRAPHY_NAME::MUSHROOM_STALK);

		center_mushroom_stalk[i]->SetPlace(18, i + 2);
		center_mushroom_stalk[i + 19]->SetPlace(21, i + 2);

		topography_list.push_back(center_mushroom_stalk[i]);
		topography_list.push_back(center_mushroom_stalk[i + 19]);
	}

	// 구름 블록 생성 & 세팅
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cloudBlock[(i * 4) + j] = new Topography(Topography::TOPOGRAPHY_NAME::CLOUD_BLOCK);
			cloudBlock[(i * 4) + j]->SetPlace(18 + j, 17 - (i * 4));
			topography_list.push_back(cloudBlock[(i * 4) + j]);
		}
	}

	// 다리 블록 생성 & 세팅
	// 왼쪽 다리
	for (int i = 0; i < 8; i++)
	{
		left_bridge[i] = new Topography(Topography::TOPOGRAPHY_NAME::UP_BRIDGE);
		left_bridge[i + 8] = new Topography(Topography::TOPOGRAPHY_NAME::DOWN_BRIDGE);

		left_bridge[i]->SetPlace(4 + i, 8);
		left_bridge[i + 8]->SetPlace(4 + i, 9);

		topography_list.push_back(left_bridge[i]);
		topography_list.push_back(left_bridge[i + 8]);
	}

	// 오른쪽 다리
	for (int i = 0; i < 8; i++)
	{
		right_bridge[i] = new Topography(Topography::TOPOGRAPHY_NAME::UP_BRIDGE);
		right_bridge[i + 8] = new Topography(Topography::TOPOGRAPHY_NAME::DOWN_BRIDGE);

		right_bridge[i]->SetPlace(28 + i, 8);
		right_bridge[i + 8]->SetPlace(28 + i, 9);

		topography_list.push_back(right_bridge[i]);
		topography_list.push_back(right_bridge[i + 8]);
	}

	// 몬스터 생성 & 세팅
	bamba = new Monster(Monster::MONSTER_NAME::BAMBA);
	bamba->SetPlace(11, 8);
	monster_list.push_back(bamba);

	ddang_gamba = new Monster(Monster::MONSTER_NAME::DDANG_GAMBA);
	ddang_gamba->SetPlace(35, 8);
	monster_list.push_back(ddang_gamba);

	for (int i = 0; i < 2; i++)
	{
		black_piranha[i] = new Monster(Monster::MONSTER_NAME::BLACK_PIRANHA);
		black_piranha[i]->SetPlace(13 + (i * 13), 7);
		monster_list.push_back(black_piranha[i]);
	}
	// 플레이어 생성 & 세팅
	player = new Player();
	player->SetPlace(2, 20);

	// 멈춤 시간 1초설정
	stop_time = 1.0f;

	game_over = new Game_Over(Vector2(WIN_CENTER_X, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	game_over->is_active = false;
	game_clear = new Game_Clear(Vector2(WIN_CENTER_X, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	game_clear->is_active = false;
	restart_message = new Restart_Message(Vector2(WIN_CENTER_X, WIN_CENTER_Y + 20), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	restart_message->is_active = false;
	play_message = new Play_Message(Vector2(WIN_CENTER_X, 15), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	play_message->is_active = false;

	for (int i = 0; i < 3; i++)
	{
		full_heart[i] = new Full_Heart(Vector2(50 + (33 * i), 65), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		full_heart[i]->is_active = false;
		full_heart[i]->scale = Vector2(0.027f, 0.027f);
		empty_heart[i] = new Empty_Heart(Vector2(50 + (33 * i), 65), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		empty_heart[i]->is_active = false;
		empty_heart[i]->scale = Vector2(0.027f, 0.027f);
	}

	for (int i = 0; i < 3; i++)
	{
		number_0[i] = new Number_0(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_0[i]->is_active = false;
		number_0[i]->scale = Vector2(0.5f, 0.5f);
		number_1[i] = new Number_1(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_1[i]->is_active = false;
		number_1[i]->scale = Vector2(0.5f, 0.5f);
		number_2[i] = new Number_2(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_2[i]->is_active = false;
		number_2[i]->scale = Vector2(0.5f, 0.5f);
		number_3[i] = new Number_3(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_3[i]->is_active = false;
		number_3[i]->scale = Vector2(0.5f, 0.5f);
		number_4[i] = new Number_4(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_4[i]->is_active = false;
		number_4[i]->scale = Vector2(0.5f, 0.5f);
		number_5[i] = new Number_5(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_5[i]->is_active = false;
		number_5[i]->scale = Vector2(0.5f, 0.5f);
		number_6[i] = new Number_6(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_6[i]->is_active = false;
		number_6[i]->scale = Vector2(0.5f, 0.5f);
		number_7[i] = new Number_7(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_7[i]->is_active = false;
		number_7[i]->scale = Vector2(0.5f, 0.5f);
		number_8[i] = new Number_8(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_8[i]->is_active = false;
		number_8[i]->scale = Vector2(0.5f, 0.5f);
		number_9[i] = new Number_9(Vector2((WIN_CENTER_X * 1.85f) + (25 * i), 60), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
		number_9[i]->is_active = false;
		number_9[i]->scale = Vector2(0.5f, 0.5f);
	}

	// 클리어타임용

	number_0[3] = new Number_0(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_0[4] = new Number_0(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_0[5] = new Number_0(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_1[3] = new Number_1(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_1[4] = new Number_1(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_1[5] = new Number_1(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_2[3] = new Number_2(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_2[4] = new Number_2(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_2[5] = new Number_2(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_3[3] = new Number_3(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_3[4] = new Number_3(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_3[5] = new Number_3(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_4[3] = new Number_4(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_4[4] = new Number_4(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_4[5] = new Number_4(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_5[3] = new Number_5(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_5[4] = new Number_5(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_5[5] = new Number_5(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_6[3] = new Number_6(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_6[4] = new Number_6(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_6[5] = new Number_6(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_7[3] = new Number_7(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_7[4] = new Number_7(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_7[5] = new Number_7(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_8[3] = new Number_8(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_8[4] = new Number_8(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_8[5] = new Number_8(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	number_9[3] = new Number_9(Vector2(WIN_CENTER_X + 135, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_9[4] = new Number_9(Vector2(WIN_CENTER_X + 230, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));
	number_9[5] = new Number_9(Vector2(WIN_CENTER_X + 275, WIN_CENTER_Y - 30), Vector2(WIN_WIDTH, WIN_HEIGHT), Float2(1, 1));

	for (int i = 0; i < 3; i++)
	{
		number_0[i + 3]->is_active = false;
		number_0[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_1[i + 3]->is_active = false;
		number_1[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_2[i + 3]->is_active = false;
		number_2[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_3[i + 3]->is_active = false;
		number_3[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_4[i + 3]->is_active = false;
		number_4[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_5[i + 3]->is_active = false;
		number_5[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_6[i + 3]->is_active = false;
		number_6[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_7[i + 3]->is_active = false;
		number_7[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_8[i + 3]->is_active = false;
		number_8[i + 3]->scale = Vector2(1.0f, 1.0f);
		number_9[i + 3]->is_active = false;
		number_9[i + 3]->scale = Vector2(1.0f, 1.0f);
	}

	// 제한 시간 설정
	// ex) 100초 -> 1 0 0
	number_1[0]->is_active = true;
	number_0[1]->is_active = true;
	number_0[2]->is_active = true;
}
/*
폰트를 구현하는 방식이라는 것이

말 그대로 해당 폰트로러 구성된 각 글자들의 이미지들을 미리 로딩해두고
실제로 이를 이용할 때 그 이미지들 중 일부를 잘라와서
그걸 적재적소에 출력하는 방식

다르게 말하면 해당 글자들을 출력하는 스프라이트를 미리 만들어두어
필요한 위치에 필요한 글자를 그때그때 옮겨 출력하는 것이
폰트 방식으로 글자 등을 출력하는 방법

이를 좀 더 제대로 만든다면 문자열을 입력했을 때 그 문자열을 분해해서
글자 하나하나를 인식해 출력하도록 하는 방식도 가능할 것이나
이렇게 만드는 건 시간이 오래 걸릴 것
-> 게임 엔진에서 폰트를 어떻게 다루나 찾아볼 것을 권장
*/
