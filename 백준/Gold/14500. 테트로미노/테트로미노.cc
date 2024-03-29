#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define MAX 500

using namespace std;

int g_iN, g_iM;
int g_Matrix[MAX][MAX] = { 0 };
vector<pair<int, int>> g_Ts[5];
int g_iAns;

void Spine(const vector<pair<int, int>>& Block, int iRad, vector<pair<int ,int>>& OUT_SpineBlock)
{
	for (int i = 0; i < 4; ++i)
	{
		pair<int, int> Pos = Block[i];

		for (int k = 0; k < iRad; ++k)
		{
			int iTemp = Pos.first;
			Pos.first = Pos.second;
			Pos.second = iTemp * -1;
		}

		OUT_SpineBlock[i] = Pos;

	}

}

void Flip(const vector<pair<int, int>>& Block, vector<pair<int, int>>& OUT_SpineBlock)
{
	for (int i = 0; i < 4; ++i)
	{
		OUT_SpineBlock[i] = { Block[i].first, Block[i].second * -1 };
	}

}

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM&& iY >= 0 && iY < g_iN;
}

void Check(const vector<pair<int, int>>& Block)
{
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iM; ++j)
		{

			int iSum = 0;
			for (int k = 0; k < 4; ++k)
			{
				int inX = j + Block[k].first;
				int inY = i + Block[k].second;
				
				if (!IsIn(inX, inY))
				{
					iSum = 0;
					break;
				}
					
				iSum += g_Matrix[inY][inX];

			}

			if (g_iAns < iSum)
				g_iAns = iSum;

		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g_iN >> g_iM;
	for (int i = 0; i < g_iN; ++i)
	{
		for (int j = 0; j < g_iM; ++j)
		{
			cin >> g_Matrix[i][j];
		}
	}

	
	g_Ts[0] = { { 0,0 }, { 1,0 }, { 2,0 }, { 3,0 } };
	g_Ts[1] = { { 0,0 }, { 1,0 }, { 1,1 }, { 0,1 } };
	g_Ts[2] = { { 0,0 }, { 0,1 }, { 0,2 }, { 1,0 } };
	g_Ts[3] = { { 0,0 }, { 0,1 }, { 1,0 }, { 1,-1 } };
	g_Ts[4] = { { 0,0 }, { 1,0 }, { -1,0 }, { 0,-1 } };


	vector<pair<int, int>> Out_Block(4);
	for (int i = 0; i < 5; ++i)
	{
		vector<pair<int, int>> FlipBlock(4);
		Flip(g_Ts[i], FlipBlock);

		Check(g_Ts[i]);
		Check(FlipBlock);

		for (int k = 1; k < 4; ++k)
		{
			Spine(g_Ts[i], k, Out_Block);
			Check(Out_Block);
			Spine(FlipBlock, k, Out_Block);
			Check(Out_Block);
		}

	}

	cout << g_iAns;


	return 0;
}