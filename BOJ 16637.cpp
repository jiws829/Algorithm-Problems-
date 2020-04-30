/*
<16637 - 괄호 추가하기>
먼저 완전 탐색을 통해 괄호를 추가할 연산을 지정해둔다.
연속된 두 연산은 괄호를 지정할 수 없다. 만약 연속된 두 연산이 지정되면 괄호가 중복되게 된다.

괄호를 씌울 연산자를 지정한 후에는 괄호 먼저 계산해주고
다음에는 나머지 연산자를 계산해서
최대값을 구해준다.
*/
#include<stdio.h>
#include<string.h>
#include<vector>
#include<limits.h>
using namespace std;

int n;
int p[11];
int t[11], cnt;
int visited[11];
int maxx = INT_MIN;

void cal() {
	int sum;
	int i;
	vector<int> a, b;
	

	//괄호 먼저 계산
	for (i = 0; i < cnt - 1; i++) {
		if (visited[i] == 1) {
			if (t[i] == 1) a.push_back(p[i] + p[i + 1]);
			else if (t[i] == 2) a.push_back(p[i] - p[i + 1]);
			else a.push_back(p[i] * p[i + 1]);

			if (t[i + 1] != 0) b.push_back(t[i + 1]);
			i++;
		}
		else {
			a.push_back(p[i]);
			b.push_back(t[i]);
		}
	}
	if (visited[cnt - 2] != 1) a.push_back(p[cnt - 1]);

	sum = a[0];
	a.erase(a.begin());
	while (!b.empty()) {
		if (b.front() == 1) sum += a.front();
		else if (b.front() == 2) sum -= a.front();
		else sum *= a.front();

		a.erase(a.begin());
		b.erase(b.begin());
	}

	if (maxx < sum) maxx = sum;
}

void per(int v) {
	if (v >= cnt - 1) {
		cal();
		return;
	}

	if (visited[v - 1] != 1) {
		visited[v] = 1;
		per(v + 1);
	}
	visited[v] = 0;
	per(v + 1);
}

int main() {
	char c[21];
	int i;

	scanf("%d", &n);
	
	scanf("%s", c);

	for (i = 0; i < strlen(c) - 1; i += 2) {
		p[cnt] = c[i] - '0';
		if (c[i + 1] == '+') t[cnt++] = 1;
		else if (c[i + 1] == '-') t[cnt++] = 2;
		else t[cnt++] = 3;
	}
	p[cnt++] = c[strlen(c) - 1] - '0';

	per(0);

	printf("%d\n", maxx);
}