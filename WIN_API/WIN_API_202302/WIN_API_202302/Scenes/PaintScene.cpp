#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(Vector2(300.0f, 300.0f), 50.0f);
	_rectangle = make_shared<RectCollider>(Vector2(550.f, 250.0f), Vector2(650.0f, 250.0f), Vector2(550.0f, 350.0f), Vector2(650.0f, 350.0f));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	if (GetAsyncKeyState('A'))
	{
		_circle->MoveCenter(Vector2(-1, -1).NormalVector2() * _speed);
		_rectangle->MoveSquare(Vector2(-1, -1).NormalVector2() * _speed);
	}
	if (GetAsyncKeyState('D'))
	{
		_circle->MoveCenter(Vector2(1, 1).NormalVector2() * _speed);
		_rectangle->MoveSquare(Vector2(1, 1).NormalVector2() * _speed);
	}

	_circle->Update();
	_rectangle->Update();
}

void PaintScene::Render(HDC hdc)
{
	_circle->Render(hdc);
	_rectangle->Render(hdc);
}
