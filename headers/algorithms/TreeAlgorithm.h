#ifndef LAB4_TREEALGORTIHM_H
#define LAB4_TREEALGORTIHM_H

#include "../data_structures/BinarySearchTree.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeAlgorithm {
public:
    static bool isSameTree(BinarySearchTree *p, BinarySearchTree *q) {
        if (p != nullptr && q == nullptr) {
            return false;
        }

        if (p == nullptr && q != nullptr) {
            return false;
        }

        if (p != nullptr && q != nullptr) {
            if (p->val != q->val) {
                return false;
            }

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return true;
    }
};


#endif //LAB4_TREEALGORTIHM_H
