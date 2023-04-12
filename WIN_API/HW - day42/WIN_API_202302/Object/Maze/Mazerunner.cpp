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
		// ���� �ٶ󺸴� ���� �������� ���������� �� �� �ִ��� Ȯ��(�ݽð����)
		int newDir = (_direction - 1 + DIR_COUNT) % DIR_COUNT; // ������������ ����
		Vector2 oldDirVector2 = frontPos[_direction]; //���� ����
		Vector2 newDirVector2 = frontPos[newDir]; // ���� ¤�� ����

		// �޼� �������� ������ �� �ִ��� Ȯ��
		Vector2 newGo = pos + newDirVector2;
		Vector2 oldGo = pos + oldDirVector2;
		if (Cango(newGo.y, newGo.x))
		{
			_footPrint = pos;
			_direction = static_cast<Dir>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}

		// ���� �ٶ󺸴� �������� ������ �� �ִ��� Ȯ��
		else if (Cango(oldGo.y, oldGo.x))
		{
			_footPrint = pos;
			pos += oldDirVector2;
			_path.push_back(pos);
		}

		// ����, ���� �� �����ִٸ� �ð�������� ȸ��
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
