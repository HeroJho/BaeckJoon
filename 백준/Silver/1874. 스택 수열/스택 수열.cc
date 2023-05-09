#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	// 4 3 6 8 7 5 2 1
	// 1 2 3 4 5 6 7 8
	
	// Pop한 숫자를 다시 넣을 수 없다.

	// 1. 정렬에서 맨 앞 숫자를 스택에 넣는다.
	// 2. 비 정렬 맨 앞 숫자와 스택 숫자를 비교한다.
	// 같다면
	//	다를때 까지 빼서 + -를 기록한다.
	// 다르다면
	//	그냥 진행

	int iN = 0; cin >> iN;
	list<int> iStacks;
	list<int> iNums;
	list<int> iSortNums;
	list<char> cAnss;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp = 0; cin >> iTemp;
		iNums.push_back(iTemp);
	}
	iSortNums = iNums;
	iSortNums.sort();

	// 1 2 5 3 4
	// 1 2 3 4 5

	iStacks.push_back(iSortNums.front());
	iSortNums.pop_front();
	cAnss.push_back('+');
	while (!iNums.empty())
	{
		if (!iStacks.empty() && (iStacks.back() == iNums.front()))
		{
			iNums.pop_front();
			iStacks.pop_back();
			cAnss.push_back('-');
		}
		else
		{
			if (iSortNums.empty())
			{
				cout << "NO";
				return 0;
			}

			iStacks.push_back(iSortNums.front());
			iSortNums.pop_front();
			cAnss.push_back('+');
		}
	}


	for (auto cAns : cAnss)
	{
		cout << cAns << "\n";
	}



	return 0;
}