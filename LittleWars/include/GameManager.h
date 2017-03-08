#pragma once
#include <list>
#include <memory>
#include "BaseScene.h"
#include "GameControler.h"
#include "GameObject.h"
#include "Collision.h"
#include "GraphicLoading.h"
#include "Player.h"
#include "GameOver.h"


class GameManager :public GameControler, public BaseScene, public std::enable_shared_from_this<GameControler>
{
public:

	GameManager(int *Key, const lws::vector<int> & window, std::shared_ptr<ISceneChanger> changer, int screen_handle);
	virtual ~GameManager(void);
	void Initialize()override;
	void Finalize()override;
	void Update()override;
	void Draw()const override;
	void InformOfBeingCleared()override;
	void AddObject(std::shared_ptr<GameObject> object)override;
private:
	template<typename T>
	T square(T x) { return x*x; }
	const lws::vector<int> &kWindow;
	//グラフィックのポインターを保持するオブジェクト
	std::shared_ptr<GraphicLoading> graph_loader_;
	//ゲームオブジェクトのポインターを管理するオブジェクト
	std::unique_ptr<std::list<std::shared_ptr<GameObject>>> list_game_object_;
	//背景を表示するオブジェクト
	std::unique_ptr<Task> back_ground_graphic_;
	//敵の出現制御
	std::unique_ptr<Task> enemy_appearance_control_;
	//当たり判定を担当するオブジェクト
	std::unique_ptr<Collision> collision_;
	//ゲームオーバーのときの処理を担当するオブジェクト
	std::unique_ptr<GameOver> game_over_;
	//プレーヤーのウィークポインター
	std::weak_ptr<Player> player_;
	bool game_over_flag_;
	//キーの情報を保持する配列
	int *key_input_;
	int bgm_handle_;
	bool ObjectUpdate(std::shared_ptr<GameObject> Object);
	void RunCombinationTest();
	void RunCollisionTest(std::shared_ptr<GameObject> o1, std::shared_ptr<GameObject> o2);
	void NotifyNearestEnemyDistance(std::shared_ptr<GameObject> Object);
	double GetSquareDistance(GameObject &o1, GameObject &o2);
};