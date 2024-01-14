#include<iostream>
using namespace std;
#define INF 1e9
#define mod 10007
typedef long long ll;
typedef pair<int, int>pi;
typedef pair<int, pi>pii;

string str;
int ans;
char now = 'A';
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		int a = abs(now - str[i]);
		ans += min(a, 26 - a);
		now = str[i];
	}
	cout << ans;
}