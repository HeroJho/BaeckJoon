#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N = 0; cin >> N;
    vector<int> Rs;
    for(int i = 0; i < N-1; ++i)
    {
        int iTemp = 0; cin >> iTemp;
        Rs.push_back(iTemp);
    }
    vector<int> Ls;
    for(int i = 0; i < N; ++i)
    {
        int iTemp = 0; cin >> iTemp;
        Ls.push_back(iTemp);
    }
    
    // 나보다 값이 작을 때까지 주유
    int iTotalSum = 0;
    int iCurCityCount = 0;
    for(int i = iCurCityCount; i < N - 1; i = iCurCityCount)
    {
        for(int j = i + 1; ; ++j)
        {   
            // 도착하면
            if(j < N - 1)
                iCurCityCount = N - 1;
            
            // 나보다 값이 작다.
            if(Ls[i] > Ls[j])
            {
                iTotalSum += Ls[i] * Rs[i];
                iCurCityCount = j;
                break;    
            }
            // 미리 주유한다
            iTotalSum += Ls[i] * Rs[j];
        }
    }
    
    cout << iTotalSum;
    
    return 0;
}