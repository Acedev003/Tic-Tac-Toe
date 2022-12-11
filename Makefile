CXX = g++
CXXFLAGS = -Wall -g

OUT_FILE  = "./bin/tic_tac"
bin_dir   = "bin"
build_dir = "build"


all: build/main.o build/util.o build/tic_tac.o
	$(CXX) build/main.o build/util.o build/tic_tac.o $(CXXFLAGS) -o $(OUT_FILE)

build/main.o: src/main.cpp
	$(CXX) -c src/main.cpp -o build/main.o	

build/util.o: src/util/util.cpp src/util/util.hpp
	$(CXX) -c src/util/util.cpp -o build/util.o	

build/tic_tac.o: src/tic_tac/tic_tac.cpp src/tic_tac/tic_tac.hpp 
	$(CXX) -c src/tic_tac/tic_tac.cpp -o build/tic_tac.o	

init:
	mkdir -p $(build_dir)
	mkdir -p $(bin_dir)

run:
	./bin/tic_tac

clean:
	rm -f build/*.o
	rm bin/tic_tac

