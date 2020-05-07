#include <string>
#include <vector>
#include<iostream>

#include<algorithm>

using namespace std;

class Node {
public:
    int x;
    int y;
    int num;
    Node* left;
    Node* right;

    Node(int x, int y, int num) {
        this->x = x;
        this->y = y;
        this->num = num;
        this->left = NULL;
        this->right = NULL;
    }

    void print() { printf("%d %d %d\n", x, y, num); }
};

int compare(Node* a, Node* b) {
    if (a->y > b->y) return 1;
    return 0;
}

void addNode(Node* root, Node* node) {
    if (node->x > root->x) {
        if (root->right == NULL) root->right = node;
        else addNode(root->right, node);
    }
    else {
        if (root->left == NULL) root->left = node;
        else addNode(root->left, node);
    }
    return;
}

void preorder(Node* node, vector<int>& ans) {
    ans.push_back(node->num);
    if (node->left != NULL) preorder(node->left, ans);
    if (node->right != NULL) preorder(node->right, ans);
}
void postorder(Node* node, vector<int>& ans) {
    if (node->left != NULL) postorder(node->left, ans);
    if (node->right != NULL) postorder(node->right, ans);
    ans.push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<Node*> tree;
    int i;

    for (i = 0; i < nodeinfo.size(); i++) {
        tree.push_back(new Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }
    sort(tree.begin(), tree.end(), compare);
    //for (i = 0; i < tree.size(); i++) tree[i]->print();

    for (i = 1; i < tree.size(); i++) {
        addNode(tree[0], tree[i]);
    }

    preorder(tree[0], answer[0]);

    postorder(tree[0], answer[1]);
    
    return answer;
}

int main() {
    vector<vector<int>> nodeinfo = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
    vector<vector<int>> answer = solution(nodeinfo);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) printf("%d ", answer[i][j]);
        printf("\n");
    }
}