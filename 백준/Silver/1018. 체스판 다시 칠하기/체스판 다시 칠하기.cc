#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int g_iY, g_iX;
vector<string> g_sMatrix;

int g_iDirX[3] = { 0, -1, 1 };
int g_iDirY[3] = { 1, 0, 0 };

int CheckRangeMatrix8x8(int iStartX, int iStartY)
{
	int iMinCount = 0;
	int iCount = 0;
	
	vector<string> sMatrix = g_sMatrix;
	
	for (int y = iStartY; y < iStartY + 8; ++y)
	{
		for (int x = iStartX; x < iStartX + 8; ++x)
		{
			char cCurChar = sMatrix[y][x];
			// 아래 좌우를 확인한다.
			for (int i = 0; i < 3; ++i)
			{
				int inX = x + g_iDirX[i];
				int inY = y + g_iDirY[i];
				if (!(inX >= iStartX && inX < iStartX + 8 && inY >= iStartY && inY < iStartY + 8))
					continue;
				// 주위가 같으면 바꾼다.
				char cAroundChar = sMatrix[inY][inX];
				if (cAroundChar == cCurChar)
				{
					if(cCurChar == 'W')
						sMatrix[inY][inX] = 'B';
					else
						sMatrix[inY][inX] = 'W';

					++iCount;
				}
			}

		}
	}
	iMinCount = iCount;
	

	sMatrix = g_sMatrix;
	char cChar = sMatrix[iStartY][iStartX];
	if (cChar == 'W')
		sMatrix[iStartY][iStartX] = 'B';
	else
		sMatrix[iStartY][iStartX] = 'W';
	iCount = 1;
	for (int y = iStartY; y < iStartY + 8; ++y)
	{
		for (int x = iStartX; x < iStartX + 8; ++x)
		{
			char cCurChar = sMatrix[y][x];
			// 아래 좌우를 확인한다.
			for (int i = 0; i < 3; ++i)
			{
				int inX = x + g_iDirX[i];
				int inY = y + g_iDirY[i];
				if (!(inX >= iStartX && inX < iStartX + 8 && inY >= iStartY && inY < iStartY + 8))
					continue;
				// 주위가 같으면 바꾼다.
				char cAroundChar = sMatrix[inY][inX];
				if (cAroundChar == cCurChar)
				{
					if (cCurChar == 'W')
						sMatrix[inY][inX] = 'B';
					else
						sMatrix[inY][inX] = 'W';

					++iCount;
				}
			}

		}
	}

	if (iMinCount > iCount)
		iMinCount = iCount;


	return iMinCount;
}

int main()
{
	cin >> g_iY >> g_iX;
	for (int i = 0; i < g_iY; ++i)
	{
		string sTemp;
		cin >> sTemp;
		g_sMatrix.push_back(sTemp);
	}

	int iMinCount = 1000;
	for (int y = 0; y < g_iY - 7; ++y)
	{
		for (int x = 0; x < g_iX - 7; ++x)
		{
			int iCount = CheckRangeMatrix8x8(x, y);
			if (iCount < iMinCount)
				iMinCount = iCount;
		}
	}

	cout << iMinCount;

	return 0;
}