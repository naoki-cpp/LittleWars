#pragma once
enum class eScene
{
	MENU,
	GAME,
	END,
	NUM,
	NONE
};
class ISceneChanger
{
public:


	virtual ~ISceneChanger()
	{
	}
	virtual void ChangeScene(eScene NextScene) = 0;//指定シーンに変更する

protected:
	ISceneChanger(){}
private:
	ISceneChanger(ISceneChanger&);
};

