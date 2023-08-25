#include <iostream>
#include <vector>

using namespace std;

int g_iN;
vector<pair<int, int>> g_Days;
int g_DP[16] = { 0 };
int g_iAns = 0;

//            방문한 날       현재 누적 돈
void DFS(int iAccDay, int iAccPay)
{

	for (int i = iAccDay + 1; i <= g_iN; ++i)
	{
		// 일할 수 있냐?
		int inDay = i + g_Days[i].first - 1;
		int inPay = iAccPay + g_Days[i].second;
		if (inDay <= g_iN)
		{
			if (g_iAns < inPay)
				g_iAns = inPay;

			DFS(inDay, inPay);
		}
	}
	
}

int main()
{
	cin >> g_iN;

	pair<int, int> Temp;
	g_Days.push_back(Temp);

	for (int i = 0; i < g_iN; ++i)
	{
		pair<int, int> Temp;
		cin >> Temp.first >> Temp.second;
		g_Days.push_back(Temp);
	}


	DFS(0, 0);
	
	cout << g_iAns;

	return 0;
}