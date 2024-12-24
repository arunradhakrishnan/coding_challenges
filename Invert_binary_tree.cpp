#include <iostream>
#include <unordered_map>
#include <list>
#include <cstdio>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}

    //   TreeNode(int x) : val(x), next(nullptr) {}
    //   TreeNode(int x, treeNode *next) : val(x), next(next) {}
  };


void invert(TreeNode* root)
{
    if(root == nullptr)
        return;
    
    TreeNode* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    invert(root->left);
    invert(root->right);
  
    

}



//Helper function to print the tree (in-order traversal)
void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

printInOrder(root);
invert(root);
cout << "\n";
printInOrder(root);


}
