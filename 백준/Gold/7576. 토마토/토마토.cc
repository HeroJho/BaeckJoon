#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Pos
{
	int x, y;
	Pos():x(0), y(0) {};
	Pos(int X, int Y) { x = X; y = Y; }
};

int Dx[4] = { 0, 0, -1, 1 };
int Dy[4] = { 1, -1, 0, 0 };

int Matrix[1001][1001] = { 0 };
list<Pos> Q;
int X, Y;

bool isIn(int x, int y)
{
	return x >= 0 && x < X && y >= 0 && y < Y;
}

void BFS()
{
	while (!Q.empty())
	{
		Pos Cur = Q.front(); Q.pop_front();
		
		for (int i = 0; i < 4; ++i)
		{
			int nX = Cur.x + Dx[i];
			int nY = Cur.y + Dy[i];

			if (isIn(nX, nY) && Matrix[nY][nX] == 0)
			{
				Matrix[nY][nX] = Matrix[Cur.y][Cur.x] + 1;
				Q.push_back(Pos(nX, nY));
			}
		}
	}
}

int main()
{
	cin >> X >> Y;
	
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			cin >> Matrix[y][x];
			if (Matrix[y][x] == 1)
				Q.push_back(Pos(x, y));
		}
	}
	
	BFS();

	int MaxDepth = 0;
	for (int y = 0; y < Y; ++y)
	{
		for (int x = 0; x < X; ++x)
		{
			if (Matrix[y][x] == 0)
			{
				cout << -1;
				return 0;
			}

			if (MaxDepth < Matrix[y][x])
				MaxDepth = Matrix[y][x];
		}
	}

	cout << --MaxDepth;

	return 0;
}