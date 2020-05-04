.PHONY: all

g = g++
flags = -Wall -c

all: bin/main run


bin/main: build/src/main.o build/src/filework.o build/src/draw.o build/src/misstake.o
	$(g) $^ -o bin/main

build/src/main.o:
	$(g)  $(flags) src/main.cpp -o $@

build/src/filework.o:
	$(g)  $(flags) src/filework.cpp -o $@

build/src/draw.o:
	$(g)  $(flags) src/draw.cpp -o $@

build/src/misstake.o:
	$(g)  $(flags) src/misstake.cpp -o $@

run:
	bin/main

clean:
	rm build/src/*.o
