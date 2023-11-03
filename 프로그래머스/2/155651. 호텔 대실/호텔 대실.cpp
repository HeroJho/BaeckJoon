#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

class Func
{
public:
	bool operator()(int L, int R)
	{
		return L > R;
	}
};

int Change_Min(const string& sTime)
{
	int iMin = 0;
	string sTemp = "";
	for (int i = 0; i < sTime.length(); ++i)
	{
		if (sTime[i] == ':')
		{
			iMin = stoi(sTemp) * 60;
			sTemp = "";
			continue;
		}

		sTemp.push_back(sTime[i]);
	}

	iMin += stoi(sTemp);

	return iMin;
}

int solution(vector<vector<string>> book_time) {

	vector<pair<int, int>> Inputs;
	for (int i = 0; i < book_time.size(); ++i)
	{
		pair<int, int> Temp;
		Temp.first = Change_Min(book_time[i][0]);
		Temp.second = Change_Min(book_time[i][1]);
		Inputs.push_back(Temp);
	}

	sort(Inputs.begin(), Inputs.end());


	priority_queue<int, vector<int>, Func> Qs;
	int iMaxRoom = 0;
	for (int i = 0; i < Inputs.size(); ++i)
	{
		if (!Qs.empty())
		{
			int iMinEnd = Qs.top();
			if (iMinEnd + 10 > Inputs[i].first)
			{  // 방이 더 필요
				Qs.push(Inputs[i].second);
			}
			else
			{ // 방 빼고 새로 추가
				Qs.pop();
				Qs.push(Inputs[i].second);
			}
		}
		else
		{
			Qs.push(Inputs[i].second);
		}
		
		if (iMaxRoom < Qs.size())
			iMaxRoom = Qs.size();
	}

	return iMaxRoom;
}