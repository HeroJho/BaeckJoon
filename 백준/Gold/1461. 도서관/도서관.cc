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

	// 정렬한다
	// -39 -37 -29 -28 -6 2 11

	// 좌우 선택 (작은거 먼저)
	//	작은거는 
	//		멀리서부터 처리
	//  먼거는
	//		먼거 남겨두고 멀리서부터 처리

	int iN, iM;
	cin >> iN >> iM;
	vector<int> LeftInputs;
	vector<int> RightInputs;
	for (int i = 0; i < iN; ++i)
	{
		int iTemp;
		cin >> iTemp;
		if (iTemp < 0)
			LeftInputs.push_back(iTemp * -1);
		else
			RightInputs.push_back(iTemp);

	}


	int iAns = 0;
	if (LeftInputs.empty())
	{
		sort(RightInputs.begin(), RightInputs.end());

		iAns += RightInputs.back();
		RightInputs.pop_back();

		for (int i = 1; i < iM; ++i)
		{
			if (!RightInputs.empty())
				RightInputs.pop_back();
		}

		while (!RightInputs.empty())
		{
			int iMax = RightInputs.back();
			iAns += RightInputs.back() * 2;
			RightInputs.pop_back();

			for (int i = 1; i < iM; ++i)
			{
				if (RightInputs.empty())
					break;

				if (iMax >= RightInputs.back())
					RightInputs.pop_back();
			}

		}

	}
	else if(RightInputs.empty())
	{
		sort(LeftInputs.begin(), LeftInputs.end());

		iAns += LeftInputs.back();
		LeftInputs.pop_back();

		for (int i = 1; i < iM; ++i)
		{
			if (!LeftInputs.empty())
				LeftInputs.pop_back();
		}

		while (!LeftInputs.empty())
		{
			int iMax = LeftInputs.back();
			iAns += LeftInputs.back() * 2;
			LeftInputs.pop_back();

			for (int i = 1; i < iM; ++i)
			{
				if (LeftInputs.empty())
					break;

				if (iMax >= LeftInputs.back())
					LeftInputs.pop_back();
			}

		}

	}
	else
	{
		sort(LeftInputs.begin(), LeftInputs.end());
		sort(RightInputs.begin(), RightInputs.end());


		if (LeftInputs.back() > RightInputs.back())
		{
			iAns += LeftInputs.back();
			LeftInputs.pop_back();

			for (int i = 1; i < iM; ++i)
			{
				if (!LeftInputs.empty())
					LeftInputs.pop_back();
			}
		}
		else
		{
			iAns += RightInputs.back();
			RightInputs.pop_back();

			for (int i = 1; i < iM; ++i)
			{
				if (!RightInputs.empty())
					RightInputs.pop_back();
			}
		}




		while (!LeftInputs.empty())
		{
			int iMax = LeftInputs.back();
			iAns += LeftInputs.back() * 2;
			LeftInputs.pop_back();

			for (int i = 1; i < iM; ++i)
			{
				if (LeftInputs.empty())
					break;

				if (iMax >= LeftInputs.back())
					LeftInputs.pop_back();
			}

		}

		while (!RightInputs.empty())
		{
			int iMax = RightInputs.back();
			iAns += RightInputs.back() * 2;
			RightInputs.pop_back();

			for (int i = 1; i < iM; ++i)
			{
				if (RightInputs.empty())
					break;

				if (iMax >= RightInputs.back())
					RightInputs.pop_back();
			}

		}
	}




	cout << iAns;


	return 0;
}