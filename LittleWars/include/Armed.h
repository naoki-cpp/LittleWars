#pragma once
#include "gameobject.h"
#include "Living.h"
class Armed :
	public Living
{
public:

	virtual ~Armed(void)
	{
	}
	virtual bool Targetable() { return true; }
protected:
	virtual void Attack() = 0;
	Armed(int HitPoint, std::shared_ptr<GraphicLoading> graph_loader, std::weak_ptr<GameControler> controler):
		Living(HitPoint,graph_loader,controler)
	{
	}
private:
	Armed(Armed&);
};

