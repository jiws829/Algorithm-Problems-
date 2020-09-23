#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<int> p, t;

int main()
{
    //freopen("./c++/input.txt", "r", stdin);
    cin >> str;

    int num = 0;
    int i;

    for (i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num *= 10;
            num += str[i] - '0';
        }
        else
        {
            p.push_back(num);
            num = 0;
            if (str[i] == '+')
                t.push_back(1);
            else
                t.push_back(2);
        }
    }
    p.push_back(num);

    //for(i=0;i<p.size();i++) printf("%d ",p[i]);
    //printf("\n");
    //for(i=0;i<t.size();i++) printf("%d ",t[i]);

    for (i = 0; i < t.size();)
    {
        if (t[i] == 1)
        {
            p[i] += p[i + 1];
            p.erase(p.begin() + i + 1);
            t.erase(t.begin() + i);
        }
        else
            i++;
    }

    int answer = p[0];
    for (i = 1; i < p.size(); i++)
    {
        answer -= p[i];
    }

    printf("%d\n", answer);
}