#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

struct tagNum
{
	int iNum = 0;
	int iCount = -1;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN = 0; cin >> iN;
	vector<int> iNums;

	int iSumNum = 0;
	int iMinNum = 5000;
	int iMaxNum = -5000;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp = 0; cin >> iTemp;
		iNums.push_back(iTemp);

		iSumNum += iTemp;
		if (iMinNum > iTemp)
			iMinNum = iTemp;
		if (iMaxNum < iTemp)
			iMaxNum = iTemp;
	}

	int iAvg = 0;

	iAvg = round((float)iSumNum / iN);

	int iRang = iMaxNum - iMinNum;

	sort(iNums.begin(), iNums.end());
	int iMid = iNums[iNums.size() / 2];

	map<int, int> iMaps;
	for (int i = 0; i < iNums.size(); ++i)
	{
		map<int, int>::iterator iter = iMaps.find(iNums[i]);
		if (iter != iMaps.end())
		{
			(*iter).second++;
		}
		else
		{
			iMaps.insert({iNums[i], 1});
		}
	}

	int iCount = 0;
	int iMaxCount = 0;
	for (auto& iter : iMaps)
	{
		if (iMaxCount < iter.second)
		{
			iMaxCount = iter.second;
		}
	}
	vector<tagNum> iTempDatas;
	for (auto& iter : iMaps)
	{
		if (iMaxCount == iter.second)
		{
			tagNum Temp; 
			Temp.iNum = iter.first;
			Temp.iCount = iter.second;
			iTempDatas.push_back(Temp);
		}
	}

	if (iTempDatas.size() >= 2)
	{
		iCount = iTempDatas[1].iNum;
	}
	else
	{
		iCount = iTempDatas[0].iNum;
	}

	//cout << '\n';
	cout << iAvg << '\n';
	cout << iMid << '\n';
	cout << iCount << '\n';
	cout << iRang;


	return 0;
}