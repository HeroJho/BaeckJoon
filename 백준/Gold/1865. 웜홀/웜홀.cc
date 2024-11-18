#include <iostream>
#include <vector>
#include <cstring>

#define INF 987654321

using namespace std;

int N, M, W;
int S, E, T;
vector<pair<pair<int, int>, int>> v;
int d[501];

void solution() {
    string result = "NO";

    memset(d, INF, sizeof(d));
    d[1] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < v.size(); j++) {
            int s = v[j].first.first;
            int e = v[j].first.second;
            int t = v[j].second;

            if (d[e] > d[s] + t) {
                d[e] = d[s] + t;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int s = v[i].first.first;
        int e = v[i].first.second;
        int t = v[i].second;

        if (d[e] > d[s] + t) {
            result = "YES";
            break;
        }
    }

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        v.clear();

        cin >> N >> M >> W;

        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            v.push_back({ { S,E },T });
            v.push_back({ { E,S },T });
        }

        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            v.push_back({ { S,E },-T });
        }

        solution();
    }

    return 0;
}