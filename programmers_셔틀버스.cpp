#include <string>
#include <vector>
#include<iostream>

#include<algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> p;
    int i, j;
    int time, now, limit;
    int ans;

    for (i = 0; i < timetable.size(); i++) {
        int num = 0;
        for (j = 0; j < timetable[i].size(); j++) {
            if (timetable[i][j] == ':') continue;
            num *= 10;
            num += timetable[i][j] - '0';
        }
        p.push_back(num);
    }
    sort(p.begin(), p.end());

    time = 900 - t;
    now = 0;
    for (i = 0; i < n; i++) {
        time += t;
        if (time % 100 >= 60) {
            int a = time / 100;
            int b = time % 100;
            a += b / 60;
            time = a * 100 + b % 60;
        }
        limit = m;

        for (j = now;;) {
            if (i == n - 1 && limit == 1) break;
            if (p[j] <= time) {
                j++;
                limit--;
            }
            else break;
            if (limit == 0 || j == p.size()) break;
        }
        now = j;
    }

    if (now == p.size() || time < p[now]) {
        ans = time;
    }
    else {
        if (p[now] % 100 == 0) {
            int a = p[now] / 100;
            a--;
            ans = a * 100 + 59;
        }
        else ans = p[now] - 1;
    }

    int a = ans / 100;
    int b = ans % 100;

    if (a < 10) answer += "0";
    answer += to_string(a) + ":";
    if (b < 10) answer += "0";
    answer += to_string(b);

    return answer;
}

int main() {
    string answer = solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
    cout << answer << endl;
}