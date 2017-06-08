# /*****************\ #
#    	Makefile      #
# \*****************/ #
# 
# print all example source files syntax highlighted with vim: http://stackoverflow.com/questions/7844434/recursively-printing-all-files-from-vim
#

FLAGS = -Wall
DEBUG = -g3 -rdynamic -ggdb #-save-temps
CC = gcc

clean:
	clear
	rm -rf bin/*
	rm -f test.txt
args: clean
	$(CC) $(DEBUG) $(FLAGS) examples/args.c -o bin/args
arrays: clean
	$(CC) $(DEBUG) $(FLAGS) examples/arrays.c -o bin/arrays && bin/arrays
cat: clean
	$(CC) $(DEBUG) $(FLAGS) examples/cat.c -o bin/cat && bin/cat parse_test.txt
fib: clean
	$(CC) $(DEBUG) $(FLAGS) examples/fib.c -o bin/fib && bin/fib
fork: clean
	$(CC) $(DEBUG) $(FLAGS) examples/fork.c -o bin/fork && bin/fork
stdin: clean
	$(CC) $(DEBUG) $(FLAGS) examples/stdin.c -o bin/stdin && bin/stdin
signals: clean
	$(CC) $(DEBUG) $(FLAGS) examples/signals.c -o bin/signals && bin/signals
grep: clean
	$(CC) $(DEBUG) $(FLAGS) examples/grep.c -o bin/grep && bin/grep
sll: clean
	$(CC) $(DEBUG) $(FLAGS) examples/sll.c -o bin/sll && bin/sll
ggT: clean
	$(CC) $(DEBUG) $(FLAGS) examples/ggT.c -o bin/ggT && bin/ggT 40 5
primes: clean
	$(CC) $(DEBUG) $(FLAGS) examples/primes.c -o bin/primes && bin/primes
parse: clean
	$(CC) $(DEBUG) $(FLAGS) examples/parse.c -o bin/parse && bin/parse
sort: clean
	$(CC) $(DEBUG) $(FLAGS) examples/sort.c -o bin/sort && bin/sort
pipes: clean
	$(CC) $(DEBUG) $(FLAGS) examples/pipes.c -o bin/pipes && bin/pipes
prime: clean
	$(CC) $(DEBUG) $(FLAGS) examples/prime.c -o bin/prime && bin/prime
rand: clean
	$(CC) $(DEBUG) $(FLAGS) examples/rand.c -o bin/rand && bin/rand
sockets: clean
	$(CC) $(DEBUG) $(FLAGS) examples/sockets.c -o bin/sockets && bin/sockets
strings: clean
	$(CC) $(DEBUG) $(FLAGS) examples/strings.c -o bin/strings && bin/strings
system: clean
	$(CC) $(DEBUG) $(FLAGS) examples/system.c -o bin/system && bin/system
threads: clean
	$(CC) $(DEBUG) $(FLAGS) examples/threads.c -o bin/threads && bin/threads
structs: clean
	$(CC) $(DEBUG) $(FLAGS) examples/structs.c -o bin/structs && bin/structs
fileio: clean
	$(CC) $(DEBUG) $(FLAGS) examples/fileio.c -o bin/fileio && bin/fileio
	
