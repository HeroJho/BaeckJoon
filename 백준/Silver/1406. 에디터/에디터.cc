#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <list>
#include <cmath>

using namespace std;





int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string sTemp;
    cin >> sTemp;

    list<char> Inputs;
    for (int i = 0; i < sTemp.length(); ++i)
    {
        Inputs.push_back(sTemp[i]);
    }

    int N;
    cin >> N;
    
    vector<string> Orders;
    for (int i = 0; i < N; ++i)
    {
        string sTemp;
        char Temp;
        cin >> Temp;
        sTemp += Temp;
        
        if (Temp == 'P')
        {
            cin >> Temp;
            sTemp += Temp;
        }
        
        Orders.push_back(sTemp);

    }
    
    // Px, L, Py
    list<char>::iterator Iter = Inputs.end();
    // P/    P
    for (int i = 0; i < N; ++i)
    {

        string CurOrder = Orders[i];

        if (CurOrder[0] == 'L')
        {
            if (Iter == Inputs.begin())
                continue;
            
            --Iter;
        }
        else if (CurOrder[0] == 'D')
        {
            if (Iter == Inputs.end())
                continue;

            ++Iter;
        }
        else if (CurOrder[0] == 'B')
        {
            if (Iter == Inputs.begin())
                continue;

            --Iter;

            // 삭제한 다음거를 가리켜야함
            Iter = Inputs.erase(Iter);

        }
        else if (CurOrder[0] == 'P')
        {
            // --Iter에 추가해야한다
            //if (Iter != Inputs.begin())
            //    --Iter;

            // Iter의 앞에 추가하고,
            // 추가한 뒤를 가리켜야함
            Iter = Inputs.insert(Iter, CurOrder[1]);
            ++Iter;

            // Iter 앞에 추가된다
        }


    }

    if (Inputs.empty())
        return 0;

    for (auto Char : Inputs)
    {
        cout << Char;
    }


    return 0;
}