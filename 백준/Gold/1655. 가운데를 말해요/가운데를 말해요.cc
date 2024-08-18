#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Func
{
public:
    bool operator()(int L, int R)
    {
        return L > R;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    
    priority_queue<int> MaxQs;
    priority_queue<int, vector<int>, Func> MinQs;

    for (int i = 0; i < N; ++i)
    {
        int Temp;
        cin >> Temp;
        
        if (i == 0)
        {
            MaxQs.push(Temp);
        }
        else if (i == 1)
        {
            if (Temp > MaxQs.top())
                MinQs.push(Temp);
            else
            {
                MinQs.push(MaxQs.top());
                MaxQs.pop();
                MaxQs.push(Temp);
            }
        }
        else
        {
            MaxQs.push(Temp);

            if (MinQs.top() < MaxQs.top())
            {
                MaxQs.pop();
                MinQs.push(Temp);

                if (MinQs.size() > MaxQs.size())
                {
                    MaxQs.push(MinQs.top());
                    MinQs.pop();
                }
            }

            if (MaxQs.size() - MinQs.size() > 1)
            {
                MinQs.push(MaxQs.top());
                MaxQs.pop();
            }

        }
        
        cout << MaxQs.top() << '\n';
    }


    return 0;
}