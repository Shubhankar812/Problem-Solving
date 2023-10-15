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
int height(Node *&root)
{
    if (!root)
    {
        return 0;
    }
    int lH = height(root->left);
    int rH = height(root->right);

    return 1 + max(lH, rH);
}
int check(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int Left = check(root->left);
    if (Left == -1)
    {
        return -1;
    }
    int Right = check(root->right);
    if (Right == -1)
    {
        return -1;
    }
    if (abs(Left - Right) > 1)
    {
        return -1;
    }
    return 1 + max(Left, Right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->left->left->left->left = new Node(9);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // cout << "Height : " << height(root) << "\n";
    if (check(root))
    {
        cout << "Balanced\n";
    }
    else
    {
        cout << "Not Balanced\n";
    }
}