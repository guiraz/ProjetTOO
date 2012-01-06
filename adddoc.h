#ifndef ADDDOC_H
#define ADDDOC_H
/*!
 *\file adddoc.h
 *\brief This file contains the GUI's add Document Window
 *\author IRLES Loïc
 *\version 0.1
 */
#include <cstring>
#include <QMessageBox>
#include <QDialog>
#include "class/library.h"
/*! \namespace Ui
 *
 * namespace who regroups all the functions and the class
 * for the GUI's add Document Window
 */
namespace Ui {
    class AddDoc;
}
/*! \class AddDoc
 *\brief add Document Window representation class
 *
 * This class represents a add Document Window wich inherit from \em QDialog
 */
class AddDoc : public QDialog
{
    Q_OBJECT

public:
    /*!
     *  \brief Constructor
     *
     *  AddDoc class's constructor
     *  \param[in] parent : the parent widget of the \em AddDoc
     */
    explicit AddDoc(Library* lib,QWidget *parent = 0);
    /*!
     *  \brief Destructor
     *
     *  AddDoc class's destructor
     */
    ~AddDoc();

private slots:
    /*!
     *  \brief \a pushButtonOk clicked()
     *
     *  When \a pushButtonOk is clicked a document is add to the library is the fields are correctly filled
     */
    void on_pushButtonOk_clicked();
    /*!
     *  \brief \a lineEditConsole Edited
     *
     *  When \a lineEditConsole is edited \a _edited[8] is put at true
     */
    void on_lineEditConsole_textEdited(const QString& );
    /*!
     *  \brief \a lineEditBand Edited
     *
     *  When \a lineEditBand is edited \a _edited[7] is put at true
     */
    void on_lineEditBand_textEdited(const QString& );
    /*!
     *  \brief \a lineEditDirector Edited
     *
     *  When \a lineEditDirector is edited \a _edited[6] is put at true
     */
    void on_lineEditDirector_textEdited(const QString& );
    /*!
     *  \brief \a lineEditStyle Edited
     *
     *  When \a lineEditStyle is edited \a _edited[5] is put at true
     */
    void on_lineEditStyle_textEdited(const QString& );
    /*!
     *  \brief \a lineEditMount Edited
     *
     *  When \a lineEditMount is edited \a _edited[4] is put at true
     */
    void on_lineEditMount_textEdited(const QString& );
    /*!
     *  \brief \a lineEditAutor Edited
     *
     *  When \a lineEditAutor is edited \a _edited[3] is put at true
     */
    void on_lineEditAutor_textEdited(const QString& );
    /*!
     *  \brief \a spinBoxYear is Changed
     *
     *  When \a spinBoxYear is changed \a _edited[2] is put at true
     */
    void on_spinBoxYear_valueChanged(const int& );
    /*!
     *  \brief \a lineEditName Edited
     *
     *  When \a lineEditNale is edited \a _edited[1] is put at true
     */
    void on_lineEditName_textEdited(const QString& );
    /*!
     *  \brief \a comboBoxType Edited
     *
     *  When \a comboBoxType is edited \a _edited[0] is put at true
     */
    void on_comboBoxType_activated(int index);
    /*!
     *  \brief \a pushButtonAbort clicked
     *
     *  When \a pushButtonAbort is clicked the windows is close whitout any modifications
     */
    void on_pushButtonAbort_clicked();

private:
    Ui::AddDoc *ui;/*!< AddDoc's user interface*/
    Library* _lib;/*!< AddDoc's Library*/
    bool* _edited;/*!< AddDoc's Edited fields*/

    /*!
     *  \brief Reference Generator
     *
     *  Search an available reference for a document and return it
     * \return a reference in a \em std::string
     */
    std::string refGenerator();
};

#endif // ADDDOC_H
