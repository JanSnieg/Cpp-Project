//
//  main.cpp
//  pierwszyP
//
//  Created by Paweł Olszowy on 20/10/2016.
//  Copyright © 2016 Paweł Olszowy. All rights reserved.
//

#include <iostream>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i=0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int manu()
{
    int liczba=0;
    std::cout << "Wpisz:/n"
                 "1. aby zobaczyć bazę"
                 "2. aby dodać przedmiot do bazy"
                 "3. aby usunąć z bazy"
                 "4. aby edytować istniejący";
    std::cin >> liczba;
    return liczba;
}



int show(char sql)
{
    int liczba = 0;
    std::cout << sql;
    std::cin >> liczba;
    return liczba;
}


int add(char sql)
{
    int liczba=0;
    char znaki[100];
    char przecinek[2] = ",";
    int rozmiar;
    int i;
    std::cout << "Podaj dane oddzielając przecinkami";
    std::cin.getline(znaki, rozmiar);
    for (i=0;i<rozmiar;i++)
    {
            //if (znaki[i]==przecinek)
    }
    
    return liczba;
}

int main(int argc, const char * argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    
    rc=sqlite3_open("test.db", &db);
    
    if ( rc )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
    }
    
    /*sql = "CREATE TABLE COMPANY("
        "ID INT PRIMARY KEY     NOT NULL,"
        "CN             TEXT    NOT NULL,"
        "NR REJ         DATE    NOT NULL,"
        "PRZEGLAD       DATE    NOT NULL,"
        "UBEZPIECZENIE  DATE    NOT NULL,"
        "TACHOGRAF      DATE    NOT NULL,"
        "OPONA1         DATE    NOT NULL,"
        "OPONA2         DATE    NOT NULL,"
        "OPONA3         DATE    NOT NULL,"
        "OPONA4         DATE    NOT NULL,"
        "OPONA5         DATE    NOT NULL,"
        "KIEROWCA       TEXT    NOT NULL,"
        "PRAWO          DATE    NOT NULL,"
        "ADR            DATE    NOT NULL,"
        "KARTA          DATE    NOT NULL);";
    */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Table created successfully\n");
    }
    show(*sql);
    sqlite3_close(db);
    return 0;
}
