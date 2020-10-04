#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> p;

int main()
{
    //freopen("./c++/input.txt", "r", stdin);

    int n;
    int i, j, k;
    string s;
    string a;
    int b;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        cin >> s;

        if (s.compare("push") == 0)
        {
            scanf("%d", &b);

            p.push_back(b);
        }
        else if (s.compare("pop") == 0)
        {
            if (p.size() == 0)
                printf("-1\n");
            else
            {
                printf("%d\n", p[p.size() - 1]);
                p.pop_back();
            }
        }
        else if (s.compare("size") == 0)
        {
            printf("%d\n", p.size());
        }
        else if (s.compare("empty") == 0)
        {
            if (p.size() == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (s.compare("top") == 0)
        {
            if (p.size() == 0)
                printf("-1\n");
            else
                printf("%d\n", p[p.size() - 1]);
        }
    }
}