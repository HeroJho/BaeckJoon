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

	string sNum;
	int iB;
	vector<int> iBs;
	cin >> sNum;
	cin >> iB;
	for (int i = 0; i < iB; ++i)
	{
		int iTemp; cin >> iTemp;
		iBs.push_back(iTemp);
	}


	int iMinCnt = abs(100 - stoi(sNum));
	for (int i = 0; i < 1000000; ++i)
	{
		string sTempNum = to_string(i);
		bool bBr = false;
		for (int j = 0; j < sTempNum.length(); ++j)
		{
			if (find(iBs.begin(), iBs.end(), sTempNum[j] - '0') != iBs.end())
			{
				bBr = true;
			}
		}

		// 채널에 고장난 곳이 없다.
		if (!bBr)
		{
			// 카운트 수
			int iTempCnt = sTempNum.length() + abs(i - stoi(sNum));
			iMinCnt = min(iMinCnt, iTempCnt);
		}
	}

	cout << iMinCnt;


	return 0;
}