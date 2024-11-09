#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int num : arr) {
        // 각 숫자를 그 값만큼 answer에 추가
        for (int i = 0; i < num; ++i) {
            answer.push_back(num);
        }
    }
    return answer;
}
