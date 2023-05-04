#include <iostream>
#include "../../headers/data_structures/BinarySearchTree.h"

Node::Node(const Student &student) : student(student) {}

const Student &Node::getStudent() const {
    return student;
}

void Node::setStudent(const Student &student) {
    Node::student = student;
}

Node *Node::getLeft() const {
    return left;
}

void Node::setLeft(Node *left) {
    Node::left = left;
}

Node *Node::getRight() const {
    return right;
}

void Node::setRight(Node *right) {
    Node::right = right;
}

void BinarySearchTree::insert(const Student &student) {
    root = insertImpl(root, student);
}

Node *BinarySearchTree::insertImpl(Node *tree, const Student &student) {
    if (tree == nullptr) {
        tree = new Node(student);
        nodesAmount++;
    } else if (student < tree->getStudent()) {
        tree->setLeft(
                insertImpl(tree->getLeft(), student)
        );
    } else if (student > tree->getStudent()) {
        tree->setRight(
                insertImpl(tree->getRight(), student)
        );
    }

    return tree;
}

void BinarySearchTree::print() {
    printImpl(root);
}

void BinarySearchTree::printImpl(Node *tree) {
    if (tree != nullptr) {
        printImpl(tree->getLeft());
        cout << tree->getStudent() << endl;
        printImpl(tree->getRight());
    }
}

int BinarySearchTree::size() {
    return nodesAmount;
}

bool BinarySearchTree::find(const Student &student) { // TODO
    return findImpl(root, student);
}

bool BinarySearchTree::findImpl(Node *tree, const Student &student) {
    if (tree == nullptr || tree->getStudent() == student) {
        return tree != nullptr;
    }

    if (student < tree->getStudent()) {
        return findImpl(tree->getLeft(), student);
    } else return findImpl(tree->getRight(), student);
}

void BinarySearchTree::erase(const Student &student) {
    root = eraseImpl(root, student);
}

Node *BinarySearchTree::eraseImpl(Node *tree, const Student &student) {
    if (tree == nullptr) {
        return nullptr;
    } else if (student < tree->getStudent()) {
        tree->setLeft(eraseImpl(tree->getLeft(), student));
    } else if (student > tree->getStudent()) {
        tree->setRight(eraseImpl(tree->getRight(), student));
    } else {
        Node *leftNode = tree->getLeft();
        Node *rightNode = tree->getRight();

        if (leftNode == nullptr && rightNode == nullptr) {
            Node *swappedNode = findMinValueNode(tree->getRight());

            tree->setStudent(swappedNode->getStudent());
            tree->setRight(eraseImpl(tree->getRight(), swappedNode->getStudent()));
        } else {
            Node *returnedNode = (tree->getLeft() == nullptr) ? rightNode : leftNode;
            nodesAmount--;
            delete tree;

            return returnedNode;
        }
    }

    return tree;
}

Node *BinarySearchTree::findMinValueNode(Node *tree) {
    if (tree == nullptr) {
        return nullptr;
    }

    Node *currentNode = tree;

    while (currentNode->getLeft() != nullptr) {
        currentNode = currentNode->getLeft();
    }

    return currentNode;
}

int BinarySearchTree::findInRange(const Student &minStudent, const Student &maxStudent) {
    Node *leftTree;
    Node *middleTree;
    Node *rightTree;

    splitTree(root, minStudent, leftTree, middleTree);
    splitTree(middleTree, maxStudent, middleTree, rightTree);

    int size = sizeOfSubtree(middleTree);

    mergeTrees(root, leftTree, rightTree);

    return size;
}

int BinarySearchTree::sizeOfSubtree(Node *tree) {
    if (tree == nullptr) {
        return 0;
    }
    return 1 + sizeOfSubtree(tree->getLeft()) + sizeOfSubtree(tree->getRight());
}

void BinarySearchTree::splitTree(Node *tree, const Student &student, Node *leftTree, Node *rightTree) {
    if (tree == nullptr) {
        leftTree = nullptr;
        rightTree = nullptr;
    } else if (tree->getStudent() <= student) {
        splitTree(tree->getRight(), student, tree->getRight(), rightTree);
        leftTree = tree;
    } else {
        splitTree(tree->getLeft(), student, leftTree, tree->getLeft());
        rightTree = tree;
    }
}

void BinarySearchTree::mergeTrees(Node *tree, Node *leftTree, Node *rightTree) {
    if (leftTree == nullptr || rightTree == nullptr) {
        tree = (leftTree != nullptr) ? leftTree : rightTree;
    } else if (leftTree->getStudent() > rightTree->getStudent()) {
        mergeTrees(leftTree->getRight(), leftTree->getLeft(), rightTree);
        tree = leftTree;
    } else {
        mergeTrees(rightTree->getLeft(), leftTree, rightTree->getLeft());
        tree = rightTree;
    }
}


