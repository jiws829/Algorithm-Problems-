#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
struct rects {
	double a, b, c, d;
}tmp;
vector<rects> p;

int x_index[10001], y_index[10001];

bool check(double a, double b, double c, double d) {
	int i;
	for (i = 0; i < p.size(); i++) {
		if (p[i].a <= a && c <= p[i].c && p[i].b <= b && d <= p[i].d) return true;
	}
	return false;
}


int main() {

	int i, j;
	double sum = 0;
	vector<double> x, y;

	cin >> n;
	for (i = 0; i < n; i++) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;

		tmp.a = a;
		tmp.b = b;
		tmp.c = a + c;
		tmp.d = b + d;
		p.push_back(tmp);

		if (x_index[(int)a * 10] == 0) { x.push_back(a); x_index[(int)a * 10] = 1; }
		if (x_index[(int)(a+c) * 10] == 0) { x.push_back(a+c); x_index[(int)(a+c) * 10] = 1; }
		if (y_index[(int)b * 10] == 0) { y.push_back(b); y_index[(int)b * 10] = 1; }
		if (y_index[(int)(b+d) * 10] == 0) { y.push_back(b+d); y_index[(int)(b+d) * 10] = 1; }
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for (i = 1; i < x.size(); i++) {
		for (j = 1; j < y.size(); j++) {
			if (check(x[i - 1], y[j - 1], x[i], y[j]) == true) {
				sum += (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
			}
		}
	}

	if (sum == (long long)sum) cout << (long long)sum;
	else printf("%.2lf\n", sum);
}