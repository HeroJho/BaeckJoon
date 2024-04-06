#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;


int N, L;
int Matrix[100][100] = { 0 };
bool Visited[100][100] = { false };
// 시작 인덱스, 가로 세로, 방향

int Ans = 0;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Matrix[i][j];
        }
    }

    int Ans = 0;


    // 가로
    for (int i = 0; i < N; ++i)
    {
        bool CanLine = true;
        bool Visited[100] = {false};
        for (int j = 0; j < N - 1; ++j)
        {

            int Dis = Matrix[i][j] - Matrix[i][j + 1];
            // 오르막
            if (Dis == -1)
            {
                int PreL = Matrix[i][j];
                bool Can = true;
                for (int l = j; l > j - L; --l)
                {

                    if (l < 0 || Visited[l] || PreL != Matrix[i][l])
                    {
                        Can = false;
                        break;
                    }

                    Visited[l] = true;
                }

                if (!Can)
                {
                    CanLine = false;
                    break;
                }

            } //내리막
            else if (Dis == 1)
            {
                int PreL = Matrix[i][j + 1];
                bool Can = true;
                for (int l = j + 1; l <= j + L; ++l)
                {

                    if (l >= N || Visited[l] || PreL != Matrix[i][l])
                    {
                        Can = false;
                        break;
                    }

                    Visited[l] = true;

                }

                if (!Can)
                {
                    CanLine = false;
                    break;
                }

            } // 평평
            else if (Dis == 0)
            {
                continue;
            }
            else
            {
                CanLine = false;
                break;
            }

        }

        if (CanLine)
            ++Ans;

    }


    // 세로
    for (int i = 0; i < N; ++i)
    {
        bool CanLine = true;
        bool Visited[100] = { false };
        
        for (int j = 0; j < N - 1; ++j)
        {

            int Dis = Matrix[j][i] - Matrix[j + 1][i];
            // 오르막
            if (Dis == -1)
            {
                int PreL = Matrix[j][i];

                bool Can = true;
                for (int l = j; l > j - L; --l)
                {

                    if (l < 0 || Visited[l] || PreL != Matrix[l][i])
                    {
                        Can = false;
                        break;
                    }

                    Visited[l] = true;

                }

                if (!Can)
                {
                    CanLine = false;
                    break;
                }

            } //내리막
            else if (Dis == 1)
            {
                int PreL = Matrix[j + 1][i];

                bool Can = true;
                for (int l = j + 1; l <= j + L; ++l)
                {

                    if (l >= N || Visited[l] || PreL != Matrix[l][i])
                    {
                        Can = false;
                        break;
                    }

                    Visited[l] = true;

                }

                if (!Can)
                {
                    CanLine = false;
                    break;
                }

            } // 평평
            else if (Dis == 0)
            {
                continue;
            }
            else
            {
                CanLine = false;
                break;
            }

        }

        if (CanLine)
            ++Ans;

    }


    cout << Ans;

    return 0;
}