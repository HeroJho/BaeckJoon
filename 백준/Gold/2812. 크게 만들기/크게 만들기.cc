#include <iostream>
#include <stack>
#include <string>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iCount;
	cin >> iN >> iCount;
	string sInput;
	cin >> sInput;

	stack<int> Qs;
	// 2 1     21
	for (int i = 0; i < iN; ++i)
	{
		int iNum = sInput[i] - '0';

		if (iCount == 0)
		{
			Qs.push(iNum);
		}

		while (iCount > 0)
		{

			if (!Qs.empty())
			{
				if (Qs.top() < iNum)
				{
					Qs.pop();
					--iCount;

					if (iCount == 0)
					{
						Qs.push(iNum);
					}
				}
				else
				{
					Qs.push(iNum);
					break;
				}
			}
			else
			{
				Qs.push(iNum);
				break;
			}
		}
	}

	if (iCount > 0)
	{
		for (int i = 0; i < iCount; ++i)
		{
			Qs.pop();
		}
	}

	int iSize = Qs.size();
	stack<int> Ss;
	for (int i = 0; i < iSize; ++i)
	{
		Ss.push(Qs.top());
		Qs.pop();
	}
	for (int i = 0; i < iSize; ++i)
	{
		cout << Ss.top();
		Ss.pop();
	}


	return 0;
}