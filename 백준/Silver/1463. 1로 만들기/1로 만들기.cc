#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


struct tagData
{
	int m_iNum = 0;
	int m_iDapth = 0;
	tagData() {};
	tagData(int iNum, int iDapth) : m_iNum(iNum), m_iDapth(iDapth) {};
};

int BFS(int iNum)
{
	vector<bool> iDpTable(iNum, false);

	list<tagData> iQs;

	tagData Data(iNum, 0);
	iQs.push_back(Data);

	int iCount = 0;
	while (true)
	{
		tagData iCurNum = iQs.front();
		iQs.pop_front();
		if (iCurNum.m_iNum == 1)
		{
			Data = iCurNum;
			break;
		}

		int iTemp = 0;
		if (iCurNum.m_iNum % 3 == 0)
		{
			iTemp = iCurNum.m_iNum / 3;
			if (iDpTable[iTemp] == false)
			{
				iQs.push_back(tagData(iTemp, iCurNum.m_iDapth + 1));
				iDpTable[iTemp] = true;
			}
		}
		if (iCurNum.m_iNum % 2 == 0)
		{
			iTemp = iCurNum.m_iNum / 2;
			if (iDpTable[iTemp] == false)
			{
				iQs.push_back(tagData(iCurNum.m_iNum / 2, iCurNum.m_iDapth + 1));
				iDpTable[iTemp] = true;
			}
		}
		if (iCurNum.m_iNum - 1 > 0)
		{
			iTemp = iCurNum.m_iNum - 1;
			if (iDpTable[iTemp] == false)
			{
				iQs.push_back(tagData(iCurNum.m_iNum - 1, iCurNum.m_iDapth + 1));
				iDpTable[iTemp] = true;
			}
		}

	}

	return Data.m_iDapth;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iNum;
	cin >> iNum;

	int iCount = BFS(iNum);
	cout << iCount;

	return 0;
}