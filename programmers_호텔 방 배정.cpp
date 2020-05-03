#include <string>
#include <vector>
#include<stdio.h>

#include<map>

using namespace std;

map<long long, long long> a;

long long find_empty(long long room_number) {
    map<long long, long long>::iterator iter;

    iter = a.find(room_number);
    if (iter == a.end()) {
        a[room_number] = room_number + 1;
        return room_number;
    }

    long long tmp = find_empty(iter->second);
    iter->second = tmp + 1;
    return tmp;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    long long num;

    for (int i = 0; i < room_number.size(); i++) {
        num = find_empty(room_number[i]);
        answer.push_back(num);
    }

    return answer;
}

int main() {
    long long k = 10;
    vector<long long> room_number = { 1,3,4,1,3,1 };

    vector<long long> answer = solution(k, room_number);

    for (int i = 0; i < answer.size(); i++) printf("%lld ", answer[i]);

}