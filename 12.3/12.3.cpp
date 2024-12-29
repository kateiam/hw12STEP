#include <iostream>
using namespace std;

void fullArray(int rows, int columns, int** arr);

void outputArray(int rows, int columns, int** arr);

void zsuvRow(int rows, int columns, int** arr, int direction);

void zsuvCol(int rows, int columns, int** arr, int direction);

int main()
{
    system("chcp 1251>null");
    srand(time(0));

    int m, n, direction, t; 

    cout << "Input rows: ";
    cin >> m;

    cout << endl;
    cout << "Input columns: ";
    cin >> n;

    int** pArr = new int* [m];

    fullArray(m, n, pArr);

    cout << endl;

    cout << "Виведення початкового масиву: " << endl;

    outputArray(m, n, pArr);

    cout << endl << "Введіть напрямок зсуву рядка (1 для правого, 2 для лівого): ";
    cin >> direction; 
    cout << endl << "Скільки разів ви хочете це зробити?";
    cin >> t;
    for (int i = 0; i < t; i++) {
        zsuvRow(m, n, pArr, direction);
    }

    cout << "Масив після змін: " << endl;
    outputArray(m, n, pArr);

    cout << endl << "Введіть напрямок зсуву стовпця (1 вниз, 2 вверх): ";
    cin >> direction;
    cout << endl << "Скільки разів ви хочете це зробити?";
    cin >> t;
    for (int i = 0; i < t; i++) {
        zsuvCol(m, n, pArr, direction);
    }

    cout << "Масив після змін: " << endl;
    outputArray(m, n, pArr);

    for (int i = 0; i < m; i++) {
        delete[] pArr[i];
    }
    delete[] pArr;

    return 0;
}

void fullArray(int rows, int columns, int** arr)
{
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = -5 + rand() % 11;

        }
    }
}

void outputArray(int rows, int columns, int** arr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << arr[i][j] << "\t";

        }
        cout << endl;
    }
}

void zsuvRow(int rows, int columns, int** arr, int direction) {
    for (int i = 0; i < rows; i++) {
        int k = arr[i][0];

        if (direction == 1) {
            for (int j = columns - 1; j > 0; j--) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = k; 
        }
        else if (direction == 2) { 
            for (int j = 0; j < columns - 1; j++) { 
                arr[i][j] = arr[i][j + 1]; 
            }
            arr[i][columns - 1] = k; 
        }
    }
}

void zsuvCol(int rows, int columns, int** arr, int direction) {
    for (int j = 0; j < columns; j++) {
        int k = arr[0][j];

        if (direction == 1) {
            for (int i = rows - 1; i > 0; i--) {
                arr[i][j] = arr[i - 1][j];
            }
            arr[0][j] = k;
        }
        else if (direction == 2) {
            for (int i = 0; i < rows - 1; i++) {
                arr[i][j] = arr[i + 1][j];
            }
            arr[rows - 1][j] = k;
        }
    }
}
