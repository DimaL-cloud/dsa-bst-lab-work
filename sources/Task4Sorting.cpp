#include <iostream>
#include <vector>

#include "algorithms/CountingSort.h"

using namespace std;

vector<int> generateRandomArray(int size) {
    vector<int> array(size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 50;
    }

    return array;
}

void print(vector<int> array) {
    for (int n : array) {
        cout << n << " ";
    }
}

int main() {
    srand(time(nullptr));

    vector<int> array = generateRandomArray(10);

    CountingSort::sort(array);

    print(array);

    return 0;
}