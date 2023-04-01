#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{

    vector<int> iAnss;
    while (1)
    {
        int L, P, V; cin >> L; cin >> P; cin >> V;
        int iCount = 0;
        int iTemp = 0;

        if (L + P + V == 0)
        {
            break;
        }

        // 나머지가 P를 넘을 경우 X
        // 18 19 20
        iCount = V / P; // 2
        iTemp = V % P;  // 4

        // 남은 시간이 머무를 수 있는 시간보다 많다.
        if (L < iTemp)
        {
            iTemp = L;
        }

        int iAns = 0;
        iAns = iCount * L; 
        iAns += iTemp; // 14

        iAnss.push_back(iAns);
    }

    int iCase = 1;
    for (auto& iAns : iAnss)
    {
        cout << "Case " << iCase << ": " << iAns << endl;
        ++iCase;
    }


    return 0;
}