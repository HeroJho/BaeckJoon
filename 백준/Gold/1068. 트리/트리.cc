
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int g_iN, g_iD;
list<int> g_Matrix[50];
int g_iCount = 0;

void DFS(int iCur)
{
	// 자식 노드가 없는 경우
	if (g_Matrix[iCur].empty())
	{
		if (iCur != g_iD)
			++g_iCount;
		return;
	}
	// 자식 노드 하나가 있지만, 해당 자식 노드가 지워진 경우
	if (g_Matrix[iCur].size() == 1 && g_Matrix[iCur].front() == g_iD)
	{
		++g_iCount;
		return;
	}

	for (auto iNum : g_Matrix[iCur])
	{
		DFS(iNum);
	}

}

int main()
{
	cin >> g_iN;
	int iRoot = 0;
	for (int i = 0; i < g_iN; ++i)
	{
		int iTemp = 0;
		cin >> iTemp;
		if (iTemp == -1)
			iRoot = i;
		else
			g_Matrix[iTemp].push_back(i);
	}
	cin >> g_iD;

	g_Matrix[g_iD].clear();
	
	DFS(iRoot);

	cout << g_iCount;

	return 0;
}