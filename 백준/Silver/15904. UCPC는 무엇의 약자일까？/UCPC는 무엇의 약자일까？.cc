#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string sS;
	getline(cin, sS);

	string sUCPC = "CPCU";

	for (int i = 0; i < sS.length(); ++i)
	{
		if (sUCPC.back() == sS[i])
		{
			sUCPC.pop_back();
			if (sUCPC.empty())
				break;
		}
	}

	if (sUCPC.empty())
	{
		cout << "I love UCPC";
	}
	else
		cout << "I hate UCPC";

	return 0;
}