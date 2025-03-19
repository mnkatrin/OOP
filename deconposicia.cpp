#include <iostream>
#include <cmath>
#include <windows.h> 
using namespace std;

//комментарий123

// Прототипы функций
float* Proc1();
float Proc2(float c, float b);
void Proc3(float* pdr, float& x1, float& x2, int& k);
void Proc4(float a, float b, float d, int k, float& x1, float& x2);
void Proc5(float x1, float x2, int k);
void decompositia();

// Основная функция
int main() {
    decompositia();
    return 0;
}

// Определение функции Proc1
float* Proc1() {
    float* pdr = new float[3];
    cout << "Input: a, b, c: ";
    cin >> pdr[0] >> pdr[1] >> pdr[2];
    return pdr;
}

// Определение функции Proc2
float Proc2(float c, float b) {
    if (b == 0) {
        cerr << "Error: division by zero!" << endl;
        return 0;
    }
    return -c / b;
}

// Определение функции Proc3
void Proc3(float* pdr, float& x1, float& x2, int& k) {
    float d = pdr[1] * pdr[1] - 4 * pdr[0] * pdr[2];
    if (d < 0) {
        k = -1;
    } else {
        k = 1;
    }
    Proc4(pdr[0], pdr[1], d, k, x1, x2);
}

// Определение функции Proc4
void Proc4(float a, float b, float d, int k, float& x1, float& x2) {
    if (k == -1) {
        x1 = (-b) / (2 * a);
        x2 = sqrt(-d) / (2 * a);
    } else {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
    }
}

// Определение функции Proc5
void Proc5(float x1, float x2, int k) {
    if (k == -1) {
        cout << "The roots are complex: " << x1 << " + i" << x2 << " и " << x1 << " - i" << x2 << endl;
    } else {
        cout << "Roots: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
}

// Определение функции decompositia
void decompositia() {
    float* pdr = Proc1();
    if (pdr[0] == 0) {
        float x = Proc2(pdr[2], pdr[1]);
        cout << "Root: x = " << x << endl;
    } else {
        float x1, x2;
        int k;
        Proc3(pdr, x1, x2, k);
        Proc5(x1, x2, k);
    }
    delete[] pdr;
}