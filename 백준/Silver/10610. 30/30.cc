#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

string g_sInput;
int g_iAns = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_sInput;

	long long iSum = 0;
	for (int i = 0; i < g_sInput.length(); ++i)
	{
		int iNum = g_sInput[i] - '0';
		iSum += iNum;
	}

	sort(g_sInput.rbegin(), g_sInput.rend());
	if (iSum % 3 == 0 && g_sInput[g_sInput.length() - 1] == '0')
	{
		cout << g_sInput;
	}
	else
	{
		cout << -1;
	}

	return 0;
}