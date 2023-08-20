#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int N, cnt =0;
  vector<int> v;
  cin >> N;
  for(int i=0;i<N;i++){
    int tmp;
    cin>> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());  
  for(int i=0;i<v.size()-1;i++){
    cnt+=v[i];
  }
  printf("%d",cnt);
}