#ifndef ADDDOC_H
#define ADDDOC_H

#include <cstring>
#include <QMessageBox>
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
    void on_pushButtonOk_clicked();
    void on_lineEditConsole_textEdited(const QString& );
    void on_lineEditBand_textEdited(const QString& );
    void on_lineEditDirector_textEdited(const QString& );
    void on_lineEditStyle_textEdited(const QString& );
    void on_lineEditMount_textEdited(const QString& );
    void on_lineEditAutor_textEdited(const QString& );
    void on_spinBoxYear_valueChanged(const int& );
    void on_lineEditName_textEdited(const QString& );
    void on_comboBoxType_activated(int index);
    void on_pushButtonAbort_clicked();

private:
    Ui::AddDoc *ui;
    Library* _lib;
    bool* _edited;
    std::string refGenerator();
};

#endif // ADDDOC_H
