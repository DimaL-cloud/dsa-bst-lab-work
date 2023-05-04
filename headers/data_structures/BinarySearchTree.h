#ifndef LAB4_BINARYSEARCHTREE_H
#define LAB4_BINARYSEARCHTREE_H

#include <vector>

#include "../entities/Student.h"

struct Node {
private:
    Student student;

    Node *left = nullptr;
    Node *right = nullptr;

public:
    explicit Node(const Student &student);

    const Student &getStudent() const;

    void setStudent(const Student &student);

    Node *getLeft() const;

    void setLeft(Node *left);

    Node *getRight() const;

    void setRight(Node *right);

};

struct BinarySearchTree {
private:
    Node *root = nullptr;
    int nodesAmount = 0;

public:
    void insert(const Student &student);

    bool find(const Student &student);

    void erase(const Student &student);

    int findInRange(const Student &minStudent, const Student &maxStudent);

    void print();

    int size();

private:
    Node *insertImpl(Node *tree, const Student &student);

    bool findImpl(Node *tree, const Student &student);

    Node *eraseImpl(Node *tree, const Student &student);

    Node *findMinValueNode(Node *tree);

    int sizeOfSubtree(Node *tree);

    void printImpl(Node *tree);

    void splitTree(Node *tree, const Student &student, Node *leftTree, Node *rightTree);

    void mergeTrees(Node *tree, Node *leftTree, Node *rightTree);
};


#endif //LAB4_BINARYSEARCHTREE_H
