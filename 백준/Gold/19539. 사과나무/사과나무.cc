
#include <iostream>
using namespace std;

int main()
{
    int iN = 0, iNow = 0, iCount = 0, iSum = 0;

    cin >> iN;
    for (int i = 0; i < iN; i++)
    {
        cin >> iNow;
        iSum += iNow;
        iCount += iNow / 2;
    }
    if (iSum % 3 != 0) cout << "NO\n";
    else iCount >= iSum / 3 ? cout << "YES\n" : cout << "NO\n";
}