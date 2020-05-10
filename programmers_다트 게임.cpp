#include <string>
#include<iostream>

using namespace std;

int p[3];
int star[3];
int m[3];

int solution(string dartResult) {
    int answer = 0;
    string s = dartResult;
    int i,num,pos;
    pos = 0;
    for (i = 0; i < 3; i++) {
        num = 0;
        while (1) {
            if (!(s[pos]>='0' && s[pos]<='9')) break;
            num *= 10;
            num += s[pos] - '0';
            pos++;
        }
        

        if (s[pos] == 'S') p[i] = num;
        else if (s[pos] == 'D') p[i] = num * num;
        else p[i] = num * num * num;
        pos++;

        if (s[pos] == '*') {
            if (i != 0) star[i - 1]++;
            star[i]++;
            pos++;
        }
        else if (s[pos] == '#') {
            m[i] = 1;
            pos++;
        }
    }
    int now;
    for (i = 0; i < 3; i++) {
        now = p[i];
        //cout << now << endl;
        if (star[i] == 1) now *= 2;
        else if (star[i] == 2) now *= 4;

        if (m[i] == 1) now *= (-1);

        answer += now;
    }
    return answer;
}

int main() {
    string s = "1D2S#10S";
    int answer = solution(s);

    cout << answer << endl;
}