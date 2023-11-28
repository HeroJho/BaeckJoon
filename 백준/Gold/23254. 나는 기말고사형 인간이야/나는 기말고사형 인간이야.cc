#include <iostream>
#include <queue>
#define MAX 200000
using namespace std;

int n, m, h, b, ans = 0, a[MAX];
priority_queue<pair<int, int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	h = n * 24;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b;
		pq.push({ b, 100 - a[i] });
	}

	while (!pq.empty() && h > 0) {
		int bb = pq.top().first;
		int aa = pq.top().second;
		pq.pop();
		if (aa >= bb) {
			ans += bb;
			pq.push({ bb, aa - bb });
			h--;
		}
		else {
			pq.push({ aa, aa });
		}
	}
	cout << ans;
}