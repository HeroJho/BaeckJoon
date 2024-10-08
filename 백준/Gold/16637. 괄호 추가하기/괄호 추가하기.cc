#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> Nums;
vector<char> Ss;

bool Visited[30] = { false };
int Ans = INT_MIN;

int Cal(int A, int B, char X)
{
    int Ans = 0;

    if (X == '+')
        Ans = A + B;
    else if (X == '*')
        Ans = A * B;
    else if (X == '-')
        Ans = A - B;

    return Ans;
}


void Go()
{
    vector<int> TempNum;
    vector<char> TempS;
    for (int i = 1; i <= N/2+1; ++i)
    {
        if (Visited[i])
        {
            int Result = Cal(Nums[i], Nums[i + 1], Ss[i]);
            TempNum.push_back(Result);
            ++i;
            if (Ss.size() > i)
                TempS.push_back(Ss[i]);
            continue;
        }

        TempNum.push_back(Nums[i]);
        if(Ss.size() > i)
            TempS.push_back(Ss[i]);
    }

    int PreNum = TempNum[0];
    for (int i = 1; i <= TempS.size(); ++i)
    {
        PreNum = Cal(PreNum, TempNum[i], TempS[i-1]);
    }

    if (Ans < PreNum)
        Ans = PreNum;

}


void DFS()
{

    Go();


    for (int i = 1; i <= N/2; ++i)
    {
        if (Visited[i] || Visited[i-1])
            continue;
        
        Visited[i] = true;
        DFS();
        Visited[i] = false;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    string Inputs;
    cin >> Inputs;

    Nums.push_back(-1);
    Ss.push_back(-1);

    for (int i = 0; i < Inputs.length(); ++i)
    {
        if (Inputs[i] != '+' && Inputs[i] != '-' &&
            Inputs[i] != '*')
        {
            Nums.push_back(Inputs[i] - '0');
        }
        else
        {
            Ss.push_back(Inputs[i]);
        }
    }

    DFS();

    cout << Ans;

    return 0;
}