#include "calculator.h"
#include "ui_calculator.h"
#include "funkcje.h"


#define nButton 21
using namespace std;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText("");
    QPushButton *Prbutton[nButton];
    QString ButtName[nButton]={"Button0","Button1","Button2","Button3","Button4","Button5","Button6","Button7","Button8","Button9","ButtonAdd",
                           "ButtonSub","ButtonCos","ButtonSin","ButtonSqrt","ButtonDiv","ButtonMulti","ButtonPow","ButtonOpen","ButtonClose","ButtonDot"};
    for(int i =0;i<nButton;i++){
        Prbutton[i] = Calculator::findChild<QPushButton *> (ButtName[i]);
        connect(Prbutton[i], SIGNAL(released()),this,
                SLOT(ButtonPressed()));}

    connect(ui->ButtonEqual, SIGNAL(released()),this,
            SLOT(Equal()));
    connect(ui->ButtonClearAll, SIGNAL(released()),this,
            SLOT(ClearAllDisplay()));
    connect(ui->ButtonClear, SIGNAL(released()),this,
            SLOT(ClearDisplay()));

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::ButtonPressed(){

    QPushButton *button=(QPushButton*)sender(); //sender return object that call method
    string exp=ui->Display->text().toStdString();
    size_t length=exp.length();
    QString butVal = button->text();
    if(ui->Display->text()=="0"){
        ui->Display->setText(button->text());
    }else if(butVal == '+' || butVal == '-' || butVal == '*' || butVal == '/' || butVal == '^' || butVal == '(' || butVal == ')'){
        ui->Display->setText(ui->Display->text()+' '+button->text());
    }else{
        if(exp[length-1]=='+'||exp[length-1]=='*'||exp[length-1]=='-'||exp[length-1]=='/' ||exp[length-1]=='^'|| exp[length-1]=='(')
            ui->Display->setText(ui->Display->text()+' '+button->text());
        else
            ui->Display->setText(ui->Display->text()+button->text());
    }

}

void Calculator::Equal(){
    QString rownanie = ui->Display->text();
    string wyrazenie = rownanie.toStdString();
    QString postfix = QString::fromStdString(InfixNaPostfix(wyrazenie));
    ui->DisplayPostfix->setText(postfix);
    double wynik = ObliczPostfix(postfix.toStdString());
    QString qstr = QString::number(wynik);
    ui->Display->setText(qstr);
    rownanie = rownanie + "=";
    ui->DisplayHistory->setText(rownanie);
}
void Calculator::ClearAllDisplay(){
    QString rownanie = ui->DisplayHistory->text();
    QString wynik = ui->Display->text();
    ui->DisplayHistory->setText(rownanie+wynik);
    ui->Display->setText("");
}
void Calculator::ClearDisplay(){
    QString rownanie = ui->Display->text();
    string wyrazenie = rownanie.toStdString();
    if(wyrazenie != ""){
    wyrazenie.pop_back();}
    rownanie = QString::fromStdString(wyrazenie);
    ui->Display->setText(rownanie);
}
