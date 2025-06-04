FLAG := gcc -m32 -fno-pie

all: bin/main

bin/main: obj/main.o obj/on_off.o obj/frecce_direzione.o obj/gomme.o
	$(FLAG) obj/main.o obj/on_off.o obj/frecce_direzione.o obj/gomme.o -o bin/main

obj/main.o: src/main.c
	$(FLAG) -c src/main.c -o obj/main.o

obj/on_off.o: src/on_off.s
	$(FLAG) -c src/on_off.s -o obj/on_off.o

obj/frecce_direzione.o: src/frecce_direzione.s
	$(FLAG) -c src/frecce_direzione.s -o obj/frecce_direzione.o

obj/gomme.o: src/gomme.s
	$(FLAG) -c src/gomme.s -o obj/gomme.o

clean:
	rm -rf obj/*.o bin/main