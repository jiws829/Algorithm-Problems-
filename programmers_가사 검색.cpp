#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> p[10001],t[10001];
    string s;
    int i, j;
    int maxx = 0;
    int minn = 1000000;
    
    for (i = 0; i < words.size(); i++) {
        p[words[i].size()].push_back(words[i]);
        s = words[i];
        reverse(s.begin(), s.end());
        t[s.size()].push_back(s);
        if (minn > words[i].size()) minn = words[i].size();
        if (maxx < words[i].size()) maxx = words[i].size();
    }
    
    for (i = minn; i <= maxx; i++) {
        sort(p[i].begin(), p[i].end());
        sort(t[i].begin(), t[i].end());
    }
    
    for (i = 0; i < queries.size(); i++) {
        if (queries[i][0] == '?' && queries[i][queries[i].size() - 1] == '?') {
            answer.push_back(p[queries[i].size()].size());
            continue;
        }
        if (queries[i][0] != '?') {  //fro?? 인 경우
            for (j = queries[i].size() - 1; j >= 0; j--) {
                if (queries[i][j] != '?') break;
            }
            s = queries[i].substr(0, j + 1);

            if (p[queries[i].size()].size() == 0) { answer.push_back(0); continue; }
            int st, en, mid;
            int a = -1, b = -1;
            st = 0;
            en = p[queries[i].size()].size() - 1;
            while (st <= en) {
                mid = (st + en) / 2;
                
                if (s.compare(p[queries[i].size()][mid]) < 0) {
                    en = mid - 1;
                }
                else {
                    st = mid + 1;
                    a = mid;
                }
            }
            
            s[s.size() - 1]++;
            
            st = 0;
            en = p[queries[i].size()].size() - 1;
            while (st <= en) {
                mid = (st + en) / 2;
                
                if (s.compare(p[queries[i].size()][mid]) < 0) {
                    en = mid - 1;
                }
                else {
                    st = mid + 1;
                    b = mid;
                }
            }
            
            answer.push_back(b - a);
        }
        else {   //????o 인 경우
            for (j = 0; j < queries[i].size(); j++) {
                if (queries[i][j] != '?') break;
            }
            s = queries[i].substr(j);
            reverse(s.begin(), s.end());

            if (t[queries[i].size()].size() == 0) { answer.push_back(0); continue; }
            int st, en, mid;
            int a = -1, b = -1;
            st = 0;
            en = t[queries[i].size()].size() - 1;
            while (st <= en) {
                mid = (st + en) / 2;
                
                if (s.compare(t[queries[i].size()][mid]) < 0) {
                    en = mid - 1;
                }
                else {
                    st = mid + 1;
                    a = mid;
                }
            }

            s[s.size() - 1]++;
            
            st = 0;
            en = t[queries[i].size()].size() - 1;
            while (st <= en) {
                mid = (st + en) / 2;
                
                if (s.compare(t[queries[i].size()][mid]) < 0) {
                    en = mid - 1;
                }
                else {
                    st = mid + 1;
                    b = mid;
                }
            }
            answer.push_back(b - a);
        }
    }


    return answer;
}

int main() {
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" , "??????" };

    vector<int> answer = solution(words, queries);

    for (int i = 0; i < answer.size(); i++) cout << answer[i] << " ";
    printf("\n");
}