#include "framework.h"
#include "Mazerunner.h"

Mazerunner::Mazerunner(shared_ptr<Maze> maze)
	: _maze(maze)
	, _footPrint(maze->Start())
	, _pos(maze->Start())
{
	LeftHand();
}

Mazerunner::~Mazerunner()
{
	_maze = nullptr;
}

void Mazerunner::Update()
{
	if (_pathIndex >= _path.size())
		return;
	
	_time += 0.4f;

	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		_pathIndex++;
	}

	_maze->GetBlock((int)_pos.y, (int)_pos.x)->SetType(MazeBlock::BlockType::PLAYER);

	if (_pathIndex > 1) 
	{
		_footPrint = _path[_pathIndex - 2];
	}
	_maze->GetBlock((int)_footPrint.y, (int)_footPrint.x)->SetType(MazeBlock::BlockType::FOOTPRINT);
}

void Mazerunner::LeftHand()
{
	Vector2 pos = _pos; // start point
	Vector2 endPos = _maze->End();
	_direction = Dir::DIR_UP;
	_path.push_back(pos);

	Vector2 frontPos[4] =
	{
		Vector2(0,-1), // UP
		Vector2(1,0), // Right
		Vector2(0,1), // Down
		Vector2(-1,0) // Left
	};

	while (pos != endPos)
	{
		// 현재 바라보는 방향 기준으로 오른쪽으로 갈 수 있는지 확인(반시계방향)
		int newDir = (_direction - 1 + DIR_COUNT) % DIR_COUNT; // 좌측방향으로 돌기
		Vector2 oldDirVector2 = frontPos[_direction]; //기존 방향
		Vector2 newDirVector2 = frontPos[newDir]; // 왼쪽 짚는 방향

		// 왼손 방향으로 전진할 수 있는지 확인
		Vector2 newGo = pos + newDirVector2;
		Vector2 oldGo = pos + oldDirVector2;
		if (Cango(newGo.y, newGo.x))
		{
			_footPrint = pos;
			_direction = static_cast<Dir>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}

		// 현재 바라보는 방향으로 전진할 수 있는지 확인
		else if (Cango(oldGo.y, oldGo.x))
		{
			_footPrint = pos;
			pos += oldDirVector2;
			_path.push_back(pos);
		}

		// 왼쪽, 앞이 다 막혀있다면 시계방향으로 회전
		else
		{
			_direction = static_cast<Dir>((_direction + 1 + DIR_COUNT) % DIR_COUNT);
		}
	}

}

bool Mazerunner::Cango(int y, int x)
{
	if (_maze->GetBlockType(y, x) == MazeBlock::BlockType::DISABLE ||
		_maze->GetBlockType(y, x) == MazeBlock::BlockType::NONE)
	{
		return false;
	}
	return true;
}
