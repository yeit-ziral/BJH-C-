#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_lineFloor = make_shared<Line>(Vector2(0, 500), Vector2(1000, 500)); // °ËÀº»ö, ±½±â 3
	_lineMouse = make_shared<Line>(Vector2(50, 250), Vector2(50, 250)); // ÆÄ¶õ»ö¼±, ±½±â 3
	_lineShadow = make_shared<Line>(Vector2(50, 450), Vector2(60, 450)); // »¡°£¼±, ±½±â 3

	blackPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	bluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	redPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
}

LineScene::~LineScene()
{
	DeleteObject(blackPen);
	DeleteObject(bluePen);
	DeleteObject(redPen);
}

void LineScene::Update()
{
	_lineMouse->_end = mousePos;
	_lineShadow->_end.x = _lineMouse->_end.x;

	_lineFloor->Update();
	_lineMouse->Update();
	_lineShadow->Update();

}

void LineScene::Render(HDC hdc)
{
	SelectObject(hdc, blackPen);
	_lineFloor->Render(hdc);

	SelectObject(hdc, bluePen);
	_lineMouse->Render(hdc);


	SelectObject(hdc, redPen);
	_lineShadow->Render(hdc);
}
