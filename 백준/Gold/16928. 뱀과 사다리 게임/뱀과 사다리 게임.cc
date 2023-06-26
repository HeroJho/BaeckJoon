#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct LadderSnake
{
	int iStart, iEnd;

	LadderSnake() : iStart(0), iEnd(0) {};
	LadderSnake(int x, int y) : iStart(x), iEnd(y){}
};

int g_iN, g_iM;
vector<LadderSnake> g_iLadderSnake;

int g_iDP[101] = { 0 };

void Input()
{
	cin >> g_iN >> g_iM;

	for (int i = 0; i < g_iN; ++i)
	{
		LadderSnake LS;
		cin >> LS.iStart >> LS.iEnd;
		g_iLadderSnake.push_back(LS);
	}
	for (int i = 0; i < g_iM; ++i)
	{
		LadderSnake LS;
		cin >> LS.iStart >> LS.iEnd;
		g_iLadderSnake.push_back(LS);
	}

	for (int i = 0; i < 101; ++i)
	{
		g_iDP[i] = 2147483647;
	}

}

void BFS()
{
	queue<int> iQs;
	iQs.push(1);

	int iCount = 0;
	g_iDP[0] = iCount;

	while (!iQs.empty())
	{
		int iSize = iQs.size();
		++iCount;

		for (int i = 0; i < iSize; ++i)
		{
			int iCurNum = iQs.front();
			iQs.pop();

			for (int j = 1; j <= 6; ++j)
			{
				int iNextNum = iCurNum + j;

				for (int k = 0; k < g_iLadderSnake.size(); ++k)
				{
					if (iNextNum == g_iLadderSnake[k].iStart)
					{
						iNextNum = g_iLadderSnake[k].iEnd;
					}
				}

				if (100 == iNextNum)
				{
					g_iDP[iNextNum] = iCount;
					return;
				}


				if (g_iDP[iNextNum] > iCount)
				{
					g_iDP[iNextNum] = iCount;
					iQs.push(iNextNum);
				}
			}
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();

	BFS();

	cout << g_iDP[100];

	return 0;
}