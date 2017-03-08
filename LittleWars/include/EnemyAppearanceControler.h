#pragma once
#include <fstream>
#include <vector>
#include "Task.h"
#include "Enemy.h"
#include "GameControler.h"
#include "GraphicLoading.h"
class EnemyAppearanceCtrl:
	public Task
{
public:
	EnemyAppearanceCtrl(const std::shared_ptr<GraphicLoading> graph_loader,const lws::vector<int> & window,std::weak_ptr<GameControler> controler);
	virtual ~EnemyAppearanceCtrl(void);
	void Initialize()override;
	void Finalize()override;
	void Update()override;
	void Draw()const override;
private:
	size_t AppearanceInterval;
	int appearance_timer_;

	enum class MapType
	{
		NONE,
		NORMAL,
		STRONG
	};
	std::weak_ptr <GameControler> controler_;
	std::shared_ptr<GraphicLoading> graph_loader_;
	std::ifstream map_file_;
	std::vector<std::vector<MapType>> map_;
	size_t current_map;

	const lws::vector<int> & kWindow_;
};