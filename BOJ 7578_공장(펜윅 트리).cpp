#include<iostream>

using namespace std;

int n;
int input[1000001];
int p[500001];
long long tree[500001];

void update(int num) {
	while (num <= n) {
		tree[num]++;
		num += (num & -num);
	}
}

long long sum(int num) {
	long long ans = 0;
	while (num > 0) {
		ans += tree[num];
		num -= (num & -num);
	}

	return ans;
}

int main() {
	int i;
	int a;
	long long answer = 0;
	
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a;
		input[a] = i;
	}
	for (i = 1; i <= n; i++) {
		cin >> a;
		p[i] = input[a];
	}

	for (i = 1; i <= n; i++) {
		update(p[i]);
		answer += sum(n) - sum(p[i]);
	}

	cout << answer;
}