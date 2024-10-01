/*
10. Враховуючи інформацію про підрозділи: найменування підрозділу,
кількість співробітників, рік заснування, відсортувати інформацію про
підрозділи за зростанням року заснування.
*/

#include <iostream>
#include <string>
using namespace std;

const int n = 5;  

struct Department {
    string name;       
    int employees;     
    int foundationYear; 
};

Department departments[n] = { 
    {"Development", 20, 1995},  
    {"Support", 50, 2005},      
    {"HR", 30, 1990},             
    {"Marketing", 15, 2010},     
    {"Sales", 25, 2000}           
};



int main() {
    cout << "Original department:\n";
    for (int i = 0; i < n; i++) {
        cout << departments[i].name << "\t"
             << departments[i].employees << "\t"
             << departments[i].foundationYear << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (departments[j].foundationYear > departments[j + 1].foundationYear) {
                Department temp = departments[j];
                departments[j] = departments[j + 1];
                departments[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted by foundation year:\n";
    for (int i = 0; i < n; i++) {
        cout << departments[i].name << "\t"
             << departments[i].employees << "\t"
             << departments[i].foundationYear << endl;
    }

    return 0;
}
