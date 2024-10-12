#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int DP[1000001] = { 0 };
int Ans[1000001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
		++DP[Temp];
	}


	for (int i = 0; i < N; ++i)
	{
		Ans[i] = -1;
	}



	stack<int> Stack;
	for (int i = N - 1; i >= 0; --i)
	{
		while (!Stack.empty())
		{
			int Top = Stack.top();
			if (DP[Inputs[i]] >= DP[Inputs[Top]])
			{
				Stack.pop();
			}
			else
			{
				Ans[i] = Inputs[Top];
				break;
			}
		}

		Stack.push(i);
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Ans[i] << ' ';
	}


	return 0;
}
