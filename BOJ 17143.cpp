/*
<17143 - 낚시왕>
시뮬레이션 문제로 상황에 맞게 상어를 움직인 후, 상어가 서로 잡아먹는 상황이나 낚시를 성공하는 상황에 맞게 상어를 지워주면 된다.

상어의 이동은 3가지 페이즈가 있다.
1. 벽에 1번도 안 부딪히는 경우
2. 벽에 1번만 부딪히는 경우
3. 벽에 2번 부딪히는 경우

이 경우에 맞게 상어 위치를 계산해주면 된다.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int r, c, m;
struct sharks {
	int x, y, s, d, z;
	char name;
}tmp;
vector<sharks> p;
int ans;

int sort_n(sharks a, sharks b) {
	if (a.y == b.y && a.x == b.x && a.z <= b.z) return 1;
	if (a.y == b.y && a.x < b.x) return 1;
	if (a.y < b.y) return 1;
	return 0;
}

int main() {
	int i, j, k;
	int x, y, s, d;

	cin >> r >> c >> m;

	if (m == 0) {
		cout << "0";
		return 0;
	}

	for (i = 0; i < m; i++) {
		cin >> tmp.x >> tmp.y >> tmp.s >> tmp.d >> tmp.z;
		tmp.name = 'A' + i;
		p.push_back(tmp);
	}
	

	for (k = 1; k <= c; k++) {
		//상어 정렬
		sort(p.begin(), p.end(), sort_n);

		//상어 잡아먹기
		for (i = 0; i < p.size() - 1;) {
			if (p[i].x == p[i + 1].x && p[i].y == p[i + 1].y) p.erase(p.begin() + i);
			else i++;
		}
		//상어 잡기
		for (i = 0; i < p.size(); i++) {
			if (p[i].y == k) {
				ans += p[i].z;
				p.erase(p.begin() + i);
				break;
			}
		}

		//상어 이동
		for (i = 0; i < p.size(); i++) {
			x = p[i].x;
			y = p[i].y;
			s = p[i].s;
			d = p[i].d;
			if (d == 1) {  //위
				s %= 2 * (r - 1);
				//1
				x -= s;

				//2
				if (x <= 1) { x = (1 - x) + 1; d = 2; }
				
				//3
				if (x >= r) { x = r - (x - r); d = 1; }				
			}
			else if (d == 2) {  //아래
				s %= 2 * (r - 1);
				//1
				x += s;

				//2
				if (x >= r) { x = r - (x - r); d = 1; }

				//3
				if (x <= 1) { x = (1 - x) + 1; d = 2; }
			}
			else if (d == 3) {  //오른쪽
				s %= 2 * (c - 1);
				//1
				y += s;

				//2
				if (y >= c) { y = c - (y - c); d = 4; }
				
				//3
				if (y <= 1) { y = (1 - y) + 1; d = 3; }
			}
			else if (d == 4) {  //왼쪽
				s %= 2 * (c - 1);
				//1
				y -= s;
				
				//2
				if (y <= 1) { y = (1 - y) + 1; d = 3; }
				
				//3
				if (y >= c) { y = c - (y - c); d = 4; }
			}
			p[i].x = x;
			p[i].y = y;
			p[i].d = d;
		}
	}

	cout << ans;



}