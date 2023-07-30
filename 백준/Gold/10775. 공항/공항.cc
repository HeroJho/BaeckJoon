#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int g_Parent[MAX] = { 0 };

int FindParent(int iu)
{
	if (g_Parent[iu] == iu)
		return iu;
	return g_Parent[iu] = FindParent(g_Parent[iu]);
}

void Join(int iA, int iB)
{
	int iPA = FindParent(iA);
	int iPB = FindParent(iB);

	if (iPA != iPB)
		g_Parent[iPA] = iPB;
}

int main()
{
	int iG, iP;
	cin >> iG >> iP;
	for (int i = 0; i < MAX; ++i)
	{
		g_Parent[i] = i;
	}

	int iAnsCount = 0;
	for (int i = 0; i < iP; ++i)
	{
		int iNum = 0;
		cin >> iNum;

		if (FindParent(iNum) == 0)
			break;
		else
		{
			++iAnsCount;
			Join(FindParent(iNum), FindParent(iNum) - 1);
		}
	}

	cout << iAnsCount;

	return 0;
}