#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> Inputs;
    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        Inputs.push_back(Temp);
    }

    int Num = 1;
    stack<int> S;
    for (int i = 0; i < N; ++i)
    {
        if (Num == Inputs[i])
        {
            ++Num;
        }
        else
        {
            while (!S.empty())
            {
                if (Num == S.top())
                {
                    ++Num;
                    S.pop();
                }
                else
                {
                    break;
                }
            }

            S.push(Inputs[i]);
        }
    }



    while (!S.empty())
    {
        if (Num == S.top())
        {
            ++Num;
            S.pop();
        }
        else
        {
            break;
        }
    }



    if (Num == N + 1)
        cout << "Nice";
    else
        cout << "Sad";


    // 하나일 경우
    // 정렬된 상태일 경우
    
    // 


    return 0;
}