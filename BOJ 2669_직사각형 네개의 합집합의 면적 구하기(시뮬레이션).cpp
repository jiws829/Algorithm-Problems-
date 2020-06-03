#include<iostream>

using namespace std;

int n;
int p[101][101];

int main() {
	//freopen("input.txt", "r", stdin);

	int i, j, k;
	int answer = 0;
	
	for (k = 0; k < 4; k++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (i = a; i < c; i++) {
			for (j = b; j < d; j++) p[i][j] = 1;
		}
	}

	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			answer += p[i][j];
		}
	}

	cout << answer << endl;

}