#ifndef LAB4_ARRAYTRIE_H
#define LAB4_ARRAYTRIE_H

#include <string>
#include <vector>
#include <unordered_map>

#define ALPHABET_SIZE 26

using namespace std;


struct ArrayTrie {
private:
    struct Node {
        Node *children[ALPHABET_SIZE];
        bool isWord = false;

        Node();
    };

    Node *root;

public:
    ArrayTrie();

    void insert(string key);

    vector<string> findByPrefix(string prefix);

private:
    void fillWordsVector(vector<string> &words, const Node *node, string &nextWord);
};


#endif //LAB4_ARRAYTRIE_H
