#pragma once
#include "gameNode.h"
#include "camera.h"

#define ENEMY 5
#define BULLET 10 
#define PI 3.1415926f
#define BOSSBULLET 200
enum StateET
{
	IDLE_Et,
	DEAD_Et
};

enum StatePlayer
{
	IDLE_Player,
	LEFT_Player,
	RIGHT_Player,
	DEAD_Player
};

struct tagPlayer
{
	RECT _rc;
	float _speed;
	bool _isFire;
	RECT _HP;
	int _showHp;
	bool _destroy;
	bool _dead;
	
};

struct tagPlayerbullet
{
	RECT _rc;
	float _speed;
	bool _isFire;
    int _playerBulletCount;
	bool _shoot;
};

struct tagEnemy
{
	RECT _rc_B_green;
	RECT _rc_B_green_side;
	RECT _rc_B_gray;
	RECT _rc_B_gray_side;
	float _speed;
	bool _isFire;
	
};

struct  tagEnemybullet
{
	RECT _rc_B_green;
	RECT _rc_B_green_side;
	RECT _rc_B_gray;
	RECT _rc_B_gray_side;
	float _speed;
	bool _isFire;
	int _enemyBulletCount;
};

class mainGame : public gameNode
{
private:
	//camera* _camera;	//ī�޶� Ŭ����

	HBRUSH _brush;

	//�̹��� ���� ��Ʈ
	RECT _rcBg;
	RECT _rcBasicgreen;

	//�̳ѹ� ����
	StatePlayer _statePlayer;
	StateET _stateEt;

	//�ʱ�ȭ�� ���ӽ�ŸƮ
	image* _gameStart;
	//���ӿ��� ȭ�� 
	image* _gameOver;
	//����Ŭ���� ȭ��
	image* _gameClear;

	//�÷��̾� ��� �̹��� ����
	image* _idle;
	image* _left;
	image* _right;
	image* _dead;
	//�÷��̾� �Ѿ� �̹���
	image* _playerbullet;

	//�⺻ �� �̹��� 
	image* _basicGreen;
	image* _basicGreenSide;
	image* _basicGray;
	image* _basicGraySide;
	//�⺻ ���̵� �� �Ѿ� �̹���
	image* _sidebullet;


	//�߰� ���� �̹��� 
	image* _middleGreen;
	image* _middleGray;
	//�߰� ���� ������ �̹���
	image* _middlePung;

	//������ ���� �̹���
	image* _lastBoss;
	//������ ���� �Ѿ� �̹���
	image* _lastBossBullet;


	//ET �̹���
	image* _ET;
	image* _ET_Dead;
	//ET �Ѿ� �̹���
	image* _etbullet;


	//����ü ����
	tagPlayer _player;
	tagEnemy _enemy[5];
	tagPlayerbullet _playerBullet[10];
	tagEnemybullet _enemyBullet[10];



	//�⺻ �� ���� ���� �ľ�
	bool _basicGreenDead[BULLET];
	bool _basicGrayDead[BULLET];
	bool _basicGreenSideDead[BULLET];
	bool _basicGraySideDead[BULLET];



	//�⺻�� hpī��Ʈ 
	int _basicGreenHpCount;
	int _basicGrayHpCount;
	int _basicGreenSideHpCount;
	int _basicGraySideHpCount;
	

	//�߰� ���� 
	RECT _rc_middle_Green;
	RECT _rc_middle_Gray;
	float _middleBossSpeed;
	//�߰� ���� �Ѿ�
	RECT _rc_middle_Green_Bullet[BOSSBULLET];
	RECT _rc_middle_Gray_Bullet[BOSSBULLET];
	float _middleBossBulletSpeed[BOSSBULLET];
	int _middleBossBulletCount;
	float _middleBossBulletGreenX[BOSSBULLET];
	float _middleBossBulletGreenY[BOSSBULLET];
	float _middleBossBulletGrayX[BOSSBULLET];
	float _middleBossBulletGrayY[BOSSBULLET];
	float _middleBossBulletAngle;

	//������ ���� 
	RECT _rc_lastBoss;
	float _lastBossSpeed;
	float _lastBossX;
	float _lastBossY;
	int bulletCount;
	RECT _rc_lastBoss_Bullet[BOSSBULLET];
	float _lastBossBulletSpeed[BOSSBULLET];
	float _lastBossBulletX[BOSSBULLET];
	float _lastBossBulletY[BOSSBULLET];
	float _lastBossBulletMoveAngle[BOSSBULLET];
	float _lastBossBulletMoveX[BOSSBULLET];
	float _lastBossBulletMoveY[BOSSBULLET];
	float _lastBossBulletAngle;
	bool _lastBulletFire[BOSSBULLET];
	bool _showBossBullet;
	
	int _lastBossBulletCount;

	//ET
	RECT _rc_ET;
	RECT _rc_ET_Bullet;
	int _etBulletcount;
	int _moveCountEt;
	bool _etAttack;

	


	//��Ÿ ���� 
	int _loopX;
	int _loopY;
	int _count;
	int _countEt;
	int _index;
	int _index_Et;
	bool _isGame;
	int _showEnemycount;
	char str[100];
	char str1[100];
	RECT wall;
	bool _bgMove;
	int _deadCount;
	int _endGameCount;


	//���� �̹��� ���� �Һ���
	bool _GameStart;
	bool _GameClear;
	bool _GameOver;

	//�Ѿ� ī��Ʈ
	int _playerBulletCount;
	int _enemyBulletCount;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//�Լ�

	//�÷��̾� �Լ�
	void movePlayer();
	void moveBulletPlayer();
	void shootPlayer();
	void animationPlayer();
	void deadPlayer();
	void destoryEnemy();

	//�⺻ �� �Լ�
	void moveEnemy();
	void moveBulletEnemy();

	//�߰� ���� �Լ� 
	void moveMiddleboss();
	void moveBulletMiddleboss();

	//������ ���� �Լ� 
	void moveLastboss();
	void moveBulletLastboss();
	void shootLastBoss();


	//ET �Լ� 
	void moveET();
	void moveBulletEt();
	void animationET();

	//��Ÿ �Լ�
	void collision();
	void wallCollision();



	mainGame() {}
	~mainGame() {}
};

