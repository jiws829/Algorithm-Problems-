#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int p[1001][1001];

int main() {
	//freopen("input.txt", "r", stdin);

	string a, b;
	int n, m;
	int i, j;

	cin >> a >> b;

	n = a.size();
	m = b.size();

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) p[i][j] = p[i - 1][j - 1] + 1;
			else {
				if (p[i - 1][j] > p[i][j - 1]) p[i][j] = p[i - 1][j];
				else p[i][j] = p[i][j - 1];
			}
		}
	}

	cout << p[n][m];
}