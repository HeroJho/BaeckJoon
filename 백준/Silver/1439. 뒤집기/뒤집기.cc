#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string N; cin >> N;

    int iCount_0 = 0;
    int iCount_1 = 0;
    char cTemp = N[0];

    if ('0' == N[0])
    {
        ++iCount_0;
    }
    else
    {
        ++iCount_1;
    }

    for (int i = 1; i < N.length(); ++i)
    {
        if (cTemp != N[i])
        {
            if ('0' == N[i])
            {
                ++iCount_0;
            }
            else
            {
                ++iCount_1;
            }

            cTemp = N[i];
        }
    }


    if (iCount_0 < iCount_1)
    {
        cout << iCount_0;
    }
    else
    {
        cout << iCount_1;
    }


    

    return 0;
}