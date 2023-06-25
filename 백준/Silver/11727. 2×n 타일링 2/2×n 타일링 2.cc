#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;

	long long iAccCount = 0;
	vector<int> iDPs(iN+1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		iAccCount += iDPs[i - 1];
		if (i % 2 == 0)
			iDPs[i] = (iAccCount + 2) % 10007;
		else
			iDPs[i] = (iAccCount + 1) % 10007;
	}

	cout << iDPs[iN];

	return 0;
}