#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--) 
    {
        int J, N;
        cin >> J >> N;

        vector<int> Box;
        for (int I = 0; I < N; I++) 
        {
            int R, C;
            cin >> R >> C;
            Box.push_back(R * C);
        }

        sort(Box.begin(), Box.end());

        int Cnt = 0;
        for (int I = N - 1; I > 0; I--) 
        {

            J -= Box[I];
            Cnt++;

            if (J <= 0) break;
        }

        cout << Cnt << "\n";
    }

    return 0;
}
