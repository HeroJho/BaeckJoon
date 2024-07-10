#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
bool Matrix[10000][10000] = { false };

void DFS(int Depth, pair<int ,int> Pos)
{
    if (Depth == 1)
    {
        Matrix[Pos.second][Pos.first] = true;
        return;
    }

    for (int i = 0; i < 9; ++i)
    {
        int Dis = Depth / 3;

        int X = Pos.first + Dis * (i % 3);
        int Y = Pos.second + Dis * (i / 3);

        if (i == 4)
            continue;
        else
            DFS(Depth / 3, {X, Y});

    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    DFS(N, {0, 0});

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (!Matrix[y][x])
                cout << " ";
            else
                cout << "*";
        }

        cout << "\n";

    }


    return 0;
}