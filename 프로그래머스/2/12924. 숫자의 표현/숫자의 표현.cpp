#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 1;
    
    for(int i = 1; i < n; ++i)
    {
        int Sum = i;
        for(int j = i + 1; j < n; ++j)
        {
            Sum += j;
            if(Sum == n)
            {
                ++answer;
            }
            else if(Sum > n)
            {
                break;
            }
        }
    }
    
    
    
    return answer;
}