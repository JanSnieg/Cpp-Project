#include "dialog.h"
#include "ui_dialog.h"
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

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //Connecting();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_button_ok_clicked()
{
    ui->edit_adr->setPrefix(".");
    QString imie = ui->edit_imie->text();
    QString nazwisko = ui->edit_nazwisko->text();
    QString prawoJazdy = ui->edit_PrawoJazdy->text();
    float adr = ui->edit_adr->value();
    QString adr1 = QString::number(adr);
    QString kartaKierowcy = ui->edit_KartaKierowcy->text();

    QSqlQuery dodawanie;
    dodawanie.prepare("INSERT INTO `testdb`.`pracownicy` (imie, nazwisko, prawoJazdy, adr, kartaKierowcy) VALUES (?,?,?,?,?)");
    dodawanie.addBindValue(QString(imie));
    dodawanie.addBindValue(QString(nazwisko));
    dodawanie.addBindValue(QString(prawoJazdy));
    dodawanie.addBindValue(QString(adr1));
    dodawanie.addBindValue(QString(kartaKierowcy));
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
