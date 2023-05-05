#ifndef LAB4_MAPTRIE_H
#define LAB4_MAPTRIE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

struct MapTrieNode {
private:
    unordered_map<char, MapTrieNode*> children;
    bool isEndOfWord = false;

public:
    bool isWord() const;

    void setIsWord(bool isEndOfWord);

    unordered_map<char, MapTrieNode*> &getChildren();

    MapTrieNode *getChild(int index);

    void setChild(int index, MapTrieNode *child);

};

struct MapTrie {
private:
    MapTrieNode *root = new MapTrieNode();

public:
    void insert(const string& key);

    vector<string> findByPrefix(const string& prefix);

private:
    void fillWordsVector(vector<string> &words, MapTrieNode *node, string& nextWord);
};


#endif //LAB4_MAPTRIE_H
