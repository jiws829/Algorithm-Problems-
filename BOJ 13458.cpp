/*
<13458 - 시험 감독>
먼저 응시자수 에서 총감독관 수를  빼주고
이후 부감독관수로 나눠서 감독관 수를 세면 됨. 딱 나눠떨어지지 않는 경우도 고려해야함

감독관 수를 세는 변수는 int 범위를 초과할 수 있으므로 long long으로 선언함
*/
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