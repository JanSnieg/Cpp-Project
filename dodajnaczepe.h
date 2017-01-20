#ifndef DODAJNACZEPE_H
#define DODAJNACZEPE_H

#include <QDialog>

namespace Ui {
class DodajNaczepe;
}

class DodajNaczepe : public QDialog
{
    Q_OBJECT

public:
    explicit DodajNaczepe(QWidget *parent = 0);
    ~DodajNaczepe();
public slots:
    void on_ok_clicked();

private:
    Ui::DodajNaczepe *ui;
};

#endif // DODAJNACZEPE_H
