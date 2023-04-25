#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    int RR, TL; cin >> RR; cin >> TL;
    list<int> P;
    for (int i = 0; i < RR; ++i)
    {
        int temp; cin >> temp;
        P.push_back(temp);
    }

    if (TL == 1)
    {
        cout << P.size();
        return 0;
    }

    P.sort();
    // sort(P.begin(), P.end());
    // 둘의 차이를 구한다.
    int iTCount = 0;
    int iCurL = P.front();
    P.pop_front();
    bool bCut = false;
    while (!P.empty())
    {
        bCut = false;

        if (-1 == iCurL)
        {
            iCurL = P.front();
            P.pop_front();

            if (P.empty())
            {
                ++iTCount;
                bCut = true;
                break;
            }
        }

        int iNexL = P.front();
        P.pop_front();
        int iD = (iNexL - iCurL) + 1;
        if (TL < iD)
        {
            iCurL = iNexL;
            ++iTCount;

            if (P.empty())
            {
                ++iTCount;
                bCut = true;
                break;
            }
        }
        else if (iD == TL)
        {
            iCurL = -1;
            ++iTCount;
            bCut = true;
        }
    }

    if (!bCut)
        ++iTCount;
    cout << iTCount;

    return 0;
}