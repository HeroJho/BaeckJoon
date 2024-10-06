#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int MaxABC[3] = {0};
int ABC[3] = { 0 };
bool Visited[201][201][201] = { false };

vector<int> Ans;

void DFS()
{
    if (Visited[ABC[0]][ABC[1]][ABC[2]])
        return;
    Visited[ABC[0]][ABC[1]][ABC[2]] = true;
    
    if (ABC[0] == 0)
    {
        Ans.push_back(ABC[2]);
    }


    int TempABC[3];
    TempABC[0] = ABC[0];
    TempABC[1] = ABC[1];
    TempABC[2] = ABC[2];

    for (int i = 0; i < 3; ++i)
    {
        if (ABC[i] <= 0)
            continue;

        // A만 붇는다
        // B만 붇는다
        // A, B만 붇는다
        // B, A 붇는다
        int One = (i + 1) % 3;
        int Two = (i + 2) % 3;

        // 일단 B에 따른다
        // MaxB를 넘으면 나머지만큼 A를 채운다
        // 안 넘으면 A를 0

        if (ABC[One] < MaxABC[One])
        {
            ABC[One] += ABC[i];
            if (ABC[One] > MaxABC[One])
            {
                int Dis = ABC[One] - MaxABC[One];
                ABC[One] = MaxABC[One];
                ABC[i] = Dis;
            }
            else
            {
                ABC[i] = 0;
            }

            DFS();
        }



        // B만 붙는다
        ABC[0] = TempABC[0];
        ABC[1] = TempABC[1];
        ABC[2] = TempABC[2];

        if (ABC[Two] < MaxABC[Two])
        {
            ABC[Two] += ABC[i];
            if (ABC[Two] > MaxABC[Two])
            {
                int Dis =  ABC[Two] - MaxABC[Two];
                ABC[Two] = MaxABC[Two];
                ABC[i] = Dis;
            }
            else
            {
                ABC[i] = 0;
            }

            DFS();
        }



        // AB 붙는다
        ABC[0] = TempABC[0];
        ABC[1] = TempABC[1];
        ABC[2] = TempABC[2];

        if (ABC[One] < MaxABC[One] && ABC[Two] < MaxABC[Two])
        {
            ABC[One] += ABC[i];
            if (ABC[One] > MaxABC[One])
            {
                int Dis = ABC[One] - MaxABC[One];
                ABC[One] = MaxABC[One];
                ABC[i] = Dis;
            }
            else
            {
                ABC[i] = 0;
            }

            if (ABC[i] != 0)
            {
                ABC[Two] += ABC[i];
                if (ABC[Two] > MaxABC[Two])
                {
                    int Dis = ABC[Two] - MaxABC[Two];
                    ABC[Two] = MaxABC[Two];
                    ABC[i] = Dis;
                }
                else
                {
                    ABC[i] = 0;
                }


                DFS();
            }

        }




        // AB 붙는다
        ABC[0] = TempABC[0];
        ABC[1] = TempABC[1];
        ABC[2] = TempABC[2];

        if (ABC[One] < MaxABC[One] && ABC[Two] < MaxABC[Two])
        {
            ABC[Two] += ABC[i];
            if (ABC[Two] > MaxABC[Two])
            {
                int Dis = ABC[Two] - MaxABC[Two];
                ABC[Two] = MaxABC[Two];
                ABC[i] = Dis;
            }
            else
            {
                ABC[i] = 0;
            }

            if (ABC[i] != 0)
            {
                ABC[One] += ABC[i];
                if (ABC[One] > MaxABC[One])
                {
                    int Dis = ABC[One] - MaxABC[One];
                    ABC[One] = MaxABC[One];
                    ABC[i] = Dis;
                }
                else
                {
                    ABC[i] = 0;
                }


                DFS();
            }

        }



    }
    



}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> MaxABC[0] >> MaxABC[1] >> MaxABC[2];
    
    ABC[2] = MaxABC[2];

    DFS();

    sort(Ans.begin(), Ans.end());

    for (int i = 0; i < Ans.size(); ++i)
    {
        cout << Ans[i] << ' ';
    }

    return 0;
}