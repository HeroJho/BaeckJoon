#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N;
vector<int> Matrix[51];
int DP[51] = { 0 };


int DFS(int Cur)
{
    // leap = 1 반환
    if (Matrix[Cur].empty())
        return 1;

    // 자식 노드 전화하는데 걸리는 시간 구하기
    vector<int> Times;
    for (int i = 0; i < Matrix[Cur].size(); ++i)
    {
        int Time = DFS(Matrix[Cur][i]);
        Times.push_back(Time);
    }

    sort(Times.begin(), Times.end());
    // 제일 오래 걸리는 시간 + 1 반환

    int Max = 0;
    int Size = Matrix[Cur].size()-1;
    for(int i = 0; i < Times.size(); ++i)
        Max = max(Max, Times[i] + Size--);

    return Max + 1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 서클 x, 부모 1, 민식 루트
    cin >> N;

    int Temp;
    cin >> Temp;
    for (int i = 1; i < N; ++i)
    {
        cin >> Temp;
        Matrix[Temp].push_back(i);

    }

    cout << DFS(0) - 1;

    return 0;
}