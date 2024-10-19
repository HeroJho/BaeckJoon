//16931번: 겉넓이 구하기
#include <iostream>
using namespace std;

int N, M;
int Arr[102][102];
int DirX[] = { -1,1,0,0 };
int DirY[] = { 0,0,-1,1 };

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Sum = 0;
    cin >> N >> M;
    Sum = 2 * N * M; //위아랫면 합 : 2*n*m

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= M; j++) 
        {
            cin >> Arr[i][j];
        }
    }
    // 4개의 옆면 합 구하기
    for (int x = 1; x <= N; x++) 
    {
        for (int y = 1; y <= M; y++) 
        {
            for (int i = 0; i < 4; i++) 
            {
                int nX = x + DirX[i];
                int nY = y + DirY[i];

                if (Arr[x][y] > Arr[nX][nY])
                    Sum += (Arr[x][y] - Arr[nX][nY]);
            }
        }
    }

    cout << Sum << "\n";

    return 0;

}