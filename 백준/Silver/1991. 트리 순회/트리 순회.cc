#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int g_iN;
pair<char, char> g_G[27];

void Render_L(char cNode)
{
	if (cNode == '.')
		return;

	cout << cNode;
	Render_L(g_G[cNode - 65].first);
	Render_L(g_G[cNode - 65].second);
}
void Render_M(char cNode)
{
	if (cNode == '.')
		return;

	Render_M(g_G[cNode - 65].first);
	cout << cNode;
	Render_M(g_G[cNode - 65].second);
}
void Render_R(char cNode)
{
	if (cNode == '.')
		return;

	Render_R(g_G[cNode - 65].first);
	Render_R(g_G[cNode - 65].second);
	cout << cNode;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_iN;

	for (int i = 0; i < g_iN; ++i)
	{
		char cTemp, cL, cR;
		cin >> cTemp >> cL >> cR;
		g_G[cTemp - 65] = { cL, cR };

	}

	Render_L('A');
	cout << '\n';
	Render_M('A');
	cout << '\n';
	Render_R('A');

	return 0;
}