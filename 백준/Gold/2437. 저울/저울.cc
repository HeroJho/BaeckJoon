#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> Ns;
    for (int i = 0; i < N; ++i)
    {
        int temp; cin >> temp;
        Ns.push_back(temp);
    }

    sort(Ns.begin(), Ns.end());

    int iSum = 0;
    // 1 2 3 4
    for (int i = 0; i < N; ++i)
    {
        if (iSum + 1 < Ns[i])
            break;
        iSum += Ns[i];
    }

    cout << iSum + 1;

    return 0;
}