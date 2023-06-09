#include "framework.h"
#include "RectCollider.h"



RectCollider::RectCollider(Vector2 center, Vector2 size)
	: Collider(center),
	_size(size),
	_halfSize(_size * 0.5f)
{
	_type = Collider::ColliderType::RECT;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	if (isDebugMode)
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
	Vector2 leftTop = Vector2(Left(), Top());
	Vector2 leftBottom = Vector2(Left(), Bottom());
	Vector2 rightTop = Vector2(Right(), Top());
	Vector2 rightBottom = Vector2(Right(), Bottom());

	if (other->IsCollision(leftTop) || other->IsCollision(leftBottom) 
		|| other->IsCollision(rightTop) || other->IsCollision(rightBottom))
		return true;

	if (Right() > other->GetCenter().x && Left() < other->GetCenter().x)
	{
		if (Top() - other->GetRadius() < other->GetCenter().y
			&& Bottom() + other->GetRadius() > other->GetCenter().y)
			return true;
	}

	if (Bottom() > other->GetCenter().y && Top() < other->GetCenter().y)
	{
		if (Left() - other->GetRadius() < other->GetCenter().x
			&& Right() + other->GetRadius() > other->GetCenter().x)
			return true;
	}

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	if (Right() > other->Left() && Left() < other->Right())
	{
		if (Bottom() > other->Top() && Top() < other->Bottom())
			return true;
	}

	return false;
}


//void RectCollider::Set4Point(const Vector2& point1, const Vector2& point2, const Vector2& point3, const Vector2& point4)
//{
//	_leftTop = point1;
//	_rightTop = point2;
//	_leftBottom = point3;
//	_rightBottom = point4;
//}
