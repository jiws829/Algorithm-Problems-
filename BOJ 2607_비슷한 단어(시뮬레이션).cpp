#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int n;
string p[101];
int dict[101][26];

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j;
    int flag;
    int answer = 0;

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> p[i];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < p[i].size(); j++)
        {
            dict[i][p[i][j] - 'A']++;
        }
    }

    for (i = 1; i < n; i++)
    {
        flag = 0;
        int len = p[0].size() - p[i].size();
        for (j = 0; j < 26; j++)
        {
            flag += abs(dict[0][j] - dict[i][j]);
        }
        if (flag <= 2 && abs(len) <= 1)
            answer++;
    }

    cout << answer;
}