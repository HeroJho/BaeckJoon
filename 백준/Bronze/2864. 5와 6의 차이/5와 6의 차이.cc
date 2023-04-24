#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int A, B; cin >> A; cin >> B;

    string sA = to_string(A);
    string sB = to_string(B);

    string minsA = sA;
    string minsB = sB;
    string maxsA = sA;
    string maxsB = sB;
    for (int i = 0; i < sA.length(); ++i)
    {
        if ('6' == sA[i])
        {
            minsA[i] = '5';
        }
        if ('5' == sA[i])
        {
            maxsA[i] = '6';
        }
    }
    for (int i = 0; i < sB.length(); ++i)
    {
        if ('6' == sB[i])
        {
            minsB[i] = '5';
        }
        if ('5' == sB[i])
        {
            maxsB[i] = '6';
        }
    }
    int minSum = stoi(minsA) + stoi(minsB);
    int maxSum = stoi(maxsA) + stoi(maxsB);

    cout << minSum << ' ' << maxSum;

    return 0;
}