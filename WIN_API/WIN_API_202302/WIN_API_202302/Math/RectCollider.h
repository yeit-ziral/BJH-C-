#pragma once
class RectCollider : public enable_shared_from_this<RectCollider>
{
public:
	RectCollider(Vector2 center, Vector2 size);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	void MoveSquare(const Vector2& value);

	void MoveCenter(const Vector2& value);

	/*void Set4Point(const Vector2& point1, const Vector2& point2, const Vector2& point3, const Vector2& point4);
	const Vector2& GetLeftTop() { return _leftTop; }
	const Vector2& GetRightTop() { return _rightTop; }
	const Vector2& GetLeftBottom() { return _leftBottom; }
	const Vector2& GetRightBottom() { return _rightBottom; }*/

	void SetCenter(const Vector2& value);
	const Vector2& GetCenter() { return _center; }

	void SetSize(const Vector2& size);
	const Vector2& GetSize() { return _size; }

	void SetGreen() { _curPenIndex = 0; }
	void SetRed() { _curPenIndex = 1; }

	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<RectCollider> other);

	float Left() const		{ return _center.x - _halfSize.x; }
	float Right() const		{ return _center.x + _halfSize.x; }
	float Top() const		{ return _center.y - _halfSize.y; }
	float Bottom() const	{ return _center.y + _halfSize.y; }
	
	const Vector2& GetHalfSize() { return _halfSize; }

private:
	vector<HPEN> _pens;
	UINT _curPenIndex = 0;

	Vector2 _leftTop = { 0.0f,0.0f };
	Vector2 _rightTop = { 0.0f,0.0f };
	Vector2 _leftBottom = { 0.0f,0.0f };
	Vector2 _rightBottom = { 0.0f,0.0f };
	Vector2 _center;
	Vector2 _size;
	Vector2 _halfSize;
};

