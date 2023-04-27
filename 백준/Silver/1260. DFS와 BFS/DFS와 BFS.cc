#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

vector<int> DFS(vector<vector<int>> Matrix, int iNodeSize, int iStart)
{
    vector<int> answer;
    list<int> stack;
    vector<bool> isCheck(iNodeSize + 1);

    stack.push_back(iStart);

    while (!stack.empty())
    {
        // 스택에서 꺼낸다.
        int iCur = stack.back(); stack.pop_back();
        
        if (isCheck[iCur])
            continue;
        // 방문 체크한다.
        isCheck[iCur] = true;
        
        // answer에 넣는다.
        answer.push_back(iCur);

        for (int i = 0; i < Matrix[iCur].size(); ++i)
        {
            // 방문한 곳인지 본다.
            int iNext = Matrix[iCur][i];
            // 연결된 노드를 스택에 넣는다.
            stack.push_back(iNext);

        }
    }
   
    return answer;
}

vector<int> BFS(vector<vector<int>> Matrix, int iNodeSize, int iStart)
{
    vector<int> answer;
    list<int> stack;
    vector<bool> isCheck(iNodeSize + 1);

    stack.push_back(iStart);

    while (!stack.empty())
    {
        // 스택에서 꺼낸다.
        int iCur = stack.front(); stack.pop_front();

        if (isCheck[iCur])
            continue;
        // 방문 체크한다.
        isCheck[iCur] = true;

        // answer에 넣는다.
        answer.push_back(iCur);

        for (int i = 0; i < Matrix[iCur].size(); ++i)
        {
            // 방문한 곳인지 본다.
            int iNext = Matrix[iCur][i];
            // 연결된 노드를 스택에 넣는다.
            stack.push_back(iNext);
        }
    }

    return answer;
}

int main()
{
    int N, M, S; cin >> N; cin >> M; cin >> S;
    vector<vector<int>> Matrix(N + 1);
    // Matrix.reserve(N);
    for (int i = 0; i < M; ++i)
    {
        int Atemp, Btemp; cin >> Atemp; cin >> Btemp;
        Matrix[Atemp].push_back(Btemp);
        Matrix[Btemp].push_back(Atemp);
    }

    for (int i = 0; i < N + 1; ++i)
    {
        sort(Matrix[i].rbegin(), Matrix[i].rend());
    }
    vector<int> answer1 = DFS(Matrix, N, S);
    for (int i = 0; i < answer1.size(); ++i)
    {
        cout << answer1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < N + 1; ++i)
    {
        sort(Matrix[i].begin(), Matrix[i].end());
    }
    answer1 = BFS(Matrix, N, S);
    for (int i = 0; i < answer1.size(); ++i)
    {
        cout << answer1[i] << ' ';
    }

    return 0;
}