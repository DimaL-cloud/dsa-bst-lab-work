#include <iostream>
#include "data_structures/AVLBinarySearchTree.h"

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

int Node::getHeight() const {
    return height;
}

void Node::setHeight(int height) {
    Node::height = height;
}

void AVLBinarySearchTree::insert(const Student &student) {
    root = insertImpl(root, student);
}


AVLBinarySearchTree::~AVLBinarySearchTree() {
    destroyNode(root);
}



Node *AVLBinarySearchTree::insertImpl(Node *node, const Student &student) {
    if (node == nullptr) {
        node = new Node(student);
    } else if (student < node->getStudent()) {
        node->setLeft(
                insertImpl(node->getLeft(), student)
        );
    } else if (student > node->getStudent()) {
        node->setRight(
                insertImpl(node->getRight(), student)
        );
    } else return node;

    node->setHeight(1 + max(heightImpl(node->getLeft()),
                            heightImpl(node->getRight())));

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && student < node->getLeft()->getStudent()) {
        return rotateRight(node);
    }

    if (balanceFactor < -1 && student > node->getRight()->getStudent()) {
        return rotateLeft(node);
    }

    if (balanceFactor > 1 && student > node->getLeft()->getStudent()) {
        node->setLeft(rotateLeft(node->getLeft()));

        return rotateRight(node);
    }

    if (balanceFactor < -1 && student < node->getRight()->getStudent()) {
        node->setRight(rotateRight(node->getRight()));

        return rotateLeft(node);
    }

    return node;
}

void AVLBinarySearchTree::print() {
    printImpl(root);
}

void AVLBinarySearchTree::printImpl(Node *node) {
    if (node != nullptr) {
        printImpl(node->getLeft());
        cout << node->getStudent() << endl;
        printImpl(node->getRight());
    }
}

int AVLBinarySearchTree::size() {
    return sizeImpl(root);
}

bool AVLBinarySearchTree::find(const Student &student) {
    return findImpl(root, student);
}

bool AVLBinarySearchTree::findImpl(Node *node, const Student &student) {
    if (node == nullptr || node->getStudent() == student) {
        return node != nullptr;
    }

    if (student < node->getStudent()) {
        return findImpl(node->getLeft(), student);
    } else return findImpl(node->getRight(), student);
}

void AVLBinarySearchTree::erase(const Student &student) {
    root = eraseImpl(root, student);
}

Node *AVLBinarySearchTree::eraseImpl(Node *node, const Student &student) {
    if (node == nullptr) {
        return nullptr;
    }

    if (student < node->getStudent()) {
        node->setLeft(eraseImpl(node->getLeft(), student));
    } else if (student > node->getStudent()) {
        node->setRight(eraseImpl(node->getRight(), student));
    } else {
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            return nullptr;
        } else if (node->getLeft() == nullptr) {
            Node *returnedNode = node->getRight();
            delete node;
            return returnedNode;
        } else if (node->getRight() == nullptr) {
            Node *returnedNode = node->getLeft();
            delete node;
            return returnedNode;
        }

        Node *minValueNode = findMinValueNode(node->getRight());

        node->setStudent(minValueNode->getStudent());
        node->setRight(eraseImpl(node->getRight(), minValueNode->getStudent()));
    }

    node->setHeight(1 + max(heightImpl(node->getLeft()),
                            heightImpl(node->getRight())));

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (getBalanceFactor(node->getLeft()) >= 0) {
            return rotateRight(node);
        } else {
            node->setLeft(rotateLeft(node->getLeft()));
            return rotateRight(node);
        }
    }

    if (balanceFactor < -1) {
        if (getBalanceFactor(node->getRight()) <= 0) {
            return rotateLeft(node);
        } else {
            node->setRight(rotateRight(node->getRight()));
            return rotateLeft(node);
        }
    }

    return node;
}

Node *AVLBinarySearchTree::findMinValueNode(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node *currentNode = node;

    while (currentNode->getLeft() != nullptr) {
        currentNode = currentNode->getLeft();
    }

    return currentNode;
}

int AVLBinarySearchTree::findInRange(const Student &minStudent, const Student &maxStudent) {
    Node *leftTree;
    Node *middleTree;
    Node *rightTree;

    splitTree(root, minStudent, leftTree, middleTree);
    splitTree(middleTree, maxStudent, middleTree, rightTree);

    int size = sizeImpl(middleTree);

    mergeTrees(root, leftTree, middleTree);
    mergeTrees(root, root, rightTree);

    return size;
}

int AVLBinarySearchTree::sizeImpl(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + sizeImpl(node->getLeft()) + sizeImpl(node->getRight());
}

void AVLBinarySearchTree::splitTree(Node *node, const Student &student, Node *&leftTree, Node *&rightTree) {
    if (node == nullptr) {
        leftTree = nullptr;
        rightTree = nullptr;
    } else if (node->getStudent() <= student) {
        splitTree(node->getRight(), student, node->right, rightTree);
        leftTree = node;
    } else {
        splitTree(node->getLeft(), student, leftTree, node->left);
        rightTree = node;
    }
}

void AVLBinarySearchTree::mergeTrees(Node *&node, Node *leftNode, Node *rightNode) {
    if (leftNode == nullptr || rightNode == nullptr) {
        node = (leftNode != nullptr) ? leftNode : rightNode;
    } else if (leftNode->getStudent() > rightNode->getStudent()) {
        mergeTrees(leftNode->right, leftNode->getLeft(), rightNode);
        node = leftNode;
    } else {
        mergeTrees(rightNode->left, leftNode, rightNode->getLeft());
        node = rightNode;
    }
}

int AVLBinarySearchTree::findInRangeTrivial(const Student &minStudent, const Student &maxStudent) {
    int foundAmount = 0;

    findInRangeTrivialImpl(minStudent, maxStudent, root, foundAmount);

    return foundAmount;
}

void AVLBinarySearchTree::findInRangeTrivialImpl(const Student &minStudent, const Student &maxStudent, Node *node,
                                                 int &foundAmount) {
    if (node == nullptr) {
        return;
    }

    if (node->getStudent() >= minStudent && node->getStudent() <= maxStudent) {
        foundAmount++;
    }

    if (node->getStudent() > minStudent) {
        findInRangeTrivialImpl(minStudent, maxStudent, node->getLeft(), foundAmount);
    }

    if (node->getStudent() < maxStudent) {
        findInRangeTrivialImpl(minStudent, maxStudent, node->getRight(), foundAmount);
    }
}

int AVLBinarySearchTree::height() {
    return heightImpl(root);
}

int AVLBinarySearchTree::heightImpl(Node *node) {
    if (node == nullptr) {
        return 0;
    }

    return node->getHeight();
}

int AVLBinarySearchTree::max(int firstNumber, int secondNumber) const {
    return (firstNumber > secondNumber) ? firstNumber : secondNumber;
}

Node *AVLBinarySearchTree::rotateRight(Node *node) {
    Node *leftChild = node->getLeft();
    Node *rightSubtreeOfLeftChild = leftChild->getRight();

    leftChild->setRight(node);
    node->setLeft(rightSubtreeOfLeftChild);

    node->setHeight(max(heightImpl(node->getLeft()),
                        heightImpl(node->getRight())) + 1);

    leftChild->setHeight(max(heightImpl(leftChild->getLeft()),
                             heightImpl(leftChild->getRight())) + 1);

    return leftChild;
}

Node *AVLBinarySearchTree::rotateLeft(Node *node) {
    Node *rightChild = node->getRight();
    Node *leftSubtreeOfRightChild = rightChild->getLeft();

    rightChild->setLeft(node);
    node->setRight(leftSubtreeOfRightChild);

    node->setHeight(max(heightImpl(node->getLeft()),
                        heightImpl(node->getRight())) + 1);
    rightChild->setHeight(max(heightImpl(rightChild->getLeft()),
                              heightImpl(rightChild->getRight())) + 1);

    return rightChild;
}

int AVLBinarySearchTree::getBalanceFactor(Node *node) {
    if (node == nullptr) {
        return 0;
    }

    return heightImpl(node->getLeft()) - heightImpl(node->getRight());
}

void AVLBinarySearchTree::destroyNode(Node *node) {
    if (node != nullptr) {
        destroyNode(node->getLeft());
        destroyNode(node->getRight());
        delete node;
    }
}

void AVLBinarySearchTree::eraseRange(const Student &minStudent, const Student &maxStudent) {
    eraseRangeImpl(root, minStudent, maxStudent);
}

void AVLBinarySearchTree::eraseRangeImpl(Node *&, const Student &minStudent, const Student &maxStudent) {
    Node *leftTree;
    Node *middleTree;
    Node *rightTree;

    splitTree(root, minStudent, leftTree, middleTree);
    splitTree(middleTree, maxStudent, middleTree, rightTree);

    mergeTrees(root, leftTree, rightTree);

    destroyNode(middleTree);
}
