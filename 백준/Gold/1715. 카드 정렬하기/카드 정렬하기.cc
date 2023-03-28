#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;


int main()
{
    int N = 0; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pQ;
    for (int i = 0; i < N; ++i)
    {
        int iTemp = 0; cin >> iTemp;
        pQ.push(iTemp);
    }

    if (1 == pQ.size())
    {
        cout << 0;
        return 0;
    }

    int iAns = 0;
    while (1)
    {
        // 제일 작은 애들 2개를 뭉친다
        int iNum1 = pQ.top(); pQ.pop();

        if (pQ.empty())
        {
            break;
        }

        int iNum2 = pQ.top(); pQ.pop();
        iNum1 += iNum2;
        iAns += iNum1;

        // 뭉친걸 넣는다.
        pQ.push(iNum1);

    }

    cout << iAns;

    return 0;
}