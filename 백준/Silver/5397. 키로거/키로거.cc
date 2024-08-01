#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;


    while (T--)
    {
        string Input;
        cin >> Input;

        list<char> Ans;
        list<char>::iterator Cur = Ans.begin();
        for (int i = 0; i < Input.size(); ++i)
        {
            if (Input[i] == '<')
            {
                // 없다면, 맨 앞이라면
                if (Ans.empty() || Cur == Ans.begin())
                    continue;

                --Cur;

            }
            else if (Input[i] == '>')
            {
                // 없다면, 맨 뒤 라면
                if (Ans.empty() || Cur == Ans.end())
                    continue;

                ++Cur;

            }
            else if (Input[i] == '-')
            {
                if (Ans.empty())
                    continue;

                if (Cur == Ans.begin())
                    continue;

                if (Cur == Ans.end())
                {
                    Ans.pop_back();
                    Cur = Ans.end();
                    continue;
                }

                // 앞을 지운다
                // 뒤를 가리키는 뜻
                --Cur;
                Cur = Ans.erase(Cur);
            }
            else
            {
                // 앞에 추가하고 원래걸 가리킨다
                // 앞에 추가하고 
                Cur = Ans.insert(Cur, Input[i]);
                ++Cur;
            }

        }

        for (list<char>::iterator iter = Ans.begin(); iter != Ans.end(); ++iter)
        {
            if (*iter == '*')
                continue;
            cout << *iter;
        }
        cout << '\n';
    }

 



    return 0;
}