#include<iostream>
#include<string>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);

	string str;
	int state = 0, i;

	cin >> str;

	for (i = 0; i < str.size(); i++) {
		if (state == 0) {
			if (str[i] == '0') state = 5;
			else state = 1;
		}
		else if (state == 1) {
			if (str[i] == '0') state = 2;
			else break;
		}
		else if (state == 2) {
			if (str[i] == '0') state = 3;
			else break;
		}
		else if (state == 3) {
			if (str[i] == '0') state = 3;
			else state = 4;
		}
		else if (state == 4) {
			if (str[i] == '0') state = 5;
			else state = 7;
		}
		else if (state == 5) {
			if (str[i] == '0') break;
			else state = 6;
		}
		else if (state == 6) {
			if (str[i] == '0') state = 5;
			else state = 1;
		}
		else if (state == 7) {
			if (str[i] == '0') state = 8;
			else state = 7;
		}
		else if (state == 8) {
			if (str[i] == '0') state = 3;
			else state = 6;
		}
	}

	if (i == str.size() && (state == 4 || state == 7 || state == 6)) cout << "SUBMARINE";
	else cout << "NOISE";
}