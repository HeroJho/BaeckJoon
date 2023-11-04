#include <string>
#include <vector>

using namespace std;

long long g_DP[500001] = { 0 };

long long solution(vector<int> sequence) {
	long long answer = 0;

	vector<long long> Temps;

	bool bT = false;
	for (int i = 0; i < sequence.size(); ++i)
	{
		if (bT)
			Temps.push_back(sequence[i]);
		else
			Temps.push_back(sequence[i] * -1);
		
		bT = !bT;
	}


	if (g_DP[0] < Temps[0])
		g_DP[0] = Temps[0];

	for (int i = 1; i < Temps.size(); ++i)
	{
		g_DP[i] = max(g_DP[i - 1] + Temps[i], Temps[i]);
	}
	long long iMax = 0;
	for (int i = 0; i < Temps.size(); ++i)
	{
		if (g_DP[i] > iMax)
			iMax = g_DP[i];
	}
	answer = iMax;



	vector<long long> Temps1;

	bT = true;
	for (int i = 0; i < sequence.size(); ++i)
	{
		if (bT)
			Temps1.push_back(sequence[i]);
		else
			Temps1.push_back(sequence[i] * -1);

		bT = !bT;
	}

	g_DP[0] = 0;
	if (g_DP[0] < Temps1[0])
		g_DP[0] = Temps1[0];

	for (int i = 1; i < Temps1.size(); ++i)
	{
		g_DP[i] = max(g_DP[i - 1] + Temps1[i], Temps1[i]);
	}
	iMax = 0;
	for (int i = 0; i < Temps1.size(); ++i)
	{
		if (g_DP[i] > iMax)
			iMax = g_DP[i];
	}
	if (answer < iMax)
		answer = iMax;


	return answer;
}
