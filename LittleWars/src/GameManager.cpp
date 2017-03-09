#include "DxLib/DxLib.h"
#include "../include/EnemyAppearanceControler.h"
#include "../include/GameManager.h"
#include "../include/Living.h"
#include "../include/Player.h"
#include "../include/FlexibleCollision.h"
#include "../include/SpaceBackGround.h"
#include "../include/Resource.h"



GameManager::GameManager(int *key, const lws::Vector<int> & window, std::shared_ptr<ISceneChanger> changer, int screen_handle) :
	BaseScene(changer, screen_handle),
	graph_loader_(std::make_shared<GraphicLoading>()),
	kWindow(window),
	key_input_(key),
	list_game_object_(std::make_unique<std::list<std::shared_ptr<GameObject>>>()),
	collision_(std::make_unique<FlexibleCollision>()),
	back_ground_graphic_(std::make_unique<SpaceBackGround>(window)),
	game_over_flag_(false)
{
}

GameManager::~GameManager(void)
{
}

void GameManager::Initialize() {
	enemy_appearance_control_ = std::make_unique<EnemyAppearanceCtrl>(graph_loader_, kWindow, shared_from_this());
	enemy_appearance_control_->Initialize();

	std::shared_ptr<Player> s_player = std::make_shared<Player>(graph_loader_, lws::Vector<double>(kWindow.x_ / 2, kWindow.y_ / 2), lws::Vector<double>(4.0, 4.0), 50, 10, kWindow, key_input_, shared_from_this());
	player_ = s_player;
	AddObject(s_player);
	for (auto object : *list_game_object_) {
		object->Initialize();
	}
	s_player.reset();
	game_over_ = std::make_unique<GameOver>(score_, kWindow, screen_handle_);
	game_over_->Initialize();
	bgm_handle_ = LoadSoundMem(BATTLE_BGM);
	PlaySoundMem(bgm_handle_, DX_PLAYTYPE_LOOP);
}

void GameManager::Finalize()
{
	game_over_->Finalize();
	enemy_appearance_control_->Finalize();
	StopSoundMem(bgm_handle_);
	DeleteSoundMem(bgm_handle_);
}

void GameManager::Update() {
	if (!game_over_flag_)
	{
		RunCombinationTest();
		for (auto game_object = list_game_object_->begin(); game_object != list_game_object_->end();)
		{
			if (!ObjectUpdate(*(game_object))) {
				(*game_object)->Finalize();
				game_object = list_game_object_->erase(game_object);
			}
			else {
				NotifyNearestEnemyDistance(*game_object);
				++game_object;
			}
		}
		enemy_appearance_control_->Update();
		back_ground_graphic_->Update();
		if (player_.expired())
		{
			game_over_flag_ = true;
		}
	}
	else
	{
		game_over_->Update();
		if (game_over_->Finished())
		{
			changer_->ChangeScene(eScene::MENU);
		}
	}
	if (key_input_[KEY_INPUT_ESCAPE] > 0)
	{
		changer_->ChangeScene(eScene::MENU);
	}
}
void GameManager::Draw()const {
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	SetDrawScreen(screen_handle_);
	if (!game_over_flag_)
	{
		for (auto Object : *list_game_object_)Object->Draw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Num of Graph%d", GetGraphNum());
		DrawFormatString(0, 50, GetColor(255, 255, 255), "Num of Objects%d", list_game_object_->size());
		DrawFormatString(0, 70, GetColor(255, 255, 255), "Score%d", score_);
		if (!player_.expired()) {
			std::shared_ptr<Player> s_player = player_.lock();
			DrawBox(0, 0, s_player->GetHitPoint(), 30, GetColor(0, 255, 0), true);
		}
		DrawBox(0, 0, 100, 30, GetColor(255, 255, 255), false);
		back_ground_graphic_->Draw();
		enemy_appearance_control_->Draw();
	}
	else
	{
		game_over_->Draw();
	}
}

void GameManager::InformOfBeingCleared()
{
	game_over_flag_ = true;
}


void GameManager::AddObject(std::shared_ptr<GameObject> object)
{
	if (object)
	{
		list_game_object_->push_back(object);
		object->Initialize();
	}
}

void GameManager::NotifyNearestEnemyDistance(std::shared_ptr<GameObject> game_object) {
	std::shared_ptr<GameObject> NearestObject = nullptr;
	double LeastDistance = square(kWindow.x_) + square(kWindow.y_);//ウィンドウの端から端までの距離以下
	for (auto object_ptr : (*list_game_object_))
	{
		double Distance = GetSquareDistance(*game_object, *object_ptr);
		if (object_ptr->Targetable() && (LeastDistance > Distance) && (static_cast<int>(object_ptr->offensive_value()) * static_cast<int>(game_object->offensive_value()) < 0))
		{
			LeastDistance = Distance;
			NearestObject = object_ptr;
		}
	}
	game_object->NearestEnemy(NearestObject);
}

bool GameManager::ObjectUpdate(std::shared_ptr<GameObject> game_object) {
	if (game_object->DisappearFlag())
	{
		return false;
	}
	game_object->Update();
	return true;
}

void GameManager::RunCollisionTest(std::shared_ptr<GameObject> game_object1, std::shared_ptr<GameObject> game_object2) {
	if ((static_cast<int>(game_object1->offensive_value()) * static_cast<int>(game_object2->offensive_value())) != 1)
	{
		if (collision_->CollisionTest(*game_object2, *game_object1)) {
			game_object1->Attacked(*game_object2);
			game_object2->Attacked(*game_object1);
		}
	}
}

double GameManager::GetSquareDistance(GameObject &game_object1, GameObject &game_object2) {
	return (square(game_object1.GetCoordinateX() - game_object2.GetCoordinateX()) + square(game_object1.GetCoordinateY() - game_object2.GetCoordinateY()));
}

void GameManager::RunCombinationTest() {

	for (auto object_it1 = list_game_object_->begin(); object_it1 != list_game_object_->end(); ++object_it1)
	{
		auto object_it2 = object_it1;
		++object_it2;
		for (; object_it2 != list_game_object_->end(); ++object_it2)
		{
			RunCollisionTest(*object_it1, *object_it2);
		}
	}
}