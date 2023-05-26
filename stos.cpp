
#include "stos.h"

StosChar::StosChar() {
    i = 0; // rozpoczecie stosu i przypisanie zmiennej top wartosci zero
    size = 2;
    dane = new char[size];

};
StosChar::~StosChar() {
    delete[] dane;
}
void StosChar::push(char c) {
    if (i == size) {
        size *= 2;
        char* ndane = new char[size];
        for (int j = 0; j < i; j++) {
            ndane[j] = dane[j];
        }
        delete[] dane;
        dane = ndane;
    }
    dane[i] = c;
    i++;
}
void StosChar::pop() {
    if (i > 0) {
        i--;
    }
}
char StosChar::top() {
    if (i > 0)return dane[i - 1];
    else return 0;
}
bool StosChar::empty() {
    if (i == 0) {
        return true;
    }
    else {
        return false;
    }
}

StosDouble::StosDouble() {
    i = 0;
    size = 2;
    dane = new double[size];

};
StosDouble::~StosDouble() {
    delete[] dane;
}
void StosDouble::push(double c) {
    if (i == size) {
        size *= 2;
        double* ndane = new double[size];
        for (int j = 0; j < i; j++) {
            ndane[j] = dane[j];
        }
        delete[] dane;
        dane = ndane;
    }
    dane[i] = c;
    i++;
}

double StosDouble::top() {
    if (i > 0)return dane[i - 1];
    else return 0;
}
