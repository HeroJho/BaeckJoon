#include <string>
#include <vector>
#include "limits.h"

using namespace std;

vector<int> g_Picks;
int g_Ans = INT_MAX;
int g_Count = 0;

void DFS(vector<int>& picks, vector<string>& minerals, int iCount)
{
	if (iCount == g_Count)
	{
		// 모든 괭이 배열 완료
		int answer = 0;
		int iHp = 0;
		string sPick = "";
		int iIndex = 0;
		for (auto sS : minerals)
		{
			if (iHp == 0)
			{
				if (g_Picks.size() <= iIndex)
					break;

				if (g_Picks[iIndex] == 0)
					sPick = "diamond";
				else if (g_Picks[iIndex] == 1)
					sPick = "iron";
				else if (g_Picks[iIndex] == 2)
					sPick = "stone";

				++iIndex;
				iHp = 5;

			}

			if (sS == "diamond")
			{
				if (sPick == "diamond")
					answer += 1;
				else if (sPick == "iron")
					answer += 5;
				else if (sPick == "stone")
					answer += 25;
			}
			else if (sS == "iron")
			{
				if (sPick == "diamond")
					answer += 1;
				else if (sPick == "iron")
					answer += 1;
				else if (sPick == "stone")
					answer += 5;
			}
			else if (sS == "stone")
			{
				if (sPick == "diamond")
					answer += 1;
				else if (sPick == "iron")
					answer += 1;
				else if (sPick == "stone")
					answer += 1;
			}

			--iHp;
		}


		if (answer < g_Ans)
			g_Ans = answer;

	}



	for (int i = 0; i < 3; ++i)
	{
		if (picks[i] <= 0)
			continue;

		--picks[i];
		g_Picks.push_back(i);

		DFS(picks, minerals, iCount + 1);

		++picks[i];
		g_Picks.pop_back();

	}
}

int solution(vector<int> picks, vector<string> minerals) {

	g_Count = picks[0] + picks[1] + picks[2];
	DFS(picks, minerals, 0);

	return g_Ans;
}