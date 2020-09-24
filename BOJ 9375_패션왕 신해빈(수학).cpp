#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int n;
map<string, int> dict;
map<string, int>::iterator iter;
vector<int> p;
vector<int> answer;

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int i, j, k;
    int m;
    string a, b;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);

        dict.clear();
        p.clear();

        for (j = 0; j < m; j++)
        {
            cin >> a >> b;

            iter = dict.find(b);
            if (iter == dict.end())
            {
                p.push_back(1);
                dict[b] = p.size() - 1;
            }
            else
            {
                p[dict[b]]++;
            }
        }

        //for(j=0;j<p.size();j++) printf("%d ",p[j]);
        //printf("\n");

        int tmp = 1;
        for (j = 0; j < p.size(); j++)
        {
            tmp *= (p[j] + 1);
        }
        answer.push_back(tmp - 1);
    }

    for (i = 0; i < answer.size(); i++)
        printf("%d\n", answer[i]);
}