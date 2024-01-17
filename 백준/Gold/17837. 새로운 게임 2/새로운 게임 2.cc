#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include "limits.h"

#define MAX 13

using namespace std;


int g_N, g_K;
int g_Matrix[MAX][MAX] = { 0 };

int g_DirX[] = {0, 1, -1, 0, 0};
int g_DirY[] = {0, 0, 0, -1, 1};

int g_FrontMatrix[MAX][MAX] = { 0 };

class Chase* g_Chases[100] = {nullptr};

bool IsIn(int x, int y)
{
	return x >= 1 && x <= g_N && y >= 1 && y <= g_N;
}


class Chase
{
public:
	Chase() {};
	Chase(int number, int dir, pair<int, int> pos) : Number(number), Dir(dir), Pos(pos) {}

	void ChangeInvDir()
	{
		switch (Dir)
		{
		case 1:
			Dir = 2;
			break;
		case 2:
			Dir = 1;
			break;
		case 3:
			Dir = 4;
			break;
		case 4:
			Dir = 3;
			break;
		}
	}

	void Move()
	{
		int inX = g_DirX[Dir] + Pos.first;
		int inY = g_DirY[Dir] + Pos.second;

		// 벗어낫다
		if (!IsIn(inX, inY))
		{
			// 파란색 : 방향을 바꾼 뒤 이동 한다.
			//			또 파란색이라면 방향만 바꾼다.
			// 체스판 이탈 : 파란색과 같다.

			ChangeInvDir();
			int inX = g_DirX[Dir] + Pos.first;
			int inY = g_DirY[Dir] + Pos.second;

			// 파란색 || 끝
			//  가만히
			if (!IsIn(inX, inY) || g_Matrix[inY][inX] == 2)
				return;

			Move();
			return;
		}


		// 해당 위치에 체스
		Chase* HereDown = nullptr;
		Chase* HereUp = nullptr;
		if (g_FrontMatrix[inY][inX] != 0)
		{
			HereDown = g_Chases[g_FrontMatrix[inY][inX]];
			HereUp = HereDown->GetLastUp();
		}

		// 해당 위치의 색
		int Color = g_Matrix[inY][inX];

		if (Color == 0) // 흰
		{
			if (HereUp) // 판에 있다면
			{
				if (IsRoot())
				{
					g_FrontMatrix[Pos.second][Pos.first] = 0;
				}
				else
				{
					// 부모를 끊는다
					DownChase->UpChase = nullptr;
					DownChase = nullptr;
				}

				//  그대로 자식으로 들어간다
				HereUp->SetUpChase(this); // Pos 동기화 까지 됨

			}
			else // 없다면
			{
				if (IsRoot())
				{
					g_FrontMatrix[Pos.second][Pos.first] = 0;
				}
				else
				{
					// 부모를 끊는다
					DownChase->UpChase = nullptr;
					DownChase = nullptr;
				}

				g_FrontMatrix[inY][inX] = Number;
				SetPosWithUp({ inX, inY });

			}

		}
		else if (Color == 1) // 빨
		{
			if (HereUp) // 판에 있다면
			{
				if (IsRoot())
				{
					g_FrontMatrix[Pos.second][Pos.first] = 0;
				}
				else
				{
					// 부모를 끊는다
					DownChase->UpChase = nullptr;
					DownChase = nullptr;
				}

				// 반대로 돌려서
				Chase* Temp = Reverse();

				//  그대로 자식으로 들어간다
				HereUp->SetUpChase(Temp); // Pos 동기화 까지 됨

			}
			else // 없다면
			{
				if (IsRoot())
				{
					g_FrontMatrix[Pos.second][Pos.first] = 0;
				}
				else
				{
					// 부모를 끊는다
					DownChase->UpChase = nullptr;
					DownChase = nullptr;
				}

				// 반대로 돌려서
				Chase* Temp = Reverse();

				g_FrontMatrix[inY][inX] = Temp->GetNumber();
				Temp->SetPosWithUp({ inX, inY });

			}

		}
		else if (Color == 2) // 파
		{
			// 파란색 :  방향을 바꾼 뒤 이동한다.
			//			또 파란색이라면 방향만 바꾼다.
			ChangeInvDir();
			int inX = g_DirX[Dir] + Pos.first;
			int inY = g_DirY[Dir] + Pos.second;

			// 파란색 || 끝
			//  가만히
			if (!IsIn(inX, inY) || g_Matrix[inY][inX] == 2)
				return;

			Move();

		}



	}

	void SetPosWithUp(pair<int, int> nPos)
	{
		Chase* Temp = this;

		while (true)
		{
			Temp->Pos = nPos;
			if (Temp->GetUp() == nullptr)
				break;

			Temp = Temp->GetUp();
		}
	}

	void SetUpChase(Chase* other)
	{
		UpChase = other;
		other->SetDownChase(this);
		other->SetPosWithUp(Pos);
	}

	void SetDownChase(Chase* other)
	{
		DownChase = other;
	}

	Chase* GetUp()
	{
		return UpChase;
	}

	Chase* GetLastUp()
	{
		Chase* Temp = this;

		while (true)
		{
			if (Temp->GetUp() == nullptr)
			{
				return Temp;
			}

			Temp = Temp->GetUp();
		}

		return nullptr;
	}

	bool IsRoot()
	{
		if (DownChase)
			return false;
		else
			return true;
	}

	Chase* Reverse()
	{
		Chase* Temp = this;

		vector<Chase*> Temps;
		while (true)
		{
			Temps.push_back(Temp);

			if (Temp->GetUp() == nullptr)
			{
				break;
			}

			Temp = Temp->GetUp();
		}


		for (int i = 0; i < Temps.size(); ++i)
		{
			Chase* Temp1 = Temps[i]->DownChase;
			Temps[i]->DownChase = Temps[i]->UpChase;
			Temps[i]->UpChase = Temp1;
		}

		// 제일 부모를 반환
		return Temps.back();
	}

	int GetNumber()
	{
		return Number;
	}

	int GetUpCount()
	{
		int iCount = 1;
		Chase* Temp = this;

		while (true)
		{
			if (Temp->GetUp() == nullptr)
			{
				return iCount;
			}

			Temp = Temp->GetUp();
			++iCount;
		}

		return -1;
	}

private:
	int Number = 0;
	int Dir = 0;
	pair<int, int> Pos;
	Chase* DownChase = nullptr;
	Chase* UpChase = nullptr;

};








bool Check4()
{
	for (int i = 1; i <= g_K; ++i)
	{
		if (g_Chases[i]->GetUpCount() >= 4)
			return true;
	}

	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 흰색 : 이동, 말이 있으면 그대로 말을 올린다
	// 빨간색 : 이동 후 이동한 말의 순서를 바꾼다.
	//		기존에 있던 말은 제외
	// 파란색 :  방향을 바꾼 뒤 이동 한다.
	//			또 파란색이라면 방향만 바꾼다.
	// 체스판 이탈 : 파란색과 같다.

	// 말이 4개 이상 쌓이면 턴 종료

	cin >> g_N >> g_K;
	for (int i = 1; i <= g_N; ++i)
	{
		for (int j = 1; j <= g_N; ++j)
		{
			cin >> g_Matrix[i][j];
		}
	}

	
	for (int i = 1; i <= g_K; ++i)
	{
		int y, x, d;
		cin >> y >> x >> d;
		g_Chases[i] = { new Chase(i, d, {x, y}) };
		g_FrontMatrix[y][x] = i;
	}


	int iCount = 0;
	while (true)
	{
		++iCount;

		if (iCount > 1000)
		{
			cout << -1;
			return 0;
		}

		for (int i = 1; i <= g_K; ++i)
		{
			g_Chases[i]->Move();

			if (Check4())
				break;
		}

		if (Check4())
			break;

	}

	cout << iCount;

	return 0;
}
