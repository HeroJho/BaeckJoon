#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

struct tagPos
{
	int iX, iY;
};

class FucX
{
public:
	bool operator()(tagPos L, tagPos R)
	{
		return L.iX < R.iX;
	}
};

class FucY
{
public:
	bool operator()(tagPos L, tagPos R)
	{
		return L.iX == R.iX && L.iY < R.iY;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;

	vector<tagPos> iPoss;
	for (int i = 0; i < iN; ++i)
	{
		tagPos Pos;
		cin >> Pos.iX >> Pos.iY;
		iPoss.push_back(Pos);
	}

	sort(iPoss.begin(), iPoss.end(), FucX());
	stable_sort(iPoss.begin(), iPoss.end(), FucY());

	for (int i = 0; i < iPoss.size(); ++i)
	{
		cout << iPoss[i].iX << ' ' << iPoss[i].iY << '\n';
	}

	return 0;
}