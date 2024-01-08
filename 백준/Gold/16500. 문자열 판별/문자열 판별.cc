#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string g_S;
int g_N;
unordered_map<char, vector<string>> g_Inputs;
vector<bool> g_DP;

bool DFS(int start)
{
    if (start == g_S.length())
        return true;

    if (g_DP[start])
        return false;

    g_DP[start] = true;

    auto iter = g_Inputs.find(g_S[start]);
    if (iter != g_Inputs.end())
    {
        for (const string& word : iter->second)
        {
            if (g_S.compare(start, word.length(), word) == 0 && DFS(start + word.length()))
                return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g_S;
    cin >> g_N;

    for (int i = 0; i < g_N; ++i)
    {
        string sTemp;
        cin >> sTemp;
        g_Inputs[sTemp[0]].push_back(sTemp);
    }

    g_DP.resize(g_S.length(), false);

    int g_Ans = DFS(0);

    cout << g_Ans;

    return 0;
}
