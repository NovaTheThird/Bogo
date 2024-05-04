PRG=bogo.exe

GCC=gcc
FLAGS=-O2 -Wall -Wextra

SOURCE=src/bogo.c
DRIVER=src/main.c

gcc:
	$(GCC) -o $(PRG) $(DRIVER) $(SOURCE) $(FLAGS)
clean:
	rm -f *.exe