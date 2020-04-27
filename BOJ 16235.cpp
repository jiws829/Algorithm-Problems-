/*
<16235 - 나무 재테크>
nXn 크기의 배열 벡터를 만들어준다.
나무들은 벡터 하나에 차근차근 넣어지게 된다.

봄에 양분을 먹고, 죽으면 체크해둔다.
여름에는 죽은 나무들을 벡터에서 지워준다
가을에는 새 묘목들을 늘리고
겨울에 양분을 추가해주면 된다.

모든 과정이 끝나고 배열들의 벡터 안에 있는 원소 개수를 합하면 정답이 된다.
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
int a[11][11], b[11][11];

struct tree {
	int age;
	int dead;
}tmp;
vector<tree> p[11][11];

int sort_n(tree x, tree y) {
	if (x.age < y.age) return 1;
	else return 0;
}

int main() {
	int i, j;
	int x, y, z;
	int age;
	int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };

	scanf("%d %d %d", &n, &m, &k);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = 5;
		}
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		tmp.age = z;
		tmp.dead = 0;
		p[x][y].push_back(tmp);
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (p[i][j].size() > 0) {
				sort(p[i][j].begin(), p[i][j].end(),sort_n);
			}
		}
	}

	while (k > 0) {
		k--;
		//spring
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				for (int kk = 0; kk < p[i][j].size(); kk++) {
					if (b[i][j] >= p[i][j][kk].age) {
						b[i][j] -= p[i][j][kk].age;
						p[i][j][kk].age++;
					}
					else p[i][j][kk].dead = 1;
				}
			}
		}
		//summer
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				for (int kk = 0; kk < p[i][j].size(); ) {
					if (p[i][j][kk].dead == 1) {
						b[i][j] += p[i][j][kk].age / 2;
						p[i][j].erase(p[i][j].begin() + kk);
					}
					else kk++;
				}
			}
		}

		//fall
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				for (int kk = 0; kk < p[i][j].size(); kk++) {
					if (p[i][j][kk].age % 5 == 0) {
						for (int ll = 0; ll < 8; ll++) {
							if (i + dx[ll]<1 || i + dx[ll]>n || j + dy[ll]<1 || j + dy[ll]>n) continue;
							tmp.age = 1;
							tmp.dead = 0;
							p[i + dx[ll]][j + dy[ll]].insert(p[i + dx[ll]][j + dy[ll]].begin(),tmp);
						}
					}
				}
			}
		}

		//winter
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				b[i][j] += a[i][j];
			}
		}
	}
	int sum = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) sum += p[i][j].size();
	}
	printf("%d\n", sum);
}