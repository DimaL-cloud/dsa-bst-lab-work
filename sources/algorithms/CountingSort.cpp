#include "algorithms/CountingSort.h"

void CountingSort::sort(vector<int> &array) {
    vector<int> resultArray(array.size());

    int maxElement = array[0];

    for (int i: array) {
        if (i > maxElement) {
            maxElement = i;
        }
    }

    vector<int> counterArray(maxElement + 1, 0);

    for (int i: array) {
        counterArray[i]++;
    }

    for (int i = 1; i < counterArray.size(); i++) {
        counterArray[i] += counterArray[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; i--) {
        int number = array[i];
        int position = counterArray[number] - 1;
        resultArray[position] = number;
    }

    array = resultArray;
}