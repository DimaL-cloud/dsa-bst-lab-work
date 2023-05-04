#include "../../headers/data_structures/MapTrie.h"

MapTrie::MapTrie() {
    root = new Node();
}

void MapTrie::insert(const string& key) {
    Node *currentNode = root;

    for (char c: key) {
        int index = c - 'a';

        if (currentNode->children[index] == nullptr) {
            currentNode->children[index] = new Node();
        }

        currentNode = currentNode->children[index];
    }

    currentNode->isWord = true;
}

vector<string> MapTrie::findByPrefix(const string& prefix) {
    vector<string> words;

    Node *currentNode = root;

    for (char c: prefix) {
        int index = c - 'a';

        if (currentNode->children[index] == nullptr) {
            return words;
        }

        currentNode = currentNode->children[index];
    }

    fillWordsVector(words, currentNode, prefix);

    return words;
}

void MapTrie::fillWordsVector(vector<string> &words, const Node *node, string &nextWord) {
    if (node == nullptr) {
        return;
    }

    if (node->isWord) {
        words.push_back(nextWord);
    }

    for (auto &child: node->children) {
        nextWord.push_back((char) (child.first + 'a'));
        fillWordsVector(words, child.second, nextWord);
        nextWord.pop_back();
    }
}
