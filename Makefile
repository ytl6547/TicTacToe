CC       = g++
CPPFLAGS = -std=c++11
all: TicTacToe

TicTacToe.o: TicTacToe.h TicTacToe.cpp
	$(CC) $(CPPFLAGS) -c TicTacToe.cpp -o TicTacToe.o

TicTacToe: TicTacToe.o main.cpp
	$(CC) $(CPPFLAGS) TicTacToe.o main.cpp -o TicTacToe

.PHONY: clean

clean:
	rm TicTacToe.o
	rm TicTacToe