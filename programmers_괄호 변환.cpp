#include <string>
#include <vector>
#include<iostream>

using namespace std;

bool check(string p) {
    int cnt = 0, i;

    for (i = 0; i < p.size(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;

        if (cnt < 0) return false;
    }
    if (cnt == 0) return true;
    else return false;
}

string solution(string p) {
    string answer = "";
    string u, v;
    int i;
    int cnt = 0;

    //1
    if (p.size() == 0) return "";

    //2
    if (p[0] == '(') cnt++;
    else cnt--;

    for (i = 1; i < p.size(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;

        if (cnt == 0) break;
    }
    u = p.substr(0, i + 1);
    v = p.substr(i + 1);

    //3
    if (check(u) == true) {
        answer = u + solution(v);
    }
    //4
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        for (i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') answer += ')';
            else answer += '(';
        }
    }

    return answer;
}

int main() {
    string p = "()))((()";

    string answer = solution(p);

    cout << answer;
}