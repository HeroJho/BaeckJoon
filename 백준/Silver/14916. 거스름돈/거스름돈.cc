#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n; cin >> n;
    int iCount5 = 0;
    
    // 3
    iCount5 = n/5;
    n %= 5;
    while(1)
    {
        if(n%2 == 0)
        {
            iCount5 += n/2;
            cout << iCount5;
            return 0;
        }
        
        --iCount5;
        n += 5;
        if(iCount5 < 0)
            break;
    }
    
    cout << -1;
    
    return 0;
}