#include <iostream>
#include <queue>

using namespace std;

string s, t;
int ans;
queue<int> q[27];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        q[s[i] - 'a'].push(i);
    }
    int flag = 1;
    while (flag) {
        int prev = -1;
        int cnt = 0;
        for (int i = 0; i < t.size(); i++) {
            int idx = t[i] - 'a';
            if (q[idx].empty()) {
                flag = 0;
                break;
            }
            while (!q[idx].empty()) {
                if (q[idx].front() > prev) {
                    prev = q[idx].front();
                    q[idx].pop();
                    cnt++;
                    break;
                }
                q[idx].pop();
            }
            if (cnt == t.size()) {
                ans++;
                break;
            }
        }
    }

    cout << ans;

}