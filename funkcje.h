#ifndef FUNKCJE_H
#define FUNKCJE_H
#include <string>
using namespace std;
//funkcja do poprawiania wyrazenia
string PoprawWyrazenie(string w);

//funkcja do sprawdzania czy dany char to litera
int czyLitera(char ch);

//funkcja do zwracania liczby od wskazanego miejsca az do napotkania " "
string scanNum(int &i,string str);

//funkcja do zwracania priorytetów danego działania
int priorytet(char c) ;

//funkcja do zmiany wyrazenia z postaci infiksowej na postfiksowa
string InfixNaPostfix(string wyrazenie) ;

//funkcja sprawdzajaca czy dany char to operator
int czyOperator(char ch);

//funkcja sprawdzajaca czy dany char to znak
int czyZnak(char ch);

//funkcja wykonujaca operacje 2 liczb
double Operacja(double a, double b, char op);

//funkcja zwracajaca wynik wyrazenia w postaci postfix
double ObliczPostfix(string postfix);

#endif
