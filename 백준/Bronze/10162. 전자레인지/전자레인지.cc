#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int T = 0; cin >> T;
    // 5 1 10
    int A = 5 * 60;
    int B = 60;
    int C = 10;
    
    int iA_Count = T / A;
    T %= A;
    int iB_Count = T / B;
    T %= B;
    int iC_Count = T / C;
    T %= C;
    
    if(0 == T)
        cout << iA_Count << " " << iB_Count << " " << iC_Count;
    else
        cout << -1 << endl;
    
    return 0;
}