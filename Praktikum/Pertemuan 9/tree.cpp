#include <bits/stdc++.h>
using namespace std;
 
class BST {
    int data;
    BST *left, *right;
 
public:
    BST() : data(0), left(NULL), right(NULL){}
    BST(int value) : data(value), left(NULL), right(NULL){}
 
    BST* Insert(BST* root, int value){
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
    root = b.Insert(root, 1);
    b.Insert(root, 8); b.Insert(root, 4); b.Insert(root, 0);b.Insert(root, 1); b.Insert(root, 22);
    cout << "Inorder: "; b.Inorder(root); cout << endl;
    cout << "Postorder ";b.Postorder(root); cout << endl;
    cout << "Preorder ";b.Preorder(root); cout << endl;
    return 0;
}
