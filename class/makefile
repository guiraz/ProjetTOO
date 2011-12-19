#Macros
cc = g++
w = -Wall
objet = main.o docs.o read.o multimedia.o film.o music.o videogame.o ebook.o book.o comic.o library.o
exe = test
#Regles princial
all: $(exe)

# %.ext -> recherche de tout les fichier avec l'extension 'ext'
%.o : %.cpp
	$(cc) $(w) -c $?
$(exe) : $(objet)
	$(cc) $(w) -o $@ $^
clean :
	rm *.o
mrpropre : clean
	rm $(exe)
	
mrpropre2 : clean
	rm $(exe)
	rm ../HTML/index.html
	rm ../HTML/style.css

# $@ nom cible
# $< nom 1ere dependance
# $^ liste dependances
# $? liste dependances plus recentes que la cible
# $* nom fichier sans suffixe
# % generique
