#include "framework.h"
#include "RectCollider.h"



RectCollider::RectCollider(Vector2 center, Vector2 size)
	: _center(center), _size(size), _halfSize(_size * 0.5f)
{
	HPEN green = CreatePen(PS_SOLID, 1, GREEN);
	HPEN red = CreatePen(PS_SOLID, 1, RED);
	_pens.push_back(green);
	_pens.push_back(red);
}

RectCollider::~RectCollider()
{
	for (auto* pen : _pens)
	{
		DeleteObject(pen);
	}
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIndex]);
	/*float left = _leftTop.x;
	float top = _leftTop.y;
	float right = _rightBottom.x;
	float bottom = _rightBottom.y;
	Rectangle(hdc, left, top, right, bottom);*/
	float left = _center.x - _halfSize.x;
	float top = _center.y - _halfSize.y;
	float right = _center.x + _halfSize.x ;
	float bottom = _center.y + _halfSize.y;

	Rectangle(hdc, left, top, right, bottom);
}

void RectCollider::MoveSquare(const Vector2& value)
{
	/*_leftTop += value;
	_rightTop += value;
	_leftBottom += value;
	_rightBottom += value;*/
	_center += value;
}

void RectCollider::MoveCenter(const Vector2& value)
{
	_center += value;
}

void RectCollider::SetCenter(const Vector2& value)
{
	_center = value;
}

void RectCollider::SetSize(const Vector2& size)
{
	_size = size;
	_halfSize = _size * 0.5f;
}

bool RectCollider::IsCollision(Vector2 pos)
{
	if (pos.x < Left() || pos.x > Right())
		return false;
	if (pos.y < Top() || pos.y > Bottom())
		return false;

	return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distanceX = abs(other->GetCenter().x - this->_center.x);
	float distanceY = abs(other->GetCenter().y - this->_center.y);

	if ((other->GetRadius() + this->_halfSize.x) < distanceX)
		return false;
	if ((other->GetRadius() + this->_halfSize.y) < distanceY)
		return false;
	return true;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	float distanceX = abs(other->GetCenter().x - this->_center.x);
	float distanceY = abs(other->GetCenter().y - this->_center.y);

	if ((other->_halfSize.x + this->_halfSize.x) < distanceX)
		return false;
	if ((other->_halfSize.y + this->_halfSize.y) < distanceY)
		return false;

	return true;
}


//void RectCollider::Set4Point(const Vector2& point1, const Vector2& point2, const Vector2& point3, const Vector2& point4)
//{
//	_leftTop = point1;
//	_rightTop = point2;
//	_leftBottom = point3;
//	_rightBottom = point4;
//}
