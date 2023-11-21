#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int iN;
    cin >> iN;

    vector<int> Inputs;
    for (int i = 0; i < iN; ++i)
    {
        int iNum;
        cin >> iNum;
        Inputs.push_back(iNum);
    }
    sort(Inputs.begin(), Inputs.end());
    cout << Inputs[(iN - 1) / 2];
}