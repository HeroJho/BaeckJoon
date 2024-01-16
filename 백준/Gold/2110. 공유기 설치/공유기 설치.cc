#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g_N, g_C;
vector<int> g_Inputs;


bool possible(int dist)
{
	// 0번째는 무조건 설치한다
	int cnt = 1;
	int prev = g_Inputs[0];

	for (int i = 1; i < g_N; i++)
	{
		// 거리가 dist 이상일 때만 설치할 때
		if (g_Inputs[i] - prev >= dist)
		{
			cnt++;
			prev = g_Inputs[i];
		}
	}
		
	// 같거나 더 많이 설치됐다면
	if (cnt >= g_C)
		return true;

	// 더 작게 설치됐다면
	return false;
}



int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> g_N >> g_C;


	for (int i = 0; i < g_N; i++)
	{
		int Temp; cin >> Temp;
		g_Inputs.push_back(Temp);
	}
		
	sort(g_Inputs.begin(), g_Inputs.end());

	//최소거리, 최대 거리
	int Low = 1, High = g_Inputs[g_N - 1] - g_Inputs[0];
	int Result = 0;

	while (Low <= High)
	{ 
		int Mid = (Low + High) / 2;

		// 거리가 mid 이상일 때 설치했을 때
		if (possible(Mid)) // C 이상 설치됐다면
		{ 
			// 거리를 높여서 확인한다.
			Result = max(Result, Mid);
			Low = Mid + 1;
		}
		else   // C보다 더 작게 설치됐다면
		{
			// 거리를 낮춰서 확인해 본다.
			High = Mid - 1;
		}
			
	}

	cout << Result << "\n";

	return 0;

}
