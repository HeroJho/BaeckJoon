#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.second > R.second;
	}
};

int main()
{
	int iT;
	cin >> iT;


	 for (int t = 0; t < iT; ++t)
	{

		int iN, iM;
		cin >> iN >> iM;
		vector<pair<int, int>> Inputs;
		for (int i = 0; i < iM; ++i)
		{
			pair<int, int> Temp;
			cin >> Temp.first >> Temp.second;
			Inputs.push_back(Temp);
		}

		// 시작 책 오름차순
		sort(Inputs.begin(), Inputs.end());

		int iAns = 0;

		// 책 순회 (누구 줄까?)
		priority_queue<pair<int, int>, vector<pair<int, int>>, Func> Qs;
		int iIndex = 0;
		for (int i = 1; i <= iN; ++i)
		{
			// i 권을 받을 수 있는 모든 애들을 Qs에 다 담는다 (end로 최소 힙)
			for (int j = iIndex; j < Inputs.size(); ++j)
			{
				if (i != Inputs[j].first)
				{
					iIndex = j;
					break;
				}

				Qs.push(Inputs[j]);
				iIndex = j;
			}

			// 다 담았다면 top에게 준다 (end가 제일 짧으니 바로 준다)
			while (!Qs.empty())
			{
				pair<int, int> MinEnd = Qs.top();
				Qs.pop();


				if (i <= MinEnd.second)
				{
					++iAns;
					break;
				}
			}

		}

		cout << iAns << '\n';




	}


	return 0;
}