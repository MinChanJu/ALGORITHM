#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
  int key, height, balance;
  Node *left;
  Node *right;

  Node(int k) : key(k), height(0), balance(0), left(nullptr), right(nullptr) {}
};

int height(Node *n)
{
  return n ? n->height : -1;
}

Node *rotateRight(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = 1 + max(height(y->left), height(y->right));
  x->height = 1 + max(height(x->left), height(x->right));

  return x;
}

Node *rotateLeft(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = 1 + max(height(x->left), height(x->right));
  y->height = 1 + max(height(y->left), height(y->right));

  return y;
}

Node *insert(Node *node, int key)
{
  if (!node)
    return new Node(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (node->key < key)
    node->right = insert(node->right, key);
  else
    return node;

  node->height = 1 + max(height(node->left), height(node->right));
  node->balance = height(node->left) - height(node->right);

  if (node->balance == 2)
  {
    if (node->left->balance == 1)
    {
      cout << "LL\n";
      return rotateRight(node);
    }

    if (node->left->balance == -1)
    {
      cout << "LR\n";
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }
  }

  if (node->balance == -2)
  {
    if (node->right->balance == -1)
    {
      cout << "RR\n";
      return rotateLeft(node);
    }

    if (node->right->balance == 1)
    {
      cout << "RL\n";
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }
  }

  return node;
}

void printTree(Node *root, int space = 0, int indent = 15)
{
  if (!root)
    return;

  space += indent;

  printTree(root->right, space);

  cout << string(space - indent, ' ');
  cout << root->key << " H:" << root->height << " B:" << root->balance << endl;

  printTree(root->left, space);
}

// 예제 실행
int main()
{
  Node *root = nullptr;
  int arr[] = {10, 20, 30, 40, 50, 25};

  for (int key : arr)
  {
    cout << "===================\n";
    root = insert(root, key);
    printTree(root);
  }
}