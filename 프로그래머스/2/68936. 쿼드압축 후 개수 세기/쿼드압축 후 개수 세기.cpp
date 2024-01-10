#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g_Arr;
int g_Ans[2] = { 0 };

int Check(pair<int, int> LT, int iSize)
{
    int Cur = g_Arr[LT.second][LT.first];
    int bB = g_Arr[LT.second][LT.first];
    for (int y = LT.second; y < LT.second + iSize; ++y)
    {
        for (int x = LT.first; x < LT.first + iSize; ++x)
        {
            if (Cur != g_Arr[y][x])
            {
                return -1;
            }

        }
    }

    return bB;
}

void Re(pair<int ,int> MPos, int Size)
{
    if (Size == 0)
        return;

    int HSize = Size / 2;

    // 1 1
    int iCheck = Check({ MPos.first - Size, MPos.second - Size }, Size);
    if(iCheck == -1)
        Re({ MPos.first - HSize , MPos.second - HSize }, HSize);
    else
        ++g_Ans[iCheck];

    // 2 1
    iCheck = Check({ MPos.first, MPos.second - Size }, Size);
    if (iCheck == -1)
        Re({ MPos.first + HSize , MPos.second - HSize }, HSize);
    else
        ++g_Ans[iCheck];

    iCheck = Check({ MPos.first - Size, MPos.second }, Size);
    if (iCheck == -1)
        Re({ MPos.first - HSize , MPos.second + HSize }, HSize);
    else
        ++g_Ans[iCheck];

    iCheck = Check({ MPos.first, MPos.second }, Size);
    if (iCheck == -1)
        Re({ MPos.first + HSize , MPos.second + HSize }, HSize);
    else
        ++g_Ans[iCheck];
    

}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    g_Arr = arr;

    int iSize = g_Arr.size();

    int iCheck = Check({ 0, 0 }, iSize);
    if (iCheck == -1)
        Re({ iSize / 2, iSize / 2 }, iSize / 2);
    else
        ++g_Ans[iCheck];
    
    answer.push_back(g_Ans[0]);
    answer.push_back(g_Ans[1]);

    cout << answer[0] << " " << answer[1];

    return answer;
}
