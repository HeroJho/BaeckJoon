#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    long long A, B; cin >> A; cin >> B;
    //   2 6
    int iCount = 0;
    while (A <= B)
    {
        if (A == B)
        {
            cout << iCount + 1;
            return 0;
        }
        else if (0 == B % 2)
        {    // 나눠지면 나눈다.
            B /= 2;

            ++iCount;
        }
        else
        {    // 안 나눠지면 끝에서 1을 뺀다.
            string sTemp = to_string(B);

            if ('1' != sTemp.back())
            {
                break;
            }

            sTemp.pop_back();
            if (!sTemp.empty())
                B = stoll(sTemp);
            else
                B = 0;

            ++iCount;
        }
    }

    cout << -1;

    return 0;
}