#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    // 500엔, 100엔, 50엔, 10엔, 5엔, 1엔
    N = 1000 - N;
    int iCount = N / 500;
    N %= 500;
    iCount += N / 100;
    N %= 100;
    iCount += N / 50;
    N %= 50;
    iCount += N / 10;
    N %= 10;
    iCount += N / 5;
    N %= 5;
    iCount += N / 1;
    N %= 1;
    
    cout << iCount << endl;
    
    return 0;
}