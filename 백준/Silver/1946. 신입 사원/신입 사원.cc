#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> iRes;

struct Data
{
    int iA = 0;
    int iB = 0;
    int iCount = 0;
};

bool Fuc(Data A, Data B)
{
    return A.iA < B.iA;
}

void Cal()
{
    int iCount = 0; cin >> iCount;
    vector<Data> Ds;
    for (int i = 0; i < iCount; ++i)
    {
        Data D; cin >> D.iA; cin >> D.iB;
        Ds.push_back(D);
    }

    sort(Ds.begin(), Ds.end(), Fuc);

    int iDe = 0;
    int iI = 0;
    for (int i = 1; i < Ds.size(); ++i)
    {
        if (Ds[iI].iB < Ds[i].iB)
        {
            ++iDe;
        }
        else
        {
            iI = i;
        }
    }

    iRes.push_back(Ds.size() - iDe);
}

int main()
{
    int iTCount = 0; cin >> iTCount;

    for (int i = 0; i < iTCount; ++i)
    {
        Cal();
    }

    for (int i = 0; i < iRes.size(); ++i)
    {
        cout << iRes[i] << endl;
    }

    return 0;
}