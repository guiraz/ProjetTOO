#include <iostream>
#include <cstring>
#include <vector>
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
   Docs * ptr;
   Film eb("Samere", "PDF", "Soncul", "ref001", 2004);
   ptr=&eb;
   cout<<ptr->getName()<<" "<<ptr->getDirector()<<" "<<ptr->getYear()<<endl;
}
