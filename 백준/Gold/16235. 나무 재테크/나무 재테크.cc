#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 11

using namespace std;

int g_N, g_M, g_K;
int g_A[MAX][MAX] = { 0 }; // 충전 양분
int g_E[MAX][MAX] = { 5 }; // 현재 양분
vector<int> g_Wood[MAX][MAX];
vector<int> g_DeadWood[MAX][MAX];
vector<int> g_FiveWood[MAX][MAX];

int g_DirX[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int g_DirY[] = { -1 ,1, 0, 0, 1, -1, 1, -1 };

class Func
{
public:
    bool operator()(int L, int R)
    {
        return L < R;
    }
};


void Init()
{
    for (int y = 1; y <= g_N; ++y)
        for (int x = 1; x <= g_N; ++x)
            g_E[y][x] = 5;
}

void A()
{
    // 나이만큼 양분을 먹고 1증가
    // 어린 나무부터 먹는다.
    // 양분이 부족하면 죽는다.

    for (int y = 1; y <= g_N; ++y)
    {
        for (int x = 1; x <= g_N; ++x)
        {
            g_DeadWood[y][x].clear();
            g_FiveWood[y][x].clear();

            if (g_Wood[y][x].empty())
                continue;

            sort(g_Wood[y][x].begin(), g_Wood[y][x].end(), Func());

            for (auto iter = g_Wood[y][x].begin(); iter != g_Wood[y][x].end();)
            {
                int Dis = g_E[y][x] - *iter;
                if (Dis < 0)
                {
                    // 죽는다
                    g_DeadWood[y][x].push_back(*iter);
                    iter = g_Wood[y][x].erase(iter);
                }
                else
                {
                    // 먹는다
                    g_E[y][x] = Dis;
                    ++(*iter);

                    if (*iter % 5 == 0)
                        g_FiveWood[y][x].push_back(*iter);

                    ++iter;
                }
            }


        }
    }


}

void B()
{
    // 죽은 나무가 양분으로 변한다
    // 죽은 나무마다 2로 나눈 값이 나무가 있던 칸에 양분을 추가한다.

    for (int y = 1; y <= g_N; ++y)
    {
        for (int x = 1; x <= g_N; ++x)
        {
            int Sum = 0;
            for (int i = 0; i < g_DeadWood[y][x].size(); ++i)
            {
                int Age = g_DeadWood[y][x][i];
                Sum += (Age / 2);

            }

            g_E[y][x] += Sum;

        }
    }


}


bool IsIn(int iX, int iY)
{
    return iX >= 1 && iX <= g_N && iY >= 1 && iY <= g_N;
}
void AddInf(int X, int Y)
{

    for (int i = 0; i < 8; ++i)
    {
        int inX = X + g_DirX[i];
        int inY = Y + g_DirY[i];

        if (!IsIn(inX, inY))
            continue;

        g_Wood[inY][inX].push_back(1);
    }

}
void C()
{
    // 나이가 5의 배수인 나무
    // 인접한 8칸 나이 1 나무 추가
    for (int y = 1; y <= g_N; ++y)
    {
        for (int x = 1; x <= g_N; ++x)
        {
    
            for (int i = 0; i < g_FiveWood[y][x].size(); ++i)
                AddInf(x, y);

        }
    }

}
void D()
{
    for (int y = 1; y <= g_N; ++y)
    {
        for (int x = 1; x <= g_N; ++x)
        {
            g_E[y][x] += g_A[y][x];
        }
    }
}

int Go()
{

    while (g_K--)
    {
        A();
        B();
        C();
        D();
    }


    int Ans = 0;
    for (int y = 1; y <= g_N; ++y)
    {
        for (int x = 1; x <= g_N; ++x)
        {
            Ans += g_Wood[y][x].size();
        }
    }

    return Ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // N * N
    cin >> g_N >> g_M >> g_K;

    for (int y = 1; y <= g_N; ++y)
    {
        for (int x = 1; x <= g_N; ++x)
        {
            cin >> g_A[y][x];
        }
    }

    for (int i = 0; i < g_M; ++i)
    {
        int x, y, z; 
        cin >> x >> y >> z;
        
        g_Wood[x][y].push_back(z);
    }

    Init();

    cout << Go();
    
    return 0;
}
