#include "stdafx.h"
#include "bullet.h"

//=============================================================
//	## bullet ## (�����Ѿ� - ������� ������ ��)
//=============================================================
HRESULT bullet::init()
{
	return S_OK;
}

void bullet::release()
{
}

void bullet::update()
{
}

void bullet::render()
{
}

//=============================================================
//	## missile ## (missile[0] -> �迭ó�� �̸� �����صΰ� �Ѿ˹߻�)
//=============================================================
HRESULT missile::init(int bulletMax, float range)
{
	//�Ѿ� ��Ÿ� �� �Ѿ� ���� �ʱ�ȭ
	_range = range;
	_bulletMax = bulletMax;

	//�Ѿ��� ������ŭ ����ü�� �ʱ�ȭ �� �� ���Ϳ� ���
	for (int i = 0; i < bulletMax; i++)
	{
		//�Ѿ� ����ü ����
		tagBullet bullet;
		//�Ѿ˱���ü �ʱ�ȭ
		//���θ޸�, ���
		//����ü�� �������� ���� �ѹ��� 0���� �ʱ�ȭ �����ش�
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.bulletImage = new image;
		bullet.bulletImage->init("Images/missile.bmp", 26, 124, true, RGB(255, 0, 255));
		bullet.speed = 5.0f;
		bullet.fire = false;

		//���Ϳ� ���
		_vBullet.push_back(bullet);
	}

	return S_OK;
}

void missile::release()
{
	for (int i = 0; i < _vBullet.size(); i++)
	{
		_vBullet[i].bulletImage->release();
		SAFE_DELETE(_vBullet[i].bulletImage);
	}
}

void missile::update()
{
	this->move();
}

void missile::render()
{
	for (int i = 0; i < _vBullet.size(); i++)
	{
		if (!_vBullet[i].fire) continue;
		_vBullet[i].bulletImage->render(getMemDC(), _vBullet[i].rc.left, _vBullet[i].rc.top);
	}
}

void missile::fire(float x, float y)
{
	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire) continue;
		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x;
		_viBullet->y = _viBullet->fireY = y;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
		break;
	}
}

void missile::move()
{
	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
		
		//�Ѿ��� ��Ÿ����� Ŀ������
		float distance = getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y);
		if (_range < distance)
		{
			_viBullet->fire = false;
		}
	}
}
