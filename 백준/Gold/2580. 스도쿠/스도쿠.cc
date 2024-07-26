#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int Matrix[10][10] = { 0 };


bool Check(int X, int Y, int Num)
{
    // 가로, 세로
    for (int i = 0; i < 9; ++i)
    {
        if (Matrix[Y][i] == Num)
            return false;

        if (Matrix[i][X] == Num)
            return false;
    }

    // 3 * 3
    int StartX = 3 * (X / 3);
    int StartY = 3 * (Y / 3);
    for (int y = StartY; y < StartY + 3; ++y)
    {
        for (int x = StartX; x < StartX + 3; ++x)
        {
            if (Matrix[y][x] == Num)
                return false;
        }
    }

    return true;
}


bool DFS(int Depth)
{
    if (Depth == 81)
        return true;


    int X = Depth % 9;
    int Y = Depth / 9;

    if (Matrix[Y][X] != 0)
        return DFS(Depth + 1);

    for (int i = 1; i <= 9; ++i)
    {        
        if (Check(X, Y, i))
        {
            Matrix[Y][X] = i;

            if (DFS(Depth + 1))
                return true;

            Matrix[Y][X] = 0;
        }

    }

    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> Matrix[i][j];
        }
    }

    DFS(0);


    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << Matrix[i][j] << ' ';
        }

        cout << endl;
    }


    return 0;
}