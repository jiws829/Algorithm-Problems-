/*
<14501 - 퇴사>
DP를 사용해서 품
맨 뒤에서 부터 for문을 돌면서
그날 상담을 했을때(ans[i+t[i]]+p[i])와
그날 상담을 안했을때(ans[i+1])의 비용을 비교한 경우 더 큰 경우를 넣음
그럼 ans[1]에 상담 최대값이 들어간다

단 ans크기는 17로 했는데 n=15일때 i가 15에서 ans[i+1]을 참조하기 때문에 ans[16]을 참조할수 있음

*/
#include<stdio.h>

int p[16], t[16];
int n;
int ans[17];

int main() {
	int i;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d %d", &t[i], &p[i]);

	for (i = n; i >= 1; i--) {
		if (i + t[i] - 1 > n) {
			ans[i] = ans[i + 1];
		}
		else {
			if (ans[i + 1] > ans[i + t[i]] + p[i]) ans[i] = ans[i + 1];
			else ans[i] = ans[i + t[i]] + p[i];
		}
	}

	printf("%d\n", ans[1]);
}