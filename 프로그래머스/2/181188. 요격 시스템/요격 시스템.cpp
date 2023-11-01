#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Func
{
public:
	bool operator()(const vector<int>& L, const vector<int>& R)
	{
		return L[0] < R[0];
	}
};
class Func1
{
public:
	bool operator()(const vector<int>& L, const vector<int>& R)
	{
		if (L[0] != R[0])
			return false;

		return L[1] < R[1];
	}
};

int solution(vector<vector<int>> targets) {
    int answer = 0;

	// 시작점으로 정렬
	sort(targets.begin(), targets.end(), Func());
	stable_sort(targets.begin(), targets.end(), Func1());

	//int iStart = targets[0][0];
	int iEnd = targets[0][1];
	for (int i = 1; i < targets.size(); ++i)
	{
		if (iEnd > targets[i][0])
		{
			if (iEnd > targets[i][1])
				iEnd = targets[i][1];

			// iStart = targets[i][0];
		}
		else
		{
			++answer;
			// iStart = targets[i][0];
			iEnd = targets[i][1];
		}

	}

	++answer;

    return answer;
}