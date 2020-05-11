#include <string>
#include <vector>
#include<iostream>

using namespace std;

char c[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string solution(int n, int t, int m, int p) {
    string answer = "";

    int num = -1;
    int count = 0;
    int turn = 1;

    while (count < t) {
        num++;
        int tmp = num;
        int q[100001], cnt = 0;
        
        do {
            q[cnt++] = tmp % n;
            tmp /= n;
        } while (tmp > 0);

        for (int i = cnt - 1; i >= 0; i--) {

            if (turn == p) {
                answer += c[q[i]];
                count++;

                if (count >= t) break;
            }
            turn++;
            if (turn > m) turn = 1;
        }
        if (count >= t) break;
    }

    
    return answer;
}

int main() {
    string answer = solution(16, 16, 2, 1);
    //string answer = solution(16, 16, 2, 2);
    cout << answer << endl;
}