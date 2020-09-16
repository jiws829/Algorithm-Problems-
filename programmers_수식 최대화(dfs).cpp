#include <string>
#include <vector>

using namespace std;

int check[3], cnt;
int visited[3];
int permu[3];
vector<long long> num, op;
long long ans;

long long cal(int size) {
    vector<long long> a, b;
    a = num;
    b = op;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < b.size(); j++) {
            if (b[j] == permu[i]) {
                long long tmp;
                if (b[j] == 0) tmp = a[j] + a[j + 1];
                else if (b[j] == 1) tmp = a[j] - a[j + 1];
                else tmp = a[j] * a[j + 1];

                b.erase(b.begin() + j);
                a[j] = tmp;
                a.erase(a.begin() + j + 1);
                j--;
            }
        }
    }
    return a[0];
}

void per(int v, int size) {
    if (v == size) {
        //for (int i = 0; i < size; i++) printf("%d ", permu[i]);
        //printf("\n");

        long long a = cal(size);
        if (a < 0) a *= (-1);
        //printf("%lld\n", a);

        if (ans < a) ans = a;

        return;
    }
    for (int i = 0; i < 3; i++) {
        if (check[i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            permu[v] = i;
            per(v + 1, size);
            visited[i] = 0;
            permu[v] = 0;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;

    int sum = 0;

    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') { sum *= 10; sum += expression[i] - '0'; }
        else {
            num.push_back(sum);
            sum = 0;
            if (expression[i] == '+') {
                op.push_back(0);
                if (check[0] == 0) { check[0] = 1; cnt++; }
            }
            else if (expression[i] == '-') {
                op.push_back(1);
                if (check[1] == 0) { check[1] = 1; cnt++; }
            }
            else {
                op.push_back(2);
                if (check[2] == 0) { check[2] = 1; cnt++; }
            }
        }
    }
    num.push_back(sum);
    /*for (int i = 0; i < num.size(); i++) printf("%d ", num[i]);
    printf("\n");
    for (int i = 0; i < op.size(); i++) printf("%d ", op[i]);*/

    per(0, cnt);

    answer = ans;

    return answer;
}