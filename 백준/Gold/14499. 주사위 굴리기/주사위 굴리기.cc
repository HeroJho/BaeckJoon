#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

enum Dir { Up = 1, Front = 2, Right = 3, Left = 4, Back = 5, Down = 6 };

int g_iN, g_iM;
int g_Matrix[20][20] = { 0 };
pair<int, int> g_StartPos;
int g_iK;
vector<int> g_Order;

int g_Das[7] = { 0 };
int g_DirX[] = { 0 , 1, -1, 0, 0 };
int g_DirY[] = { 0 , 0, 0, -1, 1 };

bool IsIn(int iX, int iY)
{
	return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

void Roll_Das(int iRoll)
{
	int iTemp = 0;

	switch (iRoll)
	{
	case 1: // Right
		iTemp = g_Das[Right];
		g_Das[Right] = g_Das[Up];
		g_Das[Up] = g_Das[Left];
		g_Das[Left] = g_Das[Down];
		g_Das[Down] = iTemp;
		break;
	case 2:	// Left
		iTemp = g_Das[Left];
		g_Das[Left] = g_Das[Up];
		g_Das[Up] = g_Das[Right];
		g_Das[Right] = g_Das[Down];
		g_Das[Down] = iTemp;
		break;
	case 3:	// Front
		iTemp = g_Das[Front];
		g_Das[Front] = g_Das[Up];
		g_Das[Up] = g_Das[Back];
		g_Das[Back] = g_Das[Down];
		g_Das[Down] = iTemp;
		break;
	case 4: // Back
		iTemp = g_Das[Back];
		g_Das[Back] = g_Das[Up];
		g_Das[Up] = g_Das[Front];
		g_Das[Front] = g_Das[Down];
		g_Das[Down] = iTemp;
		break;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iM;
	cin >> g_StartPos.second >> g_StartPos.first;
	cin >> g_iK;

	for (int y = 0; y < g_iN; ++y)
	{
		for (int x = 0; x < g_iM; ++x)
		{
			cin >> g_Matrix[y][x];
		}
	}

	vector<int> g_Anss;
	for (int i = 0; i < g_iK; ++i)
	{

		int iTemp; cin >> iTemp;

		int inX = g_StartPos.first + g_DirX[iTemp];
		int inY = g_StartPos.second + g_DirY[iTemp];

		if (!IsIn(inX, inY))
			continue;

		// 이동
		g_StartPos.first = inX;
		g_StartPos.second = inY;
		Roll_Das(iTemp);

		// 찍기
		if (g_Matrix[inY][inX] == 0)
			g_Matrix[inY][inX] = g_Das[Down];
		else
		{
			g_Das[Down] = g_Matrix[inY][inX];
			g_Matrix[inY][inX] = 0;
		}
			
		
		// Up 출력
		g_Anss.push_back(g_Das[Up]);

	}


	for (int i = 0; i < g_Anss.size(); ++i)
	{
		cout << g_Anss[i] << '\n';
	}

	return 0;
}