#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <unordered_map>
#include <algorithm>

using namespace std;


int AnsX, AnsY, Ans;
vector<vector<int>> RMatrix;
vector<vector<int>> CMatrix;

class Func
{
public:
    bool operator()(pair<int, int> L, pair<int, int> R)
    {
        if (L.second == R.second)
            return L.first < R.first;

        return L.second < R.second;
    }
};

void RtoC()
{
    CMatrix.clear();
    CMatrix.resize(RMatrix[0].size());

    for (int y = 0; y < RMatrix.size(); ++y)
    {
        for (int x = 0; x < RMatrix[y].size(); ++x)
        {
            CMatrix[x].push_back(RMatrix[y][x]);
        }
    }
}

void CtoR()
{
    RMatrix.clear();
    RMatrix.resize(CMatrix[0].size());

    for (int y = 0; y < CMatrix.size(); ++y)
    {
        for (int x = 0; x < CMatrix[y].size(); ++x)
        {
            RMatrix[x].push_back(CMatrix[y][x]);
        }
    }
}


void CalR()
{
    // 갯수 카운팅 (0은 제외)
    unordered_map<int, int> Map;
    vector<pair<int, int>> So;
    for (int y = 0; y < RMatrix.size(); ++y)
    {
        // 가로 연산
        Map.clear();
        for (int x = 0; x < RMatrix[y].size(); ++x)
        {
            if (RMatrix[y][x] == 0)
                continue;

            Map[RMatrix[y][x]]++;
        }

        So.clear();
        for (auto Pair : Map)
        {
            So.push_back(Pair);
        }


        // 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬
        sort(So.begin(), So.end(), Func());

        
        RMatrix[y].clear();
        for (int i = 0; i < So.size(); ++i)
        {
            // 행 열 100 넘어가면 제외
            if (i >= 100)
                break;

            // Matrix 갱신 
            RMatrix[y].push_back(So[i].first);
            RMatrix[y].push_back(So[i].second);
        }

    }


    // 0 넣기
    int MaxX = 0;
    for (int i = 0; i < RMatrix.size(); ++i)
    {
        if (MaxX < RMatrix[i].size())
            MaxX = RMatrix[i].size();
    }

    for (int i = 0; i < RMatrix.size(); ++i)
    {
        int DisSize = MaxX - RMatrix[i].size();
        for (int d = 0; d < DisSize; ++d)
            RMatrix[i].push_back(0);
    }
    
}


void CalC()
{
    // 갯수 카운팅 (0은 제외)
    unordered_map<int, int> Map;
    vector<pair<int, int>> So;
    for (int y = 0; y < CMatrix.size(); ++y)
    {
        // 가로 연산
        Map.clear();
        for (int x = 0; x < CMatrix[y].size(); ++x)
        {
            if (CMatrix[y][x] == 0)
                continue;

            Map[CMatrix[y][x]]++;
        }

        So.clear();
        for (auto Pair : Map)
        {
            So.push_back(Pair);
        }


        // 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬
        sort(So.begin(), So.end(), Func());


        CMatrix[y].clear();
        for (int i = 0; i < So.size(); ++i)
        {
            // 행 열 100 넘어가면 제외
            if (i >= 100)
                break;

            // Matrix 갱신 
            CMatrix[y].push_back(So[i].first);
            CMatrix[y].push_back(So[i].second);
        }

    }


    // 0 넣기
    int MaxX = 0;
    for (int i = 0; i < CMatrix.size(); ++i)
    {
        if (MaxX < CMatrix[i].size())
            MaxX = CMatrix[i].size();
    }

    for (int i = 0; i < CMatrix.size(); ++i)
    {
        int DisSize = MaxX - CMatrix[i].size();
        for (int d = 0; d < DisSize; ++d)
            CMatrix[i].push_back(0);
    }
}



void Debug()
{
    cout << endl;
    cout << endl;

    cout << "## RMatrix" << endl;
    for (int y = 0; y < RMatrix.size(); ++y)
    {
        for (int x = 0; x < RMatrix[y].size(); ++x)
        {
            cout << RMatrix[y][x] << ' ';
        }
        cout << endl;
    }

    cout << endl;

    cout << "## CMatrix" << endl;
    for (int y = 0; y < CMatrix.size(); ++y)
    {
        for (int x = 0; x < CMatrix[y].size(); ++x)
        {
            cout << CMatrix[y][x] << ' ';
        }
        cout << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> AnsY >> AnsX >> Ans;

    AnsX -= 1;
    AnsY -= 1;

    RMatrix.resize(3);
    for (int y = 0; y < 3; ++y)
    {
        for (int x = 0; x < 3; ++x)
        {
            int Temp;
            cin >> Temp;
            RMatrix[y].push_back(Temp);
        }
    }

    RtoC();

    int T = 0;
    while (T <= 100)
    {
        if (RMatrix.size() > AnsY && RMatrix[0].size() > AnsX)
        {
            if (RMatrix[AnsY][AnsX] == Ans)
                break;
        }

        // R 연산 행 >= 열
        if (RMatrix.size() >= RMatrix[0].size())
        {
            CalR();
            RtoC();
        }
        else
        {
            CalC();
            CtoR();
        }

        ++T;

        // Debug();
    }

    if (T > 100)
        cout << -1;
    else
        cout << T;


    return 0;
}