#ifndef KLASABOZA_H
#define KLASABOZA_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"
#include "fstream"
#include "iostream"
#include "QRadioButton"
#include <QMainWindow>


class KlasaBoza : public QMainWindow {

    Q_OBJECT

public:

    KlasaBoza();
    ~KlasaBoza();



    void algorytm(QRadioButton *KOBIETA_PRZYCISK, QSpinBox *WZROST,QSpinBox *WODKA, QSpinBox *WINA,QSpinBox *WIEK,QSpinBox *WAGA,QSpinBox *PIWA,QRadioButton *MEZCZNYZNA_PRZYCISK);




private slots:


};

#endif //KLASABOZA_H

