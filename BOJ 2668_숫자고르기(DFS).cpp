#include<iostream>
#include<vector>

using namespace std;

int n;
int p[101];
int q[101];

vector<int> dfs(int num) {
	int a = num, b;
	vector<int> check(n + 1);
	while (1) {
		b = p[a];

		if (b == num) {
			check[b] = 1;
			return check;
		}
		if (check[b] == 1) {
			vector<int> tmp(n + 1);
			return tmp;
		}
		check[b] = 1;
		a = b;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	int i, j;
	int count = 1;
	int answer = 0;
	
	cin >> n;
	for (i = 1; i <= n; i++) cin >> p[i];

	for (i = 1; i <= n; i++) {
		if (q[i] == 0) {
			vector<int> tmp = dfs(i);
			int flag = 0;
			for (j = 1; j <= n; j++) {
				if (tmp[j] == 1) { q[j] = count; flag = 1; answer++; }
			}
			if (flag) {
				count++;
			}
		}
	}

	cout << answer << '\n';
	for (i = 1; i <= n; i++) {
		if (q[i] > 0) cout << i << '\n';
	}

}