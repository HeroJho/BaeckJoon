#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include "limits.h"

using namespace std;


class Fuc
{
public:
	bool operator()(pair<int , int> L, pair<int ,int> R)
	{
		return L.second > R.second;
	}
};

int g_iN;
vector<list<pair<int, int>>> g_Matrix(10001);
int g_iDiss[10001] = { INT_MAX };

void Reset()
{
	for (int i = 1; i <= g_iN; ++i)
	{
		g_iDiss[i] = INT_MAX;
	}
}

void Dji(int iStart)
{
	Reset();
	priority_queue<pair<int ,int>, vector<pair<int, int>>, Fuc> Qs;
	Qs.push({iStart, 0});
	g_iDiss[iStart] = 0;

	while (!Qs.empty())
	{
		pair<int ,int> Node = Qs.top();
		Qs.pop();

		if (g_iDiss[Node.first] < Node.second)
			continue;


		for (auto nNode : g_Matrix[Node.first])
		{
			if (g_iDiss[nNode.first] == INT_MAX)
			{
				int inDis = Node.second + nNode.second;

				if (g_iDiss[nNode.first] < inDis)
					continue;

				g_iDiss[nNode.first] = inDis;
				Qs.push({ nNode.first, inDis });

			}

		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Dji 만들기
	// 1을 기준으로 돌리기 (가장 먼 거리의 노드 찾기)
	// 가장 먼 거리의 노드로 돌리기
	// 정답
	cin >> g_iN;

	if (g_iN == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < g_iN - 1; ++i)
	{
		int iStart, iEnd, iDis;
		cin >> iStart >> iEnd >> iDis;
		g_Matrix[iStart].push_back({ iEnd, iDis });
		g_Matrix[iEnd].push_back({ iStart, iDis });
	}

	Dji(1);

	int iMaxDis = 0;
	int iMaxIndex = 0;
	for (int i = 1; i <= g_iN; ++i)
	{
		if (iMaxDis < g_iDiss[i])
		{
			iMaxIndex = i;
			iMaxDis = g_iDiss[i];
		}
			
	}

	Dji(iMaxIndex);
	iMaxDis = 0;
	iMaxIndex = 0;
	for (int i = 1; i <= g_iN; ++i)
	{
		if (iMaxDis < g_iDiss[i])
		{
			iMaxIndex = i;
			iMaxDis = g_iDiss[i];
		}
	
	}

	cout << iMaxDis;

	return 0;
}