#include <iostream>
#include <list>

using namespace std;

struct Pos
{
	int x, t;
	Pos() { x = 0; t = 0; }
	Pos(int X, int T) { x = X; t = T; }
};

int S, T;
list<Pos> Q;
bool Visited[100001] = { 0 };

bool CheckBound(int x)
{
	return x >= 0 && x < 100001;
}

void BFS()
{
	Q.push_back(Pos(S, 0));

	while (!Q.empty())
	{
		Pos Cur = Q.front(); Q.pop_front();

		if (Cur.x == T)
		{
			cout << Cur.t;
			return;
		}

		if (CheckBound(Cur.x - 1) && Visited[Cur.x - 1] == false)
		{
			Q.push_back(Pos(Cur.x - 1, Cur.t + 1));
			Visited[Cur.x - 1] = true;
		}
		if (CheckBound(Cur.x + 1) && Visited[Cur.x + 1] == false)
		{
			Q.push_back(Pos(Cur.x + 1, Cur.t + 1));
			Visited[Cur.x + 1] = true;
		}
		if (CheckBound(Cur.x * 2) && Visited[Cur.x * 2] == false)
		{
			Q.push_back(Pos(Cur.x * 2, Cur.t + 1));
			Visited[Cur.x * 2] = true;
		}
	}
}

int main()
{
	cin >> S >> T;

	BFS();

	return 0;
}