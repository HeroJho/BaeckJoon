#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    // 양쪽에서 제일 큰 것과 작은 것을 곱한다
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    int Sum = 0;
    for(int i = 0 ; i < A.size(); ++i)
    {
        int Temp = A[i] * B[i];
        Sum += Temp;
    }
    
    cout << Sum;
    
    return Sum;
}