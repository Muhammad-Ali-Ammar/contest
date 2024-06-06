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

/************* LEETCODE **************************/
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

/************* LEETCODE **************************/

void go_go(TreeNode* root, int x, vector<int>& numbers) {
  x = x * 10 + root->val;
  if (root->left == nullptr && root->right == nullptr) {
    numbers.push_back(x);
    return;
  }

  if (root->left)
    go_go(root->left, x, numbers);
  if (root->right)
    go_go(root->right, x, numbers);
}
int sumNumbers(TreeNode* root) {
  if (root == nullptr)
    return 0;

  vector<int> numbers;
  go_go(root, 0, numbers);

  long long ans = 0;
  for (auto i : numbers)
    ans += i;

  return ans;
}

/*****************************LEET CODE *****************************/

void go_go(TreeNode* root, int& ans, int current) {
  if (root == nullptr)
    return;

  if (root->left == nullptr && root->right == nullptr) {
    ans = max(ans, current);
    return;
  }

  if (root->left)
    go_go(root->left, ans, current + 1);
  if (root->right)
    go_go(root->right, ans, current + 1);
}

int maxDepth(TreeNode* root) {
  int ans = 1;

  go_go(root, ans, 1);

  return ans;
}

/*****************************LEET CODE *****************************/

int go_go(TreeNode* root, int& ans) {
  if (root == nullptr)
    return 0;
  if (root->left == nullptr && root->right == nullptr)
    return 1;

  int left = go_go(root->left, ans);
  int right = go_go(root->right, ans);
  ans = max(ans, left + right + 1);

  return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
  int ans = 0;

  int temp = go_go(root, ans);
  return ans;
}

/*****************************LEET CODE *****************************/

int go_go(TreeNode* root, bool& ans) {
  if (ans == 0)
    return 0;
  if (root == nullptr)
    return 0;
  if (root->left == nullptr && root->right == nullptr)
    return 1;

  int left = go_go(root->left, ans);
  int right = go_go(root->right, ans);

  ans &= (abs(left - right) <= 1);

  return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
  bool ans = 1;

  go_go(root, ans);
  return ans;
}
/*****************************LEET CODE *****************************/

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr)
    return 1;
  if (p == nullptr || q == nullptr)
    return 0;
  if (p->val != q->val)
    return 0;

  bool ans = 1;
  ans &= isSameTree(p->left, q->left);
  ans &= isSameTree(p->right, q->right);

  return ans;
}

/*****************************LEET CODE *****************************/

bool isSameTree2(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr)
    return 1;
  if (p == nullptr || q == nullptr)
    return 0;
  if (p->val != q->val)
    return 0;

  bool ans = 1;
  ans &= isSameTree2(p->left, q->left);
  ans &= isSameTree2(p->right, q->right);

  return ans;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  if (subRoot == nullptr)
    return 1;
  if (root == nullptr)
    return 0;
  bool ans = 0;
  if (root->val == subRoot->val) {
    ans = isSameTree2(root, subRoot);
  }

  if (ans == 0) {
    ans |= isSubtree(root->left, subRoot);
    ans |= isSubtree(root->right, subRoot);
  }

  return ans;
}

/*****************************LEET CODE *****************************/

void fillFirst(TreeNode* root, TreeNode* p, map<TreeNode*, int>& mp) {
  TreeNode* current = root;

  while (current->val != p->val) {
    mp[current]++;
    if (p->val <= current->val)
      current = current->left;
    else
      current = current->right;
  }

  mp[p]++;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  map<TreeNode*, int> mp;
  fillFirst(root, p, mp);
  TreeNode* current = root;
  TreeNode* ans = root;

  // second Part .. pass through second node
  while (current->val != q->val) {
    if (mp.find(current) != mp.end()) {
      ans = current;
    }

    if (q->val <= current->val)
      current = current->left;
    else
      current = current->right;
  }
  // if the node iteself is in the map
  if (mp.find(current) != mp.end()) {
    ans = current;
  }
  return ans;
}

/*****************************LEET CODE *****************************/

// 2 stars

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if (root == nullptr)
    return ans;

  vector<int> nums;
  queue<TreeNode*> qu;
  qu.push(root);

  while (qu.empty() == false) {
    int numberOfNodes = qu.size();
    vector<int> temp;
    for (int i = 0; i < numberOfNodes; ++i) {
      TreeNode* cur = qu.front();
      qu.pop();
      temp.push_back(cur->val);
      if (cur->left)
        qu.push(cur->left);
      if (cur->right)
        qu.push(cur->right);
    }
    ans.push_back(temp);
  }

  return ans;
}

/*****************************LEET CODE *****************************/
vector<int> rightSideView(TreeNode* root) {
  vector<int> ans;
  if (root == nullptr)
    return ans;

  TreeNode* cur;

  queue<TreeNode*> qu;
  qu.push(root);
  while (qu.empty() == false) {
    int nodes = qu.size();

    for (int i = 0; i < nodes; ++i) {
      cur = qu.front();
      qu.pop();
      if (cur->left)
        qu.push(cur->left);
      if (cur->right)
        qu.push(cur->right);

      // just push if it's the lost node in the level
      if (i + 1 == nodes)
        ans.push_back(cur->val);
    }
  }
  return ans;
}

/*****************************LEET CODE *****************************/

void go_go_GoodNode(TreeNode* root, int& ans, int prev) {
  if (root == nullptr)
    return;

  if (root->val >= prev) {
    ans++;
    go_go_GoodNode(root->left, ans, root->val);
    go_go_GoodNode(root->right, ans, root->val);
  } else {
    go_go_GoodNode(root->left, ans, prev);
    go_go_GoodNode(root->right, ans, prev);
  }
}

int goodNodes(TreeNode* root) {
  int ans = 0;
  go_go_GoodNode(root, ans, INT_MIN);
  return ans;
}

/*****************************LEET CODE *****************************/

/*****************************LEET CODE *****************************/
map<int, int> mpIdx;

TreeNode* go_go_Build(vector<int>& preorder,
                      int preStart,
                      int preEnd,
                      vector<int>& inorder,
                      int inStart,
                      int inEnd) {
  if (preStart > preEnd || inStart > inEnd)
    return nullptr;

  TreeNode* root = new TreeNode(preorder[preStart]);

  int A = mpIdx[preorder[preStart]];

  int left_inStart = inStart;
  int left_inEnd = A - 1;
  int y = A - inStart;
  int left_preStart = preStart + 1;
  int left_preEnd = preStart + y;

  int right_inStart = A + 1;
  int right_inEnd = inEnd;
  int right_preStart = preStart + 1 + y;
  int right_preEnd = preEnd;

  root->left = go_go_Build(preorder, left_preStart, left_preEnd, inorder,
                           left_inStart, left_inEnd);
  root->right = go_go_Build(preorder, right_preStart, right_preEnd, inorder,
                            right_inStart, right_inEnd);

  return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int n = preorder.size();
  if (n == 0)
    return nullptr;

  for (int i = 0; i < n; ++i) {
    mpIdx[inorder[i]] = i;
  }
  return (go_go_Build(preorder, 0, n - 1, inorder, 0, n - 1));
}
/*****************************LEET CODE *****************************/
bool go_go_Boundary(TreeNode* cur,
                    long long leftBoundary,
                    long long rightBoundary) {
  if (cur == nullptr)
    return 1;
  return (cur->val > leftBoundary &&
          cur->val < rightBoundary &&                            // check ranges
          go_go_Boundary(cur->left, leftBoundary, cur->val) &&   // go left
          go_go_Boundary(cur->right, cur->val, rightBoundary));  // go right
}

bool isValidBST(TreeNode* root) {
  return go_go_Boundary(root, -1000000000000, 1000000000000);
}

/*****************************LEET CODE *****************************/
map<int, int> mpIdx2;

TreeNode* go_go_Build2(vector<int>& postorder,
                       int postStart,
                       int postEnd,
                       vector<int>& inorder,
                       int inStart,
                       int inEnd) {
  if (postStart > postEnd || inStart > inEnd)
    return nullptr;

  TreeNode* root = new TreeNode(postorder[postEnd]);

  int A = mpIdx[postorder[postEnd]];

  int left_inStart = A + 1;
  int left_inEnd = inEnd;
  int y = inEnd - A;
  int left_postStart = postEnd - y;
  int left_postEnd = postEnd - 1;

  int right_inStart = inStart;
  int right_inEnd = A - 1;
  int right_postStart = postStart;
  int right_postEnd = postEnd - y - 1;

  root->left = go_go_Build(postorder, left_postEnd, left_postEnd, inorder,
                           left_inStart, left_inEnd);
  root->right = go_go_Build(postorder, right_postStart, right_postEnd, inorder,
                            right_inStart, right_inEnd);

  return root;
}
TreeNode* buildTree_fromPostAndIn(vector<int>& postorder,
                                  vector<int>& inorder) {
  int n = postorder.size();
  if (n == 0)
    return nullptr;

  for (int i = 0; i < n; ++i) {
    mpIdx2[inorder[i]] = i;
  }
  return (go_go_Build(postorder, 0, n - 1, inorder, 0, n - 1));
}

/*****************************LEET CODE *****************************/
queue<TreeNode**> quu;
TreeNode* addBinaryTreeNode(TreeNode* newNode) {
  if (org_root == nullptr) {
    org_root = newNode;
    quu.push(&(org_root->left));
    quu.push(&org_root->right);
    return org_root;
  }

  *(quu.front()) = newNode;
  quu.pop();

  if (newNode != nullptr) {
    quu.push(&newNode->left);
    quu.push(&newNode->right);
  }
  return org_root;
}

/*****************************LEET CODE *****************************/

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
  queue<TreeNode*> qu;
  string ans;
  if (root == nullptr)
    return ans;
  ans = "";
  qu.push(root);
  while (qu.empty() == false) {
    TreeNode* curr = qu.front();
    qu.pop();
    if (curr == nullptr) {
      ans += "#_";
    } else {
      qu.push(curr->left);
      qu.push(curr->right);
      ans += "#" + to_string(curr->val);
    }
  }
  ans += "#";
  return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
  int s = 0, e = 1;
  int n = data.size();
  if (n == 0)
    return nullptr;

  while (s < n - 1) {
    e = s + 1;
    string temp = "";
    while (data[e] != '#') {
      temp += data[e++];
    }
    if (temp == "_") {
      org_root = addBinaryTreeNode(nullptr);
    } else {
      int x = stoi(temp);
      org_root = addBinaryTreeNode(new TreeNode(x));
    }
    s = e;
  }
  return org_root;
}

/*****************************LEET CODE *****************************/
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
  if (depth == 1)
    return new TreeNode(val, root, nullptr);
  ;

  queue<TreeNode*> qu;
  qu.push(root);
  --depth;

  while (--depth) {
    int n = qu.size();
    for (int i = 0; i < n; ++i) {
      TreeNode* cur = qu.front();
      qu.pop();
      if (cur->left)
        qu.push(cur->left);
      if (cur->right)
        qu.push(cur->right);
    }
  }

  int n = qu.size();
  for (int i = 0; i < n; ++i) {
    TreeNode* cur = qu.front();
    qu.pop();

    TreeNode* newNode1 = new TreeNode(val);
    TreeNode* newNode2 = new TreeNode(val);
    newNode1->left = cur->left;
    newNode2->right = cur->right;
    cur->left = newNode1;
    cur->right = newNode2;
  }
  return root;
}
/*****************************LEET CODE *****************************/

void go_go_getSmallest(TreeNode* root, string tempAns, set<string>& ans) {
  tempAns = tempAns + (char)(root->val + 'a');

  if (root->right == nullptr && root->left == nullptr) {
    reverse(tempAns.begin(), tempAns.end());
    ans.insert(tempAns);
    return;
  }

  if (root->left != nullptr) {
    go_go_getSmallest(root->left, tempAns, ans);
  }

  if (root->right != nullptr) {
    go_go_getSmallest(root->right, tempAns, ans);
  }
}
string smallestFromLeaf(TreeNode* root) {
  if (root == nullptr)
    return "";
  set<string> ans;
  go_go_getSmallest(root, "", ans);

  return *(ans.begin());
}

/*******************************************************************************/

int main() {
  org_root = addBinaryTreeNode(new TreeNode(1));
  org_root = addBinaryTreeNode(new TreeNode(2));
  org_root = addBinaryTreeNode(new TreeNode(3));
  org_root = addBinaryTreeNode(nullptr);
  org_root = addBinaryTreeNode(nullptr);
  org_root = addBinaryTreeNode(new TreeNode(4));
  return 0;
}
/*

  #pragma GCC optimize("O3", "unroll-loops")
      Solution() {
          ios_base::sync_with_stdio(false);
          cin.tie(nullptr);
          cout.tie(nullptr);
      }
*/
