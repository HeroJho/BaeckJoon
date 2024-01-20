#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include "limits.h"

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 1 2 3 4
	// 1 2
	// 1 2 5 6
	// 1 2 5
	// 1 2 5 7 8
	// 

	// pop과 i를 비교
	// i가 크다면 i를 넣는다
	// pop이 크면 pop한다


	int N;
	cin >> N;
	
	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}

	vector<char> Anss;

	stack<int> Ss;
	int CheckIndex = 0;
	for (int i = 1; CheckIndex < N;)
	{
		if (i > N + 1)
		{
			cout << "NO";
			return 0;
		}
		
		if (Ss.empty())
		{
			Ss.push(i);
			Anss.push_back('+');
			++i;
			continue;
		}

		int Top = Ss.top();
		if (Top == Inputs[CheckIndex])
		{
			Ss.pop();
			Anss.push_back('-');
			++CheckIndex;
		}
		else
		{
			Ss.push(i);
			Anss.push_back('+');
			++i;
		}

	}

	for (int i = 0; i < Anss.size(); ++i)
	{
		cout << Anss[i] << '\n';
	}

	return 0;
}
