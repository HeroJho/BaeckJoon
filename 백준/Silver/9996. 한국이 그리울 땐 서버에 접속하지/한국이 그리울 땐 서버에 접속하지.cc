#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    string Pattern = "";
    cin >> N >> Pattern;


    // *기점으로 Start와 End로 나눈다
    string Start = "";
    string End = "";
    bool Find = false;
    size_t PatternSize = Pattern.size();
    for (size_t i = 0; i < PatternSize; i++)
    {
        if (false == Find)
        {
            if (Pattern[i] == '*')
            {
                Find = true;
                continue;
            }

            Start += Pattern[i];
        }
        else
        {
            End += Pattern[i];
        }
    }



    int StartSize = Start.size();
    int EndSize = End.size();

    reverse(End.begin(), End.end());

    string Input = "";
    for (int i = 0; i < N; i++)
    {
        cin >> Input;
        Find = false;

        int InputSize = Input.size();
        if (InputSize < StartSize + EndSize)
        {
            cout << "NE" << '\n';
            continue;
        }



        for (int j = 0; j < StartSize; j++)
        {
            if (Input[j] != Start[j])
            {
                Find = true;
                continue;
            }
        }

        if (true == Find)
        {
            cout << "NE" << '\n';
            continue;
        }



        for (int j = 0; j < EndSize; ++j)
        {
            if (Input[Input.size() - 1 - j] != End[j])
            {
                Find = true;
                continue;
            }
        }

        if (true == Find)
        {
            cout << "NE" << '\n';
            continue;
        }



        cout << "DA" << '\n';
    }

    return 0;
}