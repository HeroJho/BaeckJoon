#include <iostream>
#include <algorithm>
using namespace std;

int student[10000];

int main() {
	int N;	
	int current = 0;
	int min = 0;

	cin >> N;

	for (int i = 0; i < 2 * N; i++) {
		cin >> student[i];
	}

	sort(student, student + 2 * N);	
	min = student[0] + student[2 * N - 1];

	for (int i = 0; i < 2 * N; i++) {
		current = student[i] + student[2 * N - i - 1];
		if (min > current) {
			min = current;
		}
	}

	cout << min;

	return 0;
}