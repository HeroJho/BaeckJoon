#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {	
	int n; cin >> n; 
	vector <pair<int, int>>v; 
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; 
		v.push_back({ a,b }); 
	}
	sort(v.begin(), v.end()); 
	int time = 0; 
	for (int i = 0; i < n; i++) {
		time = max(v[i].first, time); 
		time += v[i].second; 
	}
	cout << time; 
}