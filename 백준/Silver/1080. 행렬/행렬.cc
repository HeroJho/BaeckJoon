#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

vector<vector<int> > A(51,vector<int> (51,0));
vector<vector<int> > B(51,vector<int> (51,0));
vector<vector<bool> > trans(51,vector<bool> (51,false));


void change(int m,int n){

    for(int i = m; i< m+3; i++){
        for(int j = n; j < n+3; j++){
            trans[i][j] = !trans[i][j];
        }
    }

}



int main(){


    int m,n;
    cin>>m>>n;
    char c;
    int ans = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j < n; j++){
            cin>>c;
            A[i][j] = c-48;
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j < n; j++){
            cin>>c;
            B[i][j] = c-48;
            if(B[i][j] != A[i][j]){
                trans[i][j] = true;
            }
        }
    }

    if(m< 3 || n < 3){
        for(int i = 0; i < m; i++){
            for(int j = 0; j<n; j++){
                if(trans[i][j]){
                    ans = -1;
                    break;
                }
            }
        }
    }
    else{
        for(int i = 0; i <= m-3; i++){
            for(int j = 0; j <= n-3; j++){
                if(trans[i][j] == true){
                    change(i,j);
                    ans++;
                }
                
            }
        }
    }

    
    for(int i = 0; i < m; i++){
        for(int j =0; j<n;j++){
            if(trans[i][j])
                ans = -1;
        }
        
    }

    cout<<ans<<endl;


    return 0;
}