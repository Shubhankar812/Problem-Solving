#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void preorder(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    // root left right
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
void inorder(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    // left root right
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
void postorder(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    // left right root
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans;
    // preorder(root, ans);
    // inorder(root, ans);
    postorder(root, ans);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";
}