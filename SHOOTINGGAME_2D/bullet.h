#pragma once
#include "gameNode.h"

//�Ѿ� ����ü
struct tagBullet
{
	image* bulletImage;
	RECT rc;
	float x, y;
	float fireX, fireY;
	float speed;
	float angle;
	float gravity;
	float radius;
	bool fire;
};

//=============================================================
//	## bullet ## (�����Ѿ� - ������� ������ ��)
//=============================================================
class bullet : public gameNode
{
public:
	HRESULT init();
	void release();
	void update();
	void render();

	bullet() {}
	~bullet() {}
};


//=============================================================
//	## missile ## (missile[0] -> �迭ó�� �̸� �����صΰ� �Ѿ˹߻�)
//=============================================================
class missile : public gameNode
{
private:
	//�Ѿ� ����ü�� ���� ����, �ݺ���
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

private:
	float _range;		//�Ѿ� ��Ÿ�
	int _bulletMax;		//�Ѿ� �ִ밹��

public:
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();

	//�Ѿ˹߻�
	void fire(float x, float y);
	//�Ѿ˹���
	void move();

	missile() {}
	~missile() {}
};



