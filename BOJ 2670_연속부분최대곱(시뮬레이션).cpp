#include<iostream>
#include<cstdio>

using namespace std;

int n;
double p[10001];

int main() {
	//freopen("input.txt", "r", stdin);

	int i, j;
	double max = -99.0;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> p[i];

	for (i = 0; i < n; i++) {
		double tmp = 1.0;
		for (j = i; j < n; j++) {
			tmp *= p[j];
			if (max < tmp) max = tmp;
		}
	}

	printf("%.3lf\n", max);
}