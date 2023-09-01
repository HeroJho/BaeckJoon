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

	int iN;
	cin >> iN;
	vector<int> g_Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		g_Inputs.push_back(iTemp);
	}


	int iAns = 0;
	int iMax = 0;
	int iCur = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (iMax < g_Inputs[i])
		{
			iMax = g_Inputs[i];

			if (iAns < iCur)
				iAns = iCur;

			iCur = 0;
		}
		else
		{
			++iCur;
		}
			
	}

	if (iAns < iCur)
		iAns = iCur;

	cout << iAns;

	return 0;
}