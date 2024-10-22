#include <iostream>
#include <vector>

using namespace std;


int N, M;
int Matrix[51][51] = { 0 };
vector<pair<int, int>> Orders;

// (N, 1), (N, 2), (N-1, 1), (N-1, 2)
vector<pair<int ,int>> Clouds;
bool DeletedPos[51][51] = { false };

int DirX[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int DirY[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int CDirX[] = { -1, 1, -1, 1 };
int CDirY[] = { -1, -1, 1, 1 };


bool IsIn(int X, int Y)
{
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

// 명령어에 따라 구름 이동
void MoveCloud(pair<int ,int> Order)
{

    int Dir = Order.first;
    int Dis = Order.second;

    for (int i = 0; i < Clouds.size(); ++i)
    {
        int nX = Clouds[i].first;
        int nY = Clouds[i].second;

        for (int d = 0; d < Dis; ++d)
        {
            nX += DirX[Dir];
            nY += DirY[Dir];

            if (nX < 0)
                nX = N-1;
            if (nX >= N)
                nX = 0;

            if (nY < 0)
                nY = N - 1;
            if (nY >= N)
                nY = 0;
        }


        // 음수일 때
        Clouds[i].first = nX;
        Clouds[i].second = nY;
    }

}

// 구름 위치에 물의 양 1 증가 && 사라짐
void MakeWater()
{
    for (int i = 0; i < Clouds.size(); ++i)
    {
        ++Matrix[Clouds[i].second][Clouds[i].first];
        DeletedPos[Clouds[i].second][Clouds[i].first] = true;
    }

}

// 물 복사
void DupWater()
{
    for (int i = 0; i < Clouds.size(); ++i)
    {
        int Cnt = 0;
        for (int d = 0; d < 4; ++d)
        {
            int nX = Clouds[i].first + CDirX[d];
            int nY = Clouds[i].second + CDirY[d];

            if (!IsIn(nX, nY))
                continue;

            if (Matrix[nY][nX])
                ++Cnt;
        }

        Matrix[Clouds[i].second][Clouds[i].first] += Cnt;
    }

    Clouds.clear();
}

// 2이상 구름 생성
void MakeCloud()
{
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (!DeletedPos[y][x] && Matrix[y][x] >= 2)
            {
                Matrix[y][x] -= 2;
                Clouds.push_back({x, y});
            }

            DeletedPos[y][x] = false;
        }
    }

}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> Matrix[y][x];
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int D, S;
        cin >> D >> S;
        Orders.push_back({ D, S });
    }

    Clouds.push_back({ 0,   N - 1 });
    Clouds.push_back({ 1,   N - 1 });
    Clouds.push_back({ 0,   N - 2 });
    Clouds.push_back({ 1,   N - 2 });



    for (int i = 0; i < M; ++i)
    {
        MoveCloud(Orders[i]);
        MakeWater();
        DupWater();
        MakeCloud();
    }

    int Ans = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            Ans += Matrix[y][x];
        }
    }

    cout << Ans;

    return 0;
}