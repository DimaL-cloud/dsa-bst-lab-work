#ifndef LAB4_AVLBINARYSEARCHTREE_H
#define LAB4_AVLBINARYSEARCHTREE_H

#include <vector>

#include "entities/Student.h"

struct Node {
//private:
    Student student;

    Node *left = nullptr;
    Node *right = nullptr;

    int height = 0;

public:
    explicit Node(const Student &student);

    const Student &getStudent() const;

    void setStudent(const Student &student);

    Node *getLeft() const;

    void setLeft(Node *left);

    Node *getRight() const;

    void setRight(Node *right);

    int getHeight() const;

    void setHeight(int height);
};

struct AVLBinarySearchTree {
private:
    Node *root = nullptr;

public:
    virtual ~AVLBinarySearchTree();

    void insert(const Student &student);

    bool find(const Student &student);

    void erase(const Student &student);

    /*
     * Optimized version O(log(n)), where n is number of nodes
     */
    int findInRange(const Student &minStudent, const Student &maxStudent);

    void eraseRange(const Student &minStudent, const Student &maxStudent);

    /*
     * Trivial version O(n), where n is number of nodes
     */
    int findInRangeTrivial(const Student &minStudent, const Student &maxStudent);

    void print();

    int height();

    int size();

private:
    void destroyNode(Node *node);

    Node *insertImpl(Node *node, const Student &student);

    bool findImpl(Node *node, const Student &student);

    Node *eraseImpl(Node *node, const Student &student);

    Node *findMinValueNode(Node *node);

    int sizeImpl(Node *node);

    void printImpl(Node *node);

    int heightImpl(Node *node);

    void findInRangeTrivialImpl(const Student &minStudent, const Student &maxStudent, Node *node, int &foundAmount);

    void splitTree(Node *node, const Student &student, Node *&leftTree, Node *&rightTree);

    void mergeTrees(Node *&node, Node *leftNode, Node *rightNode);

    int max(int firstNumber, int secondNumber) const;

    Node *rotateRight(Node *node);

    Node *rotateLeft(Node *node);

    int getBalanceFactor(Node *node);
};


#endif //LAB4_AVLBINARYSEARCHTREE_H
