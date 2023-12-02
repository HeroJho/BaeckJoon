#include <iostream>
#include <algorithm>

using namespace std;

int g_A[20000];
int g_B[20000];

int main() 
{
    int iT, iN, iM;
    cin >> iT;
    while (iT--)
    {
        cin >> iN >> iM;
        for (int i = 0; i < iN; i++) {
            cin >> g_A[i];
        }
        for (int i = 0; i < iM; i++) {
            cin >> g_B[i];
        }
        sort(g_A, g_A + iN);
        sort(g_B, g_B + iM);
        int iResult = 0;
        for (int i = 0; i < iN; i++) {
            int iLow = 0;
            int iHigh = iM - 1;
            int x = g_A[i];
            while (iLow <= iHigh) {
                int iMid = (iLow + iHigh) / 2;
                if (g_B[iMid] >= x) iHigh = iMid - 1;
                else iLow = iMid + 1;
            }
            iResult += iLow;
        }
        cout << iResult << '\n';
    }
    return 0;
}