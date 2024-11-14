#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int S, P;
    cin >> S >> P;

    string DNA = "";
    cin >> DNA;

    int Arr[26] = { 0 };
    cin >> Arr['A' - 'A'] >> Arr['C' - 'A'] >> Arr['G' - 'A'] >> Arr['T' - 'A'];

    int Start = 0;
    int End = Start + P - 1;

    int Win[26] = { 0 };
    for (int i = Start; i <= End; ++i)
    {
        ++Win[DNA[i] - 'A'];
    }

    int Cnt = 0;
    while (End < S)
    {
        if (Arr['A' - 'A'] <= Win['A' - 'A'] && Arr['C' - 'A'] <= Win['C' - 'A'] &&
            Arr['G' - 'A'] <= Win['G' - 'A'] && Arr['T' - 'A'] <= Win['T' - 'A'])
            ++Cnt;

        --Win[DNA[Start++] - 'A'];
        ++Win[DNA[++End] - 'A'];
    }

    cout << Cnt;


    return 0;
}