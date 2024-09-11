#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

struct Data
{
    int A, B, C;
};


int N;
int Input[3] = { 0 };
bool Visited[61][61][61] = { false };


void BFS()
{
    queue<Data> Qs;
    Qs.push({ Input[0],Input[1],Input[2] });


    int Cnt = 0;
    while (!Qs.empty())
    {
        int Size = Qs.size();

        for (int s = 0; s < Size; ++s)
        {
            Data Cur = Qs.front();
            Qs.pop();

            if (Cur.A < 0)
                Cur.A = 0;
            if (Cur.B < 0)
                Cur.B = 0;
            if (Cur.C < 0)
                Cur.C = 0;

            if (Cur.A == 0 && Cur.B == 0 && Cur.C == 0)
            {
                cout << Cnt;
                return;
            }

            if (Visited[Cur.A][Cur.B][Cur.C])
                continue;
            Visited[Cur.A][Cur.B][Cur.C] = true;

            Data Nex;
            Nex.A = Cur.A - 9;
            Nex.B = Cur.B - 3;
            Nex.C = Cur.C - 1;
            Qs.push(Nex);

            Nex.A = Cur.A - 9;
            Nex.B = Cur.B - 1;
            Nex.C = Cur.C - 3;
            Qs.push(Nex);

            Nex.A = Cur.A - 3;
            Nex.B = Cur.B - 9;
            Nex.C = Cur.C - 1;
            Qs.push(Nex);

            Nex.A = Cur.A - 3;
            Nex.B = Cur.B - 1;
            Nex.C = Cur.C - 9;
            Qs.push(Nex);

            Nex.A = Cur.A - 1;
            Nex.B = Cur.B - 3;
            Nex.C = Cur.C - 9;
            Qs.push(Nex);

            Nex.A = Cur.A - 1;
            Nex.B = Cur.B - 9;
            Nex.C = Cur.C - 3;
            Qs.push(Nex);



        }

        ++Cnt;

    }

    cout << Cnt;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input[i];
    }

    BFS();

    // 931
    // 913
    // 391
    // 319
    // 193
    // 139

    return 0;
}