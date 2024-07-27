#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> Qs;
    
    for(int i = 0; i < works.size(); ++i)
    {
        if(works[i] == 0)
            continue;
        
        Qs.push(works[i]);
    }
    
    while(!Qs.empty())
    {
        if(n == 0)
            break;
        
        int Top = Qs.top();
        Qs.pop();
        
        --Top;

        if(Top != 0)
            Qs.push(Top);
        
        --n;
    }
    
    if(Qs.empty())
        answer = 0;
    else
    {
        while(!Qs.empty())
        {
            int Top = Qs.top();
            answer += Top * Top;
            Qs.pop();
        }
    }
    
    
    return answer;
}