#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long S = 0;
    cin >> S;
    
    long long iSum = 0;
    for(long long i = 0; i <= S; ++i)
    {
        iSum += i;
        if(iSum > S)
        {
            cout << i-1 << endl;
            break;
        }
        else if(iSum == S)
        {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}