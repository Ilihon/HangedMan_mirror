.PHONY: all

g = g++
flags = -Wall -c

all: bin/main


bin/main: build/main.o build/filework.o build/draw.o build/misstake.o
	$(g) $^ -o bin/main

build/main.o:
	$(g)  $(flags) src/main.cpp -o $@

build/filework.o:
	$(g)  $(flags) src/filework.cpp -o $@

build/draw.o:
	$(g)  $(flags) src/draw.cpp -o $@
	
build/misstake.o:
	$(g)  $(flags) src/misstake.cpp -o $@

run:
	bin/main

clean:
	rm build/*.o
