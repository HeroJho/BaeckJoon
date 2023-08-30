#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.first > R.first;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int iN;
	cin >> iN;

	list<pair<int,int>> Inputs;
	for (int i = 0; i < iN; ++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		Inputs.push_back({ iA, iB });
	}

	Inputs.sort(Func());

	int iAns = 0;

	int iMaxDay = Inputs.front().first;
	for (int i = iMaxDay; i > 0; --i)
	{
		int iMaxScore = 0;
		list<pair<int, int>>::iterator MaxIter;
		for (list<pair<int, int>>::iterator iter = Inputs.begin(); iter != Inputs.end(); ++iter)
		{
			if (i <= (*iter).first)
			{
				if (iMaxScore < (*iter).second)
				{
					iMaxScore = (*iter).second;
					MaxIter = iter;
				}
			}
			else
				break;
		}

		if (iMaxScore > 0)
		{
			Inputs.erase(MaxIter);
			iAns += iMaxScore;
		}

	}
	
	cout << iAns;

	return 0;
}