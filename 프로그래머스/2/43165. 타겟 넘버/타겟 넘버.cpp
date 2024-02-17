#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> g_Numbers;
int g_Target;
int g_Ans = 0;

void DFS(int Depth, int Start, int Sum)
{
    if (Depth == g_Numbers.size())
    {
        if (Sum == g_Target)
            g_Ans++;

        return;
    }


    for (int i = Start; i < g_Numbers.size(); ++i)
    {
        DFS(Depth + 1, i + 1, Sum + g_Numbers[i]);
        DFS(Depth + 1, i + 1, Sum - g_Numbers[i]);
    }

}


int solution(vector<int> numbers, int target) {
    
    g_Numbers = numbers;
    g_Target = target;

    DFS(0, 0, 0);

    return g_Ans;
}