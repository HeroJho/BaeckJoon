#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> g_Emoticons;
vector<vector<int>> g_Users;

vector<int> g_Discounts;
int g_Dis[4] = { 10, 20, 30, 40 };
pair<int, int> g_Ans;


void Check()
{
	int iAccCount = 0;
	int llTotalSum = 0;

	// 유저 순회
	for (int i = 0; i < g_Users.size(); ++i)
	{
		int llSum = 0;

		// 이모티콘 순회
		for (int k = 0; k < g_Emoticons.size(); ++k)
		{
			if (g_Discounts[k] < g_Users[i][0])
				continue;

			int iDisValue = g_Emoticons[k] - ((g_Discounts[k] / 100.f) * g_Emoticons[k]);
			llSum += iDisValue;

		}
		
		if (llSum >= g_Users[i][1])
			++iAccCount;
		else
			llTotalSum += llSum;

	}


	if (g_Ans.first < iAccCount || (g_Ans.first == iAccCount && g_Ans.second < llTotalSum))
	{
		g_Ans.first = iAccCount;
		g_Ans.second = llTotalSum;
	}
	//else if (g_Ans.first == iAccCount)
	//{
	//	if(g_Ans.second < llTotalSum)
	//		g_Ans.second = llTotalSum;
	//}

}

void DFS(int iDepth)
{
	if (iDepth == g_Emoticons.size())
	{
		// 확인
		Check();

		return;
	}


	for (int i = 0; i < 4; ++i)
	{
		g_Discounts.push_back(g_Dis[i]);
		DFS(iDepth + 1);
		g_Discounts.pop_back();

	}

}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;

	
	// 할인률이 높을 수록 더욱 많은 사람이 물건을 살 수 있다
	// 하지만 이모티콘 플러스에 가입할 사람의 수가 줄어든다.
	
	// 40%를 전부 해본다.

	// 4^7
	g_Users = users;
	g_Emoticons = emoticons;


	DFS(0);
 
	answer.push_back(g_Ans.first);
	answer.push_back(g_Ans.second);

	return answer;
}