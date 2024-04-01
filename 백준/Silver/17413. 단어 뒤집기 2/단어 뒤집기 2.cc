#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string Input;
    getline(cin, Input);

    string Stack, Ans;
    bool bSkip = false;
    for (int i = 0; i < Input.length(); ++i)
    {
        if (bSkip)
        {
            if (Input[i] == '>')
                bSkip = false;
         
            Ans += Input[i];

            continue;
        }

        if (Input[i] == ' ')
        {
            for (int s = Stack.length() - 1; s >= 0; --s)
                Ans += Stack[s];

            Ans += ' ';

            Stack = "";
        }
        else if (Input[i] == '<')
        {
            bSkip = true;

            for (int s = Stack.length() - 1; s >= 0; --s)
                Ans += Stack[s];

            Ans += '<';

            Stack = "";
        }
        else
        {
            Stack += Input[i];
        }

    }

    if (Stack != "")
    {
        for (int s = Stack.length() - 1; s >= 0; --s)
            Ans += Stack[s];
    }

    cout << Ans;

    return 0;
}
