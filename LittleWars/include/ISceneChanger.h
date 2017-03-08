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
	virtual void ChangeScene(eScene NextScene) = 0;//�w��V�[���ɕύX����

protected:
	ISceneChanger(){}
private:
	ISceneChanger(ISceneChanger&);
};

