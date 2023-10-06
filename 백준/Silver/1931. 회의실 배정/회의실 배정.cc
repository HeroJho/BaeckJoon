#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Time
{
    int iStart;
    int iEnd;
};

int main()
{
    int N = 0; cin >> N;

    vector<Time> Times;
    for (int i = 0; i < N; ++i)
    {
        int iStart, iEnd; cin >> iStart; cin >> iEnd;
        Time Temp = { iStart, iEnd };
        Times.push_back(Temp);
    }

    // 시작 시간으로 정렬한다
    sort(Times.begin(), Times.end(), [](Time ValueA, Time ValueB)
        {
            return ValueA.iStart < ValueB.iStart;
        });

    // 앞 시간부터 하나씩 받는다.
    vector<Time> TempTimes;
    TempTimes.push_back(Times.front());
    for (int i = 1; i < N; ++i)
    {
        // 가장 최근 예약된 회의
        Time TempTime = TempTimes.back();

        if (Times[i].iStart == Times[i].iEnd && Times[i].iStart == TempTime.iStart)
        {
            TempTimes.push_back(Times[i]);
        }
        // 최근꺼랑 시간이 완전 겹치고 더 작다 -> 변경
        else if (TempTime.iEnd > Times[i].iEnd)
        {
            TempTimes.pop_back();
            TempTimes.push_back(Times[i]);
        }
        // 최근꺼랑 시작 시간이 겹치고 끝나는 시간이 더 커서 안 겹치면 어차피 버려야한다 

        // 둘 다 안 겹쳤을 때 추가로 넣는다
        else if (TempTime.iEnd <= Times[i].iStart)
        {
            TempTimes.push_back(Times[i]);
        }
    }

    cout << TempTimes.size() << endl;

    return 0;
}