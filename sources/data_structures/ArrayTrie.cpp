#include "../../headers/data_structures/ArrayTrie.h"

ArrayTrie::Node::Node() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
}

ArrayTrie::ArrayTrie() {
    root = new Node();
}

void ArrayTrie::insert(string key) {
    Node *currentNode = root;

    for (char c : key) {
        int index = c - 'a';

        if (currentNode->children[index] == nullptr) {
            currentNode->children[index] = new Node();
        }

        currentNode = currentNode->children[index];
    }

    currentNode->isWord = true;
}

vector<string> ArrayTrie::findByPrefix(string prefix) {
    vector<string> words;

    Node *currentNode = root;

    for (char c : prefix) {
        int index = c - 'a';

        if (currentNode->children[index] == nullptr) {
            return words;
        }

        currentNode = currentNode->children[index];
    }

    fillWordsVector(words, currentNode, prefix);

    return words;
}

void ArrayTrie::fillWordsVector(vector<string> &words, const Node *node, string &nextWord) {
    if (node == nullptr) {
        return;
    }

    if (node->isWord) {
        words.push_back(nextWord);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node *child = node->children[i];

        if (child != nullptr) {
            nextWord.push_back((char) (i + 'a'));
            fillWordsVector(words, child, nextWord);
            nextWord.pop_back();
        }
    }
}