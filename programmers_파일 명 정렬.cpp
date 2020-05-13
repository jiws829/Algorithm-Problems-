#include <string>
#include <vector>
#include<iostream>

#include<algorithm>
using namespace std;

class file {
public :
    string name;
    string head;
    int number;
    int index;
    file(string name, string head, int number, int index) {
        this->name = name;
        this->head = head;
        this->number = number;
        this->index = index;
    }
};

int compare(file a, file b) {
    if (a.head.compare(b.head) < 0) return 1;
    if (a.head.compare(b.head) == 0 && a.number < b.number) return 1;
    if (a.head.compare(b.head) == 0 && a.number == b.number && a.index < b.index) return 1;
    return 0;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> p;
    string str;
    int i, j, k, num;

    for (i = 0; i < files.size(); i++) {
        for (j = 0; j < files[i].size(); j++) {
            if (files[i][j] >= '0' && files[i][j] <= '9') break;
        }
        str = files[i].substr(0, j);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        num = 0;
        for (k = j; k < files[i].size(); k++) {
            if (!(files[i][k] >= '0' && files[i][k] <= '9')) break;
            num *= 10;
            num += files[i][k] - '0';
        }
        p.push_back(file(files[i], str, num, i));
    }
    sort(p.begin(), p.end(), compare);

    //for (i = 0; i < p.size(); i++) cout << p[i].name << " " << p[i].head << " " << p[i].number << " " << p[i].index << " " << endl;
    for (i = 0; i < p.size(); i++) {
        answer.push_back(p[i].name);
    }
    return answer;
}

int main() {
    vector<string> answer = solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });

    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
}