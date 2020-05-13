#include <string>
#include <vector>
#include<iostream>

#include<map>
using namespace std;

map<string, int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int>::iterator iter;
    string str;
    int i, j, cnt;

    for (i = 1; i <= 26; i++) {
        char c = 'A' + i - 1;
        str = "";
        str += c;
        m[str] = i;
    }
    cnt = 27;

    for (i = 0; i < msg.size(); i++) {
        for (j = 1;i+j-1<msg.size();j++) {
            str = msg.substr(i, j);
            iter = m.find(str);
            if (iter == m.end()) {
                m[str] = cnt++;
                break;
            }
        }
        str = msg.substr(i, j - 1);
        answer.push_back(m[str]);
        i += j - 2;
    }

    return answer;
}

int main() {
    string str = "KAKAO";
    vector<int> answer = solution(str);

    for (int i = 0; i < answer.size(); i++) printf("%d ", answer[i]);
}