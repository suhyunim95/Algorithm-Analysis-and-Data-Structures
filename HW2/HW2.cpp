#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node* left;
    Node* right;
};

Node* createNode(int val)
{
    Node* node = new Node;
    node->num = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* rinsertBST(Node* root, int val)
{
    if (root == NULL) {
        return createNode(val);
    }

    if (root->num < val) {
        root->right = rinsertBST(root->right, val);
    }
  
    else {
        root->left = rinsertBST(root->left, val);
    }

    return root;
}

// Delete a node using successor
Node* deletion(Node* root, int v)
{

    if (root == NULL)
        return root;

    if (root->num > v) {
        root->left = deletion(root->left, v);
        return root;
    }
    else if (root->num < v) {
        root->right = deletion(root->right, v);
        return root;
    }

    // case 1 : There is no left child or right child
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    // case 2 : There are both childrens.
    else {
        Node* succParent = root;

        // Find successor
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->num = succ->num;
        delete succ;
        return root;
    }
}

// inorder traversal
void inorder(Node* root)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->num << " ";
    inorder(root->right);
}

int main()
{
    int BSTex[] = { 40, 60, 20, 80, 50, 10, 30, 15, 5, 35, 25, 45, 55, 70, 90, 32, 33, 48, 46 };

    Node* root = NULL;
    for (int val : BSTex) {
        root = rinsertBST(root, val);
    }

    // #1. Traverse BST with inorder method
    cout << "#1. Traverse BST with inorder method" << endl;
    inorder(root);
    cout << endl;

    cout << "#2. delete 40" << endl;
    root = deletion(root, 40);
    inorder(root);
    cout << endl;

    cout << "#3. delete 20" << endl;
    root = deletion(root, 20);
    inorder(root);
    cout << endl;

    return 0;
}

