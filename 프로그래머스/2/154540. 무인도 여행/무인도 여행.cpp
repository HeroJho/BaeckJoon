#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int g_iN, g_iM;
bool g_Visited[200][200] = {false};
int g_DirX[] = {0, 0, -1, 1};
int g_DirY[] = {-1, 1, 0, 0};

bool IsIn(int iX, int iY)
{
    return iX >= 0 && iX < g_iM && iY >= 0 && iY < g_iN;
}

int BFS(pair<int ,int> StartPos, const vector<string>& maps)
{
    queue<pair<int ,int>> Qs;
    Qs.push(StartPos);
    g_Visited[StartPos.second][StartPos.first] = true;
   
    int iSum = maps[StartPos.second][StartPos.first] - '0';
    while(!Qs.empty())
    {
        pair<int ,int> CurPos = Qs.front();
        Qs.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int inX = g_DirX[i] + CurPos.first;
            int inY = g_DirY[i] + CurPos.second;
            
            if(IsIn(inX, inY) && maps[inY][inX] != 'X' && !g_Visited[inY][inX])
            {
                g_Visited[inY][inX] = true;
                iSum += maps[inY][inX] - '0';
                
                Qs.push({inX, inY});
            }
            
        }
        
    }
    
    if(iSum)
        return iSum;
    else
        return -1;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    g_iN = maps.size();
    g_iM = maps[0].length();
    
    for(int y= 0 ; y < g_iN; ++y)
    {
        for(int x = 0; x < g_iM; ++x)
        {
            if(maps[y][x] != 'X' && !g_Visited[y][x])
            {
                answer.push_back(BFS({x, y}, maps));
            }
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}