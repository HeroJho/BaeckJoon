#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food)
{
    string answer = "";
    for(int i=1;i<food.size();i++)
    {
         while(food[i]>1)// 1개보다 많으면
         {
             answer.push_back(i+'0');// 해당 음식 세팅
             food[i] -= 2;// 개수 차감
         }
    }
    string r_answer = answer;
    reverse(r_answer.begin(), r_answer.end());//세팅한 음식 뒤집어준 문자열
    return answer + "0" + r_answer;//더해서 리턴
}