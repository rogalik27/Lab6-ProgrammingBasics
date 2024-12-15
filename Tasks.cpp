#include "Tasks.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//TASK 1

double findMin(double* arr, int size) {
    double min = *arr;
    for (double* p = arr; p < arr + size; ++p)
        if (*p < min) min = *p;
    return min;
}

double findMax(double* arr, int size) {
    double max = *arr;
    for (double* p = arr; p < arr + size; ++p)
        if (*p > max) max = *p;
    return max;
}

int Tasks::task1main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    double* arr = new double[size];
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 101;

    cout << "Array: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    double min = findMin(arr, size);
    double max = findMax(arr, size);
    double sum = min + max;

    ofstream outFile("result.txt");
    outFile << "Min: " << min << "\nMax: " << max << "\nSum: " << sum;
    outFile.close();

    cout << "Results written to result.txt" << endl;

    delete[] arr;
    return 0;
}
