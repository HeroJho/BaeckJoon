#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int R, C;

vector<string> Matrix;
int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { 1, -1, 0, 0 };

pair<int, int> JPos;
vector<pair<int, int>> PPoss;

bool IsIn(int InX, int InY)
{
    return InX >= 0 && InX < R && InY >= 0 && InY < C;
}

int BFS()
{
    int Ans = 0;

    queue<pair<int, int>> JQs, PQs;

    JQs.push(JPos);

    for (int i = 0; i < PPoss.size(); ++i)
    {
        PQs.push(PPoss[i]);
    }

    while (!JQs.empty())
    {
        ++Ans;

        int Size = JQs.size();
        
        // 지훈 한 턴
        for (int j = 0; j < Size; ++j)
        {
            pair<int, int> Cur = JQs.front();
            JQs.pop();

            // 현재 불이 덮혔다면
            if (Matrix[Cur.second][Cur.first] == 'F')
                continue;

            // 지훈 이동 4방향 칠하기
            for (int i = 0; i < 4; ++i)
            {
                int nX = DirX[i] + Cur.first;
                int nY = DirY[i] + Cur.second;

                // 가장자리 도착 끝
                if (!IsIn(nX, nY))
                    return Ans;

                // 불 벽 나 패스
                if (Matrix[nY][nX] != '.')
                    continue;

                Matrix[nY][nX] = 'J';
                JQs.push({ nX, nY });

            }
        }

        
        // 불 한 턴
        Size = PQs.size();
        for (int p = 0; p < Size; ++p)
        {
            pair<int, int> Cur = PQs.front();
            PQs.pop();

            // 지훈 이동 4방향 칠하기
            for (int i = 0; i < 4; ++i)
            {
                int nX = DirX[i] + Cur.first;
                int nY = DirY[i] + Cur.second;

                if (!IsIn(nX, nY))
                    continue;

                // 불 & 벽 패스
                if (Matrix[nY][nX] == '#' || Matrix[nY][nX] == 'F')
                    continue;

                Matrix[nY][nX] = 'F';
                PQs.push({ nX, nY });

            }
        }


    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C >> R;
    for (int y = 0; y < C; ++y)
    {
        string Temp;
        cin >> Temp;

        Matrix.push_back(Temp);

        for (int x = 0; x < R; ++x)
        {
            if (Temp[x] == 'J')
                JPos = { x, y };
            else if (Temp[x] == 'F')
                PPoss.push_back({ x,y });
        }
    }

    int Ans = BFS();
    if (Ans == -1)
        cout << "IMPOSSIBLE";
    else
        cout << Ans;


    return 0;
}
