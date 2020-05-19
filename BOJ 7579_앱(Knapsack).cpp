#include<iostream>
using namespace std;

int n, m;
int byte[101], cost[101];
int p[101][10001];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	//freopen("input.txt", "r", stdin);

	int i, j;
	int sum = 0;
	int answer = -1;

	cin >> n >> m;
	for (i = 1; i <= n; i++) cin >> byte[i];
	for (i = 1; i <= n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= sum; j++) {
			if (j < cost[i]) p[i][j] = p[i - 1][j];
			else p[i][j] = max(p[i - 1][j], byte[i] + p[i - 1][j - cost[i]]);

			//p[i][j]는 i번째 프로세스를 봤을때 j의 cost를 사용해서 얻을수 있는 최대 메모리량
		}
	}

	for (j = 0; j <= sum; j++) {
		for (i = 1; i <= n; i++) {
			if (p[i][j] >= m) {
				answer = j;
				break;
			}
		}
		if (answer != -1) break;
	}

	cout << answer;
}