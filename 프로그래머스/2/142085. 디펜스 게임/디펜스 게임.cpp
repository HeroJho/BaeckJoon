#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
	int answer = 0;
	
	int iSum = 0;
	priority_queue<int> Qs;
	int iRound = 0;
	for (; iRound < enemy.size(); ++iRound)
	{
		Qs.push(enemy[iRound]);
		iSum += enemy[iRound];
		if (iSum > n)
		{
			if (k > 0 && !Qs.empty())
			{
				int iTop = Qs.top();
				Qs.pop();

				iSum -= iTop;
				--k;
			}
			else
				break;
		}

	}

	return iRound;
}
