#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct tagValue
{
	bool m_bCNum = false;
	int m_iRank = 0;

	tagValue() {};
	tagValue(bool bB, int iR) : m_bCNum(bB), m_iRank(iR) {};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	vector<int> iAnss;
	for (int t = 0; t < T; ++t)
	{

		list<tagValue> iQs;

		int iN, iC;
		cin >> iN >> iC;
		for (int i = 0; i < iN; ++i)
		{
			int iTemp; cin >> iTemp;

			if (i == iC)
			{
				iQs.push_back(tagValue(true, iTemp));
			}
			else
			{
				iQs.push_back(tagValue(false, iTemp));
			}

		}

		int iAnsCount = 0;
		while (!iQs.empty())
		{
			bool bPass = false;
			tagValue iCurNum = iQs.front();

			list<tagValue>::iterator iter = iQs.begin();
			++iter;
			for (; iter != iQs.end(); ++iter)
			{
				if (iCurNum.m_iRank < (*iter).m_iRank)
				{
					tagValue iTemp = iQs.front();
					iQs.pop_front();

					iQs.push_back(iTemp);
					bPass = true;
					break;
				}
			}

			if (!bPass)
			{
				tagValue iTemp = iQs.front();
				iQs.pop_front();
				++iAnsCount;

				if (iTemp.m_bCNum)
				{
					iAnss.push_back(iAnsCount);
					break;
				}
			}
		}

	}

	for (int i = 0; i < iAnss.size(); ++i)
	{
		cout << iAnss[i] << endl;
	}

	
	return 0;
}