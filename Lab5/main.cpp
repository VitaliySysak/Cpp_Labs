/*
10. Написати функцію, яка в залежності від заданої ознаки проводить
сортування масиву за зростанням або за зменшенням.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>  
using namespace std;

int* createArray(int size) {
    return new int[size]; 
}

void fillArray(int* arr, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 11; 
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int* arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ascending) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            } else {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

int main() {
    int size = 5;
    int* arr = createArray(size);
    
    fillArray(arr, size);
    
    cout << "Original array:" << "\n";
    printArray(arr, size);
    
    sortArray(arr, size, true); 
    cout << "Array ascending order:" << "\n";
    printArray(arr, size);
    
    sortArray(arr, size, false); 
    cout << "Array descending order:" << "\n";
    printArray(arr, size);
    
    delete[] arr; 
    
    return 0;
}
