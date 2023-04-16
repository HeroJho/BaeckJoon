#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
 
	int N;
	cin >> N;
 
	// N번만큼 반복
	for (int i = 1; i <= N; i++) {
 
		// i행에서는 i개만큼 별을 출력
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}