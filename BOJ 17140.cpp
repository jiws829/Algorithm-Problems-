/*
<17140 - 이차원 배열과 연산>
각 배열을 문제에 주어진 조건에 맞게 연산을 진행해주면 된다.
각 번호와 반복횟수를 구조체에 저장하고 그 구조체를 qsort로 정렬해주는 방식으로 시간복잡도를 감소시켰다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct pp {
	int num, cnt;
}p[101];

int a[101][101];
int r, c, k;
int ans;

int compare(const void* c, const void* d) {
	pp* x = (pp*)c;
	pp* y = (pp*)d;

	if (x->cnt == y->cnt && x->num > y->num) return 1;
	if (x->cnt > y->cnt) return 1;
	return -1;
}

int main() {
	int i, j;
	int n, m;
	int maxx;
	int now;
	int newm, newn;
	pp p[100];

	scanf("%d %d %d", &r, &c, &k);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) scanf("%d", &a[i][j]);
	}
	newn = newm = 3;

	while (1) {
		if (a[r-1][c-1] == k) break;
		if (ans > 100) { ans = -1; break; }

		n = newn;
		m = newm;

		if (n >= m) {
			newm = 0;
			for (i = 0; i < n; i++) {
				memset(p, 0, sizeof(p));
				maxx = -1;
				for (j = 0; j < m; j++) {
					if (a[i][j] == 0) continue;
					p[a[i][j] - 1].num = a[i][j];
					p[a[i][j] - 1].cnt++;
					if(maxx<a[i][j]) maxx = a[i][j];
					a[i][j] = 0;
				}
				
				
				qsort(p, maxx, sizeof(pp), compare);

				now = 0;
				for (j = 0; j < maxx; j++) {
					if (p[j].num == 0) continue;
					a[i][now++] = p[j].num;
					a[i][now++] = p[j].cnt;
					if (now == 100) break;
				}
				if (now > newm) newm = now;
				
			}
		}
		else {
			newn = 0;

			for (j = 0; j < m; j++) {
				memset(p, 0, sizeof(p));
				maxx = -1;
				for (i = 0; i < n; i++) {
					if (a[i][j] == 0) continue;
					p[a[i][j] - 1].num = a[i][j];
					p[a[i][j] - 1].cnt++;
					if (maxx < a[i][j]) maxx = a[i][j];
					a[i][j] = 0;
				}
				
				qsort(p, maxx, sizeof(pp), compare);
				
				now = 0;
				for (i = 0; i < maxx; i++) {
					if (p[i].num == 0) continue;
					a[now++][j] = p[i].num;
					a[now++][j] = p[i].cnt;
					if (now == 100) break;
				}
				if (now > newn) newn = now;
			}

		}
		ans++;		
	}
	printf("%d\n", ans);
}
