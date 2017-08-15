#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
//this is a file for test of cppcode
//change from github_web
//another change
struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode():val(0),left(NULL),right(NULL){};
  TreeNode(int v, TreeNode* l=NULL, TreeNode* r=NULL):val(v),left(l),right(r){};
  void Delete_Tree(TreeNode* root);
};

void TreeNode::Delete_Tree(TreeNode* root){
  while(true){
      if (root == NULL) return;
      if (root->left==NULL && root->right==NULL) {delete root;return;}
      else {Delete_Tree(root->left);Delete_Tree(root->right);}
  }
}

TreeNode* creat_tree();
void pre_travel_recursion(TreeNode* root);
void pre_travel_iter(TreeNode* root);
void mid_travel_recursion(TreeNode* root);
void mid_travel_iter(TreeNode* root);
vector<int>* queen(int n);

int main(){
  TreeNode* root = creat_tree();
  pre_travel_recursion(root);
  cout << endl;
  pre_travel_iter(root);
  cout << endl;
  mid_travel_recursion(root);
  cout << endl;
  mid_travel_iter(root);
  cout << endl;
  vector<int>* newqueen = queen(8);
  cout << newqueen->end()-newqueen->begin();
  std::cin.get();
  return 0;
}

TreeNode* creat_tree(){
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);
  return root;
}

void pre_travel_recursion(TreeNode* root){
    if (root == NULL) return;
    cout << root->val <<" ";
    pre_travel_recursion(root->left);
    pre_travel_recursion(root->right);
}

void pre_travel_iter(TreeNode* root){
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
    cout << root->val << " ";
        while(s.top()->left){
            root = root->left;
            cout << root->val << " ";
            s.push(root);
        }
        while (!root->right){
            s.pop();
            if (s.empty()) return;
            root = s.top();
        }
        s.pop();
        root = root->right;
        s.push(root);
    }
}

void mid_travel_recursion(TreeNode* root){
    if (root == NULL) return;
    mid_travel_recursion(root->left);
    cout << root->val <<" ";
    mid_travel_recursion(root->right);
}

void mid_travel_iter(TreeNode* root){
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()){
        while(root->left){
            root = root->left;
            s.push(root);
        }
        cout << root->val << " ";
        s.pop();
        if (root->right){
            root = root->right;
            s.push(root);
        }else{
            while (!root->right){
                if (s.empty()){
                    if (root->right == NULL) return;
                    else break;
                }
                root = s.top();
                cout << root->val << " ";
                s.pop();
            }
            root = root->right;
            s.push(root);
        }
    }
}

vector<int>* queen(int n){
    vector<int>* result = new vector<int>(n);
    return result;
}
