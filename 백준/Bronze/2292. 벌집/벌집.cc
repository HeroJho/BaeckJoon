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

	// 1  2    3    4    5
	// 0  6   12   18    24
	// 1 2~7 8~19 20~37 38~61

	int iNum;
	cin >> iNum;
	if (iNum == 1)
	{
		cout << 1;
		return 0;
	}

	int iEndNum = 1;
	int i6Num = 0;
	int iCount = 1;
	while (true)
	{
		int iPreEndNum = iEndNum;
		i6Num += 6;
		iEndNum = i6Num + iPreEndNum;
		++iCount;
		if (iNum <= iEndNum)
		{
			cout << iCount;
			return 0;
		}
	}


	return 0;
}