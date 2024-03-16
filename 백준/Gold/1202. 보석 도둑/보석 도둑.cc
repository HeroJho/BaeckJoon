#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> MVs;
    for (int i = 0; i < N; ++i)
    {
        int M, V;
        cin >> M >> V;
        MVs.push_back({M, V});
    }

    vector<int> Ms;
    for (int i = 0; i < K; ++i)
    {
        int Temp;
        cin >> Temp;
        Ms.push_back(Temp);
    }

    // 무게 오름차순
    sort(MVs.begin(), MVs.end());
    // 가방 무게 오름차순
    sort(Ms.begin(), Ms.end());

    // i 가방 무게만큼 Q에 넣는다
    // Top을 고른다
    long long Ans = 0;

    priority_queue<int> Qs;
    int MVIndex = 0;
    for (int i = 0; i < K; ++i)
    {
        int BagM = Ms[i];
        while (MVIndex < N && MVs[MVIndex].first <= BagM)
        {
            Qs.push(MVs[MVIndex].second);
            ++MVIndex;
        }
        
        // 넣을 보석이 없거나
        // 제한 가방까지 다 넣었을 때
        //  맨 위를 뺀다
        if (!Qs.empty())
        {
            Ans += Qs.top();
            Qs.pop();
        }

    }

    cout << Ans;

    return 0;
}
