#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "radix.hpp" // Assuming your radix sort method is defined here

// Function to generate a random integer between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to measure the execution time of a sorting function
double measureTime(void (*sortFunc)(std::vector<int>*), std::vector<int>& arr) {
    std::clock_t start = std::clock();
    sortFunc(&arr);
    std::clock_t end = std::clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

// Wrapper function for std::sort
void stdSortWrapper(std::vector<int>* v) {
    std::sort(v->begin(), v->end());
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int arraySize = 20000000;
    const int numTests = 10;

    long double radixTotalTime = 0.0;
    long double stdSortTotalTime = 0.0;

    for (int test = 0; test < numTests; ++test) {
        std::vector<int> radixArray(arraySize);
        std::vector<int> stdSortArray(arraySize);

        // Fill arrays with random integers between 10^8 and 10^9
        for (int i = 0; i < arraySize; ++i) {
            radixArray[i] = randomInt(10000, 20000);
            stdSortArray[i] = radixArray[i];
        }

        // Measure the execution time of radix sort
        double radixTime = measureTime(radix, radixArray);
        radixTotalTime += radixTime;

        // Measure the execution time of std::sort
        double stdSortTime = measureTime(stdSortWrapper, stdSortArray);
        stdSortTotalTime += stdSortTime;
    }

    double avgRadixTime = radixTotalTime / numTests;
    double avgStdSortTime = stdSortTotalTime / numTests;

    std::cout << "Average Radix Sort Time: " << avgRadixTime << " seconds\n";
    std::cout << "Average std::sort Time: " << avgStdSortTime << " seconds\n";

    if (avgRadixTime < avgStdSortTime) {
        std::cout << "Radix Sort is faster on average.\n";
    } else if (avgStdSortTime < avgRadixTime) {
        std::cout << "std::sort is faster on average.\n";
    } else {
        std::cout << "Both sorting methods have similar average performance.\n";
    }

    return 0;
}
