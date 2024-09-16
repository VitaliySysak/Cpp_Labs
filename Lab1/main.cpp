#include <iostream>
#include <cmath>
using namespace std;
//Task 10
int main() {
    double a = 2, b = 3, c = 7;
    double hx = 0.31;
    
    for (double x = 0; x <= 5; x += hx) {
        double y;
        
        if (x < 2) {
            y = pow(a, (b - x)) + c;
        } 
        else if (x >= 2 && x <= 4) {
            y = pow(b, (c - x)) + a;
        } 
        else {
            y = pow(c, (a - x)) + b;
        }
        cout.precision(12);
        cout << "x = " << x << "\t y = " << y << endl;
    }
    
    return 0;
}
