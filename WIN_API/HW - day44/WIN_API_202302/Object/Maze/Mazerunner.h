#pragma once
class Mazerunner
{
public:
	Mazerunner(shared_ptr<Maze> maze);
	~Mazerunner();

	void Update();

	void LeftHand();
	bool Cango(int y, int x);

private:
	shared_ptr<Maze> _maze;

	Vector2 _pos;
	Dir _direction = Dir::DIR_UP;

	Vector2 _footPrint;
	vector<Vector2> _path;
	int _pathIndex = 0;
	float _time = 0.0f;
};

