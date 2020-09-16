#include <string>
#include <vector>

using namespace std;

struct coord {
    int x, y;
};

string solution(vector<int> numbers, string hand) {
    string answer = "";

    coord pos[12];
    pos[0].x = 3; pos[0].y = 1;
    pos[1].x = 0; pos[1].y = 0;
    pos[2].x = 0; pos[2].y = 1;
    pos[3].x = 0; pos[3].y = 2;
    pos[4].x = 1; pos[4].y = 0;
    pos[5].x = 1; pos[5].y = 1;
    pos[6].x = 1; pos[6].y = 2;
    pos[7].x = 2; pos[7].y = 0;
    pos[8].x = 2; pos[8].y = 1;
    pos[9].x = 2; pos[9].y = 2;
    pos[10].x = 3; pos[10].y = 0;
    pos[11].x = 3; pos[11].y = 2;

    int p[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            int dist = abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
            p[i][j] = p[j][i] = dist;
        }
    }

    int lx = 3, ly = 0, rx = 3, ry = 2;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) { answer += "L"; lx = pos[numbers[i]].x; ly = pos[numbers[i]].y; }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) { answer += "R"; rx = pos[numbers[i]].x; ry = pos[numbers[i]].y; }
        else {
            int x = pos[numbers[i]].x, y = pos[numbers[i]].y;

            int dl = abs(lx - x) + abs(ly - y);
            int dr = abs(rx - x) + abs(ry - y);

            if (dl < dr || (dl == dr && hand.compare("left") == 0)) {
                answer += "L";
                lx = x;
                ly = y;
            }
            else {
                answer += "R";
                rx = x;
                ry = y;
            }
        }
    }


    return answer;
}