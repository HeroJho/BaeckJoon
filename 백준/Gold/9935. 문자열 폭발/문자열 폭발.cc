#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string g_sInput;
string g_sBoom;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g_sInput;
	cin >> g_sBoom;

	// abc b abcd bcd cd
	//  0 1   2   3  4
	// abcd

	stack<pair<char, int>> Stacks;

	int iBoomIndex = 0;
	int iMaxBoomCount = g_sBoom.length();
	for (int i = 0; i < g_sInput.length(); ++i)
	{

		if (g_sInput[i] == g_sBoom[iBoomIndex])
		{
			Stacks.push({ g_sInput[i], i});
			++iBoomIndex;

			// 다 쌓였다
			if (iBoomIndex == iMaxBoomCount)
			{
				for (int p = 0; p < iMaxBoomCount; ++p)
				{
					g_sInput[Stacks.top().second] = '*';
					Stacks.pop();
				}
					

				if (!Stacks.empty() && Stacks.top().first == '*')
				{
					iBoomIndex = Stacks.top().second;
					Stacks.pop();
				}
				else
					iBoomIndex = 0;
					 
			}
		}
		else
		{
			if (g_sInput[i] == g_sBoom[0])
			{
				Stacks.push({ '*', iBoomIndex });
				Stacks.push({ g_sInput[i], i });
				iBoomIndex = 1;
			}
			else
			{
				Stacks.empty();
				iBoomIndex = 0;
			}
		}

		
	}


	string sTemp;
	for (int i = 0; i < g_sInput.length(); ++i)
	{
		if (g_sInput[i] == '*')
			continue;

		sTemp.push_back(g_sInput[i]);
	}

	if (sTemp.empty())
		cout << "FRULA";
	else
		cout << sTemp;


	return 0;
}