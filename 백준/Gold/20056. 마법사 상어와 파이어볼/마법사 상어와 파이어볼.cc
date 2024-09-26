#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


struct FireBall
{
    int X = 0, Y = 0, M = 0, S = 0, D = 0;

    FireBall() {};

    FireBall(int x, int y, int m, int s, int d)
        :X(x), Y(y), M(m), S(s), D(d) 
    {
    }

};

int DirX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int DirY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};


// 격자, 파이어볼 개수, 턴
int N, M, K;
vector<FireBall> Balls;

vector<FireBall> Matrix[51][51];

void Move()
{
    // D = 방향, S = 속력, M = 질량

    for (int i = 0; i < Balls.size(); ++i)
    {
        FireBall& Cur = Balls[i];

        // 벗어나면 사라지나
        // 순환함
        int Move = Cur.S % N;
        int nX = Cur.X + DirX[Cur.D] * Move;
        int nY = Cur.Y + DirY[Cur.D] * Move;
        
        if (nX > N)
            nX -= N;
        else if (nX < 1)
            nX += N;
        if (nY > N) 
            nY -= N;
        else if (nY < 1)
            nY += N;

        Cur.X = nX;
        Cur.Y = nY;
    }

}

void Split()
{
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            Matrix[y][x].clear();
        }
    }

    // Matrix에 표시
    for (int i = 0; i < Balls.size(); ++i)
    {
        Matrix[Balls[i].Y][Balls[i].X].push_back(Balls[i]);
    }

    // 하나의 파이어볼로 만듬
    Balls.clear();
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            if (Matrix[y][x].empty())
                continue;
            else if (Matrix[y][x].size() == 1)
            {
                Balls.push_back(Matrix[y][x].front());
                continue;
            }
            
            // 두 개 이상이다
            // *시작부터 나눠?
            int TotalM = 0, TotalS = 0;
            bool bIsOne = true;
            int PreDir = Matrix[y][x][0].D % 2;
            for (int i = 0; i < Matrix[y][x].size(); ++i)
            {
                TotalM += Matrix[y][x][i].M;
                TotalS += Matrix[y][x][i].S;

                if (PreDir != Matrix[y][x][i].D % 2)
                    bIsOne = false;
            }

            int nM, nS, nD;
            nM = TotalM / 5;
            nS = TotalS / Matrix[y][x].size();
            
            // 질량 없다
            if (nM == 0)
                continue;

            int Start = 0;
            if (bIsOne == false)
                Start = 1;
            
            for (int z = 0; z < 4; ++z)
            {
                int nDir = Start;

                Balls.push_back({ x, y, nM, nS, nDir });

                Start += 2;
            }

        }

    }

}

void RenderAns()
{
    int TotalM = 0;
    for (int i = 0; i < Balls.size(); ++i)
    {
        TotalM += Balls[i].M;
    }

    cout << TotalM;
}

void Go()
{
    // K 번
    while (K--)
    {
        Move();
        Split();
    }

    RenderAns();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i)
    {
        FireBall Ball;
        cin >> Ball.Y;
        cin >> Ball.X;
        cin >> Ball.M;
        cin >> Ball.S;
        cin >> Ball.D;

        Balls.push_back(Ball);
    }


    Go();


    return 0;
}