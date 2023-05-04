#include <iostream>

#include "../headers/data_structures/BinarySearchTree.h"
#include "../headers/data_structures/ArrayTrie.h"
#include "../headers/data_structures/MapTrie.h"

using namespace std;

int main() {
    srand(time(nullptr));

    BinarySearchTree bst;

    for (int i = 0; i < 20; i++) {
        bst.insert(Student());
    }

    bst.printVector();

    cout << bst.findInRange(Student("", HIGH, 5),
                            Student("", HIGH, 10));

    return 0;
}
