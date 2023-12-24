#include <string>
#include <vector>
#include <queue>

using namespace std;

bool g_Visited[1000001] = {false};

int BFS(int x, int y, int n)
{
    queue<int> Qs;
    Qs.push(x);

    int iCount = 0;
    while(!Qs.empty())
    {
        int iSize = Qs.size();
        for(int t = 0; t < iSize; ++t)
        {
        
            int iCur = Qs.front();
            Qs.pop();

            if(iCur > y)
                continue;
            else if(iCur == y)
            {
                return iCount;
            }
            if(g_Visited[iCur])
                continue;
            g_Visited[iCur] = true;

            Qs.push(iCur + n);
            Qs.push(iCur * 3);
            Qs.push(iCur * 2);
            
        }
    
        ++iCount;
        
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    answer = BFS(x, y ,n);
    
    return answer;
}