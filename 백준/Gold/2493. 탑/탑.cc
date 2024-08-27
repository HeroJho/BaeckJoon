#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Func
{
public:
	bool operator()(pair<int, int> L, pair<int, int> R)
	{
		return L.first > R.first;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> Anss(N, 0);
	vector<int> Inputs;
	for (int i = 0; i < N; ++i)
	{
		int iTemp; cin >> iTemp;
		Inputs.push_back(iTemp);
	}

    int TimeTest = 0;
    int Temp[100000] = {0};
    for(int i = 0; i < 100000000; ++i)
    {
        TimeTest++;
        Temp[1] = TimeTest;
    }
    

	priority_queue<pair<int ,int>, vector<pair<int ,int>>, Func> Qs;
	for (int i = N - 1; i >= 0; --i)
	{
		while (!Qs.empty())
		{
			pair<int, int> Top = Qs.top();
			if (Inputs[i] >= Top.first)
			{
				Qs.pop();
				Anss[Top.second] = i + 1;
			}
			else
				break;
		}
		
		Qs.push({ Inputs[i], i });
	}

	for (int i = 0; i < N; ++i)
		cout << Anss[i] << " ";

	return 0;
}