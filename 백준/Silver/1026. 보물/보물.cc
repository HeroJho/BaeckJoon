#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> A;
    for(int i = 0; i < N; ++i)
    {
        int iTemp = 0;
        cin >> iTemp;
        A.push_back(iTemp);
    }
    vector<int> B;
    for(int i = 0; i < N; ++i)
    {
        int iTemp = 0;
        cin >> iTemp;
        B.push_back(iTemp);
    }
    
    sort(A.begin(), A.end()); // 오름차순
    sort(B.rbegin(), B.rend()); // 내림차순
    
    int iSum = 0;
    for(int i = 0; i < N; ++i)
    {
        iSum += A[i] * B[i];
    }
    
    cout << iSum << endl;
    
    return 0;
}