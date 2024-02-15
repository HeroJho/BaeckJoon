#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, C;
int DPs[10010];
pair<int, int> Inputs[5001]; // 칼로리, 가격 순
double M, P;

int main() 
{

    while (true) 
    {
        memset(DPs, 0, sizeof(DPs));
        // 돈 : m, n : 사탕의 종류
        cin >> N >> M;

        if (N == 0 && (M < 0.001))
            break;

        for (int i = 0; i < N; i++) 
        {
            cin >> C >> P;
            Inputs[i] = make_pair(C, (int)(P * 100 + 0.5));
        }

        int intM = (int)(M * 100 + 0.5);

        // 캔디 순회
        for (int i = 0; i < N; i++) 
        {
            // i번째 캔디의 가격 ~ M 순회
            for (int j = Inputs[i].second; j <= intM; j++)
            {
                DPs[j] = max(DPs[j], DPs[j - Inputs[i].second] + Inputs[i].first);
            }
         
        }

        cout << DPs[intM] << '\n';
    }



    return 0;
}
