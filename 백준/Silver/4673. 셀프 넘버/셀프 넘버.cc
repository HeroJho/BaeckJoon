#include <iostream>
#include <string>

using namespace std;

int main()
{

	bool iDP[20001] = { false };

	for (int i = 1; i < 10001; ++i)
	{
		string s = to_string(i);

		int iTemp = i;
		for (int j = 0; j < s.length(); ++j)
		{
			iTemp += s[j] - '0';
		}

		iDP[iTemp] = true;
	}

	for (int i = 1; i < 10001; ++i)
	{
		if (!iDP[i])
			cout << i << '\n';
	}

	return 0;
}