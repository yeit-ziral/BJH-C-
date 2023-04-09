#include "framework.h"
#include "Cannon.h"

Cannon::Cannon(Vector2 pos)
	: _hp(100), _isAlive(true)
{
	_body = make_shared<CircleCollider>(pos, 50);
	_muzzle = make_shared<Line>(Vector2(pos), Vector2(pos.x + _muzzleLength, pos.y));

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		_bullets.push_back(bullet);

	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	Move();
	Angle();
	Fire();

	_body->Update();
	_muzzle->Update();
	
	for (auto& bullet : _bullets)
	{
		bullet->Update();
	}
	
}

void Cannon::Render(HDC hdc)
{
	_muzzle->Render(hdc);
	_body->Render(hdc);
	
	for (auto& bullet : _bullets)
	{
		bullet->Render(hdc);
	}
}

void Cannon::Move()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		_body->MoveCenter(Vector2(-1.0f, 0.0f));
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_body->MoveCenter(Vector2(1.0f, 0.0f));
	}

	_muzzle->_start = _body->GetCenter();
	_muzzle->_end = _muzzle->_start + _muzzleDir * _muzzleLength;

}

void Cannon::Angle()
{
	if (GetAsyncKeyState(VK_UP))
	{
		_muzzleAngle += 0.1f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		_muzzleAngle -= 0.1f;
	}

	_muzzleDir = Vector2(cosf(_muzzleAngle), -sinf(_muzzleAngle));
}

void Cannon::Fire()
{
	static bool spacePressedOnce = false;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		if (!spacePressedOnce)
		{
			auto iter = std::find_if(_bullets.begin(), _bullets.end(), [](const shared_ptr<Bullet>& bullet)->bool
				{
					if (bullet->IsActive() == false)
						return true;
					return false;
				});

			if (iter != _bullets.end())
			{
				(*iter)->SetPos(_muzzle->_end);
				(*iter)->Shoot(_muzzleDir.NormalVector2(), 10.0f);
				spacePressedOnce = true;
			}
		}
	}
	else
	{
		spacePressedOnce = false;
	}
}

void Cannon::Attacked(shared_ptr<Cannon> other)
{
	for (const auto& bullet : other->_bullets)
	{
		if (bullet->IsCollision(_body))
		{
			_hp -= 10;
			if (_hp <= 0)
			{
				_isAlive = false;
			}
		}
	}
}
