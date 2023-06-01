#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
    cin >> N;

    for(int i=0;i<N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.rbegin(),v.rend());

    int days=0;

    for(int i=0;i<N;i++) 
        days=max(days,v[i]+i+1);
    
    cout << days+1;
}
