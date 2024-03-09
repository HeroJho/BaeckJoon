#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;

int N;
vector<int> Inputs;
int DP[10000][3] = { 0 };
int Ans = 0;

void Reset()
{
	for (int i = 0; i < 10000; ++i)
	{
		DP[i][0] = -1;
		DP[i][1] = -1;
		DP[i][2] = -1;
	}
}

void DFS(int Index, int DrinkNum, int Sum)
{
	if (Ans < Sum)
		Ans = Sum;

	// Num인데 DP보다 점수가 낮고
	// DP보다 이상 먹었을 때 = 같게 먹거나 더 먹었을 때
	// 0, 1, 2잔 째 마실 수 있다
	if (Index >= N)
		return;

	// 앞에 잔에 더 높은게 있다면 확인할 필요없다
	for (int i = 0; i <= DrinkNum; ++i)
	{
		if (DP[Index][i] >= Sum)
			return;
	}

	DP[Index][DrinkNum] = Sum;

	// 지금 DrinkNum잔 마신 상태

	// 마셨나
	if (DrinkNum < 2)
		DFS(Index + 1, DrinkNum + 1, Sum + Inputs[Index]);

	// 안 마셨나
	if (DrinkNum >= 2)
		DrinkNum = 0;
	DFS(Index + 1, DrinkNum, Sum);



}

// 마셨는지 여부, 몇 번째로 마셨는지
//    
// 1
// 2
// 3

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// Reset();

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Temp;
		cin >> Temp;
		Inputs.push_back(Temp);
	}

	// DFS(0, 0, 0);

	DP[0][0] = 0;
	DP[0][1] = Inputs[0];
	DP[0][2] = Inputs[0];


	for (int i = 1; i < N; ++i)
	{
		DP[i][0] = max(DP[i - 1][1], DP[i - 1][2]);
		DP[i][0] = max(DP[i][0], DP[i - 1][0]);
		DP[i][1] = DP[i - 1][0] + Inputs[i];
		DP[i][2] = DP[i - 1][1] + Inputs[i];
	}

	Ans = max(DP[N - 1][0], DP[N - 1][1]);
	Ans = max(Ans, DP[N - 1][2]);

	cout << Ans;

	return 0;
}
