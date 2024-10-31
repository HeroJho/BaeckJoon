#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;



struct Data
{
    Data(pair<int, int> pos, int cnt)
        : Pos(pos), Cnt(cnt)
    {}

    pair<int, int> Pos;
    int Cnt;
};

class Func
{
public:
    bool operator()(Data L, Data R)
    {
        return L.Cnt < R.Cnt;
    }
};



int N;
vector<string> Matrix;

int DP[51][51] = { 0 };
int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

void Reset()
{
    for (int i = 0; i < 51; ++i)
    {
        for (int j = 0; j < 51; ++j)
        {
            DP[i][j] = INT_MAX;
        }
    }
}

bool IsIn(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

void Dij()
{
    Reset();

    priority_queue<Data, vector<Data>, Func> Qs;
    Qs.push({ {0,0}, 0 });

    while (!Qs.empty())
    {
        Data Cur = Qs.top();
        Qs.pop();


        for (int i = 0; i < 4; ++i)
        {
            int nX = Cur.Pos.first + DirX[i];
            int nY = Cur.Pos.second + DirY[i];
            int Cnt = Cur.Cnt;

            if (!IsIn(nX, nY))
                continue;

            if (Matrix[nY][nX] == '0')
                ++Cnt;

            if (DP[nY][nX] <= Cnt)
                continue;
            DP[nY][nX] = Cnt;

            //if (N - 1 == nX && N - 1 == nY)
            //    return;

            Qs.push({ {nX, nY}, Cnt });

        }


    }


}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string Temp;
        cin >> Temp;
        Matrix.push_back(Temp);
    }

    Dij();

    cout << DP[N - 1][N - 1];

    return 0;
}