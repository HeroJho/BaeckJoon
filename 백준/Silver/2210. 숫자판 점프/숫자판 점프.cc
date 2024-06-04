#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;


char Matrix[5][5];
set<string> Set;

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

bool IsIn(int X, int Y)
{
    return X >= 0 && X < 5 && Y >= 0 && Y < 5;
}

void DFS(int Depth, pair<int ,int> Pos, string Name)
{
    if (Depth >= 6)
    {
        Set.emplace(Name);
        return;
    }



    for (int i = 0; i < 4; ++i)
    {
        int nX = DirX[i] + Pos.first;
        int nY = DirY[i] + Pos.second;

        if (!IsIn(nX, nY))
            continue;
        
        DFS(Depth + 1, {nX, nY}, Name + Matrix[nY][nX]);
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> Matrix[i][j];
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            DFS(0, {j,i}, "");
        }
    }

    cout << Set.size();


    return 0;
}