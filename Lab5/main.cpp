/*
10. Написати функцію, яка в залежності від заданої ознаки проводить
сортування масиву за зростанням або за зменшенням.
*/

#include <iostream>
using namespace std;

int* createMatr(int n) {
    if (n < 1) return NULL;
    int* matr = new int[n];
    return matr;
}

void deleteMatr(int*& matr) {
    delete[] matr;
    matr = NULL;
}

void randMatr(int* matr, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        *(matr + i) = rand() % 11;
}

void vividMatr(int* matr, int n) {
    for (int i = 0; i < n; i++, cout << "\t")
        cout << *(matr + i);
    cout << endl;
}

void sortMatr(int* matr, int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascending) {
                if (*(matr + j) > *(matr + j + 1)) {
                    swap(*(matr + j), *(matr + j + 1));
                }
            } else {
                if (*(matr + j) < *(matr + j + 1)) {
                    swap(*(matr + j), *(matr + j + 1));
                }
            }
        }
    }
}

int main() {
    int n = 5;
    int* arr = createMatr(n);
    randMatr(arr, n);
    
    cout << "Original array:" << endl;
    vividMatr(arr, n);
    
    sortMatr(arr, n, true);
    cout << "Sorted array ascending:" << endl;
    vividMatr(arr, n);
    
    sortMatr(arr, n, false);
    cout << "Sorted array descending:" << endl;
    vividMatr(arr, n);
    
    deleteMatr(arr);
    
    return 0;
}
