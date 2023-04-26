#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s; cin >> s;
    sort(s.begin(), s.end());
    string a = "";
    char lc = ' ';
    for (int i = 0; i < s.length();)
    {
        // 다음거랑 같다
        if (s[i] == s[i + 1])
        {
            a.push_back(s[i]);
            i += 2;

            if (i - s.length() == 1)
            {
                if (lc == ' ')
                {
                    lc = s[i];
                }
                else
                {
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
            }

        }
        else // 다르다
        {
            // 짝수 홀수 확인
            if (s.length() % 2 == 0)
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            else
            {
                if (lc == ' ')
                {
                    lc = s[i];
                }
                else
                {
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
            }
            ++i;
        }
    }

    string total = "";
    string rs = a;
    sort(rs.rbegin(), rs.rend());
    if (lc != ' ')
    {
        total = a + lc + rs;
    }
    else
    {
        total = a + rs;
    }

    cout << total;

    return 0;
}