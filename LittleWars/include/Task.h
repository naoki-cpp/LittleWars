#pragma once
class Task
{
public:

	virtual ~Task()
	{}
	//初期化
	virtual void Initialize(){}     //初期化処理は実装してもしなくてもいい
	//後処理
	virtual void Finalize()  {}     //終了処理は実装してもしなくてもいい
	//毎フレーム呼び出す
	virtual void Update() = 0;   //更新処理は必ず継承先で実装する
	//描画処理
	virtual void Draw()const = 0;   //描画処理は必ず継承先で実装する
protected:
	Task(){};
private:
	Task(Task&);//暗黙変換の禁止
};

