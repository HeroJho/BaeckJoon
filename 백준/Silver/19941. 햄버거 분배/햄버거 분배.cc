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

	// 최대한 왼쪽 끝에 있는 햄버거를 먹는다.
	// 사람이 연속으로 등장해서 왼쪽 햄버거를 먹지 못 한다면 오른쪽 햄버거를 먹는다.
	// 오른쪽은 가장 자까운 햄버거를 먹는다.

	int iN, iM;
	cin >> iN >> iM;
	string Inputs;
	cin >> Inputs;

	int iAns = 0;

	int iH = -1;
	int iP = -1;
	bool bH = false, bP = false;
	while(true)
	{
		if (!bP)
		{
			for (int h = iP + 1; h < iN; ++h)
			{
				if (Inputs[h] == 'P')
				{
					iP = h;
					bP = true;
					break;
				}
			}
		}
		if (!bH)
		{
			for (int h = iH + 1; h < iN; ++h)
			{
				if (Inputs[h] == 'H')
				{
					iH = h;
					bH = true;
					break;
				}
			}
		}

		if (!bP || !bH)
			break;

		
		int iDis = iP - iH;
		if (abs(iDis) > iM)
		{
			if (iDis > 0)
				bH = false;
			else
				bP = false;
		}
		else
		{
			++iAns;
			bP = false;
			bH = false;
		}
			

	}

	cout << iAns;

	return 0;
}