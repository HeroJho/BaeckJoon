#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN = 0;
	cin >> iN;

	priority_queue<int, vector<int>, greater<int>> Qs;
	vector<int> Anss;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp; cin >> iTemp;

		if (0 == iTemp)
		{
			if (Qs.empty())
			{
				Anss.push_back(0);
			}
			else
			{
				int iAns = Qs.top();
				Qs.pop();
				Anss.push_back(iAns);
			}
		}
		else
		{
			Qs.push(iTemp);
		}
	}

	for (int i = 0; i < Anss.size(); ++i)
	{
		cout << Anss[i] << '\n';
	}


	return 0;
}