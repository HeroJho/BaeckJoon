#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

#define MAX 200
#define HMAX MAX/2

using namespace std;

struct Data
{
	pair<int, int> StartPos;
	int Dir = 0;
	int Se = 0;

	Data() {};
	Data(pair<int, int> InStartPos, int InDir, int InSe)
		: StartPos(InStartPos), Dir(InDir), Se(InSe)
	{
	}
};

int N;
vector<Data> Inputs;

bool Matrix[MAX][MAX] = { false };
int DirX[] = { 1, 0, -1, 0 };
int DirY[] = { 0, -1, 0, 1 };

void DrawLine(pair<int, int> Pos, int Dir, int Se)
{
	// 끝
	vector<pair<int, int>> DrawLines;
	DrawLines.push_back(Pos);

	// 방향으로 라인 넣는다
	for (int i = 0; i < 1; ++i)
	{
		Pos.first += DirX[Dir];
		Pos.second += DirY[Dir];

		DrawLines.push_back(Pos);
	}

	// 세대만큼 돌린다

	for (int s = 0; s < Se; ++s)
	{
		vector<pair<int, int>> TempLines;
		pair<int, int> Gig = DrawLines.back();

		for (int i = DrawLines.size()-1; i >= 0; --i)
		{
			pair<int, int> Cur = DrawLines[i];
			// 기준 빼고
			int nX = Cur.first - Gig.first;
			int nY = Cur.second - Gig.second;
			// 돌리고
			int Temp = nX;
			nX = nY * -1;
			nY = Temp;

			// 기준 더하고
			nX += Gig.first;
			nY += Gig.second;

			// 넣는다
			TempLines.push_back({ nX, nY });
		}

		for (int i = 0; i < TempLines.size(); ++i)
		{
			DrawLines.push_back(TempLines[i]);
		}

	}


	for (int i = 0; i < DrawLines.size(); ++i)
	{
		pair<int, int> Cur = DrawLines[i];
		int nX = Cur.first;
		int nY = Cur.second;
		Matrix[nY][nX] = true;
	}

}

void Draw()
{
	for (int i = 0; i < N; ++i)
	{
		Data Cur = Inputs[i];
		DrawLine(Cur.StartPos, Cur.Dir, Cur.Se);
	}
}

bool CheckBox(int InX, int InY)
{

	// 가로
	for (int i = InX; i < InX + 2; ++i)
	{
		if (Matrix[i][InY] == false)
			return false;
		if (Matrix[i][InY + 1] == false)
			return false;
	}

	// 세로
	for (int i = InY; i < InY + 2; ++i)
	{
		if (Matrix[InX][i] == false)
			return false;
		if (Matrix[InX + 1][i] == false)
			return false;
	}


	return true;
}

int CheckAns()
{
	int Ans = 0;
	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			if (CheckBox(x, y))
			{
				++Ans;
			}

		}
	}

	return Ans;
}

void Go()
{	
	// 그린다
	Draw();

	// 체크한다
	int Ans = CheckAns();
	
	cout << Ans;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		Inputs.push_back({ {x, y}, d, g });
	}


	Go();


	return 0;
}
