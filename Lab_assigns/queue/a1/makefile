SRC := $(wildcard *.c)

OBJ := $(patsubst %.c, %.o, $(SRC))
link.exe: $(OBJ)
	gcc -o $@ $(OBJ)

clean:
	rm *.o *.exe
