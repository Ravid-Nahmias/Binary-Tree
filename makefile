all: Btree.cpp Btree.h Ex4.cpp
	g++ -g Btree.cpp Ex4.cpp -o Ex4

all-GDB: Btree.cpp Btree.h Ex4.cpp
	g++ -g Btree.cpp Ex4.cpp -o Ex4