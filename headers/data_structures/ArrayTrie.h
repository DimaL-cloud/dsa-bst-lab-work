#ifndef LAB4_ARRAYTRIE_H
#define LAB4_ARRAYTRIE_H

#include <string>
#include <vector>
#include <unordered_map>

#define ALPHABET_SIZE 26

using namespace std;

struct ArrayTrieNode {
private:
    ArrayTrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord = false;

public:
    ArrayTrieNode();

    bool isWord() const;

    void setIsWord(bool isEndOfWord);

    ArrayTrieNode *getChild(int index);

    void setChild(int index, ArrayTrieNode *child);
};

struct ArrayTrie {
private:
    ArrayTrieNode *root = new ArrayTrieNode();

public:
    void insert(const string &key);

    vector<string> findByPrefix(const string &prefix);

private:
    void fillWordsVector(vector<string> &words, ArrayTrieNode *node, string &nextWord);
};


#endif //LAB4_ARRAYTRIE_H
