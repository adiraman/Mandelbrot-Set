CC = gcc
CXX = g++
CFLAGS = -I./include/ -Wall -pedantic -std=c++11
LDFLAGS = -lSDL2 -lSDL2_mixer

SRCDIRS = ./src
BUILDDIR = ./obj
TARGETDIR = ./exec
SRCEXT = cpp

SOURCES = $(shell find $(SRCDIRS) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIRS)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

EXECUTABLE = main
TARGET =$(TARGETDIR)/$(EXECUTABLE)
RM = rm -f
MKDIR_P = mkdir -p

all: directories $(TARGET)

directories: $(TARGETDIR)

$(TARGETDIR):
	$(MKDIR_P) $(TARGETDIR)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CXX) $(CFLAGS) -c $^
	$(MKDIR_P) $(BUILDDIR)
	mv *.o $(BUILDDIR)/

clean:
	$(RM) $(OBJECTS)

realclean:
	$(RM) $(TARGET) $(OBJECTS) *.out *.o *.bmp
