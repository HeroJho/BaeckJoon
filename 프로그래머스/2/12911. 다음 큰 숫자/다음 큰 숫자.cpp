#include <string>
#include <vector>

using namespace std;

int ToBir(int N)
{
    int Cnt=0;
    
    while(N!=0)
    {
        if(N%2==1) 
            Cnt++;
        
        N/=2;
    }
    
    return Cnt;
}

int solution(int n) 
{
    int M=ToBir(n);
    n++;
    
    while(ToBir(n)!=M)
    {
        n++;
    }
    
    return n;
}