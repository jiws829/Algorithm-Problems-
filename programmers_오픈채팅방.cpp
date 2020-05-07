#include <string>
#include <vector>
#include<iostream>

#include<map>

using namespace std;

string p[100001][2];
map<string, string> m;

vector<string> solution(vector<string> record) {

    vector<string> answer;
    int cnt = 0;
    
    int i, j;
    string a, b, c;
    int now,last;
    
    for (i = 0; i < record.size(); i++) {
        
        now = 0;
        for (j = 0; j < record[i].size(); j++) {
            if (record[i][j] == ' ') {
                if (now == 0) {
                    now = 1;
                    a = record[i].substr(0, j);
                    last = j + 1;
                    if (a.compare("Leave") == 0) {
                        b = record[i].substr(j + 1);
                        c = "";
                        break;
                    }
                }
                else if (now == 1) {
                    now = 2;
                    b = record[i].substr(last, j - last);
                    c = record[i].substr(j + 1);
                    break;
                }
            }
        }

        if (a.compare("Enter") == 0 || a.compare("Leave") == 0) {
            p[cnt][0] = a;
            p[cnt++][1] = b;
        }

        if (a.compare("Enter") == 0 || a.compare("Change") == 0) {
            m[b] = c;
        }
    }

    for (i = 0; i < cnt; i++) {
        string str = "";
        if (p[i][0].compare("Enter") == 0) {
            str += m[p[i][1]] + "님이 들어왔습니다.";
        }
        else {
            str += m[p[i][1]] + "님이 나갔습니다.";
        }
        answer.push_back(str);
    }

    return answer;
}

int main() {
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> answer = solution(record);
    
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}