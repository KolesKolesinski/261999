#include "KlasaBoza.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"
#include "fstream"
#include "iostream"
#include "QSpinBox"
#include "QRadioButton"
#include <QMainWindow>

using namespace std;

KlasaBoza::KlasaBoza(){}


KlasaBoza::~KlasaBoza(){}

void KlasaBoza::algorytm(QRadioButton *KOBIETA_PRZYCISK, QSpinBox *WZROST,QSpinBox *WODKA, QSpinBox *WINA,QSpinBox *WIEK,QSpinBox *WAGA,QSpinBox *PIWA,QRadioButton *MEZCZNYZNA_PRZYCISK){



    QString wodka = WODKA->text();
    QString wino = WINA->text();
    QString piwo = PIWA->text();
    QString wzrost = WZROST->text();
    QString waga = WAGA->text();
    QString wiek = WIEK->text();



    float K;
    int wzrost_cm = wzrost.toInt();
    int wodka_gram = wodka.toInt();
    int wino_gram = wino.toInt();
    int piwo_gram = piwo.toInt();
    int W = waga.toInt();
    int wiek_liczba = wiek.toInt();

    int A = ((20 * piwo_gram) + (wino_gram * 10) + (wodka_gram * 10));

    if(KOBIETA_PRZYCISK->isChecked())
        K = 0.6;

    else if(MEZCZNYZNA_PRZYCISK->isChecked()){
        K = 0.7;}
    else
    {
        QMessageBox::warning(this, tr("BŁAD"),tr("WPROWADZ DANE"));
        return;
    }

    float P = (A/(K*W));
    P = std::round(P*100)/100;

    if(wiek_liczba < 18){
         QMessageBox::warning(this, tr("BŁAD"),tr("NIE JESTES PELNOLETNI WIEC NIE PONAWIAJ TEGO BLEDU"));
         return;
    }

    if(wzrost_cm <= 0 or (wodka_gram <=0) and (wino_gram <=0) and (piwo_gram <=0)or(W <=0)or(wiek_liczba<=0))
        QMessageBox::warning(this, tr("BŁAD"),tr("WPROWADZ DANE"));

     else
    {
        QMessageBox::information(this, tr("WYNIK"),tr("Masz: %1 promila we krwi").arg(P));

        std::fstream file("wynik.txt", ios_base::app);
        file <<"\n|Wynik wynosi: " << P <<" promila we krwi|";
        file.close();

        }



}
