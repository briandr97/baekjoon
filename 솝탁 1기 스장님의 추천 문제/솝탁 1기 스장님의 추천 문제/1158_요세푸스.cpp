#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main(void) {
	vector<bool> v;
	int n, k;

	scanf("%d %d", &n, &k);
	v.assign(n + 1, false);

	int j = 1;
	int count;

	printf("<");
	for (int i = 0; i < n; i++) {	
		count = 0;
		while (count < k) {
			if (v[j] == false) {
				count++;
				if (count == k) {
					v[j] = true;
					if (i > 0) printf(", ");
					printf("%d", j);
				}
			}
			j++;
			if (j > n) j = 1;
		}
	}
	printf(">");
	return 0;
}