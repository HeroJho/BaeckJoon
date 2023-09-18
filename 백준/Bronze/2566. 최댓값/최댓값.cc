#include <bits/stdc++.h>
using namespace std;
int main() {
	int Max=-1,x,y; //Max가 0이면 모두 0일때 문제가 생김.
	int num;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>num;
			if(Max<num){
				Max=num;
				x=i;
				y=j;
			}		
		}
	}
	cout<<Max<<"\n"<<x<<" "<<y;
	return 0;
}