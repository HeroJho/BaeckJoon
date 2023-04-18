#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string k;
    cin >> n;
    while (n--)
    {
        cin >> k;
        cout << k[0] << k[k.size() - 1] <<'\n';
    }
}