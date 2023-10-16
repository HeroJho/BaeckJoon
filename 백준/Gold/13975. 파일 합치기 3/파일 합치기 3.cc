#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Func
{
public:
	bool operator()(long long L, long long R)
	{
		return L > R;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iT;
	cin >> iT;

	for (int t = 0; t < iT; ++t)
	{


		int iN;
		cin >> iN;

		priority_queue<long long, vector<long long>, Func> Qs;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp; cin >> iTemp;
			Qs.push(iTemp);
		}

		long long iAns = 0;
		while (Qs.size() > 1)
		{
			long long iMin1, iMin2;

			iMin1 = Qs.top();
			Qs.pop();
			iMin2 = Qs.top();
			Qs.pop();

			iAns += iMin1 + iMin2;
			Qs.push(iMin1 + iMin2);
		}

		cout << iAns << '\n';


	}




	return 0;
}