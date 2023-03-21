#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int g_iNum = 0;        // 사람 수
vector<int> g_iTimes;  // 시간

int main(int)
{
    cin >> g_iNum;
    for(int i = 0; i < g_iNum; ++i)
    {
        int iTemp = 0;
        cin >> iTemp;
        g_iTimes.push_back(iTemp);
    }

    // 오름차순 정렬
    sort(g_iTimes.begin(), g_iTimes.end());
    
    int iSum = 0;
    int iTotalTime = 0;
    // 12334
    for(auto iTime : g_iTimes)
    {
        iSum += iTime;
        iTotalTime += iSum;
    }


    cout << iTotalTime << endl;
    
    return 0;
}