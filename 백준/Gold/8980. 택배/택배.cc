#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct box {
	int from;
	int to;
	int num;
};

bool cmp( box a, box b )
{
	return a.to < b.to;
}

int n,c,m;
int in1, in2, in3;
int answer = 0;
vector<box> boxes;

int main()
{
	//n 마을 수, c 트럭 용량
	cin >> n >> c;
	cin >> m;

	vector<int> left(n + 1, c);

	for (int i = 0; i < m; i++)
	{
		cin >> in1 >> in2 >> in3;
		boxes.push_back({ in1,in2,in3 });
	}

	sort(boxes.begin(), boxes.end(),cmp);

	for (int i = 0; i < m; i++)
	{
		//가능 경로에서 최대로 실을 수 있는 것들
		int mini = left[boxes[i].from];
		for (int j = boxes[i].from + 1; j < boxes[i].to ; j++)
		{
			mini = min(mini, left[j]);
		}

		int cnt = boxes[i].num;
		if (mini < cnt)
			cnt = mini;
		answer += cnt;

		for (int j = boxes[i].from; j < boxes[i].to; j++)
		{
			left[j] -= cnt;
		}
	}
	cout << answer << endl;

	return 0;
}