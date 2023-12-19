#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

class Node {
public:
  int key, height;
  Node *left, *right;
  Node(int key) : key(key), left(nullptr), right(nullptr), height(1) {}
};

int height(Node *N) { return N ? N->height : 0; }
int max(int a, int b) { return (a > b) ? a : b; }

Node* rotateRight(Node *y) {
  Node *x = y->left, *T2 = x->right;
  y->left = T2; x->right = y;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

Node* rotateLeft(Node *x) {
  Node *y = x->right, *T2 = y->left;
  y->left = x; x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}

int getBalance(Node *N) { return height(N->left) - height(N->right); }

Node* insert(Node *node, int key) {
  if (!node) return new Node(key);
  if (key < node->key) node->left = insert(node->left, key);
  else if (key > node->key) node->right = insert(node->right, key);
  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key) return rotateRight(node);
  if (balance < -1 && key > node->right->key) return rotateLeft(node);
  if (balance > 1 && key > node->left->key) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }
  if (balance < -1 && key < node->right->key) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }
  return node;
}

void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
    deque<Node*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
        out << ((i == 0) ? setw(startLen - 1) : setw(nodeSpaceLen - 2)) << "" << ((*iter++) ? "/" : " ");
        out << setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
    }
    out << endl;
}

void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
    deque<Node*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
        out << setw(branchLen + 2) << ((*iter) ? to_string((*iter)->key).length() < 2 ? "0" + to_string((*iter)->key) : to_string((*iter)->key) : "");
        out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    out << endl;
}


void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
    deque<Node*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? setw(indentSpace + 2) : setw(2 * level + 2)) << ((*iter) ? to_string((*iter)->key) : "");

    }
    out << endl;
}

void printPretty(Node* root, int level, int indentSpace, ostream& out) {
    int h = height(root);
    int nodesInThisLevel = 1;

    int branchLen = 2 * ((int)pow(2.0, h) - 1) - (2 - level) * (int)pow(2.0, h - 1); 
    int nodeSpaceLen = 2 + (level + 1) * (int)pow(2, h);
    int startLen = branchLen + (level) + indentSpace;  

    deque<Node*> nodesQueue;
    nodesQueue.push_back(root);

    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen / 3;
        nodeSpaceLen = nodeSpaceLen / 2 + 1;
        if (branchLen % 2 == 1) {
            startLen = branchLen + (level) + indentSpace;
        }
        else {
            startLen = branchLen + (level) + indentSpace + 1;
        }

        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    
        for (int i = 0; i < nodesInThisLevel; i++) {
            Node* currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->left);
                nodesQueue.push_back(currNode->right);
            }
            else {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}
int main() {
    Node *root = NULL;
    cout << "AVL Tree" << endl;
    cout << "Insert 50" << endl;
    root = insert(root, 50);printPretty(root, 1, 3, cout);
    cout << "Insert 19" << endl;
    root = insert(root, 19);printPretty(root, 1, 3, cout);
    cout << "Insert 18" << endl;
    root = insert(root, 18);printPretty(root, 1, 3, cout);
    cout << "Insert 57" << endl;
    root = insert(root, 57);printPretty(root, 1, 3, cout);
    cout << "Insert 95" << endl;
    root = insert(root, 95);printPretty(root, 1, 3, cout);
    cout << "Insert 77" << endl;
    root = insert(root, 77);printPretty(root, 1, 3, cout);
    cout << "Insert 39" << endl;
    root = insert(root, 39);printPretty(root, 1, 3, cout);
    cout << "Insert 61" << endl;
    root = insert(root, 61);printPretty(root, 1, 3, cout);
    cout << "Insert 23" << endl;
    root = insert(root, 23);printPretty(root, 1, 3, cout);
    cout << "Insert 56" << endl;
    root = insert(root, 56);printPretty(root, 1, 3, cout);
}
