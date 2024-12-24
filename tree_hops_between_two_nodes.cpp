#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

//create the tree
    TreeNode* insertLevelOrder(const vector<int>& values) {
        if (values.empty()) 
            return nullptr;

        root = new TreeNode(values[0]);
        queue<TreeNode*> q;
        q.push(root);
        size_t i = 1;

        while (i < values.size()) {
            TreeNode* current = q.front();
            q.pop();

            if (i < values.size() && values[i] != -1) {
                current->left = new TreeNode(values[i]);
                q.push(current->left);
            }
            i++;

            if (i < values.size() && values[i] != -1) {
                current->right = new TreeNode(values[i]);
                q.push(current->right);
            }
            i++;
        }

        return root;
    }


///FIND LEAST COMMON ANCESTOR 
///FIND LEAST COMMON ANCESTOR 
///FIND LEAST COMMON ANCESTOR 
///FIND LEAST COMMON ANCESTOR 


    TreeNode* findLCA(TreeNode* node, int n1, int n2) {
        if (node == nullptr)
            return nullptr;

        if (node->val == n1 || node->val == n2)
            return node;

        TreeNode* leftLCA = findLCA(node->left, n1, n2);
        TreeNode* rightLCA = findLCA(node->right, n1, n2);

        if (leftLCA && rightLCA)
            return node;

        return leftLCA ? leftLCA : rightLCA;
    }



//FIND DISTANCE 
//FIND DISTANCE 
//FIND DISTANCE 
//FIND DISTANCE 

    int findDistance(TreeNode* node, int val, int distance) {
        if (node == nullptr) 
            return -1;

        if (node->val == val)
            return distance;

        int left = findDistance(node->left, val, distance + 1);
        int right = findDistance(node->right, val, distance + 1);

        if (left != -1)
            return left;
        if (right != -1)
            return right;


        return -1;
    }

// left distance + right distance
// left distance + right distance
// left distance + right distance
// left distance + right distance
    int calculateHops(int n1, int n2) {
        TreeNode* lca = findLCA(root, n1, n2);
        if (!lca)
            return -1;

        int d1 = findDistance(lca, n1, 0);
        int d2 = findDistance(lca, n2, 0);

        return d1 + d2;
    }
};

int main() {
    BinaryTree tree;
    vector<int> values = {1, 2, 3, 4, 5, 6, 7,8,9,10,11,12,13,14}; // Example tree

    tree.insertLevelOrder(values);

    int node1 = 1;
    int node2 = 14;

    int hops = tree.calculateHops(node1, node2);

    if (hops != -1) {
        cout << "The number of hops between node " << node1 << " and node " << node2 << " is: " << hops << endl;
    } else {
        cout << "One or both nodes not found in the tree." << endl;
    }

    return 0;
}
