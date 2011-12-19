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
    std::cout<<_docsList[position]->getRef()<<" "<<_docsList[position]->getName()<<" "<<_docsList[position]->getYear()<<" "<<_docsList[position]->getMount()<<" "<<_docsList[position]->getDirector()<<std::endl;
}

void Library::displayMusic(const int& position)
{
    std::cout<<_docsList[position]->getRef()<<" "<<_docsList[position]->getName()<<" "<<_docsList[position]->getYear()<<" "<<_docsList[position]->getMount()<<" "<<_docsList[position]->getBand()<<std::endl;
}

void Library::displayVideoGame(const int& position)
{
    std::cout<<_docsList[position]->getRef()<<" "<<_docsList[position]->getName()<<" "<<_docsList[position]->getYear()<<" "<<_docsList[position]->getMount()<<" "<<_docsList[position]->getConsole()<<std::endl;
}

void Library::displayEbook(const int& position)
{
    std::cout<<_docsList[position]->getRef()<<" "<<_docsList[position]->getName()<<" "<<_docsList[position]->getYear()<<" "<<_docsList[position]->getAutor()<<" "<<_docsList[position]->getMount()<<std::endl;
}

void Library::displayComic(const int& position)
{
    std::cout<<_docsList[position]->getRef()<<" "<<_docsList[position]->getName()<<" "<<_docsList[position]->getYear()<<" "<<_docsList[position]->getAutor()<<std::endl;
}

void Library::displayBook(const int& position)
{
    std::cout<<_docsList[position]->getRef()<<" "<<_docsList[position]->getName()<<" "<<_docsList[position]->getYear()<<" "<<_docsList[position]->getAutor()<<" "<<_docsList[position]->getStyle()<<std::endl;
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

unsigned int Library::intTheType(const int & position)
{
    if(_docsList[position]->getType()=="Film")
    {
        return 2;
    }
    else
    {
        if(_docsList[position]->getType()=="Musique")
        {
            return 6;
        }
        else
        {
            if(_docsList[position]->getType()=="Jeux Video")
            {
                return 3;
            }
            else
            {
                if(_docsList[position]->getType()=="Livre Numérique")
                {
                    return 5;
                }
                else
                {
                    if(_docsList[position]->getType()=="Bande Dessinée")
                    {
                        return 1;
                    }
                    else
                    {
                        if(_docsList[position]->getType()=="Livre")
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
