#include <bits/stdc++.h>

using namespace std;

/************** Hereeeeeeeee  */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* org_root = nullptr;

TreeNode* tree_addNode_BST(TreeNode* root, int x) {
  if (root == nullptr) {
    // al fikra hena .. lw 5leet root yesahwer 3ala newNode
    // fa nta 8yert fel copy argu not in the original.. that's why we return
    root = new TreeNode(x);
  } else {
    TreeNode* current = root;
    TreeNode* newNode = new TreeNode(x);
    while (1) {
      if (x <= current->val) {
        if (current->left == nullptr) {
          current->left = newNode;
          return root;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == nullptr) {
          current->right = newNode;
          return root;
        } else {
          current = current->right;
        }
      }
    }
  }
  return root;
}

void tree_preOrderTraverse(TreeNode* root) {
  // root left right = P L R
  if (root == nullptr)
    return;
  cout << root->val << " ";
  tree_preOrderTraverse(root->left);
  tree_preOrderTraverse(root->right);
}

void tree_inOrderTraverse(TreeNode* root) {
  // left root right =  L P R
  if (root == nullptr)
    return;
  tree_preOrderTraverse(root->left);
  cout << root->val << " ";
  tree_preOrderTraverse(root->right);
}
void tree_postOrderTraverse(TreeNode* root) {
  // left  right root =  L  R P
  if (root == nullptr)
    return;
  tree_preOrderTraverse(root->left);
  tree_preOrderTraverse(root->right);
  cout << root->val << " ";
}

void tree_breadthTraverse(TreeNode* root) {
  if (root == nullptr)
    return;
  queue<TreeNode*> qu;
  qu.push(root);

  while (qu.empty() == false) {
    TreeNode* current = qu.front();
    qu.pop();
    cout << current->val << " ";
    if (current->left)
      qu.push(current->left);
    if (current->right)
      qu.push(current->right);
  }
}

int sumOfLeftLeaves(TreeNode* root) {
  int sum = 0;
  if (root == nullptr)
    return sum;

  queue<TreeNode*> qu;
  qu.push(root);
  int counter = -1;

  while (qu.empty() == false) {
    counter++;
    TreeNode* current = qu.front();
    qu.pop();
    if (current != nullptr) {
      if (current->left == nullptr && current->right == nullptr) {
        // it's a leaf
        sum += ((counter % 2) ? current->val : 0);
      } else {
        qu.push(current->left);
        qu.push(current->right);
      }
    }
  }
  return sum;
}

int main() {
  org_root = nullptr;
  org_root = tree_addNode_BST(org_root, 6);
  org_root = tree_addNode_BST(org_root, 4);
  org_root = tree_addNode_BST(org_root, 9);
  org_root = tree_addNode_BST(org_root, 3);
  org_root = tree_addNode_BST(org_root, 5);
  org_root = tree_addNode_BST(org_root, 8);
  org_root = tree_addNode_BST(org_root, 10);
  tree_breadthTraverse(org_root);
  return 0;
}