OBJ = stdArchSim
MAN = stdArchSim.1
override CFLAGS += -Ofast -funroll-loops -flto -Wall 
override DEVEL_FLAGS += -g -Wall 
override LFLAGS += 
CC = g++
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man1

$(OBJ) : Accumulator.o Databus.o ALU.o main.o ControlSignals.o
	$(CC) -Wall $^ -o $@ $(LFLAGS)

%.o : %.cpp
	$(CC) $(DEVEL_FLAGS) -c $^

clean :
	rm -f *.o $(OBJ)

ofast :
	$(CC) $(CFLAGS) -c Accumulator.cpp
	$(CC) $(CFLAGS) -c Databus.cpp
	$(CC) $(CFLAGS) -c ALU.cpp
	$(CC) $(CFLAGS) -c main.cpp

install : $(OBJ)
	@echo "Installing program to $(DESTDIR)$(BINDIR) ..."
	@mkdir -p $(DESTDIR)$(BINDIR)
	@install -pm0755 $(OBJ) $(DESTDIR)$(BINDIR)/$(TARGET) || \
		echo "Failed. Try "make PREFIX=~ install" ?"
	@echo "Installing manpage to $(DESTDIR)$(MANDIR) ..."
	@mkdir -p $(DESTDIR)$(MANDIR)
	@install -pm0644 $(MAN) $(DESTDIR)$(MANDIR)/ || \
		echo "Failed. Try "make PREFIX=~ install" ?"
