SRC := $(wildcard *.c)

OBJ := $(patsubst %.c, %.o, $(SRC))
calc.exe: $(OBJ)
	gcc -o $@ $(OBJ)

clean:
	rm *.o *.exe
