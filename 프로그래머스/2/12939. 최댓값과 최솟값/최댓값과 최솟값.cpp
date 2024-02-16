#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;



string solution(string s) {
    string answer = "";

    vector<int> Inputs;
    string sTemp = "";
    for (int i = 0; i < s.length(); ++i)
    {
        
        if (s[i] == ' ')
        {
            int Num = stoi(sTemp);
            Inputs.push_back(Num);
            sTemp = "";

        }
        else if (s[i] == '-')
        {
            sTemp = "";
            sTemp += '-';
            ++i;
            sTemp += s[i];
        }
        else
        {
            sTemp += s[i];
        }

    }

    int Num = stoi(sTemp);
    Inputs.push_back(Num);



    sort(Inputs.begin(), Inputs.end());


    answer += to_string(Inputs.front());
    answer += ' ';
    answer += to_string(Inputs.back());


    return answer;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    
    solution("1 2 -1 -5 10 2 4");


    return 0;
}
