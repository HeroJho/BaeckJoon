#include <iostream>
#include <vector>
#include <queue>


using namespace std;


int H, M, S;
int NexS;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> H >> M >> S;
	cin >> NexS;

	// 초로 변호나
	int TotalS = (H * 60 * 60) + (M * 60) + S;
		// 1 * 60 * 60

	// 더한다

	TotalS += NexS;

	TotalS %= 24 * 60 * 60; // 만약에 24시간 넘기면


	// 분 > 시 변환

	S = TotalS % 60;
	TotalS /= 60;
	M = TotalS % 60;
	H = TotalS / 60;

	cout << H  << ' ' << M << ' ' << S;


	return 0;
}
