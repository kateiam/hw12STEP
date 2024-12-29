#include <iostream>

using namespace std;


void fillArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = -10 + rand() % 21; 
        }
    }
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int* uniqueElements(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB, int** C, int rowsC, int colsC, int& newSize) {
    int maxSize = rowsA * colsA + rowsB * colsB + rowsC * colsC; 
    int* result = new int[maxSize];
    newSize = 0;

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            bool isDuplicate = false;
            for (int k = 0; k < rowsB; ++k) {
                for (int l = 0; l < colsB; ++l) {
                    if (A[i][j] == B[k][l]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (isDuplicate) break;
            }
            for (int k = 0; k < rowsC; ++k) {
                for (int l = 0; l < colsC; ++l) {
                    if (A[i][j] == C[k][l]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (isDuplicate) break;
            }
            if (!isDuplicate) {
                result[newSize++] = A[i][j];
            }
        }
    }

    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            bool isDuplicate = false;
            for (int k = 0; k < rowsA; ++k) {
                for (int l = 0; l < colsA; ++l) {
                    if (B[i][j] == A[k][l]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (isDuplicate) break;
            }
            for (int k = 0; k < rowsC; ++k) {
                for (int l = 0; l < colsC; ++l) {
                    if (B[i][j] == C[k][l]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (isDuplicate) break;
            }
            if (!isDuplicate) {
                result[newSize++] = B[i][j];
            }
        }
    }

    for (int i = 0; i < rowsC; ++i) {
        for (int j = 0; j < colsC; ++j) {
            bool isDuplicate = false;
            for (int k = 0; k < rowsA; ++k) {
                for (int l = 0; l < colsA; ++l) {
                    if (C[i][j] == A[k][l]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (isDuplicate) break;
            }
            for (int k = 0; k < rowsB; ++k) {
                for (int l = 0; l < colsB; ++l) {
                    if (C[i][j] == B[k][l]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (isDuplicate) break;
            }
            if (!isDuplicate) {
                result[newSize++] = C[i][j];
            }
        }
    }

    return result;
}

int* negativeValues(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB, int** C, int rowsC, int colsC, int& newSize) {
    int maxSize = rowsA * colsA + rowsB * colsB + rowsC * colsC; 
    int* result = new int[maxSize];
    newSize = 0;

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            if (A[i][j] < 0) {
                result[newSize++] = A[i][j];
            }
        }
    }

    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            if (B[i][j] < 0) {
                result[newSize++] = B[i][j];
            }
        }
    }

    for (int i = 0; i < rowsC; ++i) {
        for (int j = 0; j < colsC; ++j) {
            if (C[i][j] < 0) {
                result[newSize++] = C[i][j];
            }
        }
    }

    return result;
}

int main() {
    srand(time(0));

    int rowsA = 3, colsA = 4;
    int rowsB = 3, colsB = 4;
    int rowsC = 3, colsC = 4;

    int** A = new int* [rowsA];
    int** B = new int* [rowsB];
    int** C = new int* [rowsC];

    for (int i = 0; i < rowsA; ++i) A[i] = new int[colsA];
    for (int i = 0; i < rowsB; ++i) B[i] = new int[colsB];
    for (int i = 0; i < rowsC; ++i) C[i] = new int[colsC];

    fillArray(A, rowsA, colsA);
    fillArray(B, rowsB, colsB);
    fillArray(C, rowsC, colsC);

    cout << "A:" << endl;
    printArray(A, rowsA, colsA);
    cout << "B:" << endl;
    printArray(B, rowsB, colsB);
    cout << "C:" << endl;
    printArray(C, rowsC, colsC);

    int newSize;

    int* uniqueArr = uniqueElements(A, rowsA, colsA, B, rowsB, colsB, C, rowsC, colsC, newSize);
    for (int i = 0; i < newSize; ++i) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;
    delete[] uniqueArr;

    int* negativeArr = negativeValues(A, rowsA, colsA, B, rowsB, colsB, C, rowsC, colsC, newSize);
    for (int i = 0; i < newSize; ++i) {
        cout << negativeArr[i] << " ";
    }
    cout << endl;
    delete[] negativeArr;

    for (int i = 0; i < rowsA; ++i) delete[] A[i];
    for (int i = 0; i < rowsB; ++i) delete[] B[i];
    for (int i = 0; i < rowsC; ++i) delete[] C[i];
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
