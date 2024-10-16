#include <iostream>
#include <climits>


using namespace std;


int N;
int Matrix[21][21] = { 0 };

bool IsIn(int X, int Y)
{
    return X >= 1 && X <= N && Y >= 1 && Y <= N;
}

int Go(int X, int Y, int D1, int D2)
{
    int TempMatrix[21][21] = { 0 };

    pair<int, int> A{ Y , X };
    pair<int, int> B{ Y + D2, X + D2 };

    pair<int, int> C{ A.first - D1, A.second + D1 };
    pair<int, int> D{ C.first + D2, C.second + D2 };

    // 범위 체크
    if (!IsIn(B.first, B.second) ||
        !IsIn(C.first, C.second) ||
        !IsIn(D.first, D.second) )
        return INT_MAX;


    // 1번 범위
    for (int y = 1; y < C.second; ++y)
    {
        for (int x = 1; x <= A.first; ++x)
        {
            TempMatrix[y][x] = 1;
        }
    }
  
    // 2 범위
    for (int y = 1; y <= B.second; ++y)
    {
        for (int x = A.first + 1; x <= N; ++x)
        {
            TempMatrix[y][x] = 2;
        }
    }

    // 3 범위
    for (int y = C.second; y <= N; ++y)
    {
        for (int x = 1; x < D.first; ++x)
        {
            TempMatrix[y][x] = 3;
        }
    }

    // 4 범위
    for (int y = B.second + 1; y <= N; ++y)
    {
        for (int x = D.first; x <= N; ++x)
        {
            TempMatrix[y][x] = 4;
        }
    }



    // 5범위 칠한다
    int StartX = A.first + 1;
    int StartY = A.second;
    for (int c = 0; c < (D1+1)*2-1; ++c)
    {
        int Cnt = D2 + 1;
        if (c % 2 == 0)
        {
            StartX = StartX - 1;
        }
        else
        {
            StartY = StartY + 1;
            --Cnt;
        }

        for (int i = 0; i < Cnt; ++i)
        {
            int CurX = StartX + i;
            int CurY = StartY + i;

            TempMatrix[CurY][CurX] = 5;
        }

    }





    // 차이 계산
    int PCnt[6] = { 0 };

    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            PCnt[TempMatrix[y][x]] += Matrix[y][x];
        }
    }

    for (int i = 1; i <= 5; ++i)
    {
        if (PCnt[i] == 0)
            return INT_MAX;
    }



    int Min = INT_MAX, Max = 0;
    for (int i = 1; i <= 5; ++i)
    {
        if (Min > PCnt[i])
            Min = PCnt[i];
        if (Max < PCnt[i])
            Max = PCnt[i];
    }

    
    //if (Max - Min == 0)
    //{
    //    int A = 0;

    //    cout << endl;
    //    for (int x = 1; x <= N; ++x)
    //    {
    //        for (int y = 1; y <= N; ++y)
    //        {
    //            cout << TempMatrix[x][y] << ' ';
    //        }


    //        cout << endl;
    //    }


    //    cout << endl;
    //    cout << endl;

    //}

    
    return Max - Min;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            cin >> Matrix[y][x];
        }
    }


    int Ans = INT_MAX;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            for (int d1 = 1; d1 <= 20; ++d1)
            {
                for (int d2 = 1; d2 <= 20; ++d2)
                {
                    int Temp = Go(y, x, d1, d2);
                    if (Temp < Ans)
                        Ans = Temp;
                }
            }
        }
    }

    cout << Ans;


    return 0;
}