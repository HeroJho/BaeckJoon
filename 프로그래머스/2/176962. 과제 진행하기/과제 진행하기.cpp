#include <vector>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include "limits.h"

using namespace std;

struct Data
{
	string sName = "";
	int iStart = 0, iEnd = 0;

	Data() {};
	Data(string _sName, int _iStart, int _iEnd) : sName(_sName), iStart(_iStart), iEnd(_iEnd) {};

};

class Func
{
public:
	bool operator()(Data L, Data R)
	{
		return L.iStart > R.iStart;
	}
};

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;

	priority_queue<Data, vector<Data>, Func> Inputs;
	for (int i = 0; i < plans.size(); ++i)
	{
		Data Temp;

		Temp.sName = plans[i][0];

		string sS;
		int iNum = 0;
		for (auto cS : plans[i][1])
		{
			if (cS == ':')
			{
				iNum = stoi(sS);
				Temp.iStart = iNum * 60;	

				sS = "";
				iNum = 0;
			}
			else
				sS.push_back(cS);
		}
		iNum = stoi(sS);
		Temp.iStart += iNum;

		Temp.iEnd = stoi(plans[i][2]);

		Inputs.push(Temp);
	}

	// 분으로 바꾼 뒤 시작 정렬

	// 현재 시간
	int iCurTime = 0;
	// 새로운 과제 시작
	Data Cur = Inputs.top();
	Inputs.pop();
	iCurTime = Cur.iStart;

	vector<Data> Stops;
	while (!Inputs.empty())
	{
		Data Nex = Inputs.top();

		// 진행 사이에 새로운 과제가 있냐
		int iEndTime = iCurTime + Cur.iEnd;

		if (iEndTime > Nex.iStart)
		{
			//		있다면 기존꺼 멈춰두고 ㄱ
			Cur.iEnd = iEndTime - Nex.iStart;
			iCurTime = Nex.iStart;
			Stops.push_back(Cur);
			Cur = Nex;
			Inputs.pop();
		}
		else
		{
			//		없다면
			//			끝낸다
			//			새로운 과제를 꺼낸다
			//			시간이 뜨면 가장 최근의 멈춘 과제를 꺼내서 진행한다			
			answer.push_back(Cur.sName);
			if (Stops.empty())
			{
				iCurTime = Nex.iStart;
				Cur = Nex;
				Inputs.pop();
			}
			else
			{
				if (Nex.iStart - iEndTime > 0)
				{
					iCurTime = iEndTime;
					Cur = Stops.back();
					Stops.pop_back();
				}
				else
				{
					iCurTime = Nex.iStart;
					Cur = Nex;
					Inputs.pop();
				}
			}

		}


	}
	
	answer.push_back(Cur.sName);

	for (int i = Stops.size() - 1; i >= 0; --i)
	{
		answer.push_back(Stops[i].sName);
	}

	return answer;
}
