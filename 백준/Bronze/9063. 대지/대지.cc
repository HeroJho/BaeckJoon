#include <iostream>
using namespace std;
int main()
{
    int iN;
    int iMinx = 100000; int iMaxx = -100000;
    int iMiny = 100000; int iMaxy = -100000;
    cin >> iN;
    int* x = new int[iN];
    int* y = new int[iN];
    for (int i = 0; i < iN; ++i)
    {
        cin >> x[i] >> y[i];
        if (iMinx > x[i]) iMinx = x[i];
        if (iMaxx < x[i]) iMaxx = x[i];
        if (iMiny > y[i]) iMiny = y[i];
        if (iMaxy < y[i]) iMaxy = y[i];
    }
    cout << (iMaxx - iMinx) * (iMaxy - iMiny);
    //(가장 큰 x좌표 - 가장 작은 x좌표) * (가장 큰 y좌표 - 가장 작은 y좌표)
}