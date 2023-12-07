#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    unordered_map<string, int> Map;
    for (int i = 0; i < players.size(); ++i)
    {
        Map.emplace(players[i], i);
    }

    for (int i = 0; i < callings.size(); ++i)
    {
        auto iter1 = Map.find(callings[i]);
        auto iter2 = Map.find(players[iter1->second - 1]);

        string Temp = players[iter1->second];
        players[iter1->second] = players[iter2->second];
        players[iter2->second] = Temp;

        int iTemp = iter1->second;
        iter1->second = iter2->second;
        iter2->second = iTemp;

    }

    return players;
}