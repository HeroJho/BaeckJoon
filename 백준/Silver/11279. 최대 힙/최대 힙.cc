#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Fuc
{
public:
	bool operator()(int iL, int iR)
	{
		return iL < iR;
	}
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int iN;
	cin >> iN;
	vector<int> iAnss;
	priority_queue<int, vector<int>, Fuc> iQs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		if (iTemp)
		{
			iQs.push(iTemp);
		}
		else
		{
			if (iQs.empty())
			{
				iAnss.push_back(0);
			}
			else
			{
				iAnss.push_back(iQs.top());
				iQs.pop();
			}
		}
	}

	for (auto iAns : iAnss)
	{
		cout << iAns << '\n';
	}
	

	return 0;
}