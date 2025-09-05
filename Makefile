CXX = clang++
CXXFLAGS = -std=c++20 -pedantic -Wall -Wextra -Wno-sign-compare -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable -g3

BUILDDIR = dist/
BINEXE = note
ifeq ($(OS),Windows_NT)
	BINEXE = note.exe
endif

all: build

build:
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) src/main.cpp -o $(BUILDDIR)$(BINEXE) 

clean:
	rm -rf $(BUILDDIR)
