CC = gcc
CFLAGS = -Wall -I. -L.

# Исходные файлы
SOURCES = main.c
# Выходной исполняемый файл
TARGET = myprogram

# Список зависимостей
DEPENDENCIES = libmyjournallib.a libmyrepairlib.a

all: $(TARGET)

$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) -lmyjournallib -lmyrepairlib

libmyjournallib.a: journal.c journal.h
	$(CC) $(CFLAGS) -c journal.c -o journal.o
	ar rcs $@ journal.o

libmyrepairlib.a: repair.c repair.h
	$(CC) $(CFLAGS) -c repair.c -o repair.o
	ar rcs $@ repair.o

clean:
	rm -f $(TARGET) $(DEPENDENCIES) *.o

.PHONY: all clean