#ifndef ADDDOC_H
#define ADDDOC_H

#include <QDialog>
#include "class/library.h"

namespace Ui {
    class AddDoc;
}

class AddDoc : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoc(Library* lib,QWidget *parent = 0);
    ~AddDoc();

private slots:
    void on_pushButtonAbort_clicked();

private:
    Ui::AddDoc *ui;
    Library* _lib;
};

#endif // ADDDOC_H
