#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int g_iN = 0;
int g_Map[100] = { 0 };
int g_iAns = 0;

void Shape1()
{
	g_iAns += g_iN;

	for (int i = 0; i < g_iN - 3; ++i)
	{
		if (g_Map[i] == g_Map[i + 1] && g_Map[i + 1] == g_Map[i + 2] && g_Map[i + 2] == g_Map[i + 3])
		{
			++g_iAns;
		}

	}

}

void Shape2()
{
	for (int i = 0; i < g_iN - 1; ++i)
	{
		if (g_Map[i] == g_Map[i + 1])
		{
			++g_iAns;
		}

	}

}

void Shape3()
{
	for (int i = 0; i < g_iN - 2; ++i)
	{
		if (g_Map[i] == g_Map[i + 1] && g_Map[i + 2] == g_Map[i + 1] + 1)
		{
			++g_iAns;
		}

	}
	for (int i = 0; i < g_iN - 1; ++i)
	{
		if (g_Map[i] == g_Map[i + 1] + 1)
		{
			++g_iAns;
		}
	}

}

void Shape4()
{
	for (int i = 0; i < g_iN - 2; ++i)
	{
		if (g_Map[i + 1] == g_Map[i + 2] && g_Map[i] == g_Map[i + 1] + 1)
		{
			++g_iAns;
		}

	}
	for (int i = 0; i < g_iN - 1; ++i)
	{
		if (g_Map[i] + 1 == g_Map[i + 1])
		{
			++g_iAns;
		}

	}

}

void Shape5()
{
	for (int i = 0; i < g_iN - 2; ++i)
	{
		if (g_Map[i] == g_Map[i + 1] && g_Map[i + 1] == g_Map[i + 2])
		{
			++g_iAns;
		}
		else if (g_Map[i] == g_Map[i + 1] + 1 && g_Map[i + 1] + 1 == g_Map[i + 2])
		{
			++g_iAns;
		}

	}
	for (int i = 0; i < g_iN - 1; ++i)
	{
		if (g_Map[i] == g_Map[i + 1] + 1)
		{
			++g_iAns;
		}
		else if (g_Map[i] + 1 == g_Map[i + 1])
		{
			++g_iAns;
		}
	}

}

void Shape6()
{
	for (int i = 0; i < g_iN - 2; ++i)
	{
		if (g_Map[i] == g_Map[i + 1] && g_Map[i + 1] == g_Map[i + 2])
		{
			++g_iAns;
		}
		else if (g_Map[i] + 1 == g_Map[i + 1] && g_Map[i + 1] == g_Map[i + 2])
		{
			++g_iAns;
		}

	}
	for (int i = 0; i < g_iN - 1; ++i)
	{
		if (g_Map[i] == g_Map[i + 1])
		{
			++g_iAns;
		}
		else if (g_Map[i] == g_Map[i + 1] + 2)
		{
			++g_iAns;
		}
	}

}

void Shape7()
{
	for (int i = 0; i < g_iN - 2; ++i)
	{
		if (g_Map[i] == g_Map[i + 1] && g_Map[i + 1] == g_Map[i + 2])
		{
			++g_iAns;
		}
		else if (g_Map[i] == g_Map[i + 1] && g_Map[i + 1] == g_Map[i + 2] + 1)
		{
			++g_iAns;
		}

	}
	for (int i = 0; i < g_iN - 1; ++i)
	{
		if (g_Map[i] == g_Map[i + 1])
		{
			++g_iAns;
		}
		else if (g_Map[i] + 2 == g_Map[i + 1])
		{
			++g_iAns;
		}
	}

}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int iC;
	cin >> g_iN >> iC;
	for (int i = 0; i < g_iN; ++i)
	{
		cin >> g_Map[i];
	}

	if (iC == 1)
	{
		Shape1();
	}
	else if (iC == 2)
	{
		Shape2();
	}
	else if (iC == 3)
	{
		Shape3();
	}
	else if (iC == 4)
	{
		Shape4();
	}
	else if (iC == 5)
	{
		Shape5();
	}
	else if (iC == 6)
	{
		Shape6();
	}
	else if (iC == 7)
	{
		Shape7();
	}

	cout << g_iAns;

	return 0;
}