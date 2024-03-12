#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<string> Inputs;
int DirX[] = { 0, 0, -1, 1};
int DirY[] = { -1, 1, 0, 0};

int Ans = 0;


bool IsIn(int X, int Y)
{
    return X >= 0 && X < N&& Y >= 0 && Y < N;
}

void Check()
{
    for (int i = 0; i < N; ++i)
    {
        char PreC = 0;
        int Cnt = 1;
        char PreCn = 0;
        int Cntn = 1;
        for (int j = 0; j < N; ++j)
        {
            // 가로 확인
            if (PreC != Inputs[i][j])
                Cnt = 1;
            else
                ++Cnt;

            PreC = Inputs[i][j];
            if (Cnt > Ans)
                Ans = Cnt;



            // 세로 확인
            if (PreCn != Inputs[j][i])
                Cntn = 1;
            else
                ++Cntn;

            PreCn = Inputs[j][i];
            if (Cntn > Ans)
                Ans = Cntn;
        }
    }




}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int X = j;
            int Y = i;

            for (int d = 0; d < 4; ++d)
            {
                int nX = DirX[d] + X;
                int nY = DirY[d] + Y;

                if (!IsIn(nX, nY))
                    continue;

                // 바꿀 수 있다
                if (Inputs[nY][nX] != Inputs[Y][X])
                {
                    // 바꾼다
                    char Temp = Inputs[Y][X];
                    Inputs[Y][X] = Inputs[nY][nX];
                    Inputs[nY][nX] = Temp;

                    // 확인
                    Check();

                    // 돌려놓는다
                    Temp = Inputs[Y][X];
                    Inputs[Y][X] = Inputs[nY][nX];
                    Inputs[nY][nX] = Temp;
                }

            }

        }

    }

    cout << Ans;

    return 0;
}
