#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // n = 1000, n^2 = 1,000,000
    // m = 1000, m^2 = 1,000,000
    // 2^1,000,000
    // 1,000,000^2 = 1,000,000,000,000

    int T;
    cin >> T;
    
    int N, M;
    cin >> N;

    vector<int> As, Bs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        As.push_back(Temp);
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int Temp;
        cin >> Temp;
        Bs.push_back(Temp);
    }



    vector<int> ASums;
    for (int i = 0; i < As.size(); ++i)
    {
        int Sum = 0;
        for (int z = i; z < As.size(); ++z)
        {
            Sum += As[z];
            ASums.push_back(Sum);
        }
    }

    unordered_map<int, int> BMap;
    for (int i = 0; i < Bs.size(); ++i)
    {
        int Sum = 0;
        for (int z = i; z < Bs.size(); ++z)
        {
            Sum += Bs[z];
            BMap[Sum]++;
        }
    }



    long long Ans = 0;
    for (int i = 0; i < ASums.size(); ++i)
    {
        int Dis = T - ASums[i];
        Ans += BMap[Dis];
    }

    cout << Ans;


    return 0;
}