#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<vector<int>> food;
vector<int> p;

int sort_n(vector<int> a, vector<int> b) {
    if (a[1] == b[1] && a[0] < b[0]) return 1;
    if (a[1] < b[1]) return 1;
    return 0;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int i;

    int flag = 0;

    for (i = 0; i < food_times.size(); i++) {
        food.push_back({ i + 1,food_times[i] });
    }
    sort(food.begin(), food.end(), sort_n);
    //for (i = 0; i < food.size(); i++) printf("%d %d\n", food[i][0], food[i][1]);

    for (i = 0; i < food.size(); i++) {

        if ((i > 0 && (long long)(food.size() - i) * (food[i][1] - food[i - 1][1]) <= k) || (i == 0 && (long long)(food.size() - i) * food[i][1] <= k)) {
            if (i == 0) k -= (long long)(food.size() - i) * food[i][1];
            else k -= (long long)(food.size() - i) * (food[i][1] - food[i - 1][1]);
            //printf("%lld\n", k);
        }
        else {
            flag = 1;
            break;
        }
    }

    if (flag == 0) answer = -1;
    else {
        for (int j = i; j < food.size(); j++) p.push_back(food[j][0]);
        sort(p.begin(), p.end());
        
        k %= p.size();

        answer = p[k];
    }

    return answer;
}

int main() {
    vector<int> food_times = { 3,1,2 };
    long long k = 5;

    int answer = solution(food_times, k);

    cout << answer << endl;
}