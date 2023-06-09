#pragma once
class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMaze();

	Vector2 Start() { return Vector2(1, 1); }
	Vector2 End() { return Vector2(int(_poolCountX - 2), int(_poolCountY - 2)); }
	MazeBlock::BlockType GetBlockType(int y, int x);
	shared_ptr<MazeBlock> GetBlock(int y, int x) { return _blocks[y][x]; }

	UINT GetX() { return _poolCountX; }
	UINT GetY() { return _poolCountY; }
private:
	vector<vector<shared_ptr<MazeBlock>>> _blocks; // 인덱스로 볼 때는 x,y의 순서가 반전된다 =>(y,x)
	UINT _poolCountX = 25;
	UINT _poolCountY = 25;
};

