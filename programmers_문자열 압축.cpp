#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int i, j;
    int cnt;
    string a, b;
    
    
    for (i = 1; i <= s.size() / 2; i++) {
        a = s.substr(0, i);
        cnt = 1;
        string ans;
        
        for (j = i; j < s.size(); j += i) {
            b = s.substr(j, i);
            
            if (a.compare(b) == 0) cnt++;
            else {
                if (cnt > 1) {
                    ans += to_string(cnt) + a;
                    a = b;
                    cnt = 1;
                }
                else {
                    ans += a;
                    a = b;
                }
            }

            if (j + i >= s.size()) {
                if (cnt > 1) ans += to_string(cnt) + a;
                else ans += a;
                break;
            }
        }
        
        if (answer > ans.size()) answer = ans.size();
    }

    return answer;
}

int main() {
    string s = "aabbaccc";

    int answer = solution(s);

    printf("%d\n", answer);
}