#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int iN;
	double iED[100000];
	double iMax;

	cin >> iN;
	for (int i = 0; i < iN; i++) {
		cin >> iED[i];
	}

	sort(iED, iED + iN);

	iMax = iED[iN - 1];

	for (int i = 0; i < iN - 1; i++) {
		iMax += (iED[i] / 2);
	}

	cout << iMax;

	return 0;
}