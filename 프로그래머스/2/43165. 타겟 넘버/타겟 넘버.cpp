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



    DFS(Depth + 1, Start + 1, Sum + g_Numbers[Start]);
    DFS(Depth + 1, Start + 1, Sum - g_Numbers[Start]);


}


int solution(vector<int> numbers, int target) {
    
    g_Numbers = numbers;
    g_Target = target;

    DFS(0, 0, 0);

    return g_Ans;
}


