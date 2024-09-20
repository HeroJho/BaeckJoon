#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int S;
bool Visited[1001][2001] = { false };

void BFS()
{
    queue<pair<int, int>> Qs;
    Qs.push({ 1, 0 });


    int Cnt = 0;
    while (!Qs.empty())
    {
        int Size = Qs.size();

        for (int s = 0; s < Size; ++s)
        {
            pair<int, int> Cur = Qs.front();
            Qs.pop();

            if (Cur.first > 1000)
                continue;

            if (Cur.first == S)
            {
                cout << Cnt;
                return;
            }


            if (Visited[Cur.first][Cur.second])
                continue;
            Visited[Cur.first][Cur.second] = true;


            // 복사
            Qs.push({ Cur.first, Cur.first });
            // 붙여넣기
            Qs.push({ Cur.first + Cur.second, Cur.second });
            // 하나 삭제
            if (Cur.first - 1 > 0)
                Qs.push({ Cur.first - 1, Cur.second });

        }

        ++Cnt;
    }

}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> S;

    BFS();


    return 0;
}