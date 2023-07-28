#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Vec2D
{
	int iX, iY;
	Vec2D() : iX(0), iY(0) {};
	Vec2D(int x, int  y) : iX(x), iY(y) {}
};

int g_iR, g_iC, g_iAns;

vector<string> g_Matrix;
bool g_Is[30] = { false };

int g_iDirX[4] = { 0, 0, -1, 1 };
int g_iDirY[4] = { -1, 1, 0, 0 };

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iC&& iY >= 0 && iY < g_iR;
}

void DFS(Vec2D Pos, int iCount)
{
	// A = 65
	int iChar = g_Matrix[Pos.iY][Pos.iX] - 65;
	g_Is[iChar] = true;

	if (g_iAns < iCount)
		g_iAns = iCount;

	for (int i = 0; i < 4; ++i)
	{
		int inX = Pos.iX + g_iDirX[i];
		int inY = Pos.iY + g_iDirY[i];

		if (IsIn(inX, inY))
		{
			int inChar = g_Matrix[inY][inX] - 65;
			if (!g_Is[inChar])
			{
				// g_Is[inChar] = true;
				int inCount = iCount + 1;
				DFS({inX, inY}, inCount);
				g_Is[inChar] = false;
			}
		}

	}

}

int main()
{
	cin >> g_iR >> g_iC;
	for (int i = 0; i < g_iR; ++i)
	{
		string sTemp; cin >> sTemp;
		g_Matrix.push_back(sTemp);
	}
	
	DFS({0, 0}, 1);
	
	cout << g_iAns;

	return 0;
}