#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Data
{
	int iPosIndex = 0;
	int iScore = 0;
	int iStap = 0;
};


int g_iN;
// int g_iAns = 0;
vector<int> g_iNums;
vector<int> g_iScore;

void BFS()
{
	queue<Data> Qs;
	Data CurData;
	Qs.push(CurData);

	while (!Qs.empty())
	{
		CurData = Qs.front();
		Qs.pop();

		// 3 연속
		if (CurData.iStap >= 3)
		{
			continue;
		}
		//else if (CurData.iPosIndex == g_iN && g_iAns < CurData.iScore)
		//{
		//	g_iAns = CurData.iScore;
		//	continue;
		//}
		// DP 확인
		else if (CurData.iScore < g_iScore[CurData.iPosIndex])
		{
			continue;
		}
		else if(CurData.iStap == 1 || CurData.iPosIndex == g_iN)
		{
			g_iScore[CurData.iPosIndex] = CurData.iScore;
		}
			
		// 1 stap
		Data NextData;
		NextData.iPosIndex = CurData.iPosIndex + 1;
		// 끝을 넘음
		if (NextData.iPosIndex <= g_iN) 
		{
			NextData.iScore = CurData.iScore + g_iNums[NextData.iPosIndex];
			NextData.iStap = CurData.iStap + 1;
			Qs.push(NextData);
		}

		// 2 stap
		NextData.iPosIndex = CurData.iPosIndex + 2;
		// 끝을 넘음
		if (NextData.iPosIndex <= g_iN)
		{
			NextData.iScore = CurData.iScore + g_iNums[NextData.iPosIndex];
			NextData.iStap = 1;
			Qs.push(NextData);
		}
	}
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;
	g_iNums.push_back(0);
	g_iScore.resize(g_iN + 1, 0);
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp = 0;
		cin >> iTemp;
		g_iNums.push_back(iTemp);
	}


	BFS();

	cout << g_iScore[g_iN];

	return 0;
}