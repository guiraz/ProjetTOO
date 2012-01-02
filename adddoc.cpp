#include "adddoc.h"
#include "ui_adddoc.h"

AddDoc::AddDoc(Library* lib, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDoc)
{
    _lib=lib;
    ui->setupUi(this);
}

AddDoc::~AddDoc()
{
    delete ui;
}

void AddDoc::on_pushButtonAbort_clicked()
{
    close();
}
