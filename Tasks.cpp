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

    ofstream outFile("task1result.txt");
    outFile << "Min: " << min << "\nMax: " << max << "\nSum: " << sum;
    outFile.close();

    cout << "Results written to task1result.txt" << endl;

    delete[] arr;
    return 0;
}

//TASK 2

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = rand() % 10;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void multiplyMatrices(int** a, int** b, int** c, int r1, int c1, int c2) {
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < c1; ++k)
                c[i][j] += a[i][k] * b[k][j];
        }
}

int Tasks::task2main() {
    srand(time(0));
    int r1, c1, r2, c2;
    cout << "Enter dimensions of first matrix (rows cols): \n";
    cin >> r1 >> c1;
    cout << "Enter dimensions of second matrix (rows cols): \n";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Error: Matrices cannot be multiplied." << endl;
        return 1;
    }

    int** a = new int* [r1];
    int** b = new int* [r2];
    int** c = new int* [r1];
    for (int i = 0; i < r1; ++i) a[i] = new int[c1];
    for (int i = 0; i < r2; ++i) b[i] = new int[c2];
    for (int i = 0; i < r1; ++i) c[i] = new int[c2];

    fillMatrix(a, r1, c1);
    fillMatrix(b, r2, c2);

    cout << "Matrix A:" << endl;
    printMatrix(a, r1, c1);
    cout << "Matrix B:" << endl;
    printMatrix(b, r2, c2);

    multiplyMatrices(a, b, c, r1, c1, c2);

    cout << "Resulting Matrix:" << endl;
    printMatrix(c, r1, c2);

    for (int i = 0; i < r1; ++i) delete[] a[i];
    for (int i = 0; i < r2; ++i) delete[] b[i];
    for (int i = 0; i < r1; ++i) delete[] c[i];
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
