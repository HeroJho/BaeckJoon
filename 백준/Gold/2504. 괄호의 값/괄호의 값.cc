#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string Inputs;
	cin >> Inputs;

	vector<char> Stack;
	vector<int> NumStack;
	
	for (int i = 0; i < Inputs.length(); ++i)
	{
		char Cur = Inputs[i];

		if (Cur == '(')
		{
			Stack.push_back(Cur);
		}
		else if (Cur == ')')
		{
			// (가 나올 때 까지 뺀다
			int Sum = 0;
			while (true)
			{

				// 여는 짝이 없다
				if (Stack.empty())
				{
					cout << 0;
					return 0;
				}

				char Back = Stack.back();
				Stack.pop_back();

				if (Back == '(')
				{
					if (Sum == 0)
						Sum = 2;
					else
						Sum *= 2;

					Stack.push_back('*');
					NumStack.push_back(Sum);

					break;
				}
				else if(Back == '*')
				{
					
					if (NumStack.empty())
					{
						cout << 0;
						return 0;
					}

					Sum += NumStack.back();
					NumStack.pop_back();
				}
				else // 여는걸 찾는데, 여는것도 아니고, 숫자도 아닌 다른 괄호
				{
					cout << 0;
					return 0;
				}

			}

		} 
		else if (Cur == '[')
		{
			Stack.push_back(Cur);
		}
		else if (Cur == ']')
		{
			// (가 나올 때 까지 뺀다
			int Sum = 0;
			while (true)
			{

				// 여는 짝이 없다
				if (Stack.empty())
				{
					cout << 0;
					return 0;
				}

				char Back = Stack.back();
				Stack.pop_back();

				if (Back == '[')
				{
					if (Sum == 0)
						Sum = 3;
					else
						Sum *= 3;

					Stack.push_back('*');
					NumStack.push_back(Sum);

					break;
				}
				else if (Back == '*')
				{

					if (NumStack.empty())
					{
						cout << 0;
						return 0;
					}

					Sum += NumStack.back();
					NumStack.pop_back();
				}
				else // 여는걸 찾는데, 여는것도 아니고, 숫자도 아닌 다른 괄호
				{
					cout << 0;
					return 0;
				}

			}

		}

	}

	for (int i = 0; i < Stack.size(); ++i)
	{
		char Cur = Stack[i];
		if (Cur != '*')
		{
			cout << 0;
			return 0;
		}
	}


	int Ans = 0;
	for (int i = 0; i < NumStack.size(); ++i)
	{
		Ans += NumStack[i];
	}

	cout << Ans;


	return 0;
}
