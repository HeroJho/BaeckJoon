#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "limits.h"

using namespace std;

struct Data
{
	int iR, iG, iB;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	vector<Data> Houses;
	int iDPs[1001][3] = { INT_MAX };
	for (int i = 0; i < iN; ++i)
	{
		Data data; cin >> data.iR >> data.iG >> data.iB;
		Houses.push_back(data);
	}

	iDPs[0][0] = Houses[0].iR;
	iDPs[0][1] = Houses[0].iG;
	iDPs[0][2] = Houses[0].iB;

	for (int i = 1; i < iN; ++i)
	{
		iDPs[i][0] = min(iDPs[i - 1][1], iDPs[i - 1][2]) + Houses[i].iR;
		iDPs[i][1] = min(iDPs[i - 1][0], iDPs[i - 1][2]) + Houses[i].iG;
		iDPs[i][2] = min(iDPs[i - 1][0], iDPs[i - 1][1]) + Houses[i].iB;
	}

	int iMinTemp = min(iDPs[iN - 1][0], iDPs[iN - 1][1]);
	iMinTemp = min(iMinTemp, iDPs[iN - 1][2]);
	cout << iMinTemp;

	return 0;
}