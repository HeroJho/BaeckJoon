#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Data
{
    pair<int, int> Pos;
    int Value = 0;

    Data() {};
    Data(pair<int, int> InPos, int InValue)
        : Pos(InPos), Value(InValue)
    {
    }
};

class Func
{
public:
    bool operator()(Data L, Data R)
    {
        return L.Value < R.Value;
    }
};


int N;
int NodeCnt;
vector<int> Seq;
int Love[500][4] = { 0 };
int Matrix[500][500] = { 0 };

int DirX[] = { 0, 0, -1, 1 };
int DirY[] = { -1, 1, 0, 0 };

bool IsIn(int InX, int InY)
{
    return InX >= 1 && InX <= N && InY >= 1 && InY <= N;
}

void FindPlace(int Num)
{

    // 상하좌우에 좋학생 제일 많은 곳을 찾는다
    // 4 * 4 * 400 
    priority_queue<Data, vector<Data>, Func> Qs;
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            int LoveCnt = 0;

            if (Matrix[y][x] != 0)
                continue;

            for (int d = 0; d < 4; ++d)
            {
                int nX = x + DirX[d];
                int nY = y + DirY[d];

                if (!IsIn(nX, nY))
                    continue;

                for (int v = 0; v < 4; ++v)
                {
                    if (Matrix[nY][nX] == Love[Num][v])
                    {
                        ++LoveCnt;
                        break;
                    }
                }

            }

            Qs.push({ {x, y}, LoveCnt });

        }
    }



    // 여러개면 상하좌우가 많은 빈 곳
    // 4 * 400
    int MaxValue = 0;
    vector<Data> Temp1;
    if (!Qs.empty())
    {
         MaxValue = Qs.top().Value;
         Temp1.push_back(Qs.top());
         Qs.pop();
    }

    while (!Qs.empty())
    {
        Data Cur = Qs.top();
        Qs.pop();

        if (MaxValue != Cur.Value)
            break;

        Temp1.push_back(Cur);
    }


    if (Temp1.size() > 1)
    {
        // 빈 칸 찾기
        priority_queue<Data, vector<Data>, Func> Qs1;
        for (int i = 0; i < Temp1.size(); ++i)
        {
            int X = Temp1[i].Pos.first;
            int Y = Temp1[i].Pos.second;

            int EmtCnt = 0;
            for (int d = 0; d < 4; ++d)
            {
                int nX = X + DirX[d];
                int nY = Y + DirY[d];

                if (!IsIn(nX, nY))
                    continue;

                if (Matrix[nY][nX] == 0)
                    ++EmtCnt;

            }

            Qs1.push({ {X, Y}, EmtCnt });
        }


        // 여러개면 행 -> 열 가장 작은 순으로
                // 4 * 400
        {
            int MaxValue = 0;
            vector<Data> Temp1;
            if (!Qs1.empty())
            {
                MaxValue = Qs1.top().Value;
                Temp1.push_back(Qs1.top());
                Qs1.pop();
            }

            while (!Qs1.empty())
            {
                Data Cur = Qs1.top();
                Qs1.pop();

                if (MaxValue != Cur.Value)
                    break;

                Temp1.push_back(Cur);
            }


            if (Temp1.size() > 1)
            {
                // 행->열 가장 작은 순으로
                vector<Data> Temp2;
                int MaxIndex = 0;
                for (int i = 1; i < Temp1.size(); ++i)
                {
                    if (Temp1[MaxIndex].Pos.second < Temp1[i].Pos.second)
                    {
                        MaxIndex = i;
                    }
                    else if(Temp1[MaxIndex].Pos.second == Temp1[i].Pos.second)
                    {
                        if (Temp1[MaxIndex].Pos.first < Temp1[i].Pos.first)
                        {
                            MaxIndex = i;
                        }
                    }
                }

                Matrix[Temp1[MaxIndex].Pos.second][Temp1[MaxIndex].Pos.first] = Num;
            }
            else if (!Temp1.empty())
            {
                pair<int, int> Pos = Temp1.front().Pos;
                Matrix[Pos.second][Pos.first] = Num;
            }


        }
        

    }
    else if(!Temp1.empty())
    {
        pair<int, int> Pos = Temp1.front().Pos;
        Matrix[Pos.second][Pos.first] = Num;
    }



}


void GO()
{
    for (int i = 0; i < NodeCnt; ++i)
    {
        FindPlace(Seq[i]);
    }

    int Ans = 0;
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
        {
            int Num = Matrix[y][x];
            int LoveCnt = 0;

            for (int d = 0; d < 4; ++d)
            {
                int nX = x + DirX[d];
                int nY = y + DirY[d];

                if (!IsIn(nX, nY))
                    continue;

                for (int v = 0; v < 4; ++v)
                {
                    if (Matrix[nY][nX] == Love[Num][v])
                    {
                        ++LoveCnt;
                    }
                }

            }

            if (LoveCnt == 0)
            {
                Ans += 0;
            }
            else if (LoveCnt == 1)
            {
                Ans += 1;
            }
            else if (LoveCnt == 2)
            {
                Ans += 10;
            }
            else if (LoveCnt == 3)
            {
                Ans += 100;
            }
            else if (LoveCnt == 4)
            {
                Ans += 1000;
            }

        }
    }


    cout << Ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 1,1   N,N
    // 인접하다 = 상하좌우

    // 1. 상하좌우에 좋학생 제일 많은 곳을 찾는다
    //     여러개면 상하좌우가 많은 빈 곳
    //          여러개면 행 -> 열 가장 작은 순으로

    cin >> N;
    NodeCnt = N * N;
    for (int i = 1; i <= NodeCnt; ++i)
    {
        int Temp;
        cin >> Temp;
        Seq.push_back(Temp);
        for (int j = 0; j < 4; ++j)
        {
            cin >> Love[Temp][j];
        }
    }

    GO();

    return 0;
}