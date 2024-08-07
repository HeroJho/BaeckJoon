#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Data
{
    bool IsB = false;
    pair<int, int> Pos;
};

int N;
int X, Y;
vector<string> Matrix;


int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };


void Reset()
{
    Matrix.clear();
}

bool IsIn(int InX, int InY)
{
    return InX >= 0 && InX < X && InY >= 0 && InY < Y;
}

int BFS()
{
    // 하나로 된다, 상근 넣고 불 넣으면
    // 상근과 불을 구분
    pair<int, int> BPos;
    vector<pair<int ,int>> FirePoss;
    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            if (Matrix[y][x] == '*')
            {
                FirePoss.push_back({ x, y });
            }
            else if (Matrix[y][x] == '@')
            {
                BPos = { x, y };
            }
        }
    }


    queue<Data> Qs;

    for (int i = 0; i < FirePoss.size(); ++i)
    {
        Qs.push({false, FirePoss[i]});
    }

    Qs.push({ true, BPos });



    int Cnt = 0;
    while (!Qs.empty())
    {
        int Size = Qs.size();

        ++Cnt;

        for (int s = 0; s < Size; ++s)
        {

            Data Cur = Qs.front();
            Qs.pop();

            bool IsB = Cur.IsB;
            for (int i = 0; i < 4; ++i)
            {
                int nX = DirX[i] + Cur.Pos.first;
                int nY = DirY[i] + Cur.Pos.second;

                if (!IsIn(nX, nY))
                {
                    // 상근이 끝에 도착했다면
                    if (IsB)
                    {
                        return Cnt;
                    }
                    continue;
                }

                if (Matrix[nY][nX] == '#')
                {
                    continue;
                }
                if (Matrix[nY][nX] == '*')
                {
                    continue;
                }

                if (IsB && Matrix[nY][nX] == '@')
                {
                    continue;
                }
                    
                if (IsB)
                    Matrix[nY][nX] = '@';
                else
                    Matrix[nY][nX] = '*';


                Qs.push({ IsB,{nX,nY} });

            }

        }

    }

    return -1;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 상근, 불
    cin >> N;


    while (N--)
    {
        Reset();

        cin >> X >> Y;
        for (int i = 0; i < Y; ++i)
        {
            string Temp;
            cin >> Temp;
            Matrix.push_back(Temp);
        }

        int Ans = BFS();
        if (Ans == -1)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << Ans << '\n';

    }

    return 0;
}