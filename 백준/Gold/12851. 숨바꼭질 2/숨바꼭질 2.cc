#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define MAX 200001

using namespace std;

int g_iN, g_iM;
bool g_Visited[MAX] = { false };

void BFS()
{
	queue<int> Qs;
	Qs.push(g_iN);

	int iSecond = -1;
	int iCount = 0;
	bool bStop = false;
	while (!Qs.empty())
	{
		if (bStop)
			break;

		int iSize = Qs.size();
		for (int t = 0; t < iSize; ++t)
		{

			int iCur = Qs.front();
			Qs.pop();

			g_Visited[iCur] = true;

			if (iCur == g_iM)
			{
				bStop = true;
				if (bStop)
					++iCount;

			}

			if(iCur * 2 < 200001 && !g_Visited[iCur * 2])
				Qs.push(iCur * 2);
			if (iCur + 1 < 200001 && !g_Visited[iCur + 1])
				Qs.push(iCur + 1);
			if (iCur - 1 >= 0 && !g_Visited[iCur - 1])
				Qs.push(iCur - 1);

		}

		++iSecond;

	}

	cout << iSecond << '\n';
	cout << iCount;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_iN >> g_iM;
	BFS();

	return 0;
}