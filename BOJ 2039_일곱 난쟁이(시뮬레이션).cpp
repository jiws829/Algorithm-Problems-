#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;

int main()
{
    //freopen("./c++/input.txt", "r", stdin);

    int i, j, num;
    int sum = 0;
    int flag = 0;

    for (i = 0; i < 9; i++)
    {
        cin >> num;
        p.push_back(num);
        sum += num;
    }
    sum -= 100;

    for (i = 0; i < 9; i++)
    {
        if (flag == 1)
            break;
        for (j = 0; j < 9; j++)
        {
            if (i == j)
                continue;
            if (p[i] + p[j] == sum)
            {
                p[i] = p[j] = -1;
                flag = 1;
                break;
            }
        }
    }
    sort(p.begin(), p.end());
    for (i = 2; i < 9; i++)
        cout << p[i] << '\n';
}