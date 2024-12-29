#include <iostream>
using namespace std;

void fullArray(int rows, int columns, int** arr);

void outputArray(int rows, int columns, int** arr);

void addColumn(int rows, int& columns, int**& arr, int position);

int main()
{
    system("chcp 1251>null");
    srand(time(0));

    int row, col;

    cout << "Input rows: ";
    cin >> row;

    cout << endl;
    cout << "Input columns: ";
    cin >> col;

    int** pArr = new int* [row];

    fullArray(row, col, pArr);

    cout << endl;

    cout << "Виведення початкового масиву: " << endl;

    outputArray(row, col, pArr);
    
    int position; //індекс

    cout << endl << "Введіть позицію, щоб додати новий стовпець (від 0 до максимальної (-1) кількості стовпчиків): ";
    cin >> position;

    addColumn(row, col, pArr, position);

    cout << "Новий масив: " << endl;
    outputArray(row, col, pArr); 

    for (int i = 0; i < row; i++) {
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

void addColumn(int rows, int& columns, int**& arr, int position) {
    int** newArray = new int* [rows];
    for (int i = 0; i < rows; i++) {
        newArray[i] = new int[columns + 1];
        for (int j = 0; j < position; j++) {
            newArray[i][j] = arr[i][j];
        }
        newArray[i][position] = -5 + rand() % 11;
        for (int j = position; j < columns; j++) {
            newArray[i][j + 1] = arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArray; 
    columns++; 
}
