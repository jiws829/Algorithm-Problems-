#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> p;

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    string s;
    int i;
    int flag;

    while (1)
    {
        getline(cin, s);
        if (s.compare(".") == 0)
            break;

        //cout<<s<<endl;

        flag = 0;
        p.clear();

        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
                p.push_back(s[i]);
            else if (s[i] == ')')
            {
                if (p[p.size() - 1] == '(')
                    p.pop_back();
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (p[p.size() - 1] == '[')
                    p.pop_back();
                else
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0 && p.size() == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
}