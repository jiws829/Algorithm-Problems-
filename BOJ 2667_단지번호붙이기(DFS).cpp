#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n;
int p[26][26];

int count(int x, int y) {
	int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
	int sum = 0;

	p[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n && p[x + dx[i]][y + dy[i]] == 1) {
			sum += count(x + dx[i], y + dy[i]);
		}
	}
	return sum + 1;
}

int main() {

	int i, j;
	vector<int> answer;

	cin >> n;
	for (i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (j = 0; j < str.size(); j++) {
			p[i][j] = str[j] - '0';
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (p[i][j] == 1) {
				int cnt=count(i, j);
				answer.push_back(cnt);
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (i = 0; i < answer.size(); i++) cout << answer[i] << '\n';

}