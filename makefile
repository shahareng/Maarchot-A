CC=gcc
WALL= -Wall -g
O_MAIN=main.o
O_BANK=myBank.o

all: libmybank.so libmybank.a mains maind
main.o: main.c myBank.h
	$(CC) $(WALL) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) -fPIC -c myBank.c

libmybank.so: $(O_BANK)
	$(CC) -shared -o libmybank.so $(O_BANK)

libmybank.a: $(O_BANK)
	ar -rcs libmybank.a $(O_BANK)

 mains: $(O_MAIN) libmybank.a
	$(CC) $(WALL) -o mains $(O_MAIN) libmybank.a

 maind: $(O_MAIN)
	$(CC) $(WALL) -o maind $(O_MAIN) ./libmybank.so

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind 