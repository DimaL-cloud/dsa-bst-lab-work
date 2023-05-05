#include "../../headers/data_structures/ArrayTrie.h"

ArrayTrieNode::ArrayTrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
}

void ArrayTrie::insert(const string &key) {
    ArrayTrieNode *currentNode = root;

    for (char c: key) {
        int index = c - 'a';

        if (currentNode->getChild(index) == nullptr) {
            currentNode->setChild(index, new ArrayTrieNode());
        }

        currentNode = currentNode->getChild(index);
    }

    currentNode->setIsWord(true);
}

vector<string> ArrayTrie::findByPrefix(const string &prefix) {
    vector<string> words;

    ArrayTrieNode *currentNode = root;

    for (char c: prefix) {
        int index = c - 'a';

        if (currentNode->getChild(index) == nullptr) {
            return words;
        }

        currentNode = currentNode->getChild(index);
    }

    string nextWord = prefix;

    fillWordsVector(words, currentNode, nextWord);

    return words;
}

void ArrayTrie::fillWordsVector(vector<string> &words, ArrayTrieNode *node, string &nextWord) {
    if (node == nullptr) {
        return;
    }

    if (node->isWord()) {
        words.push_back(nextWord);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        ArrayTrieNode *child = node->getChild(i);

        if (child != nullptr) {
            nextWord.push_back((char) (i + 'a'));
            fillWordsVector(words, child, nextWord);
            nextWord.pop_back();
        }
    }
}

bool ArrayTrieNode::isWord() const {
    return isEndOfWord;
}

void ArrayTrieNode::setIsWord(bool isEndOfWord) {
    ArrayTrieNode::isEndOfWord = isEndOfWord;
}

ArrayTrieNode *ArrayTrieNode::getChild(int index) {
    return children[index];
}

void ArrayTrieNode::setChild(int index, ArrayTrieNode *child) {
    this->children[index] = child;
}
