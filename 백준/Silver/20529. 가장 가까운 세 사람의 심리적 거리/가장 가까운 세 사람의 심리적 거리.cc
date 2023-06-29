#include <stdio.h>
#include <string.h>

int check(char str1[], char str2[]) {
	int i, n=0;
	for (i = 0; i < 4; i++) {
		if (str1[i] != str2[i]) n++;
	}
	return n;
}

int main() {
	int T, N, i, j, k, min = 987654321, tmp = 0;
	char str[100001][4] = { 0 };
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%s", str[i]);
		}
		for (i = 0; i < N; i++) {
			for (j = i + 1; j < N; j++) {
				for (k = j + 1; k < N; k++) {
					tmp += check(str[i], str[j]);
					tmp += check(str[j], str[k]);
					tmp += check(str[i], str[k]);
					min = min < tmp ? min : tmp;
					tmp = 0;
					if (min == 0) break;
				}
				if (min == 0) break;
			}
			if (min == 0) break;
		}
		printf("%d\n", min);
		min = 987654321;
	}
}