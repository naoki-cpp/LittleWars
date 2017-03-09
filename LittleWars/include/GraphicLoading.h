#pragma once
#include <memory>
#include "GraphicElement.h"
#include "../include/Resource.h"

enum GraphType{
	PLAYER = 0,
	NORMAL_ENEMY,
	STRONG_ENEMY,
	EXTREME_ENEMY,
	MISSILE,
	LOCK_ON_SIGHT,
	MACHINEGUN,
	EXPLOSION,
	TYPE_NUM
};
//グラフロードクラス
class GraphicLoading
{
public:

	GraphicLoading()
	{
		graphic_[GraphType::PLAYER] = std::make_shared<GraphicElement>(PLAYERGRAPH);
		graphic_[GraphType::NORMAL_ENEMY] = std::make_shared<GraphicElement>(NORMAL_ENEMY_GRAPH);
		graphic_[GraphType::STRONG_ENEMY] = std::make_shared<GraphicElement>(STRONG_ENEMY_GRAPH);
		graphic_[GraphType::EXTREME_ENEMY] = std::make_shared<GraphicElement>(EXTREME_ENEMY_GRAPH);
		graphic_[GraphType::MISSILE] = std::make_shared<GraphicElement>(MISSILE_GRAPH);
		graphic_[GraphType::LOCK_ON_SIGHT] = std::make_shared<GraphicElement>(LOCK_ON_SIGHT_GRAPH);
		graphic_[GraphType::MACHINEGUN] = std::make_shared<GraphicElement>(MACHINEGUN_GRAPH);
		graphic_[GraphType::EXPLOSION] = std::make_shared<GraphicElement>(EXPLOSION_GRAPH, lws::Vector<size_t>(64, 64), lws::Vector<size_t>(16, 1));
	}
	std::shared_ptr<GraphicElement> GetGraphicPtr(GraphType type)const { return graphic_[type]; }
	virtual ~GraphicLoading()
	{
	}
private:
	std::shared_ptr<GraphicElement> graphic_[static_cast<size_t>(GraphType::TYPE_NUM)];
};

