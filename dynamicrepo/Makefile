CC = gcc
CFLAGS = -Wall
LDFLAGS = -ldl

SRC = main.c
OBJ = $(SRC:.c=.o)

LIBRARIES = -L./ -lrepair -ljournal

myprogram: $(OBJ)
	$(CC) $(CFLAGS) -o myprogram $(OBJ) $(LIBRARIES) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f myprogram $(OBJ)

.PHONY: all clean