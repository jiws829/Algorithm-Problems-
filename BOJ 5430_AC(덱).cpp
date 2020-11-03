#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    //freopen("./c++/input.txt", "r", stdin);

    int t;
    string s, str;
    int n;
    deque<int> p;
    int i, j;
    int num;
    int reverse;
    int flag;

    cin >> t;
    while (t-- > 0)
    {
        cin >> s;
        cin >> n;

        cin >> str;
        num = 0;
        p.clear();
        flag = 0;

        for (i = 1; i < str.size(); i++)
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
            }
        }

        if (n == 0)
            p.clear();

        //for(i=0;i<n;i++) printf("%d ",p[i]);
        //printf("\n-------------\n");

        reverse = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
            {
                reverse = 1 - reverse;
            }
            else
            {
                if (p.size() == 0)
                {
                    flag = 1;
                    break;
                }
                if (reverse == 0)
                    p.pop_front();
                else
                    p.pop_back();
            }
        }

        if (flag == 1)
            cout << "error\n";
        else
        {
            if (reverse == 0)
            {
                cout << "[";
                while (!p.empty())
                {
                    num = p.front();
                    p.pop_front();
                    cout << num;
                    if (p.empty() == 0)
                        cout << ",";
                }
                cout << "]\n";
            }
            else
            {
                cout << "[";
                while (!p.empty())
                {
                    num = p.back();
                    p.pop_back();
                    cout << num;
                    if (p.empty() == 0)
                        cout << ",";
                }
                cout << "]\n";
            }
        }
    }
}
