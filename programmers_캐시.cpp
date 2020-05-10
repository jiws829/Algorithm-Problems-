#include <string>
#include <vector>
#include<iostream>

#include<algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cnt = 0, i, j;
    int hit;
    vector<string> c;

    for (i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        if (cacheSize == 0) {
            answer += 5;
            continue;
        }

        hit = -1;
        for (j = 0; j < c.size(); j++) {
            if (c[j].compare(cities[i]) == 0) {
                hit = j;
                break;
            }
        }

        if (hit != -1) {  //hit
            c.erase(c.begin() + hit);
            answer += 1;
        }
        else {   //miss
            if (c.size() == cacheSize) c.erase(c.begin());
            answer += 5;
        }
        c.push_back(cities[i]);
    }

    return answer;
}

int main() {
    int n = 3;
    vector<string> a = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    int answer = solution(n, a);

    cout << answer << endl;
}