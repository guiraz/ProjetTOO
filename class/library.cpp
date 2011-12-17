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
