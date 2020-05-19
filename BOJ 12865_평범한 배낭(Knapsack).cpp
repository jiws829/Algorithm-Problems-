#include<iostream>
using namespace std;

int n, k;
int p[102][100001];
int weight[101], value[101];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int i, j;
	
	cin >> n >> k;
	for (i = 1; i <= n; i++) cin >> weight[i] >> value[i];

	for (i = 1; i <= n+1; i++) {
		for (j = 1; j <= k; j++) {
			if (weight[i-1] > j) p[i][j] = p[i - 1][j];
			else p[i][j] = max(value[i-1]+p[i-1][j-weight[i-1]],p[i-1][j]);
		}
	}
	cout << p[n+1][k];
}