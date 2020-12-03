ECHO = echo
GCC = g++
CCFLAGS = -c -Wall -g -ansi -pedantic -O1 -std=c++11
OBJETS = StreamLog.o Stats_graph.o main.o
PRINT_MAP = -DMAP
#PRINT_MAP =
EXEC = ../Tests/analog
#LIBRARIES = -l

$(EXEC) : $(OBJETS)
	$(GCC) -o $(EXEC) $(OBJETS)

%.o : %.cpp
	$(GCC) $(CCFLAGS) $(PRINT_MAP) $<

StreamLog.o : StreamLog.h
Stats_graph.o : Stats_graph.h

Run : $(EXEC)
	./$(EXEC)

Memory_Check : $(EXEC)
	valgrind --leak-check=yes ./$(EXEC)

Clean :
	rm -rf *.o

MrProper : Clean
	rm -rf $(EXEC)