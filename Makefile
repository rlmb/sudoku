# set compiler and compile options
EXEC = main
# use the GNU C++ compiler
CXX = g++
# use  C++11, some optimization, report all warnings and enable debugging
CFLAGS = -std=c++11 -O2 -Wall -g

# set a list of directories
INCDIR = ./include
BINDIR = ./bin
SRCDIR = ./src

# set the include folder where the .h files reside
CFLAGS += -I$(INCDIR)

# add here the source files for the compilation
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJ)
	$(CXX) $(CFLAGS) -o $(BINDIR)/$(EXEC) $(SOURCES) $(LDFLAGS)

clean:
	rm -vf $(BINDIR)/$(EXEC)

