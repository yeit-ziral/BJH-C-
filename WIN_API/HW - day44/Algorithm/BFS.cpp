#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// 이산수학의 그래프
// 그래프에 대한 조사
// 그래프의 기원
// 그래프를 쓰는 이유

vector<vector<bool>> adjacent2;
vector<bool> visited;

void CreateGraphByMatrix()
{
    adjacent2 = vector<vector<bool>>(7, vector<bool>(7, false));
    visited = vector<bool>(7, false);

    //    0  1  2  3  4  5  6
    // 0  T  T  T  F  T  F  F
    // 1  T  T  F  F  F  F  F
    // 2  T  F  T  T  F  T  F
    // 3  F  F  T  T  F  F  F
    // 4  T  F  F  F  T  F  T
    // 5  F  F  T  F  F  T  F
    // 6  F  F  F  F  T  F  F

    adjacent2[0][0] = true;
    adjacent2[0][1] = true;
    adjacent2[0][2] = true;
    adjacent2[0][4] = true;

    adjacent2[1][0] = true;
    adjacent2[1][1] = true;

    adjacent2[2][0] = true;
    adjacent2[2][2] = true;
    adjacent2[2][3] = true;
    adjacent2[2][5] = true;

    adjacent2[3][2] = true;
    adjacent2[3][3] = true;

    adjacent2[4][0] = true;
    adjacent2[4][4] = true;
    adjacent2[4][6] = true;

    adjacent2[5][2] = true;
    adjacent2[5][5] = true;

    adjacent2[6][4] = true;
    adjacent2[6][6] = true;
}

void BFS(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << start << "를 방문했습니다." << endl;

    while (!q.empty())
    {
        int here = q.front();
        q.pop();

        cout << here << "를 방문했습니다." << endl;

        for (int there = 0; there < adjacent2.size(); there++)
        {
            // 갈곳이 출발점과 동일하면 다음으로
            if (here == there)
                continue;

            // 인접해있는가?
            if (adjacent2[here][there] == false)
                continue;

            // 방문여부
            if (visited[there] == true)
                continue;

            // 갈곳을 찾은경우
            visited[there] = true;
            q.push(there);
        }
    }
}

int BfsAll()
{
    int count = 0;

    for (int start = 0; start < 7; start++)
    {
        if (visited[start] == false)
        {
            BFS(start);
            count++;
        }
    }

    return count;
}

int main()
{
    CreateGraphByMatrix();
    BFS(0);
    int count = BfsAll();
    return 0;
}