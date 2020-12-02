ECHO = echo
GCC = g++
CCFLAGS = -c -Wall -g -ansi -pedantic -O1 -std=c++11
OBJETS = Catalogue.o TableauDynamique.o Trajet.o TrajetCompose.o TrajetSimple.o main.o
PRINT_MAP = -DMAP
#PRINT_MAP =
EXEC = main
#LIBRARIES = -l

$(EXEC) : $(OBJETS)
	$(GCC) -o $(EXEC) $(OBJETS)

%.o : %.cpp
	$(GCC) $(CCFLAGS) $(PRINT_MAP) $<

Catalogue.o : Catalogue.h
TableauDynamique.o : TableauDynamique.h
Trajet.o : Trajet.h
TrajetCompose.o : TrajetCompose.h
TrajetSimple.o : TrajetSimple.h

Run : $(EXEC)
	./$(EXEC)

Memory_Check : $(EXEC)
	valgrind --leak-check=yes ./$(EXEC)

Clean :
	rm -rf *.o

MrProper : Clean
	rm -rf $(EXEC)