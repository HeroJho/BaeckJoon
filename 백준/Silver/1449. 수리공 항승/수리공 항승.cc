#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int N, TL; cin >> N; cin >> TL;
    vector<int> Rs;
    for(int i = 0; i < N; ++i)
    {
        int temp; cin >> temp;
        Rs.push_back(temp);
    }
    
    sort(Rs.begin(), Rs.end());
    
    int iCount = 0;
    int iStart = Rs[0];
    for(int i = 1; i < N; ++i)
    {
        if(TL <= Rs[i]-iStart)
        {
            ++iCount;
            iStart = Rs[i];
        }
    }
    
    ++iCount;
    cout << iCount;
    
    return 0;
}