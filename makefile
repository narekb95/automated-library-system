GXX = g++
GXXFLAGS = -std=c++11 -O3

TARGET := libExample

all : $(TARGET)

$(TARGET): main.cpp lib.o user.o book.o
	$(GXX) $(GXXFLAGS) -o $(TARGET) main.cpp *.o

lib.o: lib.cpp lib.h user.o book.o
	$(GXX) $(GXXFLAGS) -c lib.cpp user.o book.o

user.o: user.cpp user.h book.o
	$(GXX) $(GXXFLAGS) -c user.cpp book.o

book.o: book.cpp book.h
	$(GXX) $(GXXFLAGS) -c book.cpp

clean:
	$(RM) *.o *~


