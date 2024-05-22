#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Func
{
public:
    bool operator()(string L, string R)
    {
        return L.length() < R.length();
    }
};

void Go()
{
    int N;
    cin >> N;
    vector<string> Inputs;
    for (int i = 0; i < N; ++i)
    {
        string Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    sort(Inputs.begin(), Inputs.end(), Func());

    unordered_map<string, bool> Maps;
    for (int i = 0; i < N; ++i)
    {
        string Temp;
        for (int z = 0; z < Inputs[i].length(); ++z)
        {
            Temp += Inputs[i][z];

            // Temp 찾는다
            auto iter = Maps.find(Temp);
            if (iter != Maps.end())
            {
                cout << "NO" << '\n';
                return;
            }
        }

        Maps.emplace(Temp, false);
    }

    // 911
    // 9119

    // 9119
    // 911

    // 크기 오름 정렬하고

    cout << "YES" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        Go();
    }


    return 0;
}