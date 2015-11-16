CC=g++
CFLAGS=-Wall -g -std=c++11

Target=shareptr_test mutex_test

all: $(Target)

shareptr_test: shareptr_test.o
	$(CC) shareptr_test.o  -o $@

shareptr_test.o: shareptr_test.cpp
	$(CC) $(CFLAGS) shareptr_test.cpp

mutex_test: mutex_test.o
	$(CC) mutex_test.o  -o $@

mutex_test.o: mutex_test.cpp
	$(CC) $(CFLAGS) mutex_test.cpp

clean:
	rm *o shareptr_test