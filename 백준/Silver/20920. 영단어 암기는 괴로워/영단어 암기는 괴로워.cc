#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Func
{
public:
    bool operator()(pair<string, int> L, pair<string, int> R)
    {
        return L.second > R.second;
    }
};

class Func1
{
public:
    bool operator()(pair<string, int> L, pair<string, int> R)
    {
        if (L.second != R.second)
            return false;

        return L.first.length() > R.first.length();
    }
};

class Func2
{
public:
    bool operator()(pair<string, int> L, pair<string, int> R)
    {
        if (L.second != R.second)
            return false;
        if (L.first.length() != R.first.length())
            return false;

        return L.first < R.first;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> Inputs;
    
    for (int i = 0; i < N; ++i)
    {
        string Temp;
        cin >> Temp;

        if (Temp.length() < M)
            continue;

        ++Inputs[Temp];
    }


    vector<pair<string, int>> AA;
    
    for (auto Pair : Inputs)
    {
        AA.push_back({ Pair.first, Pair.second });
    }

    sort(AA.begin(), AA.end(), Func());

    stable_sort(AA.begin(), AA.end(), Func1());
    stable_sort(AA.begin(), AA.end(), Func2());


    for (auto Pair : AA)
    {
        cout << Pair.first << '\n';
    }


    return 0;
}