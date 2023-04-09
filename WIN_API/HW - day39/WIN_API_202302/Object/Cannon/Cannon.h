#pragma once
class Cannon
{
public: 
	Cannon(Vector2 pos);
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Angle();
	void Fire();

	int GetHp() { return _hp; }

	bool IsAlive() { return _isAlive; }

	void Attacked(shared_ptr<Cannon> other);

	vector<shared_ptr<Bullet>> _bullets;

private:
	float _muzzleLength = 100.0f;
	float _muzzleAngle = 0.0f;
	Vector2 _muzzleDir = Vector2(1.0f, 0.0f);

	// 컴포넌트 패턴 (부품 조립 패턴) => 생산성의 증가
	shared_ptr<CircleCollider> _body;
	shared_ptr<Line> _muzzle;


	int _hp;
	bool _isAlive;
};

