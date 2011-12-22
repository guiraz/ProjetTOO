#include "library.h"

Library::Library()
{
}

Library::~Library()
{
}

void Library::erase()
{
    for(unsigned int i=0; i<_docsList.size(); i++)
    {
        _docsList[i]=NULL;
        delete _docsList[i];
    }
    _docsList.clear();
}

Docs* Library::getElement(const int& position)
{
    return _docsList[position];
}

void Library::pushElement(Docs* element)
{
    _docsList.push_back(element);
}

void Library::popElement(const int & position)
{
    for(unsigned int i=position; i<_docsList.size()-1; i++)
    {
        invert(i, i+1);
    }
    _docsList[_docsList.size()-1]=NULL;
    delete _docsList[_docsList.size()-1];
    _docsList.pop_back();
}

void Library::displayAll()
{
    for(unsigned int i=0; i<_docsList.size(); i++)
    {
        switch(intTheType(i))
        {
        case 2:
            displayFilm(i);
            break;
        case 6:
            displayMusic(i);
            break;
        case 3:
            displayVideoGame(i);
            break;
        case 5:
            displayEbook(i);
            break;
        case 1:
            displayComic(i);
            break;
        case 4:
            displayBook(i);
            break;
        default:
            std::cout<<"Problem Occured -> Function Library::displayll() i>6 or i<1"<<std::endl;
        }
    }
}

void Library::displayFilm(const int& position)
{
    std::cout<<getElement(position)->getRef()<<" "<<getElement(position)->getName()<<" "<<getElement(position)->getYear()<<" "<<getElement(position)->getMount()<<" "<<getElement(position)->getDirector()<<std::endl;
}

void Library::displayMusic(const int& position)
{
    std::cout<<getElement(position)->getRef()<<" "<<getElement(position)->getName()<<" "<<getElement(position)->getYear()<<" "<<getElement(position)->getMount()<<" "<<getElement(position)->getBand()<<std::endl;
}

void Library::displayVideoGame(const int& position)
{
    std::cout<<getElement(position)->getRef()<<" "<<getElement(position)->getName()<<" "<<getElement(position)->getYear()<<" "<<getElement(position)->getMount()<<" "<<getElement(position)->getConsole()<<std::endl;
}

void Library::displayEbook(const int& position)
{
    std::cout<<getElement(position)->getRef()<<" "<<getElement(position)->getName()<<" "<<getElement(position)->getYear()<<" "<<getElement(position)->getAutor()<<" "<<getElement(position)->getMount()<<std::endl;
}

void Library::displayComic(const int& position)
{
    std::cout<<getElement(position)->getRef()<<" "<<getElement(position)->getName()<<" "<<getElement(position)->getYear()<<" "<<getElement(position)->getAutor()<<std::endl;
}

void Library::displayBook(const int& position)
{
    std::cout<<getElement(position)->getRef()<<" "<<getElement(position)->getName()<<" "<<getElement(position)->getYear()<<" "<<getElement(position)->getAutor()<<" "<<getElement(position)->getStyle()<<std::endl;
}

void Library::invert(const int& pos1, const int& pos2)
{
    Docs * ptr;
    ptr=_docsList[pos1];
    _docsList[pos1]=_docsList[pos2];
    _docsList[pos2]=ptr;
}

void Library::sortByType()
{
    int curse=0;
    for(unsigned int i=1; i<7; i++)
    {
        for(unsigned int j=curse; j<_docsList.size(); j++)
        {
            if(intTheType(j)==i)
            {
                invert(j, curse);
                curse++;
            }
        }
    }
}

void Library::sortByName()
{

    for(unsigned int i=0; i<_docsList.size()-1; i++)
    {
        int min=i;
        for(unsigned int j=i+1; j<_docsList.size(); j++)
        {
            if(_docsList[min]->getName().compare(_docsList[j]->getName())>0)
            {
                min=j;
            }
        }
        invert(i, min);
    }

}

void Library::sortByYear()
{

    for(unsigned int i=0; i<_docsList.size()-1; i++)
    {
        int min=i;
        for(unsigned int j=i+1; j<_docsList.size(); j++)
        {
            if(_docsList[min]->getYear()>_docsList[j]->getYear())
            {
                min=j;
            }
        }
        invert(i, min);
    }

}

void Library::exportLib2Html()
{

    std::ofstream css("../HTML/style.css");
    if(css)
    {
        css<<"table"<<std::endl;
        css<<"{"<<std::endl;
        css<<"    width: 99%;"<<std::endl;
        css<<"    border-collapse: collapse;"<<std::endl;
        css<<"}"<<std::endl;
        css<<"td"<<std::endl;
        css<<"{"<<std::endl;
        css<<"    width: 16%;"<<std::endl;
        css<<"    text-align: center;"<<std::endl;
        css<<"    border: 1px solid black;"<<std::endl;
        css<<"}"<<std::endl;
        css.close();
    }

    std::ofstream html("../HTML/index.html");
    if(html)
    {
        html<<"<!DOCTYPE html>"<<std::endl;
        html<<"<head>"<<std::endl;
        html<<"   <meta charset=\"utf-8\" />"<<std::endl;
        html<<"   <link rel=\"stylesheet\" href=\"style.css\" />"<<std::endl;
        html<<"   <title>|-> Exportation bibliothéque multimédia <-|</title>"<<std::endl;
        html<<"</head>"<<std::endl;
        html<<"<body>"<<std::endl;
        html<<"<table>"<<std::endl;
        html<<"   <tr>"<<std::endl;
        html<<"      <td><a href=\"#film\">Film</a>"<<std::endl;
        html<<"      </td>"<<std::endl;
        html<<"      <td><a href=\"#book\">Livre</a>"<<std::endl;
        html<<"      </td>"<<std::endl;
        html<<"      <td><a href=\"#music\">Musique</a>"<<std::endl;
        html<<"      </td>"<<std::endl;
        html<<"      <td><a href=\"#vg\">Jeux Video</a>"<<std::endl;
        html<<"      </td>"<<std::endl;
        html<<"      <td><a href=\"#comic\">Bande Dessinée</a>"<<std::endl;
        html<<"      </td>"<<std::endl;
        html<<"      <td><a href=\"#ebook\">Livre Numérique</a>"<<std::endl;
        html<<"      </td>"<<std::endl;
        html<<"   </tr>"<<std::endl;
        html<<"</table>"<<std::endl;

        html<<"<h1 id=\"film\">Films</h1>"<<std::endl;
        for(unsigned int i=0; i<_docsList.size(); i++)
        {
            if(intTheType(i)==2)
            {
                html<<"<b>"<<_docsList[i]->getName()<<"</b> de "<<_docsList[i]->getDirector()<<" tourné en "<<_docsList[i]->getYear()<<" sur "<<_docsList[i]->getMount()<<". (REF: "<<_docsList[i]->getRef()<<")<br />"<<std::endl;
            }
        }

        html<<"<h1 id=\"book\">Livres</h1>"<<std::endl;
        for(unsigned int i=0; i<_docsList.size(); i++)
        {
            if(intTheType(i)==4)
            {
                html<<"<b>"<<_docsList[i]->getName()<<"</b> est un(e) "<<_docsList[i]->getStyle()<<" de "<<_docsList[i]->getAutor()<<" édité en "<<_docsList[i]->getYear()<<". (REF: "<<_docsList[i]->getRef()<<")<br />"<<std::endl;
            }
        }

        html<<"<h1 id=\"music\">Musique</h1>"<<std::endl;
        for(unsigned int i=0; i<_docsList.size(); i++)
        {
            if(intTheType(i)==6)
            {
                html<<"<b>"<<_docsList[i]->getName()<<"</b> de "<<_docsList[i]->getBand()<<" sorti en "<<_docsList[i]->getYear()<<" sur "<<_docsList[i]->getMount()<<". (REF: "<<_docsList[i]->getRef()<<")<br />"<<std::endl;
            }
        }

        html<<" <h1 id=\"vg\">Jeux Video</h1>"<<std::endl;
        for(unsigned int i=0; i<_docsList.size(); i++)
        {
            if(intTheType(i)==3)
            {
                html<<"<b>"<<_docsList[i]->getName()<<"</b> sorti en "<<_docsList[i]->getYear()<<" sur "<<_docsList[i]->getConsole()<<" en "<<_docsList[i]->getMount()<<". (REF: "<<_docsList[i]->getRef()<<")<br />"<<std::endl;
            }
        }

        html<<"<h1 id=\"comic\">Bande dessinée</h1>"<<std::endl;
        for(unsigned int i=0; i<_docsList.size(); i++)
        {
            if(intTheType(i)==1)
            {
                html<<"<b>"<<_docsList[i]->getName()<<"</b> de "<<_docsList[i]->getAutor()<<" édité en "<<_docsList[i]->getYear()<<". (REF: "<<_docsList[i]->getRef()<<")<br />"<<std::endl;
            }
        }

        html<<"<h1 id=\"ebook\">Livres Numériques</h1>"<<std::endl;
        for(unsigned int i=0; i<_docsList.size(); i++)
        {
            if(intTheType(i)==5)
            {
                html<<"<b>"<<_docsList[i]->getName()<<"</b> de "<<_docsList[i]->getAutor()<<" diponible depuis "<<_docsList[i]->getYear()<<" en "<<_docsList[i]->getMount()<<". (REF: "<<_docsList[i]->getRef()<<")<br />"<<std::endl;
            }
        }
        html<<"</body>"<<std::endl;
        html<<"</html>"<<std::endl;
        html.close();
    }
}
/*
void Library::importDB()
{
    QSqlQuery importDBQuery;

    importDBQuery.exec("select * from FILM;");
    if (importDBQuery.first())
    {
        do
        {
            const std::string ref=importDBQuery.value(0).toString().toStdString();
            const std::string name=importDBQuery.value(1).toString().toStdString();
            const std::string director=importDBQuery.value(2).toString().toStdString();
            const int year=importDBQuery.value(3).toInt();
            const std::string mount=importDBQuery.value(4).toString().toStdString();

            pushElement(new Film(director, mount, name, ref, year));

        }while(importDBQuery.next());
    }
    importDBQuery.clear();

    importDBQuery.exec("select * from MUSIC;");
    if (importDBQuery.first())
    {
        do
        {
            const std::string ref=importDBQuery.value(0).toString().toStdString();
            const std::string name=importDBQuery.value(1).toString().toStdString();
            const std::string band=importDBQuery.value(2).toString().toStdString();
            const int year=importDBQuery.value(3).toInt();
            const std::string mount=importDBQuery.value(4).toString().toStdString();

            pushElement(new Music(band, mount, name, ref, year));

        }while(importDBQuery.next());
    }
    importDBQuery.clear();

    importDBQuery.exec("select * from VG;");
    if (importDBQuery.first())
    {
        do
        {
            const std::string ref=importDBQuery.value(0).toString().toStdString();
            const std::string name=importDBQuery.value(1).toString().toStdString();
            const std::string console=importDBQuery.value(2).toString().toStdString();
            const int year=importDBQuery.value(3).toInt();
            const std::string mount=importDBQuery.value(4).toString().toStdString();

            pushElement(new VideoGame(console, mount, name, ref, year));

        }while(importDBQuery.next());
    }
    importDBQuery.clear();

    importDBQuery.exec("select * from EBOOK;");
    if (importDBQuery.first())
    {
        do
        {
            const std::string ref=importDBQuery.value(0).toString().toStdString();
            const std::string name=importDBQuery.value(1).toString().toStdString();
            const std::string autor=importDBQuery.value(2).toString().toStdString();
            const int year=importDBQuery.value(3).toInt();
            const std::string mount=importDBQuery.value(4).toString().toStdString();

            pushElement(new Ebook(autor, mount, name, ref, year));

        }while(importDBQuery.next());
    }
    importDBQuery.clear();

    importDBQuery.exec("select * from BOOK;");
    if (importDBQuery.first())
    {
        do
        {
            const std::string ref=importDBQuery.value(0).toString().toStdString();
            const std::string name=importDBQuery.value(1).toString().toStdString();
            const std::string autor=importDBQuery.value(2).toString().toStdString();
            const int year=importDBQuery.value(3).toInt();
            const std::string style=importDBQuery.value(4).toString().toStdString();

            pushElement(new Book(style, autor, name, ref, year));

        }while(importDBQuery.next());
    }
    importDBQuery.clear();

    importDBQuery.exec("select * from COMIC;");
    if (importDBQuery.first())
    {
        do
        {
            const std::string ref=importDBQuery.value(0).toString().toStdString();
            const std::string name=importDBQuery.value(1).toString().toStdString();
            const std::string autor=importDBQuery.value(2).toString().toStdString();
            const int year=importDBQuery.value(3).toInt();

            pushElement(new Comic(autor, name, ref, year));

        }while(importDBQuery.next());
    }
    importDBQuery.clear();
}

void Library::exportDB()
{
    for(unsigned int i=0; i<_docsList.size(); i++)
    {
        QSqlQuery exportDBQuery;
        QString query;

        switch(intTheType(i))
        {
        case 2:
        {
            const std::string ref=getElement(i)->getRef();
            const std::string name=getElement(i)->getName();
            const std::string director=getElement(i)->getDirector();
            const int year=getElement(i)->getYear();
            const std::string mount=getElement(i)->getMount();
            query="insert into FILM values (\"";
            query+= QString::fromStdString(ref);
            query+= "\", \"";
            query+= QString::fromStdString(name);
            query+= "\", \"";
            query+= QString::fromStdString(director);
            query+= "\", ";
            query+= QString::number(year, 10);
            query+= ", \"";
            query+= QString::fromStdString(mount);
            query+= "\");";
            exportDBQuery.exec(query);
        }
            break;
        case 6:
        {
            const std::string ref=getElement(i)->getRef();
            const std::string name=getElement(i)->getName();
            const std::string band=getElement(i)->getBand();
            const int year=getElement(i)->getYear();
            const std::string mount=getElement(i)->getMount();
            query="insert into MUSIC values (\"";
            query+= QString::fromStdString(ref);
            query+= "\", \"";
            query+= QString::fromStdString(name);
            query+= "\", \"";
            query+= QString::fromStdString(band);
            query+= "\", ";
            query+= QString::number(year, 10);
            query+= ", \"";
            query+= QString::fromStdString(mount);
            query+= "\");";
            exportDBQuery.exec(query);
        }
            break;
        case 3:
        {
            const std::string ref=getElement(i)->getRef();
            const std::string name=getElement(i)->getName();
            const std::string console=getElement(i)->getConsole();
            const int year=getElement(i)->getYear();
            const std::string mount=getElement(i)->getMount();
            query="insert into VG values (\"";
            query+= QString::fromStdString(ref);
            query+= "\", \"";
            query+= QString::fromStdString(name);
            query+= "\", \"";
            query+= QString::fromStdString(console);
            query+= "\", ";
            query+= QString::number(year, 10);
            query+= ", \"";
            query+= QString::fromStdString(mount);
            query+= "\");";
            exportDBQuery.exec(query);
        }
            break;
        case 5:
        {
            const std::string ref=getElement(i)->getRef();
            const std::string name=getElement(i)->getName();
            const std::string autor=getElement(i)->getAutor();
            const int year=getElement(i)->getYear();
            const std::string mount=getElement(i)->getMount();
            query="insert into EBOOK values (\"";
            query+= QString::fromStdString(ref);
            query+= "\", \"";
            query+= QString::fromStdString(name);
            query+= "\", \"";
            query+= QString::fromStdString(autor);
            query+= "\", ";
            query+= QString::number(year, 10);
            query+= ", \"";
            query+= QString::fromStdString(mount);
            query+= "\");";
            exportDBQuery.exec(query);
        }
            break;
        case 1:
        {
            const std::string ref=getElement(i)->getRef();
            const std::string name=getElement(i)->getName();
            const std::string autor=getElement(i)->getAutor();
            const int year=getElement(i)->getYear();
            query="insert into COMIC values (\"";
            query+= QString::fromStdString(ref);
            query+= "\", \"";
            query+= QString::fromStdString(name);
            query+= "\", \"";
            query+= QString::fromStdString(autor);
            query+= "\", ";
            query+= QString::number(year, 10);
            query+= ");";
            exportDBQuery.exec(query);
        }
            break;
        case 4:
        {
            const std::string ref=getElement(i)->getRef();
            const std::string name=getElement(i)->getName();
            const std::string autor=getElement(i)->getAutor();
            const int year=getElement(i)->getYear();
            const std::string style=getElement(i)->getStyle();
            query="insert into BOOK values (\"";
            query+= QString::fromStdString(ref);
            query+= "\", \"";
            query+= QString::fromStdString(name);
            query+= "\", \"";
            query+= QString::fromStdString(autor);
            query+= "\", ";
            query+= QString::number(year, 10);
            query+= ", \"";
            query+= QString::fromStdString(style);
            query+= "\");";
            exportDBQuery.exec(query);
        }
            break;
        default:
            std::cout<<"Problem Occured -> Function Library::exportDB() i>6 or i<1"<<std::endl;
        }
        exportDBQuery.clear();
    }
}

void Library::clearDB()
{
    QSqlQuery clearDBQuery;

    clearDBQuery.exec("delete from FILM;");
    clearDBQuery.clear();

    clearDBQuery.exec("delete from MUSIC;");
    clearDBQuery.clear();

    clearDBQuery.exec("delete from BOOK;");
    clearDBQuery.clear();

    clearDBQuery.exec("delete from EBOOK;");
    clearDBQuery.clear();

    clearDBQuery.exec("delete from VG;");
    clearDBQuery.clear();

    clearDBQuery.exec("delete from COMIC;");
    clearDBQuery.clear();
}
*/
unsigned int Library::intTheType(const int & position)
{
    if(getElement(position)->getType()=="Film")
    {
        return 2;
    }
    else
    {
        if(getElement(position)->getType()=="Musique")
        {
            return 6;
        }
        else
        {
            if(getElement(position)->getType()=="Jeux Video")
            {
                return 3;
            }
            else
            {
                if(getElement(position)->getType()=="Livre Numérique")
                {
                    return 5;
                }
                else
                {
                    if(getElement(position)->getType()=="Bande Dessinée")
                    {
                        return 1;
                    }
                    else
                    {
                        if(getElement(position)->getType()=="Livre")
                        {
                            return 4;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
