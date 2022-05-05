debug: CFLAGS += -g
debug: CFLAGS += -O0
debug: CFLAGS += -DDEBUG
debug: conf2d

conf2d: conf2d.c args.c


clean:
	rm -f *.o
	rm -f conf2d
