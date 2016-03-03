OBJ = stdArchSim
MAN = stdArchSim.1
override CFLAGS += -Ofast -funroll-loops -flto -Wall -std=c++11
override DEVEL_FLAGS += -g -Wall -std=c++11
override LFLAGS +=
CXX ?= g++
PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man1
CXXFILES = ALU.cpp  Decoder.cpp  main.cpp	MainMemory.cpp	Microinstruction.cpp  RegisterArray.cpp  ROM.cpp
OBJFILES = $(patsubst %.cpp,%.o,$(CXXFILES))

$(OBJ) : $(OBJFILES)
	$(CXX) $(DEVEL_FLAGS) $^ -o $@ $(LFLAGS)

%.o : %.cpp
	$(CXX) $(DEVEL_FLAGS) -c $^

clean :
	rm -f *.o $(OBJ)

clear : clean

ofast : clean
	$(CXX) $(CFLAGS) -c $(CXXFILES)
	$(CXX) $(CFLAGS) -o $(OBJ) $(OBJFILES) $(LFLAGS)

install : $(OBJ)
	@echo "Installing program to $(DESTDIR)$(BINDIR) ..."
	@mkdir -p $(DESTDIR)$(BINDIR)
	@install -pm0755 $(OBJ) $(DESTDIR)$(BINDIR)/$(TARGET) || \
		echo "Failed. Try "make PREFIX=~ install" ?"
	@echo "Installing manpage to $(DESTDIR)$(MANDIR) ..."
	@mkdir -p $(DESTDIR)$(MANDIR)
	@install -pm0644 $(MAN) $(DESTDIR)$(MANDIR)/ || \
		echo "Failed. Try "make PREFIX=~ install" ?"

all : install

