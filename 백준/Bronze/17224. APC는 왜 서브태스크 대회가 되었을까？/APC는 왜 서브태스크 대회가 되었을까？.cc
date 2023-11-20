#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int iN, iL, iK, i, iA, iB, iS = 0;
    vector<pair<int, int>> v;

    cin >> iN >> iL >> iK;

    for (i = 0; i < iN; i++)
    {
        cin >> iA >> iB;
        v.push_back(make_pair(iA, iB));
    }

    for (i = 0; i < iN; i++)
    {
        if (iK == 0) break;

        if (iL >= v[i].second)
        {
            iS += 140;
            iK--;
        }
    }

    for (i = 0; i < iN; i++)
    {
        if (iK == 0) break;

        if (iL >= v[i].first && iL < v[i].second)
        {
            iS += 100;
            iK--;
        }
    }

    cout << iS << endl;
}