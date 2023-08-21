#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int g_iN, g_iStart, g_iEnd, g_iCount;

int g_iMatrix[101][101] = { 0 };
bool g_bVisited[101] = { false };

void BFS()
{
	queue<int> Qs;
	Qs.push(g_iStart);
	g_bVisited[g_iStart] = true;

	int iAns = 0;

	while (!Qs.empty())
	{
		int iSize = Qs.size();

		for (int t = 0; t < iSize; ++t)
		{
			int iCurNum = Qs.front();
			Qs.pop();

			if (iCurNum == g_iEnd)
			{
				cout << iAns;
				return;
			}

			for (int i = 1; i <= g_iN; ++i)
			{
				if (!g_bVisited[i] && g_iMatrix[iCurNum][i])
				{
					g_bVisited[i] = true;
					Qs.push(i);
				}
			}

		}

		++iAns;

	}

	cout << -1;

}

int main()
{
	cin >> g_iN >> g_iStart >> g_iEnd >> g_iCount;

	for (int i = 0; i < g_iCount; ++i)
	{
		int iTemp1, iTemp2;
		cin >> iTemp1 >> iTemp2;

		g_iMatrix[iTemp1][iTemp2] = 1;
		g_iMatrix[iTemp2][iTemp1] = 1;
	}

	BFS();


	return 0;
}