#pragma once
class RectCollider
{
public:
	RectCollider(Vector2 leftTop, Vector2 rightTop, Vector2 leftBottom, Vector2 rightBottom);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	void MoveSquare(const Vector2& value);

	void Set4Point(const Vector2& point1, const Vector2& point2, const Vector2& point3, const Vector2& point4);
	const Vector2& GetLeftTop() { return _leftTop; }
	const Vector2& GetRightTop() { return _rightTop; }
	const Vector2& GetLeftBottom() { return _leftBottom; }
	const Vector2& GetRightBottom() { return _rightBottom; }

private:
	Vector2 _leftTop = { 0.0f,0.0f };
	Vector2 _rightTop = { 0.0f,0.0f };
	Vector2 _leftBottom = { 0.0f,0.0f };
	Vector2 _rightBottom = { 0.0f,0.0f };

};

