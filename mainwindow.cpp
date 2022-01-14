#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "KlasaBoza.h"
#include <iostream>

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


        KlasaBoza alkomat;
        alkomat.algorytm(ui->KOBIETA_PRZYCISK, ui->WZROST,ui->WODKA,ui->WINA,ui->WIEK,ui->WAGA,ui->PIWA,ui->MEZCZNYZNA_PRZYCISK);



  }

