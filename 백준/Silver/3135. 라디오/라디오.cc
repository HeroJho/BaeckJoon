#include <iostream>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int From, To, N, Gap, Idx = 100;
	int Arr[7];

	cin >> From >> To >> N;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	Gap = abs(To - From);

	for (int i = 0; i < N; i++)
	{
		int Tmp = abs(Arr[i] - To);
		if (Gap > Tmp)
		{
			Gap = Tmp;
			Idx = i;
		}
	}
	if (Idx != 100)
		cout << abs(Arr[Idx] - To) + 1;
	else
		cout << abs(To - From);
}