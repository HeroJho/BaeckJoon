#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int g_Col = 0;

class Func
{
public:
    bool operator()(vector<int> L, vector<int> R)
    {
        return L[g_Col] < R[g_Col];
    }

};
class Func1
{
public:
    bool operator()(vector<int> L, vector<int> R)
    {
        return L[g_Col] == R[g_Col] && L[0] > R[0];
    }

};

int DoXOR(int L, int R)
{
    // 1010 = 10
    
    // 2진수 변환
    vector<bool> BL, BR;
    int iNum = L;
    while (iNum != 0)
    {
        if (iNum == 1)
        {
            BL.push_back(1);
            break;
        }
        BL.push_back(iNum % 2);
        iNum /= 2;
    }
    iNum = R;
    while (iNum != 0)
    {
        if (iNum == 1)
        {
            BR.push_back(1);
            break;
        }
        BR.push_back(iNum % 2);
        iNum /= 2;
    }

    // 0101
    // 1010
    // 11001

    //reverse(BL.begin(), BL.end());
    //reverse(BR.begin(), BR.end());

    int MaxSize = max(BL.size(), BR.size());

    vector<bool> Ans;
    for (int i = 0; i < MaxSize; ++i)
    {
        if (BL.size() > i && BR.size() > i)
        {
            if (BL[i] != BR[i])
            {
                Ans.push_back(1);
            }
            else
            {
                Ans.push_back(0);
            }
        }
        else if (BL.size() <= i)
        {
            if (BR[i] == 1)
            {
                Ans.push_back(1);
            }
            else
            {
                Ans.push_back(0);
            }
        }
        else if (BR.size() <= i)
        {
            if (BL[i] == 1)
            {
                Ans.push_back(1);
            }
            else
            {
                Ans.push_back(0);
            }
        }
     
    }

    long long iAnsNum = 0;
    long long iSumNum = 1;
    for (int i = 0; i < Ans.size(); ++i)
    {
        if (Ans[i] == 1)
        {
            iAnsNum += iSumNum;
        }
        iSumNum *= 2;
    }
    // 1010
    return iAnsNum;

}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    g_Col = col - 1;

    // Col 번째로 오름차순 정렬
        // 같다면 첫 번째 컬럼으로 내림차순 정렬

    sort(data.begin(), data.end(), Func());
    stable_sort(data.begin(), data.end(), Func1());

    vector<int> Sums;
    for (int i = row_begin; i <= row_end; ++i)
    {
        int iIndex = i - 1;
        int iSum = 0;
        for (int k = 0; k < data[iIndex].size(); ++k) 
        {
            iSum += data[iIndex][k] % i;
        }
        Sums.push_back(iSum);
    }

    // XOR = 서로 다를 때 1
    int iXO = DoXOR(Sums[0], Sums[1]);
    for (int i = 2; i < Sums.size(); ++i)
    {
        iXO = DoXOR(iXO, Sums[i]);
    }

    answer = iXO;

    return answer;
}
