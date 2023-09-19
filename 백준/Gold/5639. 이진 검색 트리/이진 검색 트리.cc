
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

vector<int> g_Inputs;

// 50 30 24 5 28 45 98 52 60 
// 5 28 24 45 30 60 52 98 50


void DFS(int iStart, int iEnd)
{
	if (iStart >= iEnd)
	{
		return;
	}

	int iL = iStart + 1;
	int iR = iL;
	for (int i = iR; i < iEnd; ++i)
	{
		if (g_Inputs[iStart] < g_Inputs[i])
		{
			iR = i;
			break;
		}
	}
	
	// 왼쪽 출력
	DFS(iL, iR);
	// 오른 출력
	DFS(iR, iEnd);
	// 중앙 출력
	cout << g_Inputs[iStart] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iTemp;
	while (cin >> iTemp)
	{	
		g_Inputs.push_back(iTemp); 
	}

	DFS(0, g_Inputs.size());


	return 0;
}