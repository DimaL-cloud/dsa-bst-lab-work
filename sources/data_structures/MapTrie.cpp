#include "../../headers/data_structures/MapTrie.h"

void MapTrie::insert(const string &key) {
    MapTrieNode *currentNode = root;

    for (char c: key) {
        int index = c - 'a';

        if (currentNode->getChild(index) == nullptr) {
            currentNode->setChild(index, new MapTrieNode());
        }

        currentNode = currentNode->getChild(index);
    }

    currentNode->setIsWord(true);
}

vector<string> MapTrie::findByPrefix(const string &prefix) {
    vector<string> words;

    MapTrieNode *currentNode = root;

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

void MapTrie::fillWordsVector(vector<string> &words, MapTrieNode *node, string &nextWord) {
    if (node == nullptr) {
        return;
    }

    if (node->isWord()) {
        words.push_back(nextWord);
    }

    for (auto &child: node->getChildren()) {
        nextWord.push_back((char) (child.first + 'a'));
        fillWordsVector(words, child.second, nextWord);
        nextWord.pop_back();
    }
}

bool MapTrieNode::isWord() const {
    return isEndOfWord;
}

void MapTrieNode::setIsWord(bool isEndOfWord) {
    MapTrieNode::isEndOfWord = isEndOfWord;
}

unordered_map<char, MapTrieNode*> &MapTrieNode::getChildren() {
    return children;
}

MapTrieNode *MapTrieNode::getChild(int index) {
    return children[index];
}

void MapTrieNode::setChild(int index, MapTrieNode *child) {
    this->children[index] = child;
}


