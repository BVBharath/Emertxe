SRC:= $(wildcard *.c)

OBJ:= $(patsubst *.c, *.o, $(SRC))

a9.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o *.exe
