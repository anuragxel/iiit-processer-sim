OBJ = stdArchAssembler
MAN = stdArchAssembler.1
override CFLAGS += -Ofast -funroll-loops -flto -Wall -std=c++11
override DEVEL_FLAGS += -g -Wall -std=c++11
override LFLAGS +=
CC = g++
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man1

$(OBJ) : Assembler.o
	$(CC) $(DEVEL_FLAGS) $^ -o $@ $(LFLAGS)

Assembler.o : Assembler.cpp
	$(CC) $(DEVEL_FLAGS) -c $^

clean :
	rm -f Assembler.o $(OBJ)

clear : clean

ofast :
	$(CC) $(CFLAGS) -c Assembler.cpp
	$(CC) $(CFLAGS) -o $(OBJ) Assembler.o $(LFLAGS)

install : $(OBJ)
	@echo "Installing program to $(DESTDIR)$(BINDIR) ..."
	@mkdir -p $(DESTDIR)$(BINDIR)
	@install -pm0755 $(OBJ) $(DESTDIR)$(BINDIR)/$(TARGET) || \
		echo "Failed. Try "make PREFIX=~ install" ?"
	@echo "Installing manpage to $(DESTDIR)$(MANDIR) ..."
	@mkdir -p $(DESTDIR)$(MANDIR)
	@install -pm0644 $(MAN) $(DESTDIR)$(MANDIR)/ || \
		echo "Failed. Try "make PREFIX=~ install" ?"
