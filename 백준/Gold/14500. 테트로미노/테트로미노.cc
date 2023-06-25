#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vec2D
{
	int iX, iY;
	Vec2D(int x, int y) : iX(x), iY(y){ }
};

int g_iN, g_iM;
int g_iMatrix[500][500] = { 0 };

vector<Vec2D> g_OriBlock[5]{ 
	{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }, 
	{ {0, 0}, {1, 0}, {1, 1}, {0, 1} }, 
	{ {0, 0}, {0, 1}, {0, 2}, {1, 2} }, 
	{ {0, 0}, {0, 1}, {1, 1}, {1, 2} }, 
	{ {0, 0}, {1, 0}, {2, 0}, {1, 1} } };


void Rot_Index(vector<Vec2D>& RotIndex)
{
	// 90도 회전 = 둘이 바꾸고, 바꾼거에서 - 곱하기
	
	for (int i = 0; i < 4; ++i)
	{
		int iTemp = RotIndex[i].iX;
		RotIndex[i].iX = RotIndex[i].iY;
		RotIndex[i].iY = iTemp;

		RotIndex[i].iX *= -1;
	}

}

void Flip_Index(vector<Vec2D>& RotIndex)
{
	for (int i = 0; i < 4; ++i)
	{
		RotIndex[i].iX *= -1;
	}
}

bool Check_Range(int iX, int iY)
{
	return iX < g_iN && iX >= 0 && iY < g_iM && iY >= 0;
}

int Ans()
{
	int iMaxCount = 0;
	for (int y = 0; y < g_iM; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			for (int i = 0; i < 5; ++i)
			{
				// 돌리기
				int iFlips = 2;
				while (iFlips)
				{
					vector<Vec2D> Blocks = g_OriBlock[i];

					--iFlips;
					if (iFlips == 0)
					{
						Flip_Index(Blocks);
					}

					for (int r = 0; r < 4; ++r)
					{
						Rot_Index(Blocks);
						int iSum = 0;

						bool bBreak = false;
						for (int k = 0; k < 4; ++k)
						{
							int inX = x + Blocks[k].iX;
							int inY = y + Blocks[k].iY;

							if (Check_Range(inX, inY))
							{
								iSum += g_iMatrix[inY][inX];
							}
							else
							{
								bBreak = true;
								break;
							}
						}

						if (!bBreak && iMaxCount < iSum)
						{
							iMaxCount = iSum;
						}
					}

				}
				
			}

		}
	}

	return iMaxCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iM >> g_iN;

	for (int y = 0; y < g_iM; ++y)
	{
		for (int x = 0; x < g_iN; ++x)
		{
			cin >> g_iMatrix[y][x];
		}
	}

	cout << Ans();

	return 0;
}