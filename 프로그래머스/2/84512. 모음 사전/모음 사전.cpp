#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string Word;
char W[] = { 'A', 'E', 'I', 'O', 'U' };
int Cnt = -1;
int Ans = 0;

void DFS(string InWord)
{
    if (InWord.length() > 5)
    {
        return;
    }

    ++Cnt;
    if (InWord == Word)
    {
        Ans = Cnt;
    }

    for (int i = 0; i < 5; ++i)
    {
        DFS(InWord + W[i]);
    }
   
}


int solution(string word) {
    Word = word;

    DFS("");

    return Ans;
}