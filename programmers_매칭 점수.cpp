#include <string>
#include <vector>
#include<iostream>

#include<algorithm>
#include<map>

using namespace std;

map<string, int> m;
map<string, int>::iterator iter;
int p[22];
int cnt[22];
int graph[22][22];
double point[22];

int solution(string word, vector<string> pages) {
    int answer = 0;
    int i, j;
    int st, en, mid;
    string str;

    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (i = 0; i < pages.size(); i++) {
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);

        //meta
        st = en = mid = 0;
        while (mid <= st) {
            st = pages[i].find("<meta", st + 1);
            en = pages[i].find(">", st);
            mid = pages[i].rfind("https://", en);
        }
        en = pages[i].find("\"/", mid);
        str = pages[i].substr(mid, en - mid);
        m[str] = i;


        //body
        st = pages[i].find("<body>", en);
        for (j = st;;) {
            j = pages[i].find(word, j + 1);
            if (j == string::npos) break;
            else {
                if (!(pages[i][j - 1] >= 'a' && pages[i][j - 1] <= 'z') && !(pages[i][j + word.size()] >= 'a' && pages[i][j + word.size()] <= 'z')) {
                    p[i]++;
                    j += word.size();
                }
            }
        }
    }

    //link
    for (i = 0; i < pages.size(); i++) {
        for (st = 0, en = 0;;) {
            st = pages[i].find("<a href", en);
            if (st == string::npos) break;
            else {
                cnt[i]++;
                st = pages[i].find("https://", st);
                en = pages[i].find("\"", st);
                str = pages[i].substr(st, en - st);

                iter = m.find(str);
                if (iter != m.end()) {
                    graph[i][iter->second] = 1;
                }
            }
        }
    }

    //점수 계산
    for (i = 0; i < pages.size(); i++) {
        for (j = 0; j < pages.size(); j++) {
            if (i == j) continue;

            if (graph[i][j] == 1) {
                point[j] += (double)p[i] / cnt[i];
            }
        }
    }
    for (i = 0; i < pages.size(); i++) point[i] += (double)p[i];

    double max = -999.0;
    for (i = 0; i < pages.size(); i++) {
        if (max < point[i]) { max = point[i]; answer = i; }
    }

    return answer;
}

int main() {
 
    string word = "blind";
    vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };

    int answer = solution(word, pages);
    cout << answer << endl;
}