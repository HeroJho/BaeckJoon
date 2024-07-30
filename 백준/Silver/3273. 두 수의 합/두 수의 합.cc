#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    int K;
    cin >> K;

    sort(Inputs.begin(), Inputs.end());

    int Ans = 0;
    int L = 0, R = N - 1;
    while (L < R)
    {
        int Sum = Inputs[L] + Inputs[R];

        if (Sum < K)
        {
            ++L;
        }
        else if(Sum > K)
        {
            --R;
        }
        else
        {
            ++Ans;
            ++L;
            --R;
        }

    }

    cout << Ans;


    return 0;
}