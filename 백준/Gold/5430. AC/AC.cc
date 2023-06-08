#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int iT;
	cin >> iT;
	vector<string> Anss;
	for (int t = 0; t < iT; ++t)
	{
		vector<int> iTemps();

		string sFunc;
		int iN = 0;
		string sNum;
		cin >> sFunc;
		cin >> iN;
		cin >> sNum;

		list<int> iNums;
		string sTemp = "";
		for (int i = 1; i < sNum.length(); ++i)
		{
			char cTemp = sNum[i];
			if ((cTemp == ',' || cTemp == ']') && sTemp.length() > 0)
			{
				int iNum = stoi(sTemp);
				sTemp = "";
				iNums.push_back(iNum);
			}
			else
			{
				sTemp += cTemp;
			}
		}

		bool bIsError = false;
		bool bReverse = false;
		for (int i = 0; i < sFunc.length(); ++i)
		{
			if (sFunc[i] == 'R')
			{
				bReverse = !bReverse;
			}
			else if (sFunc[i] == 'D')
			{
				if (iNums.empty())
				{
					bIsError = true;
					break;
				}
				else
				{
					if (bReverse)
						iNums.pop_back();
					else
						iNums.pop_front();
				}
			}
		}

		if (bReverse)
			reverse(iNums.begin(), iNums.end());

		if (bIsError)
		{
			Anss.push_back("error");
		}
		else
		{
			string sAns = "";
			sAns += '[';
			int iCount = 0;
			for (auto iNum : iNums)
			{
				++iCount;
				if (iCount != iNums.size())
				{
					sAns += to_string(iNum);
					sAns += ',';
				}
				else
				{
					sAns += to_string(iNum);
				}
			}
			sAns += ']';
			Anss.push_back(sAns);
		}
	}

	for (int i = 0; i < Anss.size(); ++i)
	{
		cout << Anss[i] << endl;
	}


	return 0;
}