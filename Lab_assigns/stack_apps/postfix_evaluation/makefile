SRC := $(wildcard *.c)

OBJ := $(patsubst %.c, %.o, $(SRC))
link.exe: $(OBJ)
	gcc -o $@ $(OBJ) -lm

clean:
	rm *.o *.exe
