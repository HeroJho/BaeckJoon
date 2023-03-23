#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string N;
    cin >> N;

    int iTotalSum = 0;
    string sPrePo = "+";
    bool bM = false;
    string sTemp;
    for (int i = 0; i < N.size(); ++i)
    {
        // 숫자
        if ('-' != N[i] && '+' != N[i])
        {
            sTemp += N[i];
        }
        else
        {
            int iNum = stoi(sTemp);
            sTemp = "";

            // 시작이 - 이면 그 뒤로 나오는 모든 +를 -로 바꿀 수 있다.



            if ("-" == sPrePo)
            {
                // 뺀다
                iTotalSum -= iNum;
            }
            else if("+" == sPrePo)
            {
                // 더한다
                if (bM)
                    iTotalSum -= iNum;
                else
                    iTotalSum += iNum;
            }

            if ("-" == sPrePo && '+' == N[i])
            {
                bM = true;
            }
            else if ("+" == sPrePo && '-' == N[i])
            {
                bM = false;
            }
            sPrePo = N[i];
        }
    }


    int iNum = stoi(sTemp);

    if ("-" == sPrePo)
    {
        // 뺀다
        iTotalSum -= iNum;
    }
    else if ("+" == sPrePo)
    {
        // 더한다
        if (bM)
            iTotalSum -= iNum;
        else
            iTotalSum += iNum;
    }

    cout << iTotalSum << endl;

    return 0;
}