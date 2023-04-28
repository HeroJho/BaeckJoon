#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

struct Pos
{
    int x, y;
    Pos()
    {
        x = 0; y = 0;
    }
    Pos(int ix, int iy)
    {
        x = ix; y = iy;
    }
};

int N, M;

int Mage[101][101];
bool isCheck[101][101];
Pos Parents[101][101];
list<Pos> q;

int BFS()
{

    q.push_back(Pos(0, 0));
    Parents[0][0] = Pos(0, 0);
    isCheck[0][0] = true;
    while (!q.empty())
    {
        Pos Cur = q.front(); q.pop_front();

        if (Cur.x == N-1 && Cur.y == M-1)
            break;

        // 상하좌우를 확인한다.
        if ((Cur.x < N && Cur.y + 1 < M) && isCheck[Cur.x][Cur.y + 1] != true && 1 == Mage[Cur.x][Cur.y + 1])
        {
            q.push_back(Pos(Cur.x, Cur.y + 1));
            isCheck[Cur.x][Cur.y + 1] = true;
            Parents[Cur.x][Cur.y + 1] = Pos(Cur.x, Cur.y);
        }
        if ((Cur.x < N && Cur.y - 1 < M) && isCheck[Cur.x][Cur.y - 1] != true && 1 == Mage[Cur.x][Cur.y - 1])
        {
            q.push_back(Pos(Cur.x, Cur.y - 1));
            isCheck[Cur.x][Cur.y - 1] = true;
            Parents[Cur.x][Cur.y - 1] = Pos(Cur.x, Cur.y);
        }
        if ((Cur.x - 1< N && Cur.y < M) && isCheck[Cur.x - 1][Cur.y] != true && 1 == Mage[Cur.x - 1][Cur.y])
        {
            q.push_back(Pos(Cur.x - 1, Cur.y));
            isCheck[Cur.x - 1][Cur.y] = true;
            Parents[Cur.x - 1][Cur.y] = Pos(Cur.x, Cur.y);
        }
        if ((Cur.x + 1 < N && Cur.y < M) && isCheck[Cur.x + 1][Cur.y] != true && 1 == Mage[Cur.x + 1][Cur.y])
        {
            q.push_back(Pos(Cur.x + 1, Cur.y));
            isCheck[Cur.x + 1][Cur.y] = true;
            Parents[Cur.x + 1][Cur.y] = Pos(Cur.x, Cur.y);
        }
    }

    int iCount = 1;
    Pos Cur = Parents[N - 1][M - 1];
    while (1)
    {
        ++iCount;
        Cur = Parents[Cur.x][Cur.y];
        
        if (Cur.x == 0 && Cur.y == 0)
            break;
    }


    return iCount;
}

void Clear()
{
    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0; j < 101; ++j)
        {
            Mage[i][j] = 0;
            isCheck[i][j] = 0;
        }
    }
}

int main()
{
    cin >> N; cin >> M;
    vector<string> TempMage;
    for (int i = 0; i < N; ++i)
    {
        string s; cin >> s;
        TempMage.push_back(s);
    }

    Clear();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if ('1' == TempMage[i][j])
                Mage[i][j] = 1;
        }
    }

    int iCount = BFS();

    cout << iCount + 1;

    return 0;
}