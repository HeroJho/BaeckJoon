#include <string>
#include <vector>
#include "limits.h"

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;

	vector<int> Sums;
	Sums.push_back(0);
	int iSum = 0;

	pair<int, int> Temp = { 0, 0 };
	for (int i = 0; i < sequence.size(); ++i)
	{
		iSum += sequence[i];
		Sums.push_back(iSum);

		if (sequence[i] <= k)
		{
			Temp.first = i;
			Temp.second = i + 1;
		}
	}

	bool bT = false;
	while(true)
	{
		if (bT)
		{
			--Temp.first;
			--Temp.second;
			if (Temp.first < 0)
			{
				++Temp.first;
				++Temp.second;
				break;
			}
				

			int iTempSum = Sums[Temp.second] - Sums[Temp.first];
			if (iTempSum == k)
				continue;


			++Temp.first;
			++Temp.second;
			break;
		}

		int iTempSum = Sums[Temp.second] - Sums[Temp.first];
		if (iTempSum > k)
		{
			--Temp.second;
		}
		else if(iTempSum < k)
		{
			--Temp.first;
		}
		else if(iTempSum == k)
		{
			bT = true;
		}

	}


	answer.push_back(Temp.first);
	answer.push_back(Temp.second - 1);

	return answer;
}