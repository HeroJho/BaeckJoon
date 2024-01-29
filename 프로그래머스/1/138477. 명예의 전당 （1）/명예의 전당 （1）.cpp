#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer, v;
    for(auto c : score)
    {
        v.push_back(c);
        sort(v.begin(),v.end());//정렬
        //k개 이상이면 맨처음 값 삭제(오름차순정렬이기때문에 가장 처음이 가장 작은값)
        if (v.size() > k) v.erase(v.begin());
        answer.push_back(*v.begin());//맨처음값 추가
    }
    return answer;
}