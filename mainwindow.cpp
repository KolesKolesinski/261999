#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"
#include "fstream"
#include "iostream"
#include "QRadioButton"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_SPRAWDZ_clicked()
{
    QString wodka = ui->WODKA->text();
    QString wino = ui->WINA->text();
    QString piwo = ui->PIWA->text();
    QString wzrost = ui->WZROST->text();
    QString waga = ui->WAGA->text();
    QString wiek = ui->WIEK->text();



    float K;
    int wzrost_cm = wzrost.toInt();
    int wodka_gram = wodka.toInt();
    int wino_gram = wino.toInt();
    int piwo_gram = piwo.toInt();
    int W = waga.toInt();
    int wiek_liczba = wiek.toInt();

    int A = ((20 * piwo_gram) + (wino_gram * 10) + (wodka_gram * 10));

    if(ui->KOBIETA_PRZYCISK->isChecked())
        K = 0.6;

    else if(ui->MEZCZNYZNA_PRZYCISK->isChecked()){
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



