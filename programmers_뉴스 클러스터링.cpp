#include <string>
#include <iostream>

#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int i, j;
    int numa, numb;
    vector<string> a, b;
    string str;

    int ans1, ans2;
    ans1 = ans2 = 0;

    map<string, int> ma, mb;
    map<string, int>::iterator iter;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (i = 0; i < str1.size() - 1; i++) {
        str = str1.substr(i, 2);
        if (str[0] >= 'a' && str[1] >= 'a' && str[0] <= 'z' && str[1] <= 'z') {
            a.push_back(str);
            ma[a[a.size() - 1]]++;
        }
    }
    for (i = 0; i < str2.size() - 1; i++) {
        str = str2.substr(i, 2);
        if (str[0] >= 'a' && str[1] >= 'a' && str[0] <= 'z' && str[1] <= 'z') {
            b.push_back(str);
            mb[b[b.size() - 1]]++;
        }
    }

    
    for (i = 0; i < a.size(); i++) {
        iter = ma.find(a[i]);
        if (iter == ma.end()) continue;

        numa = ma[a[i]];

        iter = mb.find(a[i]);
        if (iter != mb.end()) { //겹치는 애들
            numb = iter->second;
            if (numa <= numb) { ans1 += numa; ans2 += numb; }
            else { ans1 += numb; ans2 += numa; }
            mb.erase(a[i]);
        }
        else {
            ans2 += numa;
        }
        ma.erase(a[i]);
    }
    
    for (i = 0; i < b.size(); i++) {
        iter = mb.find(b[i]);

        if (iter != mb.end()) {
            ans2 += iter->second;
            mb.erase(b[i]);
        }
    }

    double ans;
    if (ans1 == 0 && ans2 == 0) ans = 1.0;
    else ans = (double)ans1 / ans2;
    
    ans *= 65536;

    answer = (int)ans;

    return answer;
}

int main() {
    int answer = solution("FRANCE","french");
    //int answer = solution("aa1+aa2", "AAAA12");
    //int answer = solution("E=M*C^2", "e=m*c^2");
    //int answer = solution("ABDDDD", "DDDEFGGG");

    cout << answer << endl;
}