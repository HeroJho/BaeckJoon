#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN;
int g_iAns;
int g_Matrix[15][15] = {0};
bool g_Visited[15][15] = { false };

int g_DirX[] = { 0 , 0, -1, 1, 1, 1, -1, -1 };
int g_DirY[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iN && iY >= 0 && iY < g_iN;
}

void Check(int iX, int iY)
{
	++g_Matrix[iY][iX];

	for (int i = 0; i < 8; ++i)
	{
		int inX = iX, inY = iY;
		while (true)
		{
			inX += g_DirX[i];
			inY += g_DirY[i];

			if (IsIn(inX, inY))
				++g_Matrix[inY][inX];
			else
				break;

		}

	}

}
void UnCheck(int iX, int iY)
{
	--g_Matrix[iY][iX];

	for (int i = 0; i < 8; ++i)
	{
		int inX = iX, inY = iY;
		while (true)
		{
			inX += g_DirX[i];
			inY += g_DirY[i];

			if (IsIn(inX, inY))
				--g_Matrix[inY][inX];
			else
				break;

		}

	}

}

void DFS(int iQnCount)
{
	if (iQnCount == g_iN)
	{
		// 모든 말을 놨다
		++g_iAns;
		return;
	}


	for (int x = 0; x < g_iN; ++x)
	{
		if (g_Matrix[iQnCount][x] > 0)
			continue;


		Check(x, iQnCount);
		DFS(iQnCount + 1);
		UnCheck(x, iQnCount);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;

	DFS(0);

	cout << g_iAns;


	return 0;
}