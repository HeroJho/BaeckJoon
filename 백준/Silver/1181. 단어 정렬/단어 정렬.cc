#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Func1
{
public:
	bool operator()(string sL, string sR)
	{
		return sL.size() < sR.size();
	}
};

class Func2
{
public:
	bool operator()(string sL, string sR)
	{
		return sL.size() == sR.size() && sL < sR;
	}
};

int main()
{
	int iN = 0;
	cin >> iN;
	vector<string> sSs;
	for (int i = 0; i < iN; ++i)
	{
		string sTemp;
		cin >> sTemp;
		sSs.push_back(sTemp);
	}
	
	sort(sSs.begin(), sSs.end(), Func1());
	stable_sort(sSs.begin(), sSs.end(), Func2());
	sSs.erase(unique(sSs.begin(), sSs.end()), sSs.end());

	for (int i = 0; i < sSs.size(); ++i)
	{
		cout << sSs[i] << endl;
	}

	return 0;
}