#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> As;
    for(int i = 0; i < N; ++i)
    {
        int iTemp = 0;
        cin >> iTemp;
        As.push_back(iTemp);
    }
    
    // L = W/N    L * N = W;
    //  10 = 20/2
    
    // 제일 쌘 줄 부터 달아서 최소 무게를 정한다.
    // 그다음 내림차순으로 줄을 달아보면서 최대 무게를 갱신한다.
    sort(As.rbegin(), As.rend());
    
    int iMaxW = As.front();
    for(int i = 1; i < N; ++i)
    {
        int iN = i + 1;
        int iL = As[i];
        
        if(iMaxW < iL * iN)
            iMaxW = iL * iN;
    }
    
    cout << iMaxW << endl;
    
    return 0;
}