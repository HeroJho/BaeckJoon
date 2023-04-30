#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct Pos
{
    int x, y;
    Pos() :x(0), y(0) {};
    Pos(int X, int Y) { x = X; y = Y; }
};

int X, Y;
int Matrix[1001][1001] = { 0 };
list<Pos> q;
vector<Pos> Starts;

void BFS()
{

    for (int i = 0; i < Starts.size(); ++i)
    {
        q.push_back(Starts[i]);
    }

    while (!q.empty())
    {
        Pos Cur = q.front(); q.pop_front();
        Pos Temp;

        bool isIn = Cur.x >= 0 && Cur.x < X && Cur.y + 1 >= 0 && Cur.y + 1 < Y;
        if (isIn && Matrix[Cur.x][Cur.y + 1] == 0)
        {
            Matrix[Cur.x][Cur.y + 1] = Matrix[Cur.x][Cur.y] + 1;
            Temp = Cur;
            Temp.y += 1;
            q.push_back(Temp);
        }
        isIn = Cur.x >= 0 && Cur.x < X && Cur.y - 1 >= 0 && Cur.y - 1 < Y;
        if (isIn && Matrix[Cur.x][Cur.y - 1] == 0)
        {
            Matrix[Cur.x][Cur.y - 1] = Matrix[Cur.x][Cur.y] + 1;
            Temp = Cur;
            Temp.y -= 1;
            q.push_back(Temp);
        }
        isIn = Cur.x - 1 >= 0 && Cur.x - 1 < X && Cur.y >= 0 && Cur.y < Y;
        if (isIn && Matrix[Cur.x - 1][Cur.y] == 0)
        {
            Matrix[Cur.x - 1][Cur.y] = Matrix[Cur.x][Cur.y] + 1;
            Temp = Cur;
            Temp.x -= 1;
            q.push_back(Temp);
        }
        isIn = Cur.x + 1 >= 0 && Cur.x + 1 < X && Cur.y >= 0 && Cur.y < Y;
        if (isIn && Matrix[Cur.x + 1][Cur.y] == 0)
        {
            Matrix[Cur.x + 1][Cur.y] = Matrix[Cur.x][Cur.y] + 1;
            Temp = Cur;
            Temp.x += 1;
            q.push_back(Temp);
        }
    }

}

int main()
{
    cin >> X >> Y;
    for (int i = 0; i < Y; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            cin >> Matrix[j][i];
            if (Matrix[j][i] == 1)
                Starts.push_back(Pos(j, i));
        }
    }

    BFS();

    int iDepth = 0;
    for (int i = 0; i < Y; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            if (Matrix[j][i] == 0)
            {
                cout << -1;
                return 0;
            }
            if (iDepth < Matrix[j][i])
                iDepth = Matrix[j][i];
        }
    }

    cout << --iDepth;

    return 0;
}