#include <string>
#include <vector>
#include<iostream>

#include<algorithm>
#include<string.h>
using namespace std;

int check[2001];

class times {
public:
    int index;
    double a, b;

    times(int index, double a, double b) {
        this->index = index;
        this->a = a;
        this->b = b;
    }
};

int compare(times a, times b) {
    if (a.a < b.a) return 1;
    return 0;
}

int solution(vector<string> lines) {
    vector<times> time;
    int answer = -999;
    int cnt, cn;
    int i, j;
    int h, m;
    double s, dur;

    for (i = 0; i < lines.size(); i++) {
        h = (lines[i][11] - '0') * 10 + lines[i][12] - '0';
        m = (lines[i][14] - '0') * 10 + lines[i][15] - '0';
        s = (double)(lines[i][17] - '0') * 10 + lines[i][18] - '0' + (lines[i][20] - '0') * 0.1 + (lines[i][21] - '0') * 0.01 + (lines[i][22] - '0') * 0.001;

        s += (double)h * 3600 + m * 60;

        string str = lines[i].substr(24);
        double tmp = 1.0;
        dur = 0;
        for (j = 0; j < str.size() - 1; j++) {
            if (str[j] == '.') continue;
            dur += (double)tmp * (str[j] - '0');
            tmp *= 0.1;
        }
        
        tmp = s - dur;
        tmp += 0.001;

        if (tmp < 0) tmp = 0;
        time.push_back(times(i, tmp, s));
    }
    sort(time.begin(), time.end(), compare);
    
    for (i = 0; i < time.size(); i++) {
        memset(check, 0, sizeof(check));
        cnt = cn = 1;
        for (j = 0; j < i; j++) {
            if (time[j].a <= time[i].a && time[i].a <= time[j].b) cnt++;
            else if (time[i].a - time[j].b < 1.0) cnt++;
        }

        for (j = i + 1; j < time.size(); j++) {
            if (time[i].b <= time[j].a && time[j].a - time[i].b < 1.0) cn++;
            else if (time[j].a <= time[i].b && time[i].b <= time[j].b) cn++;
        }
        if (answer < cnt) answer = cnt;
        if (answer < cn) answer = cn;
    }

    return answer;
}

int main() {
    int answer = solution({ "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" });

    cout << answer << endl;
}