#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;



int N, C;
vector<int> Inputs;



int Go(int Dis)
{
	int Cnt = 1;
	int Pre = Inputs[0];
	for (int i = 1; i < Inputs.size(); ++i)
	{
		if (Inputs[i] - Pre >= Dis)
		{
			Pre = Inputs[i];
			++Cnt;
		}
	}

	return Cnt;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}

	sort(Inputs.begin(), Inputs.end());

	int Ans = 0;
	int Left = 0, Right = Inputs.back() - Inputs.front();
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		int Cnt = Go(Mid);
		if (Cnt >= C)
		{
			Left = Mid + 1;
			Ans = Mid;
		}
		else
		{
			Right = Mid - 1;
		}

	}

	cout << Ans;


	return 0;
}

