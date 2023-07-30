#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Fuc
{
public:
	bool operator()(long long iL, long long iR)
	{
		return iL > iR;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	
	priority_queue<long long, vector<long long>, Fuc> Qs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp = 0;
		cin >> iTemp;
		Qs.push(iTemp);
	}

	for (int i = 0; i < iM; ++i)
	{
		long long iTemp1 = Qs.top();
		Qs.pop();
		long long iTemp2 = Qs.top();
		Qs.pop();

		long long iSum = iTemp1 + iTemp2;
		Qs.push(iSum);
		Qs.push(iSum);
	}

	int iSize = Qs.size();
	long long iAns = 0;
	for (int i = 0; i < iSize; ++i)
	{
		iAns += Qs.top();
		Qs.pop();
	}

	cout << iAns;

	return 0;
}