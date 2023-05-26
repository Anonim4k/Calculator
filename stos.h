
#pragma once


class StosChar {
private:
    char* dane; // tablica do przechowywania elementow
public:
    int size; // rozmiar stosu
    int i; // pozycja ostatniego elementu
    StosChar();
    ~StosChar();
    void push(char a);
    void pop();
    char top();
    bool empty();
};

class StosDouble:public StosChar {
private:    
    double* dane;
public:
    StosDouble();
    ~StosDouble();
    void push(double a);
    double top();
};


