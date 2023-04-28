#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int Matrix[101][101];
bool Visited[101];

int N, M;
int iCount = 0;

void Clear()
{
    for (int i = 0; i < 101; ++i)
    {
        Visited[i] = false;

        for (int j = 0; j < 101; ++j)
        {
            Matrix[i][j] = 0;
        }
    }
}

void DFS(int v)
{
    Visited[v] = true;
    ++iCount;

    for (int i = 0; i < N + 1; ++i)
    {
        if (Matrix[v][i] == 1 && Visited[i] == false)
        {
            DFS(i);
        }
    }
}

int main()
{
    Clear();
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int iTemp1, iTemp2; cin >> iTemp1 >> iTemp2;
        Matrix[iTemp1][iTemp2] = 1;
        Matrix[iTemp2][iTemp1] = 1;
    }

    DFS(1);

    cout << --iCount;

    return 0;
}