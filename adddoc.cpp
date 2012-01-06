#include "adddoc.h"
#include "ui_adddoc.h"

AddDoc::AddDoc(Library* lib, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDoc)
{
    _lib=lib;
    _edited=new bool[9];
    for (int i=0; i<9; i++)
    {
        _edited[i]=false;
    }
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

void AddDoc::on_comboBoxType_activated(int index)
{
    switch (index)
    {
    case 0:
        ui->labelAutor->setEnabled(false);
        ui->labelName->setEnabled(false);
        ui->labelYear->setEnabled(false);
        ui->labelMount->setEnabled(false);
        ui->labelDirector->setEnabled(false);
        ui->labelBand->setEnabled(false);
        ui->labelConsole->setEnabled(false);
        ui->labelStyle->setEnabled(false);

        ui->lineEditAutor->setEnabled(false);
        ui->lineEditName->setEnabled(false);
        ui->spinBoxYear->setEnabled(false);
        ui->lineEditMount->setEnabled(false);
        ui->lineEditDirector->setEnabled(false);
        ui->lineEditBand->setEnabled(false);
        ui->lineEditConsole->setEnabled(false);
        ui->lineEditStyle->setEnabled(false);
        _edited[0]=false;
        break;
    case 1:
        ui->labelAutor->setEnabled(true);
        ui->labelName->setEnabled(true);
        ui->labelYear->setEnabled(true);
        ui->labelMount->setEnabled(false);
        ui->labelDirector->setEnabled(false);
        ui->labelBand->setEnabled(false);
        ui->labelConsole->setEnabled(false);
        ui->labelStyle->setEnabled(false);

        ui->lineEditAutor->setEnabled(true);
        ui->lineEditName->setEnabled(true);
        ui->spinBoxYear->setEnabled(true);
        ui->lineEditMount->setEnabled(false);
        ui->lineEditDirector->setEnabled(false);
        ui->lineEditBand->setEnabled(false);
        ui->lineEditConsole->setEnabled(false);
        ui->lineEditStyle->setEnabled(false);
        _edited[0]=true;
        break;
    case 2:
        ui->labelAutor->setEnabled(false);
        ui->labelName->setEnabled(true);
        ui->labelYear->setEnabled(true);
        ui->labelMount->setEnabled(true);
        ui->labelDirector->setEnabled(true);
        ui->labelBand->setEnabled(false);
        ui->labelConsole->setEnabled(false);
        ui->labelStyle->setEnabled(false);

        ui->lineEditAutor->setEnabled(false);
        ui->lineEditName->setEnabled(true);
        ui->spinBoxYear->setEnabled(true);
        ui->lineEditMount->setEnabled(true);
        ui->lineEditDirector->setEnabled(true);
        ui->lineEditBand->setEnabled(false);
        ui->lineEditConsole->setEnabled(false);
        ui->lineEditStyle->setEnabled(false);
        _edited[0]=true;
        break;
    case 3:
        ui->labelAutor->setEnabled(false);
        ui->labelName->setEnabled(true);
        ui->labelYear->setEnabled(true);
        ui->labelMount->setEnabled(true);
        ui->labelDirector->setEnabled(false);
        ui->labelBand->setEnabled(false);
        ui->labelConsole->setEnabled(true);
        ui->labelStyle->setEnabled(false);

        ui->lineEditAutor->setEnabled(false);
        ui->lineEditName->setEnabled(true);
        ui->spinBoxYear->setEnabled(true);
        ui->lineEditMount->setEnabled(true);
        ui->lineEditDirector->setEnabled(false);
        ui->lineEditBand->setEnabled(false);
        ui->lineEditConsole->setEnabled(true);
        ui->lineEditStyle->setEnabled(false);
        _edited[0]=true;
        break;
    case 4:
        ui->labelAutor->setEnabled(true);
        ui->labelName->setEnabled(true);
        ui->labelYear->setEnabled(true);
        ui->labelMount->setEnabled(false);
        ui->labelDirector->setEnabled(false);
        ui->labelBand->setEnabled(false);
        ui->labelConsole->setEnabled(false);
        ui->labelStyle->setEnabled(true);

        ui->lineEditAutor->setEnabled(true);
        ui->lineEditName->setEnabled(true);
        ui->spinBoxYear->setEnabled(true);
        ui->lineEditMount->setEnabled(false);
        ui->lineEditDirector->setEnabled(false);
        ui->lineEditBand->setEnabled(false);
        ui->lineEditConsole->setEnabled(false);
        ui->lineEditStyle->setEnabled(true);
        _edited[0]=true;
        break;
    case 5:
        ui->labelAutor->setEnabled(true);
        ui->labelName->setEnabled(true);
        ui->labelYear->setEnabled(true);
        ui->labelMount->setEnabled(true);
        ui->labelDirector->setEnabled(false);
        ui->labelBand->setEnabled(false);
        ui->labelConsole->setEnabled(false);
        ui->labelStyle->setEnabled(false);

        ui->lineEditAutor->setEnabled(true);
        ui->lineEditName->setEnabled(true);
        ui->spinBoxYear->setEnabled(true);
        ui->lineEditMount->setEnabled(true);
        ui->lineEditDirector->setEnabled(false);
        ui->lineEditBand->setEnabled(false);
        ui->lineEditConsole->setEnabled(false);
        ui->lineEditStyle->setEnabled(false);
        _edited[0]=true;
        break;
    case 6:
        ui->labelAutor->setEnabled(false);
        ui->labelName->setEnabled(true);
        ui->labelYear->setEnabled(true);
        ui->labelMount->setEnabled(true);
        ui->labelDirector->setEnabled(false);
        ui->labelBand->setEnabled(true);
        ui->labelConsole->setEnabled(false);
        ui->labelStyle->setEnabled(false);

        ui->lineEditAutor->setEnabled(false);
        ui->lineEditName->setEnabled(true);
        ui->spinBoxYear->setEnabled(true);
        ui->lineEditMount->setEnabled(true);
        ui->lineEditDirector->setEnabled(false);
        ui->lineEditBand->setEnabled(true);
        ui->lineEditConsole->setEnabled(false);
        ui->lineEditStyle->setEnabled(false);
        _edited[0]=true;
        break;

    }
}

void AddDoc::on_lineEditName_textEdited(const QString& text)
{
   if (text.size()!=0)
   {
      _edited[1]=true;
   }
   else
   {
      _edited[1]=false;
   }
}

void AddDoc::on_spinBoxYear_valueChanged(const int&)
{
     _edited[2]=true;
}

void AddDoc::on_lineEditAutor_textEdited(const QString& text)
{
    if (text.size()!=0)
    {
       _edited[3]=true;
    }
    else
    {
       _edited[3]=false;
    }

}

void AddDoc::on_lineEditMount_textEdited(const QString& text)
{
    if (text.size()!=0)
    {
       _edited[4]=true;
    }
    else
    {
       _edited[4]=false;
    }
}

void AddDoc::on_lineEditStyle_textEdited(const QString& text)
{
    if (text.size()!=0)
    {
       _edited[5]=true;
    }
    else
    {
       _edited[5]=false;
    }
}

void AddDoc::on_lineEditDirector_textEdited(const QString& text)
{
    if (text.size()!=0)
    {
       _edited[6]=true;
    }
    else
    {
       _edited[6]=false;
    }
}

void AddDoc::on_lineEditBand_textEdited(const QString& text)
{
    if (text.size()!=0)
    {
       _edited[7]=true;
    }
    else
    {
       _edited[7]=false;
    }
}

void AddDoc::on_lineEditConsole_textEdited(const QString& text)
{
    if (text.size()!=0)
    {
       _edited[8]=true;
    }
    else
    {
       _edited[8]=false;
    }
}

void AddDoc::on_pushButtonOk_clicked()
{
    QString name,autor,director,mount,console,band,style;
    int year = ui->spinBoxYear->value();
    name = ui->lineEditName->text();
    autor = ui->lineEditAutor->text();
    director = ui->lineEditDirector->text();
    mount = ui->lineEditMount->text();
    console = ui->lineEditConsole->text();
    band = ui->lineEditBand->text();
    style = ui->lineEditStyle->text();
    switch (ui->comboBoxType->currentIndex())
    {
    case 0:
        QMessageBox::critical(this, "Erreur de type", "Veuillez choisir un type svp !!!");
        break;
    case 1:
        if(_edited[0] && _edited[1] && _edited[2] && _edited[3])
        {
            _lib->pushElement(new Comic(autor.toStdString(),name.toStdString(),refGenerator(),year));
            close();
        }
        else
        {
             QMessageBox::critical(this, "Erreur", "Veuillez remplir tout les champs svp !!!");
        }
        break;
    case 2:
        if(_edited[0] && _edited[1] && _edited[2] &&  _edited[4] && _edited[6])
        {
            _lib->pushElement(new Film(director.toStdString(),mount.toStdString(),name.toStdString(),refGenerator(),year));
            close();
        }
        else
        {
             QMessageBox::critical(this, "Erreur", "Veuillez remplir tout les champs svp !!!");
        }
        break;
    case 3:
        if(_edited[0] && _edited[1] && _edited[2] && _edited[4] && _edited[8])
        {
            _lib->pushElement(new VideoGame(console.toStdString(),mount.toStdString(),name.toStdString(),refGenerator(),year));
            close();
        }
        else
        {
             QMessageBox::critical(this, "Erreur", "Veuillez remplir tout les champs svp !!!");
        }
        break;
    case 4:
        if(_edited[0] && _edited[1] && _edited[2] && _edited[3] && _edited[5])
        {
            _lib->pushElement(new Book(style.toStdString(),autor.toStdString(),name.toStdString(),refGenerator(),year));
            close();
        }
        else
        {
             QMessageBox::critical(this, "Erreur", "Veuillez remplir tout les champs svp !!!");
        }
        break;
    case 5:
        if(_edited[0] && _edited[1] && _edited[2] && _edited[3] && _edited[4])
        {
            _lib->pushElement(new Ebook(autor.toStdString(),mount.toStdString(),name.toStdString(),refGenerator(),year));
            close();
        }
        else
        {
             QMessageBox::critical(this, "Erreur", "Veuillez remplir tout les champs svp !!!");
        }
        break;
    case 6:
        if(_edited[0] && _edited[1] && _edited[4] && _edited[7] && _edited[2])
        {
            _lib->pushElement(new Music(band.toStdString(),mount.toStdString(),name.toStdString(),refGenerator(),year));
            close();
        }
        else
        {
             QMessageBox::critical(this, "Erreur", "Veuillez remplir tout les champs svp !!!");
        }
        break;
    }
}

std::string AddDoc::refGenerator()
{
    bool exist = true;
    int iref = -1;
    while (exist)
    {
        exist=false;
        iref ++;
        for(unsigned int i = 0; i<_lib->getSize();i++)
        {
            if(iref==QString::fromStdString(_lib->getElement(i)->getRef()).toInt())
            {
                exist=true;
            }
        }
    }

    QString QSref;
    QSref.setNum(iref);

    switch (QSref.size())
    {
    case 0 :
        return "000000";
        break;
    case 1 :
        QSref = "00000"+QSref;
        return QSref.toStdString();
        break;
    case 2 :
        QSref = "0000"+QSref;
        return QSref.toStdString();
        break;
    case 3 :
        QSref = "000"+QSref;
        return QSref.toStdString();
        break;
    case 4 :
        QSref = "00"+QSref;
        return QSref.toStdString();
        break;
    case 5 :
        QSref = "0"+QSref;
        return QSref.toStdString();
        break;
    case 6 :
        return QSref.toStdString();
        break;
    }
    return "";
}
