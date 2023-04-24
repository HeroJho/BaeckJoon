#include<iostream>
#include<queue>
#include<string>

using namespace std;

typedef struct Data
{
    int S;
    int E;
};

class Func
{
public:
    bool operator()(Data l, Data r)
    {
        return l.E > r.E;
    }
};
class rFunc
{
public:
    bool operator()(Data l, Data r)
    {
        return l.S > r.S;
    }
};


int main()
{
    int N; cin >> N;
    priority_queue<Data, vector<Data>, rFunc> p;
    priority_queue<Data, vector<Data>, Func> Endp;


    for (int i = 0; i < N; ++i)
    {
        int s, e; cin >> s; cin >> e;
        Data d; d.S = s; d.E = e;
        p.push(d);
    }

    // 힙에서 뺀다. 끝 시간을 넣는다.
    int iRoomCount = 1;
    Data d = p.top(); p.pop();
    Endp.push(d);
    while (!p.empty())
    {
        Data d = p.top(); p.pop();
        Data Endd = Endp.top();

        // 겹친다
        if (Endd.E > d.S)
        {
            ++iRoomCount;
            Endp.push(d);
        }
        else
        {
            Endp.pop();
            Endp.push(d);
        }
    }

    cout << iRoomCount;

    return 0;
}