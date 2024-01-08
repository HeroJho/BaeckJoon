#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string g_S;
int g_N;
unordered_set<string> g_Words;
vector<bool> g_DP;

bool DFS(int start)
{
    if (start == g_S.length())
        return true;

    if (g_DP[start])
        return false;

    g_DP[start] = true;

    for (int i = 1; start + i <= g_S.length(); ++i)
    {
        string current = g_S.substr(start, i);
        if (g_Words.find(current) != g_Words.end() && DFS(start + i))
            return true;
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
        g_Words.insert(sTemp);
    }

    g_DP.resize(g_S.length(), false);

    int g_Ans = DFS(0);

    cout << g_Ans;

    return 0;
}