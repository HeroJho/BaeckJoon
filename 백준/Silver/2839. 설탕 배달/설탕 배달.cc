#include<iostream>
using namespace std;

int N = 0;
int main(int)
{
    cin >> N;
    
    int iCount = 0;
    while(0 <= N)
    {
        if(0 == N%5)
        {
            iCount += N/5;
            cout << iCount << endl;
            return 0;
        }

        N -= 3;
        ++iCount;
    }
    cout << -1 << endl;
    
    return 0;
}