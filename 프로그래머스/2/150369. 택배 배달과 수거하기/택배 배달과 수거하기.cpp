#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = -1;

	int iStartIndex = deliveries.size() - 1;
	for (int i = iStartIndex; i >= 0; --i)
	{
		if (deliveries[i] == 0 && pickups[i] == 0)
		{
			--iStartIndex;
			continue;
		}

		break;
	}
	if (iStartIndex < 0)
	{
		iStartIndex = 0;
		return 0;
	}
		


	answer = 0;
	while (true)
	{
		int iTempCap = cap;
		for (int i = iStartIndex; i >= 0; --i)
		{
			if (iTempCap == 0)
				break;
			
			if (deliveries[i] == 0)
				continue;


			int iDis = deliveries[i] - iTempCap;
			if (iDis >= 0)
			{
				deliveries[i] = iDis;
				iTempCap = 0;
			}
			else
			{
				iTempCap -= deliveries[i];
				deliveries[i] = 0;
			}

		}
		iTempCap = cap;
		for (int i = iStartIndex; i >= 0; --i)
		{
			if (iTempCap == 0)
				break;

			if (pickups[i] == 0)
				continue;


			int iDis = pickups[i] - iTempCap;
			if (iDis >= 0)
			{
				pickups[i] = iDis;
				iTempCap = 0;
			}
			else
			{
				iTempCap -= pickups[i];
				pickups[i] = 0;
			}

		}

		answer += ((long long)iStartIndex + 1) * 2;

		int iTemp = iStartIndex;
		for (int i = iTemp; i >= 0; --i)
		{
			if (deliveries[i] == 0 && pickups[i] == 0)
			{
				--iTemp;
				continue;
			}

			break;
		}
		iStartIndex = iTemp;
		if (iStartIndex < 0)
			break;

	}



	return answer;
}