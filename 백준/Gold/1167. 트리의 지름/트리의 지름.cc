#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
	int iNum = 0;
	int iDis = 0;

	Node() {};
	Node(int num, int dis) : iNum(num), iDis(dis) {}
};

int g_iN;
int g_iAns = 0;
vector<list<Node>> g_Matrix(100001);
int g_iMaxNodeDis[100001] = { 0 };

void Reset()
{
	for (int i = 0; i <= g_iN; ++i)
	{
		g_iMaxNodeDis[i] = -1;
	}
}

int BFS(int iStartNode)
{
	queue<Node> iQs;
	iQs.push(Node(iStartNode, 0));
	g_iMaxNodeDis[iStartNode] = 0;

	int iMaxNode = 0;

	while (!iQs.empty())
	{
		Node CurNode = iQs.front();
		iQs.pop();

		for (auto NextNode : g_Matrix[CurNode.iNum])
		{
			if (g_iMaxNodeDis[NextNode.iNum] == -1)
			{
				int iTDis = CurNode.iDis + NextNode.iDis;

	/*			if (g_iMaxNodeDis[NextNode.iNum] > iTDis)
					continue;*/
				g_iMaxNodeDis[NextNode.iNum] = iTDis;

				iQs.push(Node(NextNode.iNum, iTDis));

				if (g_iAns < iTDis)
				{
					g_iAns = iTDis;
					iMaxNode = NextNode.iNum;
				}
					
			}
		}
	}

	return iMaxNode;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> g_iN;
	for (int i = 0; i < g_iN; ++i)
	{
		int iNode;
		cin >> iNode;

		while (true)
		{
			int inNode, iDis;
			cin >> inNode;

			if (inNode == -1)
				break;

			cin >> iDis;

			g_Matrix[iNode].push_back(Node(inNode, iDis));
		}
	}


	Reset();
	int iNode = BFS(1); // 임의의 정점 x = 1
	Reset();
	BFS(iNode); // 정점 y

	cout << g_iAns;

	return 0;
}