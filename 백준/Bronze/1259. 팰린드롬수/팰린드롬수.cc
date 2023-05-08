#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// 짝수면 q가 비어있어야하고
	// 홀수면 q에 하나의 원소만 남는다.
	vector<string> sAns;
	while (1)
	{
		string sTemp;
		cin >> sTemp;
		if (sTemp == "0")
			break;

		for (int i = 0; i < sTemp.length(); ++i)
		{
			int iFront = i;
			int iBack = sTemp.length() -1 -i;
			if (iFront >= iBack)
			{
				sAns.push_back("yes");
				break;
			}
			else if(sTemp[iFront] != sTemp[iBack])
			{
				sAns.push_back("no");
				break;
			}
		}
	}

	for (int i = 0; i < sAns.size(); ++i)
	{
		cout << sAns[i] << endl;
	}

	return 0;
}