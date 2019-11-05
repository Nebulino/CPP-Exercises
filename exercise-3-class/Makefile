# -D NDEBUG => define NDEBUG => GEnerates test without debug
# -O3 => activate all optimization

# Best using => -D NDEBUG -O3

#CXX flags
CXXFLAGS = -D NDEBUG -O3
INC=-I./include

run_me: ./build/main.o ./build/dbuffer.o
	g++ ./build/dbuffer.o ./build/main.o -o ./run_me

./build/main.o: tests $(INC)/dbuffer.h
	g++ -c $(CXXFLAGS) ./src/main.cpp -o ./build/main.o

./build/dbuffer.o: ./src/dbuffer.cpp $(INC)/dbuffer.h
	g++ -c $(CXXFLAGS) $(INC)dbuffer.h -o ./build/dbuffer.o

.PHONY:
	clean:
		rm -rf ./run_me ./build/*