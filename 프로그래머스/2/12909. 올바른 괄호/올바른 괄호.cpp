#include<string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{

    stack<char> Qs;
    for (int i = 0; i < s.length(); ++i)
    {
         if (s[i] == ')')
         {
             if (Qs.empty())
                 return false;

             Qs.pop();
         }
         else
         {
             Qs.push(s[i]);
         }

    }

    if (!Qs.empty())
        return false;

    return true;
}