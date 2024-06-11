#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int Matrix[1001] = { 0 };
bool Visited[1001] = { false };


void Reset()
{
    for (int i = 0; i < 1001; ++i)
    {
        Visited[i] = false;
    }
}

void DFS(int Cur)
{
    if (Visited[Cur] == true)
        return;
    Visited[Cur] = true;
 
    DFS(Matrix[Cur]);

}

void IterDFS()
{
    Reset();

    int Ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (Visited[i] == true)
            continue;

        Ans++;

        DFS(i);
    }

    cout << Ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)
        {
            cin >> Matrix[i];
        }

        IterDFS();
    }


    return 0;
}