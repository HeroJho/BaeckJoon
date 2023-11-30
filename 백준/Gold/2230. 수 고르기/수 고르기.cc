#include <iostream>
using namespace std;
 
void sortGapInsertion(int list[], int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i += gap) {
        key = list[i];
        for (j = i - gap; j >= first && list[j] < key; j -= gap) {
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}
 
void shellSort(int list[], int n) {
    int gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        if (gap % 2 == 0) {
            gap++;
        }
        for (int i = 0; i < gap; i++) {
            sortGapInsertion(list, i, n - 1, gap);
        }
    }
}
    
 
int main() {
    int N, M;
    const int SIZE = 100000;
    int list[SIZE];
 
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }
    
    shellSort(list, N);
 
    int left = 0;
    int right = 0;
    int ans = 2000000000;
    while (right<N&&left<N) {
        int temp = list[left] - list[right];
        if (temp > M) {
            ans = min(ans, temp);
            left++;
        }
        else if (temp < M) {
            right++;
        }
        else if (temp == M) {
            ans = min(ans, temp);
            right++;
        }
    }
 
    cout << ans;
    return 0;
}
