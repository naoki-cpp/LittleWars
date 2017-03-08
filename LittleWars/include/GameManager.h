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
	//�O���t�B�b�N�̃|�C���^�[��ێ�����I�u�W�F�N�g
	std::shared_ptr<GraphicLoading> graph_loader_;
	//�Q�[���I�u�W�F�N�g�̃|�C���^�[���Ǘ�����I�u�W�F�N�g
	std::unique_ptr<std::list<std::shared_ptr<GameObject>>> list_game_object_;
	//�w�i��\������I�u�W�F�N�g
	std::unique_ptr<Task> back_ground_graphic_;
	//�G�̏o������
	std::unique_ptr<Task> enemy_appearance_control_;
	//�����蔻���S������I�u�W�F�N�g
	std::unique_ptr<Collision> collision_;
	//�Q�[���I�[�o�[�̂Ƃ��̏�����S������I�u�W�F�N�g
	std::unique_ptr<GameOver> game_over_;
	//�v���[���[�̃E�B�[�N�|�C���^�[
	std::weak_ptr<Player> player_;
	bool game_over_flag_;
	//�L�[�̏���ێ�����z��
	int *key_input_;
	int bgm_handle_;
	bool ObjectUpdate(std::shared_ptr<GameObject> Object);
	void RunCombinationTest();
	void RunCollisionTest(std::shared_ptr<GameObject> o1, std::shared_ptr<GameObject> o2);
	void NotifyNearestEnemyDistance(std::shared_ptr<GameObject> Object);
	double GetSquareDistance(GameObject &o1, GameObject &o2);
};