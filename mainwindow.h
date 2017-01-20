#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include "dodajnaczepe.h"
#include "dodajciagnik.h"
#include <QMainWindow>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Dialog *oknoPracownika;
    DodajNaczepe *dodajNaczepe;
    dodajciagnik *dodajCiagnik;


private slots:

    void on_Lista_pracownicy_cellClicked(int row, int column);

    void on_lista_ciagniki_cellClicked(int row, int column);

    void on_lista_naczepy_cellClicked(int row, int column);

    void showOknoPracownik();

    void showDodajNaczepe();

    void showDodajCiagnik();

    void edytowaniePracownicy();
    void edytowanieNaczepy();
    void edytowanieCiagniki();

    void usuwaniePracownika();
    void usuwanieCiagnika();
    void usuwanieNaczepy();

    void on_button_refresh_clicked();

    void on_ok_clicked();

    void on_usun_clicked();

private:
    Ui::MainWindow *ui;
    bool Connecting();
    void Refreshing();
};

#endif // MAINWINDOW_H
