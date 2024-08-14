#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int S, X, Y;
int Matrix[201][201] = { 0 };
vector<pair<int, pair<int, int>>> Temps;

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

void Debug()
{
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cout << Matrix[y][x] << ' ';
        }
        cout << endl;
    }
}

bool IsIn(int InX, int InY)
{
    return InX >= 0 && InX < N && InY >= 0 && InY < N;
}

void BFS()
{
    queue<pair<int, int>> Qs;

    for (int i = 0; i < Temps.size(); ++i)
    {
        // cout << Temps[i].first << endl;
        Qs.push(Temps[i].second);
    }

    int Time = 0;
    while (!Qs.empty())
    {
        //cout << Time << endl;
        //Debug();
        //cout << endl;
        //cout << endl;

        if (Time == S)
            break;

        int Size = Qs.size();
        for (int s = 0; s < Size; ++s)
        {
            pair<int, int> Cur = Qs.front();
            Qs.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nX = DirX[i] + Cur.first;
                int nY = DirY[i] + Cur.second;

                if (!IsIn(nX, nY))
                    continue;

                if (Matrix[nY][nX] != 0)
                    continue;

                Matrix[nY][nX] = Matrix[Cur.second][Cur.first];
                Qs.push({ nX, nY });

            }

        }

        ++Time;
    }

    cout << Matrix[X][Y];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> Matrix[y][x];
            if(Matrix[y][x] != 0)
                Temps.push_back({ Matrix[y][x],{x,y} });
        }
    }
    cin >> S >> X >> Y;
    --X; --Y;

    sort(Temps.begin(), Temps.end());

    BFS();

    return 0;
}