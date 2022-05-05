debug: CFLAGS += -g
debug: CFLAGS += -O0
debug: CFLAGS += -DDEBUG
debug: conf2d

conf2d: args.o clocker.o conf2d.o dir2file.o monitor.o

*.o: *.c

clean:
	rm -f *.o
	rm -f conf2d
