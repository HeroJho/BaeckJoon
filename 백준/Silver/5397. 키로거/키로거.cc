#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	list<char> List;
	list<char>::iterator t;

	string L;
	cin >> T;

	for (int i = 0; i < T; i++) 
	{
		cin >> L;

		List.clear();
		t = List.begin();

		for (int j = 0; j < L.length(); j++) 
		{
			if (L[j] == '<' && t != List.begin()) 
				t--;
			else if (L[j] == '>' && t != List.end()) 
				t++;
			else if (L[j] == '-' && t != List.begin()) 
				t = List.erase(--t);
			else if (L[j] != '<' && L[j] != '>' && L[j] != '-') 
				List.insert(t, L[j]);
		}

		for (t = List.begin(); t != List.end(); t++)
			cout << *t;

		cout << '\n';
	}

	return 0;
}