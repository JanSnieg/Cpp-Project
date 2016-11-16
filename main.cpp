#include <QCoreApplication>
#include <QApplication>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QTextStream>
//CREATE DATABASE testdb;
//USE testdb;
//CREATE TABLE pracownicy (id INT NOT NULL, imie VARCHAR(20), nazwisko VARCHAR(20), prawoJazdy DATE, adr FLOAT, kartaKierowcy DATE, PRIMARY KEY (id));
//CREATE TABLE ciagniki (id INT NOT NULL, nrRej VARCHAR(20), przeglad DATE, ubezpieczenie DATE, legalizacjaTacho DATE, czytanieTacho DATE, opony1 DATE, opony2 DATE, PRIMARY KEY (id));
//CREATE TABLE naczepy (id INT NOT NULL, nrRej VARCHAR(20), przeglad DATE, ubezpieczenie DATE, opony1 DATE, opony2 DATE, opony3 DATE, PRIMARY KEY (id));

bool Connecting()
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

bool AddingEmployee()
{
    qDebug() << "Podaj imie pracownika";
    QTextStream i(stdin);
    QString imie = i.readLine();

    qDebug() << "Podaj nazwisko pracownika";
    QTextStream n(stdin);
    QString nazwisko = n.readLine();

    qDebug() << "Podaj date waznosci prawa jazdy (rrrr-mm-dd)";
    QTextStream prawoJ(stdin);
    QString prawoJazdy = prawoJ.readLine();

    float adr;
    qDebug() << "Podaj ADR";
    QTextStream cin(stdin);
    cin >> adr;

    qDebug() << "Podaj date waznosci karty kierowcy (rrrr-mm-dd)";
    QTextStream kartaK(stdin);
    QString kartaKierowcy = kartaK.readLine();

    QSqlQuery dodawanie;
    dodawanie.prepare("INSERT INTO `testdb`.`pracownicy` (imie, nazwisko, prawoJazdy, adr, kartaKierowcy) VALUES (?,?,?,?,?)");
    dodawanie.addBindValue(imie);
    dodawanie.addBindValue(nazwisko);
    dodawanie.addBindValue(prawoJazdy);
    dodawanie.addBindValue(adr);
    dodawanie.addBindValue(kartaKierowcy);
    dodawanie.exec();

    qDebug() << "Wpisano imie, nazwisko oraz wszystkie dane.";
}

bool AddingTruck()
{
    qDebug() << "Podaj numer rejestracyjny cagnika";
    QTextStream nrR(stdin);
    QString nrRej = nrR.readLine();

    qDebug() << "Podaj date przegladu (rrrr-mm-dd)";
    QTextStream p(stdin);
    QString przeglad = p.readLine();

    qDebug() << "Podaj date ubezpieczenia (rrrr-mm-dd)";
    QTextStream u(stdin);
    QString ubezpieczenie = u.readLine();

    qDebug() << "Podaj date legalizacji tachografu (rrrr-mm-dd)";
    QTextStream legalizacjaT(stdin);
    QString legalizacjaTacho = legalizacjaT.readLine();

    qDebug() << "Podaj date czytanie tachografu (rrrr-mm-dd)";
    QTextStream czytanieT(stdin);
    QString czytanieTacho = czytanieT.readLine();

    qDebug() << "Podaj date wymiany opon pierwszej osi (rrrr-mm-dd)";
    QTextStream o1(stdin);
    QString opony1 = o1.readLine();

    qDebug() << "Podaj date wymiany opon drugiej osi (rrrr-mm-dd)";
    QTextStream o2(stdin);
    QString opony2 = o2.readLine();

    QSqlQuery dodawanie;
    dodawanie.prepare("INSERT INTO `testdb`.`ciagniki` (nrRej, przeglad, ubezpieczenie, legalizacjaTacho, czytanieTacho, opony1, opony2) VALUES (?,?,?,?,?,?,?)");
    dodawanie.addBindValue(nrRej);
    dodawanie.addBindValue(przeglad);
    dodawanie.addBindValue(ubezpieczenie);
    dodawanie.addBindValue(legalizacjaTacho);
    dodawanie.addBindValue(czytanieTacho);
    dodawanie.addBindValue(opony1);
    dodawanie.addBindValue(opony2);
    dodawanie.exec();

    qDebug() << "Wpisano dane ciągnika do bazy danych.";
}

bool AddingTrailer()
{
    qDebug() << "Podaj numer rejestracyjny naczepy";
    QTextStream nrR(stdin);
    QString nrRej = nrR.readLine();

    qDebug() << "Podaj date przegladu (rrrr-mm-dd)";
    QTextStream p(stdin);
    QString przeglad = p.readLine();

    qDebug() << "Podaj date ubezpieczenia (rrrr-mm-dd)";
    QTextStream u(stdin);
    QString ubezpieczenie = u.readLine();

    qDebug() << "Podaj date wymiany opon pierwszej osi (rrrr-mm-dd)";
    QTextStream o1(stdin);
    QString opony1 = o1.readLine();

    qDebug() << "Podaj date wymiany opon drugiej osi (rrrr-mm-dd)";
    QTextStream o2(stdin);
    QString opony2 = o2.readLine();

    qDebug() << "Podaj date wymiany opon trzeciej osi (rrrr-mm-dd)";
    QTextStream o3(stdin);
    QString opony3 = o3.readLine();

    QSqlQuery dodawanie;
    dodawanie.prepare("INSERT INTO `testdb`.`ciagniki` (nrRej, przeglad, ubezpieczenie, opony1, opony2, opony3) VALUES (?,?,?,?,?,?)");
    dodawanie.addBindValue(nrRej);
    dodawanie.addBindValue(przeglad);
    dodawanie.addBindValue(ubezpieczenie);
    dodawanie.addBindValue(opony1);
    dodawanie.addBindValue(opony2);
    dodawanie.addBindValue(opony3);
    dodawanie.exec();

    qDebug() << "Wpisano dane ciągnika do bazy danych.";
}

bool DownloadingEmployee()
{
    QSqlQuery pobieranie;
    pobieranie.exec("SELECT * FROM `testdb`.`pracownicy`");
    while (pobieranie.next())
    {
        int id = pobieranie.value(0).toInt();
        QString imie = pobieranie.value(1).toString();
        QString nazwisko = pobieranie.value(2).toString();
        QString prawoJazdy = pobieranie.value(3).toString();
        float adr = pobieranie.value(4).toFloat();
        QString kartaKierowcy = pobieranie.value(5).toString();
        qDebug() << id << imie << nazwisko << prawoJazdy << adr << kartaKierowcy;
    }

}

bool DownloadingTruck()
{
    QSqlQuery pobieranie;
    pobieranie.exec("SELECT * FROM `testdb`.`ciagniki`");
    while (pobieranie.next())
    {
        int id = pobieranie.value(0).toInt();
        QString nrRej = pobieranie.value(1).toString();
        QString przeglad = pobieranie.value(2).toString();
        QString ubezpieczenie = pobieranie.value(3).toString();
        QString legalizacjaTacho = pobieranie.value(4).toString();
        QString czytanieTacho = pobieranie.value(5).toString();
        QString opony1 = pobieranie.value(6).toString();
        QString opony2 = pobieranie.value(7).toString();
        qDebug() << id << nrRej << przeglad << ubezpieczenie << legalizacjaTacho << czytanieTacho << opony1 << opony2;
    }

}

bool DownloadingTrailer()
{
    QSqlQuery pobieranie;
    pobieranie.exec("SELECT * FROM `testdb`.`naczepy`");
    while (pobieranie.next())
    {
        int id = pobieranie.value(0).toInt();
        QString nrRej = pobieranie.value(1).toString();
        QString przeglad = pobieranie.value(2).toString();
        QString ubezpieczenie = pobieranie.value(3).toString();
        QString opony1 = pobieranie.value(4).toString();
        QString opony2 = pobieranie.value(5).toString();
        QString opony3 = pobieranie.value(6).toString();
        qDebug() << id << nrRej << przeglad << ubezpieczenie << opony1 << opony2 << opony3;
    }

}

bool Deleting()
{
    int n = 0;
    do
    {
        if (n==0)
        {
            qDebug() << "Usun: 1-pracownika\n 2-ciagnik\n 3-naczepe\n 9-wroc do menu";
            QTextStream cin(stdin);
            cin >> n;
        }
        else if (n==1)
        {

                DownloadingEmployee();

                qDebug() << "Podaj id do usuniecia";
                QTextStream s1(stdin);
                QString idPracownicy = s1.readLine();
                QSqlQuery usuwaniePracownicy;
                usuwaniePracownicy.prepare("DELETE FROM `testdb`.`pracownicy` WHERE id = ? ");
                usuwaniePracownicy.addBindValue(idPracownicy);
                usuwaniePracownicy.exec();
                n=0;
        }
        else if (n==2)
        {
            DownloadingTruck();

            qDebug() << "Podaj id do usuniecia";
            QTextStream s2(stdin);
            QString idCiagniki = s2.readLine();
            QSqlQuery usuwanieCiagniki;
            usuwanieCiagniki.prepare("DELETE FROM `testdb`.`ciagniki` WHERE id = ? ");
            usuwanieCiagniki.addBindValue(idCiagniki);
            usuwanieCiagniki.exec();
            n=0;
        }
        else if (n==3)
        {
            DownloadingTrailer();

            qDebug() << "Podaj id do usuniecia";
            QTextStream s3(stdin);
            QString idNaczepy = s3.readLine();
            QSqlQuery usuwanieNaczepy;
            usuwanieNaczepy.prepare("DELETE FROM `testdb`.`naczepy` WHERE id = ? ");
            usuwanieNaczepy.addBindValue(idNaczepy);
            usuwanieNaczepy.exec();
            n=0;

        }
        else
        {
            qDebug() << "Zly numer";
            n = 0;
        }

    }while (n!=9);
}

bool Updateing()
{
    qDebug() << "Podaj id pracownika, ktorego chcesz zmienic";
    QTextStream s(stdin);
    QString id_update = s.readLine();
    qDebug() << "Podaj nowe imie pracownika";
    QTextStream i(stdin);
    QString imie_update = s.readLine();
    qDebug() << "Podaj nowe nazwisko pracownika";
    QTextStream n(stdin);
    QString nazwisko_update = s.readLine();

    QSqlQuery edytowanie;
    edytowanie.prepare("UPDATE pracownicy SET imie = ?, nazwisko = ? WHERE id = ? ");
    edytowanie.addBindValue(imie_update);
    edytowanie.addBindValue(nazwisko_update);
    edytowanie.addBindValue(id_update);
    edytowanie.exec();
}

int Menu()
{
    qDebug() << "Co chcesz zrobic:\n 1-wyświetlenie pracownikow\n 2-wyswietlenie ciagnikow\n 3-wyswietlenie naczep\n 4-dodawanie pracownika\n 5-dodawanie ciagnika\n 6-dodawanie naczepy\n 7-usuwanie\n 8-edytowanie\n 9-zamkniecie programu.";
    int liczba;
    QTextStream cin(stdin);
    cin >> liczba;
    return liczba;
}

int main()
{
    Connecting();
    int n = Menu();
    do
    {

        switch (n)
        {
        case 0:
            n = Menu();
            break;
        case 1:
            DownloadingEmployee();
            n = Menu();
            break;
        case 2:
            DownloadingTruck();
            n = Menu();
            break;
        case 3:
            DownloadingTrailer();
            n = Menu();
            break;
        case 4:
            AddingEmployee();
            n = Menu();
            break;
        case 5:
           AddingTruck();
           n = Menu();
           break;
        case 6:
           AddingTrailer();
           n = Menu();
           break;
        case 7:
            Deleting();
            n = Menu();
            break;
        case 8:
            Updateing();
            n = Menu();
            break;
        default:
            qDebug() << "Zły numer...";
            n = Menu();
        }
    }while (n != 9);

    return 0;
}
