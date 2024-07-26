#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> Matrix[100001];
int N;


bool Visited [100001] = {false};

void Reset()
{
    for(int i = 0; i <= N; ++i)
    {
        Visited[i] = false;
    }
}

int BFS(int StartPos, int DestPos)
{
    queue<int> Qs;
    Qs.push(StartPos);
    Visited[StartPos] = true;
   
    int Cnt = 0;
    while(!Qs.empty())
    {
        ++Cnt;
        
        int Count = Qs.size();
        
        for(int s = 0; s < Count; ++s)
        {
            int CurPos = Qs.front();
            Qs.pop();

            for(int i = 0; i < Matrix[CurPos].size(); ++i)
            {
                int nPos = Matrix[CurPos][i];
                if(Visited[nPos])
                    continue;

                if(nPos == DestPos)
                    return Cnt;

                Visited[nPos] = true;
                Qs.push(nPos);
            }  
            
        }
        
    }
    
    return -1;
}


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    N = n;
    for(int i = 0; i < roads.size(); ++i)
    {
        Matrix[roads[i][0]].push_back(roads[i][1]); 
        Matrix[roads[i][1]].push_back(roads[i][0]); 
    }
    
    for(int i = 0; i < sources.size(); ++i)
    {
        if(sources[i] == destination)
        {
            answer.push_back(0);
            continue;
        }
            
        Reset();
        int Cnt = BFS(sources[i], destination);
        answer.push_back(Cnt);
    }
    
    return answer;
}