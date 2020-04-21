#include<stdio.h>

int n;
int p[1000000];
int b, c;
long long count = 0;

int main() {
	int i;
	int num;

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &p[i]);
	scanf("%d %d", &b, &c);

	for (i = 0; i < n; i++) {
		p[i] -= b;
		count++;

		if (p[i] <= 0) continue;
		else {
			if (p[i] % c == 0) { num = p[i] / c; }
			else { num = p[i] / c; num++; }

			count += num;
		}
	}
	printf("%lld\n", count);
}