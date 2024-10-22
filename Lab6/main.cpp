#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream> 

using namespace std;

int main() {
    int n = 10;
    int** matrix = new int*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    srand(time(0));

    cout << "Matrix:" << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 21 - 10; 
            cout << matrix[i][j] << "\t";   
        }
        cout << "\n";
    }

    // запис у файл
    ofstream outputFile("matrix.txt");
    if (!outputFile) {
        cerr << "Error while opening" << "\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outputFile << matrix[i][j] << "\t"; 
        }
        outputFile << "\n";  
    }

    outputFile.close();


    int localMinCount = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int current = matrix[i][j];
            if ((current < matrix[i-1][j]) && (current < matrix[i+1][j]) && (current < matrix[i][j-1]) && (current < matrix[i][j+1])) {
                localMinCount++;
            }
        }
    }

    int sumAboveDiagonal = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sumAboveDiagonal += abs(matrix[i][j]);
        }
    }

    cout << "Num of local minimums: " << localMinCount << "\n";
    cout << "Sum above main diagonal: " << sumAboveDiagonal << "\n";

    // читання з файлу
    ifstream inputFile("matrix.txt");
    if (!inputFile) {
        cerr << "Error while opening file" << "\n";
        return 1;
    }

    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    cout << "\nMatrix read from file: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> matrix[i][j];  
            cout << matrix[i][j] << "\t";  
        }
        cout << "\n";
    }

    inputFile.close(); 

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}
