#pragma once
class Task
{
public:

	virtual ~Task()
	{}
	//������
	virtual void Initialize(){}     //�����������͎������Ă����Ȃ��Ă�����
	//�㏈��
	virtual void Finalize()  {}     //�I�������͎������Ă����Ȃ��Ă�����
	//���t���[���Ăяo��
	virtual void Update() = 0;   //�X�V�����͕K���p����Ŏ�������
	//�`�揈��
	virtual void Draw()const = 0;   //�`�揈���͕K���p����Ŏ�������
protected:
	Task(){};
private:
	Task(Task&);//�Öٕϊ��̋֎~
};

