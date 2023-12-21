#include <iostream>
#include <algorithm>
using namespace std;

struct menu{
    int a,b;
    int gap; // = a-b
    bool operator<(menu &other){
        if(gap!=other.gap) return gap>other.gap;
        else return a>other.a;
    }
}m[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int n,x; cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>m[i].a>>m[i].b;
        m[i].gap = m[i].a - m[i].b;
    }

    sort(m,m+n);

    int ans=0;
    for(int i=0; i<n; i++){
        int dday=n-i-1;
  
        if(m[i].gap<=0){ 
            ans+=m[i].b;
            x-=1000;
        }

        else if(x-5000>=dday*1000){ //현재돈-5000(현재 A를 고름)이 남은날짜*1000보다 커야 A를 고를 수 있음
            ans+=m[i].a;
            x-=5000;
        }
        //  현재 a를 골랐을때 남은 예산으로는 남은 날들 동안 1000원짜리 학식조차 못 먹는다면 b를 골라야 한다.
        else{
            ans+=m[i].b;
            x-=1000;
        }
    }
    cout<<ans;
    return 0;
}