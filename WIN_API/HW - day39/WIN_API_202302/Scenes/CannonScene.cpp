#include "framework.h"
#include "CannonScene.h"

CannonScene::CannonScene()
{
	_cannon = make_shared<Cannon>(Vector2(WIN_WIDTH * 0.6f, WIN_HEIGHT * 0.5f));
	_cannon2 = make_shared<Cannon>(Vector2(WIN_WIDTH * 0.3f, WIN_HEIGHT * 0.5f));
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon->Attacked(_cannon2);
	_cannon2->Attacked(_cannon);

	_cannon->Update();
	_cannon2->Update();
}

void CannonScene::Render(HDC hdc)
{
	if(_cannon->IsAlive())
	{
		_cannon->Render(hdc);
	}

	if (_cannon2->IsAlive())
	{
		_cannon2->Render(hdc);
	}
}


