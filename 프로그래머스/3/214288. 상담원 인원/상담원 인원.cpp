#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

class Func
{
public:
	bool operator()(int L, int R)
	{
		return L > R;
	}
};

int g_iK, g_iN;
vector<pair<int, int>> g_Reqes[6];
int g_Ns[6] = { 0 };

int g_Ans = INT_MAX;

// iS 번째 유형 상담 진행
int Go(int iS)
{
	int iWaitTime = 0;
	int iN = g_Ns[iS];
	priority_queue<int, vector<int>, Func> Qs;

	for (int i = 0; i < g_Reqes[iS].size(); ++i)
	{
		// 상담원이 있다
		if (iN > 0)
		{
			// 시작 시간이 제일 빠른 애
			int iEndTime = g_Reqes[iS][i].first + g_Reqes[iS][i].second;
			Qs.push(iEndTime);

			--iN;
		}
		else // 없다
		{
			// 제일 빨리 끝나는 애의 시간
			int iMinTime = Qs.top();
			Qs.pop();
			int iWTime = iMinTime - g_Reqes[iS][i].first;
			if (iWTime < 0)
				iWTime = 0;
			
			iWaitTime += iWTime;

			int iEndTime = g_Reqes[iS][i].first + g_Reqes[iS][i].second + iWTime;
			Qs.push(iEndTime);
		}

	}


	// 기다린 시간
	return iWaitTime;
}


void DFS(int iDepth, int iSum)
{
	if (iSum > g_iN || iDepth > g_iK + 1)
		return;

	if (iDepth == g_iK + 1)
	{
		if (iSum != g_iN)
			return;

		int iWaitTime = 0;
		for (int i = 1; i <= g_iK; ++i)
		{
			iWaitTime += Go(i);
		}

		if (g_Ans > iWaitTime)
		{
			g_Ans = iWaitTime;
		}

		return;
	}

	for (int i = 1; i <= g_iN; ++i)
	{
		g_Ns[iDepth] = i;
		DFS(iDepth + 1, iSum + i);
	}

}


int solution(int k, int n, vector<vector<int>> reqs) {
	int answer = 0;

	g_iK = k;
	g_iN = n;

	for (int i = 0; i < reqs.size(); ++i)
	{
		g_Reqes[reqs[i][2]].push_back({ reqs[i][0], reqs[i][1] });
	}

	for (int i = 1; i <= g_iK; ++i)
	{
		sort(g_Reqes[i].begin(), g_Reqes[i].end());
	}



	DFS(1, 0);



	return g_Ans;
}
