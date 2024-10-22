#include <iostream>
#include <cstdlib> 
#include <ctime>    
//Task 10
const int N = 5;  

int main() {

    int** matrix = new int*[N];

    int sumEven = 0;

   for (int i = 0; i < N; i++) {
        *(matrix+i) = new int[N];
        }

    srand(time(0));
    std::cout << "Original Matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand() % 20;
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (matrix[i][j] % 2 == 0) {
                sumEven += matrix[i][j];
            }
        }
    }

    std::cout << "\nSum of even elements above the main diagonal: " << sumEven << std::endl;

    if (sumEven % 3 == 0) {
        for (int i = 0; i < N; ++i) {
            matrix[i][N - 1 - i] = 0;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
    
    for (int i = 0; i < N; i++) {
        delete [] matrix[i];
        }

    return 0;
}

