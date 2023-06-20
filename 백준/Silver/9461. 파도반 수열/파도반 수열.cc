#include <iostream>
#include <vector>

using namespace std;

int main()
{

	// 한 단계를 건너뛴다.

	// 1 2 3 4 5 6 7 8 9 10
	// 1 1 1 2 2 3 4 5 7 9
	
	int iT;
	cin >> iT;
	++iT;
	vector<long long> iAnss;
	while (--iT)
	{
		int iN;
		cin >> iN;
		--iN;
		vector<long long> iTemps = { 1, 1, 1, 2, 2 };
		if (iN < 5)
		{
			iAnss.push_back(iTemps[iN]);
		}
		else
		{
			for (int i = 5; i <= iN; ++i)
			{
				iTemps.push_back(iTemps[i - 1] + iTemps[i - 5]);
			}
			iAnss.push_back(iTemps.back());
		}
	}

	for (auto iAns : iAnss)
	{
		cout << iAns << endl;
	}
	

	return 0;
}