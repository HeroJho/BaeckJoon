#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;


class Func
{
public:
    bool operator()(int L, int R)
    {
        return L < R;
    }
};

int N, M, D;
int Matrix[15][15] = { 0 };

// 궁수의 포지션
int ArPosX[3] = { 0 };
int Ans = 0;

void Reset()
{
    ArPosX[0] = -1;
    ArPosX[1] = -1;
    ArPosX[2] = -1;

}

int Go()
{
    int Cnt = 0;

    // 판을 복사
    int TempMatrix[15][15] = { 0 };
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            TempMatrix[y][x] = Matrix[y][x];
        }
    }

    while (true)
    {
        // 공격
        //  몬스터와의 거리 확인
        //  가장 가까운 적을 뽑는다
        //  여러마리라면 x가 적은 애를 뽑는다
        //  제거 = Ans++


        // ================궁수의 공격 순서는?
        // 동시에 공격한다
        // 같은 적이 여러 궁수한테 맞을 수 있다
        pair<int, int> DestroyPos3[3];
        bool Can3[3] = { false };
        for (int i = 0; i < 3; ++i)
        {

            int CurArPosY = N;
            int CurArPosX = ArPosX[i];

            pair<int, int> DestroyPos;
            int MinDis = INT_MAX;
            bool NoAn = true;
            for (int y = 0; y < N; ++y)
            {
                for (int x = 0; x < M; ++x)
                {
                    if (TempMatrix[y][x] == 0)
                        continue;

                    NoAn = false;

                    int Dis = abs(CurArPosY - y) + abs(CurArPosX - x);

                    // 거리제한을 벗어나면 x
                    if (Dis > D)
                        continue;

                    if (Dis < MinDis)
                    {
                        DestroyPos.first = x;
                        DestroyPos.second = y;
                        MinDis = Dis;
                    }
                    else if (Dis == MinDis)
                    {
                        if (x < CurArPosX)
                        {
                            DestroyPos.first = x;
                            DestroyPos.second = y;
                            MinDis = Dis;
                        }
                    }

                }

            }

            // 몬스터가 하나도 없다
            if (NoAn)
            {
                return Cnt;
            }

            if (MinDis != INT_MAX)
            {
                // 제거
                DestroyPos3[i] = DestroyPos;
                Can3[i] = true;
            }

        }

        for (int i = 0; i < 3; ++i)
        {
            if (Can3[i] == false)
                continue;
            if (TempMatrix[DestroyPos3[i].second][DestroyPos3[i].first] == 0)
                continue;

            TempMatrix[DestroyPos3[i].second][DestroyPos3[i].first] = 0;
            ++Cnt;
        }


        // 몬스터 이동
        for (int y = N - 1; y >= 0; --y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (TempMatrix[y][x] == 0)
                    continue;

                int nY = y + 1;
                if (nY >= N)
                {
                    TempMatrix[y][x] = 0;
                    continue;
                }

                TempMatrix[y][x] = 0;
                TempMatrix[nY][x] = 1;
            }
        }

    }


    return Cnt;
}

void DFS(int ArNum, int StartIndex)
{
    // 포지션이 다 차면
    //  시뮬레이션 한다
    if (ArNum >= 3)
    {
        int Cnt = Go();
        if (Ans < Cnt)
        {
            Ans = Cnt;
        }


        return;
    }
    
    // 0~M x로 변경
    for (int x = StartIndex; x < M; ++x)
    {
        ArPosX[ArNum] = x;
        DFS(ArNum + 1, x + 1);
        ArPosX[ArNum] = -1;

    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> D;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            cin >> Matrix[y][x];
        }
    }

    Reset();

    DFS(0, 0);

    cout << Ans;

    return 0;
}
