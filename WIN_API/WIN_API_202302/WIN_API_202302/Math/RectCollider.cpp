#include "framework.h"
#include "RectCollider.h"



RectCollider::RectCollider(Vector2 leftTop, Vector2 rightTop, Vector2 leftBottom, Vector2 rightBottom)
	: _leftTop(leftTop)
	, _rightTop(rightTop)
	, _leftBottom(leftBottom)
	, _rightBottom(rightBottom)
{
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float left = _leftTop.x;
	float top = _leftTop.y;
	float right = _rightBottom.x;
	float bottom = _rightBottom.y;
	Rectangle(hdc, left, top, right, bottom);
}

void RectCollider::MoveSquare(const Vector2& value)
{
	_leftTop += value;
	_rightTop += value;
	_leftBottom += value;
	_rightBottom += value;
}

void RectCollider::Set4Point(const Vector2& point1, const Vector2& point2, const Vector2& point3, const Vector2& point4)
{
	_leftTop = point1;
	_rightTop = point2;
	_leftBottom = point3;
	_rightBottom = point4;
}
