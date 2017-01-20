#include "dodajciagnik.h"
#include "ui_dodajciagnik.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QTextStream>
#include <QMessageBox>


dodajciagnik::dodajciagnik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodajciagnik)
{
    ui->setupUi(this);
}

dodajciagnik::~dodajciagnik()
{
    delete ui;
}

void dodajciagnik::on_ok_clicked()
{
    QString nrRej = ui->nrRejEdit->text();
    QString przeglad = ui->przegladEdit->text();
    QString ubezpieczenie = ui->UbezpieczenieEdit->text();
    QString legalizacjaTacho = ui->LegalizacjaTachoEdit->text();
    QString czytanieTacho = ui->CzytanieTachoEdit->text();
    QString opony1 = ui->Opony1Edit->text();
    QString opony2 = ui->Opony2Edit->text();

    QSqlQuery dodawanie;
    dodawanie.prepare("INSERT INTO testdb.ciagniki (nrRej,przeglad,ubezpieczenie,legalizacjaTacho,czytanieTacho,opony1, opony2) VALUES (?,?,?,?,?,?,?)");
    dodawanie.addBindValue(nrRej);
    dodawanie.addBindValue(przeglad);
    dodawanie.addBindValue(ubezpieczenie);
    dodawanie.addBindValue(legalizacjaTacho);
    dodawanie.addBindValue(czytanieTacho);
    dodawanie.addBindValue(opony1);
    dodawanie.addBindValue(opony2);
    if ( !dodawanie.exec())
    {
        QMessageBox::warning(NULL,dodawanie.lastQuery(),dodawanie.lastError().text(),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(NULL,"Dodano","Wpisane dane dodano do bazy danych",QMessageBox::Ok);
        this->close();
    }
}
