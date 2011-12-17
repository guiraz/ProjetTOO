#include <iostream>
#include <cstring>
#include <vector>
#include "library.h"
#include "docs.h"
#include "read.h"
#include "multimedia.h"
#include "film.h"
#include "music.h"
#include "videogame.h"
#include "ebook.h"
#include "book.h"
#include "comic.h"

using namespace std;

int main()
{
   Library lib;
   Film f("Christopher Nolan", "Blu-Ray", "Batman : The Dark Knight", "ref001", 2008);
   Film f2("Georges Lucas", "DVD", "Un nouvel espoir", "ref002", 1977);
   Book l("Récit", "John Krakauer", "Into The Wild", "ref003", 2008);
   Ebook eb("Delphine de Vigan", "ePub", "Rien ne s'oppose a la nuit", "ref004", 2011);
   Comic bd("Morris", "Lucky Luke : La corde au cou", "ref005", 2006);
   Comic bd2("Rosinsky - Van Hamme", "Thorgal : Au dela des ombres", "ref006", 1998);
   VideoGame vg("PS3", "Blu-Ray", "Batman Arkham City", "ref007", 2011);
   VideoGame vg2("Xbox 360", "DVD", "Call Of Duty : Black Ops", "ref008", 2010);
   Music mus("Will Smith", "CD", "Big Willie Style", "ref009", 1997);
   Music mus2("Placebo", "CD", "Self Tilted", "ref010", 1996);
   
   
   lib.pushElement(&mus);
   lib.pushElement(&f2);
   lib.pushElement(&vg);
   lib.pushElement(&eb);
   lib.pushElement(&f);
   lib.pushElement(&bd2);
   lib.pushElement(&l);
   lib.pushElement(&vg2);
   lib.pushElement(&bd);
   lib.pushElement(&mus2);
   
   
   lib.displayAll();
   lib.sortByType();
   cout<<endl<<endl;
   lib.displayAll();
   lib.erase();
}
