#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string Inputs;
    cin >> Inputs;

    int Ans = 0;

    char Pre = '0';
    string Stack;
    for (int i = 0; i < Inputs.length(); ++i)
    {
        char Cur = Inputs[i];

        // 레이저일 때
        if (Pre == '(' && Cur == ')')
        {
            Stack.pop_back();
            Ans += Stack.length();
        }
        else // 아닐 때
        {
            // 닫히냐
            if (Cur == ')')
            {
                Stack.pop_back();
                Ans += 1;
            }
            else if(Cur == '(') // 열리냐 
            {
                Stack.push_back(Cur);
            }

        }
        
        Pre = Cur;
        
    }

    cout << Ans;

    return 0;
}
