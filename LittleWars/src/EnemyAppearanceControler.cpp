#include <string>
#include "DxLib/DxLib.h"
#include "..\include\EnemyAppearanceControler.h"
#include "../include/NormalEnemy.h"
#include "..\include\StrongEnemy.h"

EnemyAppearanceCtrl::EnemyAppearanceCtrl(std::shared_ptr<GraphicLoading> graph_loader, const lws::Vector<int> & window, std::weak_ptr<GameControler> controler) :
	AppearanceInterval(100),
	graph_loader_(graph_loader),
	appearance_timer_(0),
	controler_(controler),
	kWindow_(window),
	map_file_("map/map"),
	map_(0,std::vector<MapType>(0)),
	current_map(0)
{
}

EnemyAppearanceCtrl::~EnemyAppearanceCtrl(void)
{
}
void EnemyAppearanceCtrl::Initialize()
{
	size_t counter = 0;
	while (!map_file_.eof())
	{
		std::string str;
		map_file_ >> str;
		map_.push_back(std::vector<MapType>(0));
		for (size_t i = 0; i < str.length(); ++i)
		{
			if (str[i] == '1')
			{
				map_[counter].push_back(MapType::NORMAL);
			}
			else if (str[i] == '2')
			{
				map_[counter].push_back(MapType::STRONG);
			}
			else
			{
				map_[counter].push_back(MapType::NONE);
			}

		}
		++counter;
	}
}

void EnemyAppearanceCtrl::Finalize()
{
}

void EnemyAppearanceCtrl::Update()
{
	if (appearance_timer_ <= 0)
	{
		appearance_timer_ = AppearanceInterval;
		if (current_map < map_.size())
		{
			int index = 0;
			for (auto obj_type : map_[current_map])
			{
				switch (obj_type)
				{
				case MapType::NONE:
					break;
				case MapType::NORMAL:
					controler_.lock()->AddObject(std::make_shared<NormalEnemy>(graph_loader_, lws::Vector<double>(static_cast<double>(index) *kWindow_.x_/ map_[current_map].size() + 21, 32), lws::Vector<double>(0.0, 0.5), kWindow_, controler_));
					break;
				case MapType::STRONG:
					controler_.lock()->AddObject(std::make_shared<StrongEnemy>(graph_loader_, lws::Vector<double>(static_cast<double>(index) *kWindow_.x_/ map_[current_map].size() + 21, 32), lws::Vector<double>(0.0, 0.5), kWindow_, controler_));
					break;
				default:
					break;
				}
				++index;
			}
			++current_map;
		}
		else
		{
			controler_.lock()->InformOfBeingCleared();
		}
	}
	else
	{
		--appearance_timer_;
	}
}

void EnemyAppearanceCtrl::Draw() const
{
}
