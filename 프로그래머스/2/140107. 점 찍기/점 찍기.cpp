#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    // k의 배수
    for(long long i = 0; i <= d; i+=k) {
        
        long long maxY = sqrt((long long)d * d - (long long)i * i);
        
        answer += floor(maxY / k) + 1;
        
    }
    
    return answer;
}