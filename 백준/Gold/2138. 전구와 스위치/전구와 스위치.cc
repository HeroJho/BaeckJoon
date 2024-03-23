#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

void Flip(int Index, string& Temp)
{
	for (int i = Index - 1; i <= Index + 1; ++i)
	{
		if (i < 0 || i >= Temp.length())
			continue;

		if(Temp[i] == '0')
			Temp[i] = '1';
		else if (Temp[i] == '1')
			Temp[i] = '0';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	string Start, End;
	cin >> Start >> End;

	// 0번째 안 누르고 시작
	int Ans = 0;
	string Temp = Start;
	for (int i = 0; i < Temp.length() - 1; ++i)
	{
		// 다르다면
		if (Temp[i] != End[i])
		{
			Flip(i + 1, Temp);
			Ans++;
		}

		if (Temp == End)
		{
			cout << Ans;
			return 0;
		}
	}

	// 누르고 시작
	Ans = 1;
	Temp = Start;
	Flip(0, Temp);
	for (int i = 0; i < Temp.length() - 1; ++i)
	{
		// 다르다면
		if (Temp[i] != End[i])
		{
			Flip(i + 1, Temp);
			Ans++;
		}

		if (Temp == End)
		{
			cout << Ans;
			return 0;
		}
	}

	cout << -1;

	return 0;
}
