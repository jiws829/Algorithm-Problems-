#include <string>
#include <vector>

#include<map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> total;
    map<string, int>::iterator iter;
    int count = 0;
    for (int i = 0; i < gems.size(); i++) {
        iter = total.find(gems[i]);
        if (iter == total.end()) {
            count++;
            total[gems[i]] = 1;
        }
    }


    map<string, int> m;
    int left = 0, right = 0;
    int cnt = 1;
    m[gems[0]] = 1;

    int min = 21000000;
    int l, r;

    while (left < gems.size() && right < gems.size()) {
        //printf("%d %d -> %d\n", left, right, cnt);
        if (cnt < count) {
            right++;
            if (right >= gems.size()) break;
            iter = m.find(gems[right]);
            if (iter == m.end()) {
                m[gems[right]] = 1;
                cnt++;
            }
            else m[gems[right]]++;
        }
        else {
            if (min > right - left || (min == left - right && l > left)) {
                min = right - left;
                l = left; r = right;
            }

            if (m[gems[left]] == 1) {
                m.erase(gems[left]);
                cnt--;
            }
            else m[gems[left]]--;
            left++;
            if (left >= gems.size()) break;
        }
    }
    answer.push_back(l + 1);
    answer.push_back(r + 1);

    return answer;
}