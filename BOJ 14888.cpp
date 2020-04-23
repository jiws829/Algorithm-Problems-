/*
<14888 - 연산자 끼워넣기>
먼저 dfs로 연산자 수열을 모두 만든다.

완성된 연산자와 입력받은 수열로 계산을 한 뒤, 최대값과 최소값을 갱신해준다.
*/
#include<stdio.h>

int n;
int p[12]; //입력받는 수열
int t[4]; //덧셈 뺄셈 곱셈 나눗셈
int q[12]; //dfs로 생성되는 연산자 수열
int maxx = -2100000000, minn = 2100000000;

void cal() {  //완성된 수식으로 결과값 계산하는 함수
	int sum = p[0];
	int i;

	for (i = 0; i < n - 1; i++) {
		if (q[i] == 0) {
			sum += p[i + 1];
		}
		else if (q[i] == 1) {
			sum -= p[i + 1];
		}
		else if (q[i] == 2) {
			sum *= p[i + 1];
		}
		else {
			sum /= p[i + 1];
		}
	}
	if (maxx < sum) maxx = sum;
	if (minn > sum) minn = sum;
}

void dfs(int v) {
	if (v == n - 1) {
		cal();
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (t[i] > 0) {
			t[i]--;
			q[v] = i;
			dfs(v + 1);
			q[v] = 0;
			t[i]++;
		}
	}

}

int main() {
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &p[i]);
	for (i = 0; i < 4; i++) scanf("%d", &t[i]);

	dfs(0); //연산자의 모든 경우의 수 고려

	printf("%d\n%d\n", maxx, minn);
}