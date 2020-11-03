#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> p;

int main()
{
    //freopen("./c++/input.txt","r",stdin);

    int n;
    int i, num;
    string str;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> str;
        if (str.compare("push_back") == 0)
        {
            cin >> num;
            p.push_back(num);
        }
        else if (str.compare("push_front") == 0)
        {
            cin >> num;
            p.push_front(num);
        }
        else if (str.compare("pop_front") == 0)
        {
            if (p.empty())
                cout << "-1\n";
            else
            {
                num = p.front();
                cout << num << '\n';
                p.pop_front();
            }
        }
        else if (str.compare("pop_back") == 0)
        {
            if (p.empty())
                cout << "-1\n";
            else
            {
                num = p.back();
                cout << num << '\n';
                p.pop_back();
            }
        }
        else if (str.compare("size") == 0)
        {
            cout << p.size() << '\n';
        }
        else if (str.compare("empty") == 0)
        {
            cout << p.empty() << '\n';
        }
        else if (str.compare("front") == 0)
        {
            if (p.empty())
                cout << "-1\n";
            else
            {
                num = p.front();
                cout << num << '\n';
            }
        }
        else if (str.compare("back") == 0)
        {
            if (p.empty())
                cout << "-1\n";
            else
            {
                num = p.back();
                cout << num << '\n';
            }
        }
    }
}
