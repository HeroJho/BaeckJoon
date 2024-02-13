#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define MAX 99999

using namespace std;

int g_N, g_T, g_G;
bool g_Visited[100000] = { false };


bool DoB(int& Num)
{
    if (Num == 0)
        return false;

    Num *= 2;
    if (Num > MAX)
        return false;

    // *
    string sNum = to_string(Num);
    --sNum[0];

    Num = stoi(sNum);

    return true;
}

int BFS()
{
    queue<int> Qs;
    Qs.push(g_N);
    g_Visited[g_N] = true;

    int Count = 0;

    if (g_N == g_G)
        return 0;

    while (!Qs.empty())
    {
        int Size = Qs.size();
        ++Count;

        if (Count > g_T)
            return -1;

        for (int t = 0; t < Size; ++t)
        {

            int Cur = Qs.front();
            Qs.pop();

            int Temp = Cur;
            if (DoB(Temp) && !g_Visited[Temp])
            {
                if (Temp == g_G)
                {
                    return Count;
                }

                g_Visited[Temp] = true;
                Qs.push(Temp);
            }
            if (Cur + 1 <= MAX && !g_Visited[Cur + 1])
            {
                if (Cur + 1 == g_G)
                {
                    return Count;
                }

                g_Visited[Cur + 1] = true;
                Qs.push(Cur + 1);
            }


        }

    }

    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g_N >> g_T >> g_G;


    int Ans = BFS();
    if (Ans == -1)
        cout << "ANG";
    else
        cout << Ans;

    return 0;
}
