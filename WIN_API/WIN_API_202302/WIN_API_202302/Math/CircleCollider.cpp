#include "framework.h"
#include "CircleCollider.h"

class RectCollider;

CircleCollider::CircleCollider(Vector2 center, float radius)
: _center(center)
, _radius(radius)
{
	HPEN green =	CreatePen(PS_SOLID, 1, GREEN);
	HPEN red =		CreatePen(PS_SOLID, 1, RED);
	_pens.push_back(green);
	_pens.push_back(red);
}

CircleCollider::~CircleCollider()
{
	for (auto* pen : _pens)
	{
		DeleteObject(pen);
	}
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIndex]);

	float left = _center.x - _radius;
	float top = _center.y - _radius;
	float right = _center.x + _radius;
	float bottom = _center.y + _radius;
	Ellipse(hdc, left, top, right, bottom);
}

void CircleCollider::MoveCenter(const Vector2& value)
{
	_center += value;
}

void CircleCollider::SetCenter(const Vector2& value)
{
	_center = value;
}

void CircleCollider::SetRadius(float radius)
{
	_radius = radius;
}

bool CircleCollider::IsCollision(Vector2 pos)
{
	float distance = (_center - pos).Length();

	return distance < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = (_center - other->GetCenter()).Length();
	float sum = _radius + other->GetRadius();

	return distance < sum;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	float distanceX = abs(other->GetCenter().x - this->_center.x);
	float distanceY = abs(other->GetCenter().y - this->_center.y);

	if ((this->GetRadius() + other->GetHalfSize().x) < distanceX)
		return false;
	if ((this->GetRadius() + other->GetHalfSize().y) < distanceY)
		return false;
	return true;
	//return other->IsCollision(shared_from_this());
}