/*
10. Враховуючи інформацію про підрозділи: найменування підрозділу,
кількість співробітників, рік заснування, відсортувати інформацію про
підрозділи за зростанням року заснування.
*/

#include <iostream>

struct Department {
    std::string name;   
    int employees;      
    int yearFounded;   
};


void sortDepartmentsByYear(Department departments[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (departments[j].yearFounded > departments[j + 1].yearFounded) {
                Department temp = departments[j];
                departments[j] = departments[j + 1];
                departments[j + 1] = temp;
            }
        }
    }
}

int main() {
    Department departments[4] = {
        {"Developer", 15, 1990},
        {"Designer", 50, 2005},
        {"BA", 20, 1985},
        {"PM", 30, 2010}
    };

    int size = 4;

    sortDepartmentsByYear(departments, size);
    std::cout << "Departments sorted by year of foundation:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Name: " << departments[i].name
                  << ", Number of employees: " << departments[i].employees
                  << ", Year of foundation: " << departments[i].yearFounded << "\n";
    }

    return 0;
}
