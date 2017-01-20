#ifndef DODAJCIAGNIK_H
#define DODAJCIAGNIK_H

#include <QDialog>

namespace Ui {
class dodajciagnik;
}

class dodajciagnik : public QDialog
{
    Q_OBJECT

public:
    explicit dodajciagnik(QWidget *parent = 0);
    ~dodajciagnik();
public slots:
    void on_ok_clicked();

private:
    Ui::dodajciagnik *ui;
};

#endif // DODAJCIAGNIK_H
