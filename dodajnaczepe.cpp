#include "dodajnaczepe.h"
#include "ui_dodajnaczepe.h"
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


DodajNaczepe::DodajNaczepe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajNaczepe)
{
    ui->setupUi(this);
}

DodajNaczepe::~DodajNaczepe()
{
    delete ui;
}

void DodajNaczepe::on_ok_clicked()
{
    QString nrRej = ui->nrRejEdit->text();
    QString przeglad = ui->przegladEdit->text();
    QString ubezpieczenie = ui->UbezpieczenieEdit->text();
    QString opony1 = ui->opony1Edit->text();
    QString opony2 = ui->opony2Edit->text();
    QString opony3 = ui->opony3Edit->text();

    QSqlQuery dodawanie;
    dodawanie.prepare("INSERT INTO testdb.naczepy (nrRej,przeglad,ubezpieczenie,opony1, opony2, opony3) VALUES (?,?,?,?,?,?)");
    dodawanie.addBindValue(nrRej);
    dodawanie.addBindValue(przeglad);
    dodawanie.addBindValue(ubezpieczenie);
    dodawanie.addBindValue(opony1);
    dodawanie.addBindValue(opony2);
    dodawanie.addBindValue(opony3);
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
