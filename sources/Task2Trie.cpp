#include <iostream>
#include <fstream>
#include <vector>

#include "../headers/data_structures/ArrayTrie.h"
#include "../headers/data_structures/MapTrie.h"

using namespace std;

void openFile(ifstream &inputFile, string &codeFilePath) {
    try {
        inputFile.open(codeFilePath);
        if (!inputFile.is_open()) {
            throw runtime_error("Failed to open file: " + codeFilePath);
        }
    }
    catch (exception &e) {
        cerr << e.what() << endl;
        exit(1);
    }
}

void printVector(const vector<string> &words) {
    for (auto &word: words) {
        cout << word << endl;
    }
}

template<typename T>
double measureTrieTime(T trie) {
    clock_t startTime = clock();

    for (int i = 0; i < 500; i++) {
        trie.findByPrefix("a");
    }

    clock_t endTime = clock();

    return (double(endTime - startTime)) / CLOCKS_PER_SEC;
}

int main() {
    MapTrie mapTrie;
    ArrayTrie arrayTrie;

    string codeFilePath = "words_alpha.txt";
    ifstream inputFile;

    openFile(inputFile, codeFilePath);

    string inputWord;

    while (getline(inputFile, inputWord)) {
        mapTrie.insert(inputWord);
//        arrayTrie.insert(inputWord);
    }

    inputFile.close();

//    cout << measureTrieTime(mapTrie) << endl;
//    cout << measureTrieTime(arrayTrie) << endl;

    string prefix;

    cin >> prefix;

    vector<string> words = mapTrie.findByPrefix(prefix);

    printVector(words);

    return 0;
}