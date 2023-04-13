#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> v;
int n, k, cnt;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> n >> k;
    
    for(int i = 1; i < (int)sqrt(n) + 1; i++)
        if(n % i == 0)
        {
            v.push_back(i);
            cnt++;
        }

    if(v[v.size()-1] * v[v.size()-1] == n)
        if(cnt * 2 - 1 >= k)
            for(int i = v.size()-1; i > 0; i--)
                v.push_back(n / v[i-1]);
        else
        {
            cout << 0;
            return 0;
        }
    else
        if(cnt * 2 >= k)
            for(int i = v.size(); i > 0; i--)
                v.push_back(n / v[i-1]);
        else
        {
            cout << 0;
            return 0;
        }
        
    cout << v[k -1];
    
    return 0;
}