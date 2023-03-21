#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, K;

int main(int)
{
    cin >> N; cin >> K;
    vector<int> iValues;
    for (int i = 0; i < N; ++i)
    {
        int iTemp = 0; cin >> iTemp;
        iValues.push_back(iTemp);
    }

    // K보다 큰 원소 삭제
    auto iter_end = remove_if(iValues.begin(), iValues.end(),
        [](int iValue) {return K < iValue; });
    iValues.erase(iter_end, iValues.end());
    reverse(iValues.begin(), iValues.end());
    
    int iCount = 0;
    for (auto &iValue : iValues)
    {
        while(0 <= K - iValue)
        {
            ++iCount;
            K -= iValue;
        }
    }

    cout << iCount << endl;
    
    return 0;
}