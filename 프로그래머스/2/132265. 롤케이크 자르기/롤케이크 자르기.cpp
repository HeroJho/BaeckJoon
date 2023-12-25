#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int g_DP[10001][2] = { 0 };
int g_LCnt, g_RCnt;


int solution(vector<int> topping) {
	int answer = 0;


	for (int i = 0; i < topping.size(); ++i)
	{
		if (g_DP[topping[i]][1] == 0)
		{
			++g_RCnt;
		}
		++g_DP[topping[i]][1];
		
	}

	for (int i = 0; i < topping.size(); ++i)
	{
		--g_DP[topping[i]][1];
		if (g_DP[topping[i]][1] == 0)
		{
			--g_RCnt;
		}
		else if (g_DP[topping[i]][1] < 0)
		{
			g_DP[topping[i]][1] = 0;
		}

		// ====
		if (g_DP[topping[i]][0] == 0)
		{
			++g_LCnt;
		}
		++g_DP[topping[i]][0];


		if (g_RCnt == g_LCnt)
			++answer;
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	
	return 0;
}
