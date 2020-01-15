CC = g++
CPPFLAGS = -g -Wall -std=c++11

all:ll_merge_sort

ll_merge_sort: main.cpp linkedlist.o
	$(CC) $(CPPFLAGS) main.cpp linkedlist.o -o ll_merge_sort

linkedlist.o: linkedlist.h linkedlist.cpp
	$(CC) $(CPPFLAGS) -c linkedlist.cpp -o linkedlist.o