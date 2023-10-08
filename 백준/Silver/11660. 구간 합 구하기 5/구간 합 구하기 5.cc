#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct Data
{
	pair<int, int> Start, End;
	Data() {};
};

int g_Matrix[1025][1025] = { 0 };
int g_Sum[1025][1025] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	int iAccSum = 0;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iN; ++j)
		{
			cin >> g_Matrix[i][j];
			iAccSum += g_Matrix[i][j];
			g_Sum[i][j] = iAccSum;
		}
	}

	vector<Data> Inputs;
	for (int i = 0; i < iM; ++i)
	{
		Data Temp;
		cin >> Temp.Start.second >> Temp.Start.first;
		cin >> Temp.End.second >> Temp.End.first;
		Inputs.push_back(Temp);
	}

	


	for (int i = 0; i < iM; ++i)
	{
		int iAns = 0;
		for (int y = Inputs[i].Start.second; y <= Inputs[i].End.second; ++y)
		{
			int inX = Inputs[i].Start.first - 1;
			int inY = y;
			if (inX <= 0)
			{
				inX = iN;
				--inY;
				if (inY <= 0)
				{
					inX = 0;
					inY = 0;
				}
			}

			iAns += g_Sum[y][Inputs[i].End.first] - g_Sum[inY][inX];

		}

		cout << iAns << '\n';

	}


	return 0;
}