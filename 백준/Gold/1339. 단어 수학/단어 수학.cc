#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector <pair<int, char>> v;
int tmp[26];
int p[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n;
    int ans=0;
    string str;
    p[0]=1;
    for(int i=1;i<10;i++){
        p[i] = p[i-1]*10;
    }
    cin>>n;
    memset(tmp, 0, sizeof(tmp));
    for(int i=0;i<n;i++){
        cin>>str;
        int k=0;
        for(int j=str.length()-1;j>=0;j--){
            tmp[str[j]-'A']+=p[k];   
            k++;
        }
    }
    for(int i=0;i<26;i++){
        if(tmp[i]>0) v.push_back({tmp[i],i+'A'});
    }
    sort(v.begin(),v.end(),greater<>());
    int m=9;
    for(int i=0;i<v.size();i++){
        ans+=m*v[i].first;
        m--;
    }
    cout<<ans;
    return 0;
}