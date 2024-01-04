#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

int g_N, g_M;
vector<int> g_Inputs;
vector<pair<int, int>> g_Inputs2;


void Boy(int Index)
{
	int iTempIndex = Index;
	while (iTempIndex <= g_N)
	{
		if (g_Inputs[iTempIndex] == 0)
			g_Inputs[iTempIndex] = 1;
		else
			g_Inputs[iTempIndex] = 0;

		iTempIndex += Index;
	}
}

void Girl(int Index)
{
	int Mid = Index;
	int Left = Mid - 1, Right = Mid + 1;

	if (g_Inputs[Mid] == 0)
		g_Inputs[Mid] = 1;
	else
		g_Inputs[Mid] = 0;

	while (true)
	{
		if (Left < 1 || Right > g_N)
			break;

		if (g_Inputs[Left] == g_Inputs[Right])
		{
			if (g_Inputs[Left] == 0)
				g_Inputs[Left] = 1;
			else
				g_Inputs[Left] = 0;

			if (g_Inputs[Right] == 0)
				g_Inputs[Right] = 1;
			else
				g_Inputs[Right] = 0;

			--Left;
			++Right;
		}
		else
			break;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_N;
	g_Inputs.push_back(-1);
	for (int i = 0; i < g_N; ++i)
	{
		int iTemp; cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}
	cin >> g_M;
	for (int i = 0; i < g_M; ++i)
	{
		int iTemp1, iTemp2; cin >> iTemp1 >> iTemp2;
		g_Inputs2.push_back({iTemp1, iTemp2});
	}

	for (int i = 0; i < g_M; ++i)
	{
		if (g_Inputs2[i].first == 1)
			Boy(g_Inputs2[i].second);
		else
			Girl(g_Inputs2[i].second);
	}

	for (int i = 1; i <= g_N; ++i)
	{
		if (20 < i)
			cout << '\n';
		cout << g_Inputs[i];
		if (20 >= i)
			cout << ' ';
	}


	return 0;
}