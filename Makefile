CPPFLAGS = -I.
CC = g++
OBJS = main.cpp tst_scanner.cpp scanner.cpp
OBJS1 = main.o tst_scanner.o scanner.o
HOBJS = token.h tst_scanner.h scanner.h
TARGET = scanner

$(TARGET): $(OBJS1)
	$(CC) $(CPPFLAGS) $(OBJS1) -o $(TARGET)

$(OBJS1): $(OBJS)
	$(CC) $(CPPFLAGS) -c $(OBJS)

clean:
	rm -f *o input.dat $(TARGET)

