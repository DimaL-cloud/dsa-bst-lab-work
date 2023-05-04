#ifndef LAB4_MAPTRIE_H
#define LAB4_MAPTRIE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

struct MapTrie {
private:
    struct Node {
        unordered_map<char, Node*> children;
        bool isWord = false;
    };

    Node *root;

public:
    MapTrie();

    void insert(string key);

    vector<string> findByPrefix(string prefix);

private:
    void fillWordsVector(vector<string> &words, const Node *node, string &nextWord);
};


#endif //LAB4_MAPTRIE_H
