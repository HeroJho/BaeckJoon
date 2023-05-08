#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g_iX, g_iY, g_iW, g_iH;

int main()
{
	cin >> g_iX >> g_iY >> g_iW >> g_iH;

	vector<int> iAnss;

	iAnss.push_back(g_iW - g_iX);
	iAnss.push_back(g_iH - g_iY);
	iAnss.push_back(g_iX);
	iAnss.push_back(g_iY);

	sort(iAnss.begin(), iAnss.end());

	cout << iAnss[0];

	return 0;
}