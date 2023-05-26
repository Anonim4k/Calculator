#include"funkcje.h"
#include "stos.h"

#include<cmath>
string PoprawWyrazenie(string w) {
    string wynik;
    wynik += w[0];
    int dl = w.length();
    for (int i = 1; i < dl; i++) {
        if (w[i] != ' ') {
            if (czyZnak(w[i - 1]) && czyZnak(w[i])) {
                wynik += w[i];
            }
            else if (czyLitera(w[i - 1]) && czyLitera(w[i])) {
                wynik += w[i];
            }
            else if (czyLitera(w[i - 1]) && czyZnak(w[i])) {
                wynik += w[i];
            }
            else {
                wynik += " ";
                wynik += w[i];
            }
        }
    }
    return wynik;
}

int czyLitera(char ch) {
    if (int(ch)>=97 && int(ch)<=122)
        return 1;
    else return 0;
}
void Zamiana(string& subject, const string& search) {
    size_t pos = 0;
    string replace, Strliczba;
    int posliczb;
    double liczba, x;

    while ((pos = subject.find(search, pos)) != string::npos) {
        posliczb = pos + search.length();
        Strliczba = scanNum(posliczb,subject);
        liczba = stod(Strliczba);
        if(search == "sin") x = sin(liczba*3.14159/180);
        else if(search == "cos") x = cos(liczba*3.14159/180);
        else if(search == "sqrt") x = sqrt(liczba);
        replace = to_string(x);
        subject.replace(pos, search.length()+Strliczba.length(), replace);
        pos += replace.length();
    }
}

int priorytet(char znak){
    if (znak == '+' || znak == '-'){
        return 1;
    }else if (znak == '*' || znak == '/'){
        return 2;
    }else if (znak == '^'){
        return 3;
    }else{
        return 0;
    };
}

string scanNum(int &i,string str){
    string value;
    value = str[i++];
    while(str[i]!=' ' && i<int(str.length())){
        value+=str[i++];
    }
    return value;
}

int czyOperator(char ch){
    if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
        return 1;
    else return 0;
}
double Operacja(double a, double b, char op){
        if(op == '+')
            return b+a;
        else if(op == '-')
            return b-a;
        else if(op == '*')
            return b*a;
        else if(op == '/')
            return b/a;
        else if(op == '^')
            return (double)pow(b,a);
        else
            return INT_MIN;
}
int czyZnak(char ch){
    if((ch >= '0' && ch <= '9') || ch == '.')
        return 1;
    else return 0;
}

string InfixNaPostfix(string wyrazenie){
    StosChar stos;
    string wyjscie;
    wyrazenie = PoprawWyrazenie(wyrazenie);
    Zamiana(wyrazenie,"cos");
    Zamiana(wyrazenie,"sin");
    Zamiana(wyrazenie,"sqrt");
    for (int i = 0; i < int(wyrazenie.length()); i++){
        char c = wyrazenie[i];
        if(c==' ')continue;
        if (czyOperator(c)){
            if(!stos.empty() && priorytet(stos.top()) >= priorytet(c)){
                wyjscie += stos.top();
                wyjscie +=" ";
                stos.pop();
            }
            stos.push(c);
        }else if (c == '('){
            stos.push(c);
        }else if (c == ')'){
            while (stos.top() != '('){
                wyjscie += stos.top();
                wyjscie +=" ";
                stos.pop();
            }
            stos.pop();
        }else if(czyZnak(c)){
            wyjscie +=scanNum(i,wyrazenie);
            wyjscie +=" ";
        }
    }

    while(!stos.empty()){
        wyjscie += stos.top();
        stos.pop();
    }
    return wyjscie;
}
double ObliczPostfix(string postfix){
    double a;
    double b;

    StosDouble wynik;
    for (int i = 0; i < int(postfix.length()); i++){
        if(czyOperator(postfix[i])){
            a = wynik.top();
            wynik.pop();
            b = wynik.top();
            wynik.pop();
            wynik.push(Operacja(a,b,postfix[i]));
        }else if(czyZnak(postfix[i])){
            wynik.push(stod(scanNum(i,postfix)));
        }
    }
    return wynik.top();

}






