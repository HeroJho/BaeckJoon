#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct Item
{
	int iW = 0, iV = 0;
	Item() {};
	Item(int w, int v) : iW(w), iV(v) {};

};

int g_iN, g_iMaxW, g_iMaxV = 0;
vector<Item> g_iItems;
bool g_Visited[100] = { false };
int g_DP[100001] = { 0 };

void DFS(int iV, int iW)
{

	if (g_iMaxV < iV)
		g_iMaxV = iV;

	for (int i = 0; i < g_iItems.size(); ++i)
	{
		if (g_Visited[i])
			continue;

		int inV = iV + g_iItems[i].iV;
		int inW = iW + g_iItems[i].iW;

		if (inW > g_iMaxW)
			continue;

		if (g_DP[inW] >= inV)
			continue;
		g_DP[inW] = inV;

		g_Visited[i] = true;
		DFS(inV, inW);
		g_Visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN >> g_iMaxW;

	for (int i = 0; i < g_iN; ++i)
	{
		Item item;
		cin >> item.iW >> item.iV;
		g_iItems.push_back(item);
	}

	DFS(0, 0);

	cout << g_iMaxV;


	return 0;
}