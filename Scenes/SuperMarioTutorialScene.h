#pragma once
class SuperMarioTutorialScene : public Scene
{
private:

	Background* background;

	Topography* bottom_ground[80];
	Topography* top_ground[80];

	Topography* left_ground_1[6];
	Topography* left_ground_2[6];

	Topography* right_ground_1[6];
	Topography* right_ground_2[6];


	Topography* stoneBlock[38];

	Topography* red_mushroom_1[8];
	Topography* red_mushroom_2[8];

	Topography* yellow_mushroom_1[12];
	Topography* yellow_mushroom_2[12];

	Topography* green_mushroom_1[5];
	Topography* green_mushroom_2[5];

	Topography* center_mushroom_stalk[38];

	Topography* cloudBlock[16];

	Topography* left_bridge[16];
	Topography* right_bridge[16];

	vector<Topography*> topography_list;


	Monster* bamba;
	Monster* ddang_gamba;
	Monster* black_piranha[2];

	vector<Monster*> monster_list;


	Player* player;

	float jump_speed;
	float gravity;


	Game_Over* game_over;
	Game_Clear* game_clear;
	Restart_Message* restart_message;
	Play_Message* play_message;

	Number_0* number_0[6];
	Number_1* number_1[6];
	Number_2* number_2[6];
	Number_3* number_3[6];
	Number_4* number_4[6];
	Number_5* number_5[6];
	Number_6* number_6[6];
	Number_7* number_7[6];
	Number_8* number_8[6];
	Number_9* number_9[6];

	Full_Heart* full_heart[3];
	Empty_Heart* empty_heart[3];


public:
	float stop_time;
	float play_time;
	float reset_time; // 타임카운트를 하기 위해 임의로 설정
	float restart_message_time;
	float clear_time; // 클리어 시간을 표시하는 시간
	int time_count;
	Player::PLAYER_POW pow;

	SuperMarioTutorialScene();
	~SuperMarioTutorialScene();


	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	float GetStopTime() { return stop_time; }

	void SetMap();
};