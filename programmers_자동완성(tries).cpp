#include <string>
#include <vector>
#include<iostream>

#include<map>
using namespace std;

class tries {
public :
    char c;
    int cnt;
    vector<int> child_list;
    tries* down[26];
    int depth;
    int end;

    tries(char c) {
        this->c = c;
        this->cnt = 1;
        this->child_list.clear();
        this->depth = 0;
        this->end = 0;
        for (int i = 0; i < 26; i++) {
            this->down[i] = NULL;
        }
    }
};

vector<tries*> p;
int ans;

void addNode(string s, tries* root) {
    int i;
    tries* now = root;
    for (i = 0; i < s.size(); i++) {
        if (now->down[s[i] - 'a'] == NULL) {
            p.push_back(new tries(s[i]));
            now->down[s[i] - 'a'] = p[p.size() - 1];
            now->child_list.push_back(s[i] - 'a');
            now->down[s[i] - 'a']->depth = now->depth + 1;
            now = now->down[s[i] - 'a'];
        }
        else {
            now = now->down[s[i] - 'a'];
            now->cnt++;
        }

        if (i == s.size() - 1) now->end = 1;
    }   
}

void traverse(tries* root) {
    //printf("%c %d depth:%d  end:%d\n", root->c, root->cnt, root->depth,root->end);

    if (root->cnt == 1) {
        ans += root->depth;
        return;
    }
    for (int i = 0; i < root->child_list.size(); i++) {
        if (root->end==1) {
            ans += root->depth;
        }
        traverse(root->down[root->child_list[i]]);
    }
    return;
}

int solution(vector<string> words) {
    int answer = 0;
    int i, j;
    

    p.push_back(new tries('\0'));
    
    for (i = 0; i < words.size(); i++) {
        addNode(words[i],p[0]);
    }

    tries* root = p[0];
    for (i = 0; i < root->child_list.size(); i++) {
        traverse(root->down[root->child_list[i]]);
    }
    
    answer = ans;
    return answer;
}

int main() {
    int answer = solution({ "go", "gone", "guild" });

    cout << answer << endl;
}