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

	string iL, iR;
	cin >> iL >> iR;

	// 자릿수 체크
	if (iL.length() != iR.length())
	{// 다르다면
		cout << 0;
	}
	else
	{// 같다면
		int iCount = 0;
		for (int i = 0; i < iL.length(); ++i)
		{
			if (iL[i] == iR[i])
			{
				if (iL[i] == '8' && iR[i] == '8')
				{
					++iCount;
				}

				continue;
			}



			break;
		}

		cout << iCount;
	}


	return 0;
}