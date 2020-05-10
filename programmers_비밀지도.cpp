#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int p[17][17] = { 0, };
    string str;

    int i, j, num;
    for (i = 0; i < n; i++) {
        j = n - 1;
        num = arr1[i];
        while (num > 0) {
            if (num % 2 == 1) {
                p[i][j] = 1;
            }
            j--;
            num /= 2;
        }

        j = n - 1;
        num = arr2[i];
        while (num > 0) {
            if (num % 2 == 1) {
                p[i][j] = 1;
            }
            j--;
            num /= 2;
        }
    }
    for (i = 0; i < n; i++) {
        str = "";
        for (j = 0; j < n; j++) {
            if (p[i][j] == 1) str += '#';
            else str += " ";
        }
        answer.push_back(str);
    }

    return answer;
}

int main() {
    int n = 5;
    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };


    vector<string> answer = solution(n, arr1, arr2);

    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}