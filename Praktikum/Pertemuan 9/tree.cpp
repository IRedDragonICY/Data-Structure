#include <bits/stdc++.h>
using namespace std;

class BST {
    char data;
    BST *left, *right;

public:
    BST() : data('\0'), left(NULL), right(NULL){}
    BST(char value) : data(value), left(NULL), right(NULL){}

    BST* Insert(BST* root, char value){
        if (!root) return new BST(value);
        if (value >= root->data) root->right = Insert(root->right, value);
        else if (value < root->data) root->left = Insert(root->left, value);
        return root;
    }

    void Inorder(BST* root){
        if (!root) return;
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }

    void Preorder(BST* root){
        if (!root) return;
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Postorder(BST* root){
        if (!root) return;
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
};

int main(){
    BST b, *root = NULL;
    root = b.Insert(root, 'J'); b.Insert(root, 'R'); b.Insert(root, 'D'); b.Insert(root, 'G'); b.Insert(root, 'T'); b.Insert(root, 'E'); b.Insert(root, 'M'); b.Insert(root, 'H'); b.Insert(root, 'P'); b.Insert(root, 'A'); b.Insert(root, 'F'); b.Insert(root, 'Q');
    cout << "Inorder   : "; b.Inorder(root); cout << endl;
    cout << "Postorder : "; b.Postorder(root); cout << endl;
    cout << "Preorder  : "; b.Preorder(root); cout << endl;
    return 0;
}