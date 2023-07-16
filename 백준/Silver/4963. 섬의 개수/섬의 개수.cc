#include <iostream>
#include <array>

using namespace std;

#define MAX 50
#define EIGHT 8

int w{ 0 }, h{ 0 };
array < array<bool, MAX>, MAX> arr{ {0} };
array < array<bool, MAX>, MAX> visited{ {0} };

void DFS(int x, int y)
{
    // 각축 기준 T, B, R, L, LT, LB, RT, RB
    array<int, EIGHT> pivotX{ 0, 0, 1, -1, -1, -1, 1, 1 };
    array<int, EIGHT> pivotY{ 1, -1, 0, 0, 1, -1, 1, -1 };

    visited[y][x] = true;

    for (int i = 0; i < EIGHT; i++)
    {
        // 배추의 상, 하, 좌, 우를 임시 보관하는 변수
        int tempX = x + pivotX[i];
        int tempY = y + pivotY[i];

        if (tempX < 0 || tempX >= w || tempY < 0 || tempY >= h)
        {
            // 배열에서 접근할 수 없는 값은 continue
            continue;
        }

        if (arr[tempY][tempX] == true && visited[tempY][tempX] == false)
        {
            // 땅이고 && 방문하지 않은 곳 이라면
            visited[tempY][tempX] = true;
            DFS(tempX, tempY);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    while (true)
    {
        cin >> w >> h;

        if (0 == w && 0 == h)
        {
            break;
        }

        // 초기화
        //arr = { {false} };
        //visited = { {false} };

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                arr[i][j] = false;
                visited[i][j] = false;
            }
        }

        int island{ 0 };
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> island;
                if (1 == island)
                {
                    arr[i][j] = true;
                }
            }
        }

        int result{ 0 };
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (arr[i][j] == true && visited[i][j] == false)
                {
                    // 땅이면서 && 방문하지 않은 곳 이라면
                    result++;
                    
                    DFS(j, i);
                }
            }
        }

        cout << result << '\n';

    }

    return 0;
}