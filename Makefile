debug: CFLAGS += -g
debug: CFLAGS += -O0
debug: CFLAGS += -DDEBUG
debug: conf2d

conf2d: conf2d.o args.o read_dir.o

*.o: *.c

clean:
	rm -f *.o
	rm -f conf2d
