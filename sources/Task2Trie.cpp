#include <iostream>
#include <fstream>
#include <vector>

#include "data_structures/ArrayTrie.h"
#include "data_structures/MapTrie.h"

#define WORDS_FILE_PATH "words_alpha.txt"
#define SEARCH_ITERATIONS 500

using namespace std;

void openFile(ifstream &inputFile, const string &codeFilePath) {
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
double measureTrieTime(T trie, const string &prefix) {
    clock_t startTime = clock();

    for (int i = 0; i < SEARCH_ITERATIONS; i++) {
        trie.findByPrefix(prefix);
    }

    clock_t endTime = clock();

    return (double(endTime - startTime)) / CLOCKS_PER_SEC;
}

int main() {
    MapTrie mapTrie;
    ArrayTrie arrayTrie;

    ifstream inputFile;

    openFile(inputFile, WORDS_FILE_PATH);

    string inputWord;

    while (inputFile >> inputWord) {
        mapTrie.insert(inputWord);
        arrayTrie.insert(inputWord);
    }

    inputFile.close();

    string prefix;

    cout << "Enter word: ";
    cin >> prefix;

    cout << endl;

    cout << "Search " << SEARCH_ITERATIONS << " iterations" << endl;
    cout << "Trie on array: " << measureTrieTime(arrayTrie, prefix) << endl;
    cout << "Trie on map (unordered_map): " << measureTrieTime(mapTrie, prefix) << endl;

    cout << endl;

//    vector<string> words = arrayTrie.findByPrefix(prefix);
//
//    printVector(words);

    return 0;
}