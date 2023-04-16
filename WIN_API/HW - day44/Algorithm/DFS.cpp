#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// �̻������ �׷���
// �׷����� ���� ����
// �׷����� ���
// �׷����� ���� ����

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

void DFS(int start)
{
    if (visited[start])
        return;
    visited[start] = true;
    cout << start << "�� �湮�߽��ϴ�." << endl;

    for (int there = 0; there < adjacent2.size(); there++)
    {
        // ������ ������� �����ϸ� ��������
        if (start == there)
            continue;

        // �������ִ°�?
        if (adjacent2[start][there] == false)
            continue;

        // �湮����
        if (visited[there] == true)
            continue;

        // ������ ã�����
        DFS(there);
    }
}

int DfsAll()
{
    int count = 0;

    for (int start = 0; start < 7; start++)
    {
        if (visited[start] == false)
        {
            DFS(start);
            count++;
        }
    }

    return count;
}

void BFS(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << start << "�� �湮�߽��ϴ�." << endl;

    while (!q.empty())
    {
        int here = q.front();
        q.pop();

        cout << here << "�� �湮�߽��ϴ�." << endl;

        for (int there = 0; there < adjacent2.size(); there++)
        {
            // ������ ������� �����ϸ� ��������
            if (here == there)
                continue;

            // �������ִ°�?
            if (adjacent2[here][there] == false)
                continue;

            // �湮����
            if (visited[there] == true)
                continue;

            // ������ ã�����
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

int DFS()
{
    CreateGraphByMatrix();
    DFS(0);
    BFS(0);
    int count = DfsAll();
    return 0;
}