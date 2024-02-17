#include <iostream>
#include <vector>
#include <queue>

using namespace std;



vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; ++i)
    {
        if (yellow % i != 0)
            continue;

        int x = yellow / i;
        int y = i;

        // 세로 길이가 더 길다 = 더 나눌 필요없다.
        if (x < y)
            break;

        // 테두리 감쌀만큼 brown이 있냐
        int Count = (x + 2) * (y + 2);
        int Temp = Count - (x * y);
        if (brown < Temp)
            continue;

        answer.push_back(x + 2);
        answer.push_back(y + 2);
        break;
    }


    return answer;
}
