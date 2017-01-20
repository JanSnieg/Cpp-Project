#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>
#include <QDate>
#include <QColor>
#include <QMessageBox>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionPracownika,SIGNAL(triggered()),this,SLOT(showOknoPracownik()));
    connect(ui->actionNaczepy,SIGNAL(triggered()),this,SLOT(showDodajNaczepe()));
    connect(ui->actionCiagnik,SIGNAL(triggered()),this,SLOT(showDodajCiagnik()));

    Connecting();
    Refreshing();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::Connecting()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("testdb");
    db.setUserName("root");
    if(!db.open())
    {
        qDebug() << "Error zwiazany z Baza";
        qDebug() << db.lastError();
        return false;
    }
    else
        return true;
}

void MainWindow:: Refreshing()
{
    int RowsPracownicy =0;
    int ColumnsPracownicy= 0;
    QDate now = QDate::currentDate();
    QSqlQuery pracownik("SELECT id,nazwisko,prawoJazdy,kartaKierowcy FROM testdb.pracownicy ORDER BY prawoJazdy, kartaKierowcy");
    ui->Lista_pracownicy->setColumnCount(RowsPracownicy=2);
    ui->Lista_pracownicy->setRowCount(ColumnsPracownicy=pracownik.size());
    qDebug() << ColumnsPracownicy;
    qDebug() << RowsPracownicy;
    int iPracownik = 0;
    for (int i = 0; i<=RowsPracownicy ;i++)
    {
        QString imie = pracownik.record().fieldName(i);
        QTableWidgetItem *newItem = new QTableWidgetItem(imie);
        ui ->Lista_pracownicy->setHorizontalHeaderItem(i, newItem);
    }
    while (pracownik.next())
    {

        QDate data1 = pracownik.value(2).toDate();
        QDate data2 = pracownik.value(3).toDate();
        for (int i=0; i<=RowsPracownicy-1; i++)
        {
                ui->Lista_pracownicy->setItem(iPracownik,i,new QTableWidgetItem(pracownik.value(i).toString()));
        }
        if (now.daysTo(data1)<=7)
        {
               ui->Lista_pracownicy->item(iPracownik,0)->setBackground(Qt::red);
        }
        else if (now.daysTo(data1)<=14)
        {
            ui->Lista_pracownicy->item(iPracownik,0)->setBackground(Qt::yellow);
        }
        if (now.daysTo(data2)<=7)
        {
               ui->Lista_pracownicy->item(iPracownik,0)->setBackground(Qt::red);
        }
        else if (now.daysTo(data2)<=14)
        {
            ui->Lista_pracownicy->item(iPracownik,0)->setBackground(Qt::yellow);
        }

        iPracownik ++;
    }


int RowsCiagnik =1;
int ColumnsCiagnik =1;
QSqlQuery ciagnik("SELECT * FROM testdb.ciagniki");
ui->lista_ciagniki->setColumnCount(RowsCiagnik=2);
ui->lista_ciagniki->setRowCount(ColumnsCiagnik=ciagnik.size());
int iCiagnik = 0;
for (int i = 0; i<=RowsCiagnik ;i++)
{
    QString rej1 = ciagnik.record().fieldName(i);
    QTableWidgetItem *newItem = new QTableWidgetItem(rej1);
    ui ->lista_ciagniki->setHorizontalHeaderItem(i, newItem);
}
while (ciagnik.next())
{
    QDate dataPrzeglad = ciagnik.value(2).toDate();
    QDate dataUbezpieczenie = ciagnik.value(3).toDate();
    QDate dataLegalizacja = ciagnik.value(4).toDate();
    QDate dataCzytanie = ciagnik.value(5).toDate();
    QDate dataOpony1 = ciagnik.value(6).toDate();
    QDate dataOpony2 = ciagnik.value(7).toDate();
    for (int i=0; i<=RowsCiagnik-1; i++)
    {
             ui->lista_ciagniki->setItem(iCiagnik,i,new QTableWidgetItem(ciagnik.value(i).toString()));
    }
    if (now.daysTo(dataPrzeglad)<=7)
    {
             ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataPrzeglad)<=14)
    {
        ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataUbezpieczenie)<=7)
    {
             ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataUbezpieczenie)<=14)
    {
        ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataLegalizacja)<=7)
    {
             ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataLegalizacja)<=14)
    {
        ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataCzytanie)<=7)
    {
             ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataCzytanie)<=14)
    {
        ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataOpony1)<=7)
    {
             ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataOpony1)<=14)
    {
        ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataOpony2)<=7)
    {
             ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataOpony2)<=14)
    {
        ui->lista_ciagniki->item(iCiagnik,0)->setBackground(Qt::yellow);
    }


    iCiagnik ++;
}


int RowsNaczepa =1;
int ColumnsNaczepa =1;
QSqlQuery naczepa("SELECT * FROM testdb.naczepy");
ui->lista_naczepy->setColumnCount(RowsNaczepa=2);
ui->lista_naczepy->setRowCount(ColumnsNaczepa=naczepa.size());
int iNaczepa = 0;
for (int i = 0; i<=RowsNaczepa ;i++)
{
    QString rej2 = naczepa.record().fieldName(i);
    QTableWidgetItem *newItem = new QTableWidgetItem(rej2);
    ui ->lista_naczepy->setHorizontalHeaderItem(i, newItem);
}
while (naczepa.next())
{
    QDate dataPrzegladNaczepa = naczepa.value(2).toDate();
    QDate dataUbezpieczenieNaczepa = naczepa.value(2).toDate();
    QDate dataOpony1Naczepa = naczepa.value(4).toDate();
    QDate dataOpony2Naczepa = naczepa.value(5).toDate();
    QDate dataOpony3Naczepa = naczepa.value(6).toDate();
    for (int i=0; i<=RowsNaczepa-1; i++)
    {
        ui->lista_naczepy->setItem(iNaczepa,i,new QTableWidgetItem(naczepa.value(i).toString()));
    }
    if (now.daysTo(dataPrzegladNaczepa)<=7)
    {
             ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataPrzegladNaczepa)<=14)
    {
        ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataUbezpieczenieNaczepa)<=7)
    {
             ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataUbezpieczenieNaczepa)<=14)
    {
        ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataOpony1Naczepa)<=7 )
    {
             ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataOpony1Naczepa)<=14)
    {
        ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataOpony2Naczepa)<=7)
    {
             ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataOpony2Naczepa)<=14)
    {
        ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::yellow);
    }
    if (now.daysTo(dataOpony3Naczepa)<=7)
    {
             ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::red);
    }
    else if (now.daysTo(dataOpony3Naczepa)<=14)
    {
        ui->lista_naczepy->item(iNaczepa,0)->setBackground(Qt::yellow);
    }
    iNaczepa ++;
}
}

void MainWindow::on_Lista_pracownicy_cellClicked(int row, int column)
{
    int Rows=1;
    int Columns=1;
    QString x =ui->Lista_pracownicy->item(row,0)->text();
    QSqlQuery query;
    QDate now = QDate::currentDate();
    query.prepare("SELECT * FROM testdb.pracownicy WHERE id=? ");
    query.addBindValue(x);
    query.exec();
    ui->Ogolne->setColumnCount(Rows=query.record().count());
    ui->Ogolne->setRowCount(Columns=query.size());
    int ii = 0;
    for (int i = 0; i<=Rows ;i++)
    {
        QString nazwa = query.record().fieldName(i);
        QTableWidgetItem *newItem = new QTableWidgetItem(nazwa);
        ui ->Ogolne->setHorizontalHeaderItem(i, newItem);
    }
    while (query.next())
    {
        for (int i=0; i<=Rows-1; i++)
        {
            ui->Ogolne->setItem(ii,i,new QTableWidgetItem(query.value(i).toString()));
        }
        QDate data1 = query.value(3).toDate();
        QDate data2 = query.value(5).toDate();
        if (now.daysTo(data1)<=7)
        {
            ui->Ogolne->item(ii,3)->setBackground(Qt::red);
        }
        else if (now.daysTo(data1)<=14)
        {
            ui->Ogolne->item(ii,0)->setBackground(Qt::yellow);
        }
        if (now.daysTo(data2)<=7)
        {
            ui->Ogolne->item(ii,5)->setBackground(Qt::red);
        }
        else if (now.daysTo(data2)<=14)
        {
            ui->Ogolne->item(ii,0)->setBackground(Qt::yellow);
        }
        ii ++;
    }

}
void MainWindow::on_lista_ciagniki_cellClicked(int row, int column)
{
    int Rows=1;
    int Columns=1;
    QDate now = QDate::currentDate();
    QString x =ui->lista_ciagniki->item(row,0)->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM testdb.ciagniki WHERE id=?");
    query.addBindValue(x);
    query.exec();
    ui->Ogolne->setColumnCount(Rows=query.record().count());
    ui->Ogolne->setRowCount(Columns=query.size());
    int ii = 0;
    for (int i = 0; i<=Rows ;i++)
    {
        QString nazwa = query.record().fieldName(i);
        QTableWidgetItem *newItem = new QTableWidgetItem(nazwa);
        ui ->Ogolne->setHorizontalHeaderItem(i, newItem);
    }
    while (query.next())
    {
        QDate dataPrzeglad = query.value(2).toDate();
        QDate dataUbezpieczenie = query.value(3).toDate();
        QDate dataLegalizacja = query.value(4).toDate();
        QDate dataCzytanie = query.value(5).toDate();
        QDate dataOpony1 = query.value(6).toDate();
        QDate dataOpony2 = query.value(7).toDate();
        for (int i=0; i<=Rows-1; i++)
        {
            ui->Ogolne->setItem(ii,i,new QTableWidgetItem(query.value(i).toString()));
        }
        if (now.daysTo(dataPrzeglad)<=7)
        {
                 ui->Ogolne->item(ii,2)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataPrzeglad)<=14)
        {
            ui->Ogolne->item(ii,2)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataUbezpieczenie)<=7)
        {
                 ui->Ogolne->item(ii,3)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataUbezpieczenie)<=14)
        {
            ui->Ogolne->item(ii,3)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataLegalizacja)<=7 )
        {
                 ui->Ogolne->item(ii,4)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataLegalizacja)<=14)
        {
            ui->Ogolne->item(ii,4)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataCzytanie)<=7)
        {
                 ui->Ogolne->item(ii,5)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataCzytanie)<=14)
        {
            ui->Ogolne->item(ii,5)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataOpony1)<=7)
        {
                 ui->Ogolne->item(ii,6)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataOpony1)<=14)
        {
            ui->Ogolne->item(ii,6)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataOpony2)<=7)
        {
                 ui->Ogolne->item(ii,6)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataOpony2)<=14)
        {
            ui->Ogolne->item(ii,6)->setBackground(Qt::yellow);
        }
        ii ++;
    }
}
void MainWindow::on_lista_naczepy_cellClicked(int row, int column)
{
    int Rows=1;
    int Columns=1;
    QDate now = QDate::currentDate();

    QString x =ui->lista_naczepy->item(row,0)->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM testdb.naczepy WHERE id=?");
    query.addBindValue(x);
    query.exec();
    ui->Ogolne->setColumnCount(Rows=query.record().count());
    ui->Ogolne->setRowCount(Columns=query.size());
    int ii = 0;
    for (int i = 0; i<=Rows ;i++)
    {
        QString nazwa = query.record().fieldName(i);
        QTableWidgetItem *newItem = new QTableWidgetItem(nazwa);
        ui ->Ogolne->setHorizontalHeaderItem(i, newItem);
    }
    while (query.next())
    {
        QDate dataPrzegladNaczepa = query.value(2).toDate();
        QDate dataUbezpieczenieNaczepa = query.value(2).toDate();
        QDate dataOpony1Naczepa = query.value(4).toDate();
        QDate dataOpony2Naczepa = query.value(5).toDate();
        QDate dataOpony3Naczepa = query.value(6).toDate();
        for (int i=0; i<=Rows-1; i++)
        {
            ui->Ogolne->setItem(ii,i,new QTableWidgetItem(query.value(i).toString()));
        }
        if (now.daysTo(dataPrzegladNaczepa)<=7)
        {
                 ui->Ogolne->item(ii,2)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataPrzegladNaczepa)<=14)
        {
            ui->Ogolne->item(ii,2)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataUbezpieczenieNaczepa)<=7)
        {
                 ui->Ogolne->item(ii,3)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataUbezpieczenieNaczepa)<=14)
        {
            ui->Ogolne->item(ii,3)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataOpony1Naczepa)<=7 )
        {
                 ui->Ogolne->item(ii,4)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataOpony1Naczepa)<=14)
        {
            ui->Ogolne->item(ii,4)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataOpony2Naczepa)<=7)
        {
                 ui->Ogolne->item(ii,5)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataOpony2Naczepa)<=14)
        {
            ui->Ogolne->item(ii,5)->setBackground(Qt::yellow);
        }
        if (now.daysTo(dataOpony3Naczepa)<=7)
        {
                 ui->Ogolne->item(ii,6)->setBackground(Qt::red);
        }
        else if (now.daysTo(dataOpony3Naczepa)<=14)
        {
            ui->Ogolne->item(ii,6)->setBackground(Qt::yellow);
        }
        ii ++;
    }
}

void MainWindow::showOknoPracownik()
{
    oknoPracownika = new Dialog(this);
    oknoPracownika->show();
    oknoPracownika->exec();
}
void MainWindow::showDodajNaczepe()
{
    dodajNaczepe = new DodajNaczepe(this);
    dodajNaczepe->show();
    dodajNaczepe->exec();
}
void MainWindow::showDodajCiagnik()
{
    dodajCiagnik = new dodajciagnik(this);
    dodajCiagnik->show();
    dodajCiagnik->exec();
}

void MainWindow::on_button_refresh_clicked()
{
    Refreshing();
}

void MainWindow::edytowaniePracownicy()
{
    QString x =ui->Ogolne->item(0,0)->text();
    QString imie =ui->Ogolne->item(0,1)->text();
    QString nazwisko =ui->Ogolne->item(0,2)->text();
    QString prawoJazdy =ui->Ogolne->item(0,3)->text();
    QString adr =ui->Ogolne->item(0,4)->text();
    QString kartaKierowcy =ui->Ogolne->item(0,5)->text();
    QSqlQuery edytowanie;
    edytowanie.prepare("UPDATE testdb.pracownicy SET imie = ?, nazwisko = ?, prawoJazdy = ?, adr = ?, kartaKierowcy = ? WHERE id = ?");
    edytowanie.addBindValue(imie);
    edytowanie.addBindValue(nazwisko);
    edytowanie.addBindValue(prawoJazdy);
    edytowanie.addBindValue(adr);
    edytowanie.addBindValue(kartaKierowcy);
    edytowanie.addBindValue(x);
    if ( !edytowanie.exec())
    {
        QMessageBox::warning(NULL,edytowanie.lastQuery(),edytowanie.lastError().text(),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(NULL,"Dodano","Pomyślnie edytowanio baze danych",QMessageBox::Ok);
    }
}
void MainWindow::edytowanieCiagniki()
{
    QString x = ui->Ogolne->item(0,0)->text();
    QString nrRej = ui->Ogolne->item(0,1)->text();
    QString przeglad = ui->Ogolne->item(0,2)->text();
    QString ubezpieczenie = ui->Ogolne->item(0,3)->text();
    QString legalizacjaTacho = ui->Ogolne->item(0,4)->text();
    QString czytanieTacho = ui->Ogolne->item(0,5)->text();
    QString opony1 = ui->Ogolne->item(0,6)->text();
    QString opony2 = ui->Ogolne->item(0,7)->text();
    QSqlQuery edytowanie;
    edytowanie.prepare("UPDATE testdb.ciagniki SET nrRej=?, przeglad=?, ubezpieczenie=?, legalizacjaTacho=?, czytanieTacho=?, opony1=?, opony2=? WHERE id=?");
    edytowanie.addBindValue(nrRej);
    edytowanie.addBindValue(przeglad);
    edytowanie.addBindValue(ubezpieczenie);
    edytowanie.addBindValue(legalizacjaTacho);
    edytowanie.addBindValue(czytanieTacho);
    edytowanie.addBindValue(opony1);
    edytowanie.addBindValue(opony2);
    edytowanie.addBindValue(x);
    if ( !edytowanie.exec())
    {
        QMessageBox::warning(NULL,edytowanie.lastQuery(),edytowanie.lastError().text(),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(NULL,"Dodano","Pomyślnie edytowanio baze danych",QMessageBox::Ok);
    }
}
void MainWindow::edytowanieNaczepy()
{
    QString x = ui->Ogolne->item(0,0)->text();
    QString nrRej = ui->Ogolne->item(0,1)->text();
    QString przeglad = ui->Ogolne->item(0,2)->text();
    QString ubezpieczenie = ui->Ogolne->item(0,3)->text();
    QString opony1 = ui->Ogolne->item(0,4)->text();
    QString opony2 = ui->Ogolne->item(0,5)->text();
    QString opony3 = ui->Ogolne->item(0,6)->text();
    QSqlQuery edytowanie;
    edytowanie.prepare("UPDATE testdb.naczepy SET nrRej=?, przeglad=?, ubezpieczenie=?, opony1=?, opony2=?, opony3=?  WHERE id=?");
    edytowanie.addBindValue(nrRej);
    edytowanie.addBindValue(przeglad);
    edytowanie.addBindValue(ubezpieczenie);
    edytowanie.addBindValue(opony1);
    edytowanie.addBindValue(opony2);
    edytowanie.addBindValue(opony3);
    edytowanie.addBindValue(x);
    if ( !edytowanie.exec())
    {
        QMessageBox::warning(NULL,edytowanie.lastQuery(),edytowanie.lastError().text(),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(NULL,"Dodano","Pomyślnie edytowanio baze danych",QMessageBox::Ok);
    }
}

void MainWindow::usuwaniePracownika()
{
    QString x = ui->Ogolne->item(0,0)->text();
    QSqlQuery usuwanie;
    usuwanie.prepare("DELETE FROM testdb.pracownicy WHERE id=?");
    usuwanie.addBindValue(x);
    if ( !usuwanie.exec())
    {
        QMessageBox::warning(NULL,usuwanie.lastQuery(),usuwanie.lastError().text(),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(NULL,"Usunięto","Usunięto dane z bazy danych",QMessageBox::Ok);
    }
}
void MainWindow::usuwanieCiagnika()
{
    QString x = ui->Ogolne->item(0,0)->text();
    QSqlQuery usuwanie;
    usuwanie.prepare("DELETE FROM testdb.ciagniki WHERE id=?");
    usuwanie.addBindValue(x);
    if ( !usuwanie.exec())
    {
        QMessageBox::warning(NULL,usuwanie.lastQuery(),usuwanie.lastError().text(),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(NULL,"Usunięto","Usunięto dane z bazy danych",QMessageBox::Ok);
    }
}
void MainWindow::usuwanieNaczepy()
{
    QString x = ui->Ogolne->item(0,0)->text();
    QSqlQuery usuwanie;
    usuwanie.prepare("DELETE FROM testdb.naczepy WHERE id=?");
    usuwanie.addBindValue(x);
    if ( !usuwanie.exec())
    {
        QMessageBox::warning(NULL,usuwanie.lastQuery(),usuwanie.lastError().text(),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(NULL,"Usunięto","Usunięto dane z bazy danych",QMessageBox::Ok);
    }
}

void MainWindow::on_ok_clicked()
{
    if (ui->Ogolne->item(0,7) != NULL)
    {
        edytowanieCiagniki();
    }
    else if (ui->Ogolne->item(0,6) != NULL)
    {
        edytowanieNaczepy();
    }
    else
    {
        edytowaniePracownicy();
    }
    Refreshing();
}

void MainWindow::on_usun_clicked()
{
    if (ui->Ogolne->item(0,7) != NULL)
    {
        usuwanieCiagnika();
    }
    else if (ui->Ogolne->item(0,6) != NULL)
    {
        usuwanieNaczepy();
    }
    else
    {
        usuwaniePracownika();
    }
    Refreshing();
}
