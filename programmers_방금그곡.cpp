#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maxx = -999;
    int i, j, k;
    string x, y, z, str;

    string n="";
    for (i = 0; i < m.size(); i++) {
        if (i + 1 < m.size() && m[i + 1] == '#') {
            switch (m[i]) {
            case 'C':n += 'H'; break;
            case 'D':n += 'I'; break;
            case 'F':n += 'J'; break;
            case 'G':n += 'K'; break;
            case 'A':n += 'L'; break;
            }
            i++;
        }
        else n += m[i];
    }

    for (i = 0; i < musicinfos.size(); i++) {
        int a = ((musicinfos[i][0] - '0') * 10 + musicinfos[i][1] - '0') * 60 + (musicinfos[i][3] - '0') * 10 + musicinfos[i][4] - '0';
        int b = ((musicinfos[i][6] - '0') * 10 + musicinfos[i][7] - '0') * 60 + (musicinfos[i][9] - '0') * 10 + musicinfos[i][10] - '0';
        for (j = 12; j < musicinfos[i].size(); j++) {
            if (musicinfos[i][j] == ',') break;
        }
        x = musicinfos[i].substr(12, j - 12);
        y = musicinfos[i].substr(j + 1);
        z = "";
        for (j = 0; j < y.size(); j++) {
            if (j + 1 < y.size() && y[j + 1] == '#') {
                switch (y[j]) {
                case 'C':z += 'H'; break;
                case 'D':z += 'I'; break;
                case 'F':z += 'J'; break;
                case 'G':z += 'K'; break;
                case 'A':z += 'L'; break;
                }
                j++;
            }
            else z += y[j];
        }
        
        k = 0;
        str = "";
        for (j = 0; j < b - a; j++) {
            str += z[k++];
            if (k >= z.size()) k = 0;
        }

        if (str.size() < n.size()) continue;

        for (j = 0; j <= str.size() - n.size(); j++) {
            y = str.substr(j, n.size());

            if (n.compare(y) == 0) {
                if (maxx < b - a) {
                    maxx = b - a;
                    answer = x;
                }
            }
        }

    }

    return answer;
}

int main() {
    string answer = solution("ABCC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" });
    

    cout << answer << endl;
}