#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int Y, X;
vector<string> Matrix;
bool Visited[251][251] = { false };

int DirX[] = { 0 ,0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

bool IsIn(int InX, int InY)
{
    return InX >= 0 && InX < X && InY >= 0 && InY < Y;
}


void BFS(pair<int ,int>& OutAns, pair<int ,int> Start)
{
    queue<pair<int, int>> Qs;

    Qs.push(Start);
    Visited[Start.second][Start.first] = true;

    if (Matrix[Start.second][Start.first] == 'o')
        ++OutAns.first;
    else if (Matrix[Start.second][Start.first] == 'v')
        ++OutAns.second;

    while (!Qs.empty())
    {
        pair<int, int> Cur = Qs.front();
        Qs.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nX = DirX[i] + Cur.first;
            int nY = DirY[i] + Cur.second;

            if (!IsIn(nX, nY))
                continue;

            if (Visited[nY][nX])
                continue;
            Visited[nY][nX] = true;

            if (Matrix[nY][nX] == '#')
                continue;

            if (Matrix[nY][nX] == 'o')
                ++OutAns.first;
            else if (Matrix[nY][nX] == 'v')
                ++OutAns.second;

            Qs.push({ nX,nY });
        }
    }


}

void IterBFS()
{
    pair<int, int> Ans;
    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            if (Visited[y][x])
                continue;
            if (Matrix[y][x] == '#')
                continue;

            pair<int, int> Now;
            BFS(Now, { x,y });

            if (Now.first > Now.second)
                Ans.first += Now.first;
            else
                Ans.second += Now.second;
        }
    }

    cout << Ans.first << ' ' << Ans.second;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> Y >> X;
    for (int y = 0; y < Y; ++y)
    {
        string Temp;
        cin >> Temp;
        Matrix.push_back(Temp);
    }

    IterBFS();

    return 0;
}