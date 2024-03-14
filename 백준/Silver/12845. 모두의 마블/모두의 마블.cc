#include <iostream>
#include <algorithm>
using namespace std;

// 내림차순
bool DESC(int a, int b) {
	return a > b;
}

int main() {
	int N;	// 카드의 개수
	int level[1000];	// 카드의 레벨
	int gold = 0;	// 골드

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}

	// 내림차순으로 정렬
	sort(level, level + N, DESC);

	for (int i = 1; i < N; i++) {
		// 가장 큰 값은 계속 더해지므로,
		// 가장 큰 값+ 나머지 값들을 계속 더해나감
		gold += (level[0] + level[i]);
	}

	cout << gold;

	return 0;
}